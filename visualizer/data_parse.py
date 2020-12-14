# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    data_parse.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 13:55:55 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/13 18:14:02 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from class_ant import *

def     room_or_link(line):
	for c in line:
		if c == 'L':
			return 'A'
		elif c == ' ':
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
				set_ant(line[0:-1], ants, phase)
	