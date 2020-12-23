# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    set_img.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 14:42:39 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/23 14:50:21 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
from matplotlib.pyplot import imread
import numpy as np
from class_ant import *

def		show_bg_img():
	bgimg = imread("visualizer/img/bgimg2.jpg")
	# bgimg = imread("img/bgimg2.jpg")
	im_ax = plt.axes([0, 0, 1, 1])
	im_ax.imshow(bgimg, aspect='auto')

def		convertData(x, y, transax, transfg):
	xx,yy = transax((x,y))
	xa,ya = transfg((xx,yy))
	return xa, ya

def		getRoomCoordinates(room, nodes):
	return (nodes[room])

def setOneFrame(x, y, transax, transfg, ant_img):
	imsize = 0.04
	xa, ya = convertData(x, y, transax, transfg)
	a = plt.axes([xa-imsize/2.0,ya-imsize/2.0, imsize, imsize])
	a.axis('off')
	obj = a.imshow(ant_img, animated=True)
	return obj

def	distributor(gnr, ants, transax, transfg, ant_img):
	oneFrame = []
	totalFrames = []
	startedAnts = 0
	frame_nb = 0
	while startedAnts or frame_nb == 0:
		phase = int(frame_nb / gnr)
		i = 0
		for i in range(1, len(ants)):
			if ants[i].start_phase == phase or ants[i].start_phase == '#':
				if ants[i].start_phase == phase:
					startedAnts += 1
					ants[i].setAsStarted()
				c = 0
				xcoor = ants[i].xcoor
				ycoor = ants[i].ycoor
				coorlen = len(xcoor)
				if xcoor[coorlen - 1] == '#' and startedAnts != 0:
					startedAnts -= 1
					ants[i].setAsFinished()
				else:
					while c < coorlen and xcoor[c] == '#':
						c += 1
					if c < coorlen:
						oneFrame.extend([setOneFrame(xcoor[c], ycoor[c], transax, transfg, ant_img)])
						ants[i].deletePointFromCoor(c)
		frame_nb += 1
		totalFrames.append(oneFrame.copy())
		oneFrame.clear()
	return totalFrames


def	print_ants(ants):
	for i in range(1, len(ants)):
		print(i, ants[i].path)
