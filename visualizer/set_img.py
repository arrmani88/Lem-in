# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    set_img.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 14:42:39 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/19 14:08:59 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
from matplotlib.pyplot import imread
import numpy as np
from class_ant import *

def		show_bg_img():
	bgimg = imread("img/bgimg2.jpg")
	im_ax = plt.axes([0, 0, 1, 1])
	im_ax.imshow(bgimg, aspect='auto')

def		convertData(x, y, transax, transfg):
	xx,yy = transax((x,y))
	xa,ya = transfg((xx,yy))
	return xa, ya

def	print_debug(n1, n2, i):
	print("ant=", i, " from(", n1,  ") to (", n2, ")", sep='')

def		getRoomCoordinates(room, nodes):
	return (nodes[room])

def     setAnimationList(transax, transfg, ants, nodes):
	phase = 1
	images_lst = []
	while (grp_stp := group_Step(transax, transfg, ants, nodes, phase)) != -1:
		images_lst.append([grp_stp])
		print()
		phase += 1
	return images_lst

def     group_Step(transax, transfg, ants, nodes, phase):
	groupStep = []
	n1 = (-1, -1)
	ant_img = imread("img/ant.png")
	for i in range(1, len(ants)):
		if ants[i].start_phase == phase or ants[i].start_phase == '#':
			p = 0
			pth = ants[i].path
			while p < len(pth) and pth[p] == '#':
				p += 1
			if p + 1 < len(pth):# or p == len(pth):
				# print_debug(pth[p], pth[p+1], i)
				n1 = getRoomCoordinates(pth[p], nodes)
				if p != 0 or (p == 0 and ants[i].start_phase == '#' ):
					ants[i].deleteRoomFromPath(p)
					n2 = getRoomCoordinates(pth[p + 1], nodes)
				elif p == 0:
					n2 = n1
					n1 = (0, 4)
				groupStep.append(oneAntStep(n1, n2, transax, transfg, ant_img))
			if ants[i].start_phase == phase:
				ants[i].setAsStarted()
	if n1 == (-1, -1):
		return (-1)
	return groupStep

def     oneAntStep(n1, n2, transax, transfg, ant_img):
	imsize = 0.1
	oneMove = []
	gnr = 3
	for (x, y) in zip(np.linspace(n1[0], n2[0], gnr, endpoint=True), np.linspace(n1[1], n2[1], gnr, endpoint=True)):
		xa, ya = convertData(x, y, transax, transfg)
		a = plt.axes([xa-imsize/2.0,ya-imsize/2.0, imsize, imsize])
		a.axis('off')
		oneMove.append(a.imshow(ant_img, animated=True))
	return oneMove
