# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    set_img.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 14:42:39 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/13 17:49:31 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.image as mtimg
from matplotlib.pyplot import imread
from matplotlib.offsetbox import OffsetImage, AnnotationBbox
import matplotlib.image as mpimg

def	show_bg_img():
	bgimg = imread("visualizer/img/bgimg2.jpg")
	im_ax = plt.axes([0, 0, 1, 1])
	im_ax.imshow(bgimg, aspect='auto')

def     add_icon(g, x, y):
	img = imread("visualizer/img/ant.png")
	ax=plt.gca()
	fig=plt.gcf()
	transax = ax.transData.transform
	transfg = fig.transFigure.inverted().transform
	imsize = 0.1
	
	xx,yy = transax((x,y))
	xa,ya = transfg((xx,yy))
	a = plt.axes([xa-imsize/2.0,ya-imsize/2.0, imsize, imsize])
	a.imshow(img)
	a.axis('off')
	return(a)

# def	add_icon(ax):
# 	img = mpimg.imread('visualizer/img/ant.png')
# 	imagebox = OffsetImage(img, zoom=0.02)
# 	anbx = AnnotationBbox(imagebox, (2, 2))
# 	ax.add_artist(anbx)
# 	plt.draw()