# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    set_img.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 14:42:39 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/14 21:04:49 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.image as mtimg
from matplotlib.pyplot import imread
from matplotlib.offsetbox import OffsetImage, AnnotationBbox
import matplotlib.image as mpimg
import numpy as np

def		show_bg_img():
	bgimg = imread("visualizer/img/bgimg2.jpg")
	im_ax = plt.axes([0, 0, 1, 1])
	im_ax.imshow(bgimg, aspect='auto')

def		convertData(x, y, transax, transfg):
	xx,yy = transax((x,y))
	xa,ya = transfg((xx,yy))
	return xa, ya

def     setAnimationList(transax, transfg, imglst):
	ant_img = imread("visualizer/img/ant.png")
	moveOneAnt(transax, transfg, ant_img)
	return 1

def     moveOneAnt(n1, n2, transax, transfg, ant_img):
	imsize = 0.1
	for (x, y) in zip(np.linspace(n1[0], n1[1], 10, endpoint=True), np.linspace(n2[0], n2[1], 10, endpoint=True)):
		xa, ya = convertData(x, y, transax, transfg)
		a = plt.axes([xa-imsize/2.0,ya-imsize/2.0, imsize, imsize])
		a.axis('off')
		oneMove = a.imshow(ant_img, animated=True)
	return oneMove
