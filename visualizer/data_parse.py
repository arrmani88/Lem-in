# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    data_parse.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 13:55:55 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/24 10:51:18 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from class_ant import *
from set_img import *

def     room_or_link(line):
	if line[0] == 'L':
		return 'A'
	for c in line:
		if c == ' ':
			return 'r'
		elif c == '-':
			return 'l'

def     append_edge(line, edges):
	tmp = line.split('-')
	edges.append((tmp[0], tmp[1]))

def		append_node(line, nodes):
	tmp = re.split('\ +', line)
	nodes[tmp[0]] = (int(tmp[1]), int(tmp[2]))
	return (int(tmp[1]), int(tmp[2]))

def		add_nodes_edges(g, edges):
	g.add_edges_from(edges)

def		pointsBtwn2Rooms(x1, y1, room2, ant, nodes, gnr, i):
	(x, y) = getRoomCoordinates(room2, nodes)
	xlst = np.linspace(x1, x, gnr, endpoint=True)
	ylst = np.linspace(y1, y, gnr, endpoint=True)
	ant.extend_coor(xlst, ylst)

def 	translatePath2Coordinates(ants, nodes, start, gnr):
	for i in range(1, len(ants)):
		pointsBtwn2Rooms(start[0], start[1], ants[i].path[0], ants[i], nodes, gnr, i)
		for j in range(1, len(ants[i].path)):
			pointsBtwn2Rooms(ants[i].xcoor[-1], ants[i].ycoor[-1], ants[i].path[j], ants[i], nodes, gnr, i)

def	parse_data(nodes, edges, ants, gnr):
	phase = 0
	starting_room = 0
	# fd = open("maaps/out", "r")
	fd = open(0, "r")
	lines = fd.readlines()
	for line in lines:
		if line[0:-1] == 'ERROR':
			print(line, end='')
			exit()
		if line[0:-1] == '##start' and starting_room == 0:
			starting_room = 1
		elif starting_room == 1:
			starting_room = -1
			start = append_node(line[0:-1], nodes)
		elif line[0] != '#':
			var = room_or_link(line)
			if var == 'r':
				append_node(line[0:-1], nodes)
			elif var == 'l':
				append_edge(line[0:-1], edges)
			elif var == 'A':
				set_ant(line[0:-2], ants, phase)
				phase += 1
	translatePath2Coordinates(ants, nodes, start, gnr)
