# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vi.py                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrmani88 <arrmani88@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 14:42:43 by arrmani88         #+#    #+#              #
#    Updated: 2020/12/09 23:01:32 by arrmani88        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.image as mtimg
from matplotlib.pyplot import imread
from add_icon import *

def     room_or_link(line):
	for c in line:
		if c == ' ':
			return 'r'
		elif c == '-':
			return 'l'

def     append_to_edges(line, edges):
	tmp = line.split('-')
	edges.append((tmp[0], tmp[1]))

def		append_to_nodes(line, nodes):
	tmp = line.split(' ')
	nodes[tmp[0]] = (int(tmp[1]), int(tmp[2]))

def		add_nodes_edges(g):
	# sqr = imread('visualizer/img/sqr.png')
	# g.add_node("1", image=sqr)
	# g.add_node("2", image=sqr)
	g.add_edges_from(edges)

edges = []
nodes = {}
fd = open("maaps/holygraph", "r")
lines = fd.readlines()
for line in lines:
	if line[0] != '#':
		var = room_or_link(line)
		if var == 'r':
			append_to_nodes(line[0:-1], nodes)
		elif var == 'l':
			append_to_edges(line[0:-1], edges)
#1920px, 1080px, 96x96dpi = 20inc, 11.25inc

g = nx.Graph()
plt.figure(figsize=(20, 11.25))

bgimg = imread("visualizer/img/bgimg.jpg")
im_ax = plt.axes([0, 0, 1, 1])
im_ax.imshow(bgimg, aspect='auto')
g_ax = plt.axes([0, 0, 1.0, 0.9])
add_nodes_edges(g)
nx.draw(g, pos=nodes, ax=g_ax, with_labels=True, node_size=700, node_color="#51361a",
node_shape="s", linewidths=20, font_size=10, font_color="skyblue",
font_weight="bold", width=5, edge_color="grey")

plt.show()
