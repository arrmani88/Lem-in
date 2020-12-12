# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vi.py                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 14:42:43 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/12 14:04:49 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.pyplot import imread
from class_ant import *
from add_icon import *
from data_parse import *

edges = []
nodes = {}
ants = []
ants.append(0)
fd = open("out", "r")
lines = fd.readlines()
parse_data(lines, nodes, edges, ants)

g = nx.Graph()
plt.figure(figsize=(20, 11.25))

bgimg = imread("visualizer/img/bgimg2.jpg")
im_ax = plt.axes([0, 0, 1, 1])
im_ax.imshow(bgimg, aspect='auto')
g_ax = plt.axes([0.035, 0.22, 0.92, 0.65])
add_nodes_edges(g, edges)
nx.draw(g, pos=nodes, ax=g_ax, with_labels=True, node_size=500, node_color="#B78356",
node_shape="8", linewidths=30, font_size=20, font_color="#33190a",
font_weight="bold", width=5, edge_color="#33190a")

plt.show()
#G.add_node(4, s="v", b=5) #s= specific shape for each node
