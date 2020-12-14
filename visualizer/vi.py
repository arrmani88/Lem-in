# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vi.py                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 14:42:43 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/14 21:14:15 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.pyplot import imread
from class_ant import *
from set_img import *
from data_parse import *
import matplotlib.animation as animation

edges = []
nodes = {}
ants = []
imglst = []
ants.append(0)
parse_data(nodes, edges, ants)

fig = plt.figure(figsize=(20, 11.25))

show_bg_img()

g = nx.Graph()
gr_ax = plt.axes([0.035, 0.22, 0.92, 0.65])
add_nodes_edges(g, edges)
nx.draw(g, pos=nodes, ax=gr_ax, with_labels=True, node_size=210,
node_color="#B78356", node_shape="8", linewidths=30, font_size=20,
font_color="#33190a", font_weight="bold", width=5, edge_color="#33190a")
transax = gr_ax.transData.transform
transfg = fig.transFigure.inverted().transform

imglst = setAnimationList(transax, transfg, imglst)

anim = animation.ArtistAnimation(fig, imglst, interval=400, blit=False, repeat=False)

plt.show()
