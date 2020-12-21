# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vi.py                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 14:42:43 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/21 16:53:00 by anel-bou         ###   ########.fr        #
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
ants.append(0)
gnr = 5
parse_data(nodes, edges, ants, gnr)

# fig = plt.figure(figsize=(23.532656156639245, 13.237119088109575))
# fig = plt.figure(figsize=(33, 17.25))
fig = plt.figure(figsize=(15, 7.5))
# fig = plt.figure(figsize=(10, 5))
show_bg_img()

g = nx.Graph()
gr_ax = plt.axes([0.035, 0.22, 0.92, 0.65])
# gr_ax = plt.axes([0, 0, 1, 1])
add_nodes_edges(g, edges)
nx.draw(g, pos=nodes, ax=gr_ax, with_labels=True, node_size=300,
node_color="#B78356", node_shape="8", linewidths=10, font_size=20,
font_color="#33190a", font_weight="bold", width=3, edge_color="#33190a")
transax = gr_ax.transData.transform
transfg = fig.transFigure.inverted().transform

totalFrames = distributor(gnr, ants, transax, transfg, imread("visualizer/img/ant1.png"))
# totalFrames = distributor(gnr, ants, transax, transfg, imread("img/ant1.png"))
# print(totalFrames)
anim = animation.ArtistAnimation(fig, totalFrames, interval=1, repeat=False)
# anim.save('Lem-in.mp4', fps=30)#, extra_args=['-vcodec', 'libx264'])
plt.show()













# imsize = 0.1
# xa, ya = convertData(0, 0, transax, transfg)
# a = plt.axes([xa-imsize/2.0,ya-imsize/2.0, imsize, imsize])
# a.imshow(ant_img, animated=True)
# a.axis('off')

# def animate(i):
#     global a
#     simpleDraw(a, i, i, transax, transfg, ant_img)
# anim = animation.FuncAnimation(fig, animate, repeat=False, frames=100, interval=2)


# def	simpleDraw(a, x, y, transax, transfg, ant_img):
# 	imsize = 0.1
# 	xa, ya = convertData(x, y, transax, transfg)
# 	a = plt.axes([xa-imsize/2.0,ya-imsize/2.0, imsize, imsize])
	# a.axis('off')

