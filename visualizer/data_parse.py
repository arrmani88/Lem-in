# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    data_parse.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 13:55:55 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/19 20:57:53 by anel-bou         ###   ########.fr        #
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
	tmp = line.split(' ')
	nodes[tmp[0]] = (int(tmp[1]), int(tmp[2]))

def		add_nodes_edges(g, edges):
	g.add_edges_from(edges)

def		pointsBtwn2Rooms(x1, y1, room2, ant, nodes):
	(x, y) = getRoomCoordinates(room2, nodes)
	xlst = np.linspace(x1, x, 30, endpoint=True)
	ylst = np.linspace(y1, y, 30, endpoint=True)
	ant.extend_coor(xlst, ylst)

def 	translatePath2Coordinates(ants, nodes, start, gnr):
	for i in range(1, len(ants)):
		pointsBtwn2Rooms(start[0], start[1], ants[i].path[0], ants[i], nodes)
		for room in ants[i].path:
			pointsBtwn2Rooms(ants[i].xcoor[-1], ants[i].ycoor[-1], room, ants[i], nodes)

def	parse_data(nodes, edges, ants):
	phase = 0
	fd = open("maaps/out", "r")
	lines = fd.readlines()
	for line in lines:
		if line[0] != '#':
			var = room_or_link(line)
			if var == 'r':
				append_node(line[0:-1], nodes)
			elif var == 'l':
				append_edge(line[0:-1], edges)
			elif var == 'A':
				phase += 1
				totalAnts = set_ant(line[0:-1], ants, phase)
	translatePath2Coordinates(ants, nodes, (0, 4), 3)
	return phase