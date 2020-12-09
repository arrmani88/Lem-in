# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    add_icon.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrmani88 <arrmani88@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 14:42:39 by arrmani88         #+#    #+#              #
#    Updated: 2020/12/09 15:00:45 by arrmani88        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.image as mtimg
from matplotlib.pyplot import imread

def     add_icon(g, nodes):
    img = imread("visualizer/img/ant.png")
    ax=plt.gca()
    fig=plt.gcf()
    transax = ax.transData.transform
    transfg = fig.transFigure.inverted().transform
    imsize = 0.1 # this is the image size
    for n in g.nodes():
        (x,y) = nodes[n]
        xx,yy = transax((x,y)) # figure coordinates
        xa,ya = transfg((xx,yy)) # axes coordinates
        a = plt.axes([xa-imsize/2.0,ya-imsize/2.0, imsize, imsize])
        a.imshow(img)
        a.axis('off')