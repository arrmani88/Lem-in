# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    class_ant.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/11 14:00:26 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/20 12:29:24 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import re

class Ant:
	def __init__(self, start_phase):
		self.start_phase = start_phase
		self.path = []
		self.xcoor = []
		self.ycoor = []
	def	append_room(self, name):
		self.path.append(name)
	def setAsStarted(self):
		self.start_phase = '#'
	def	setAsFinished(self):
		self.start_phase = '-1'
	def	deletePointFromCoor(self, i):
		self.xcoor[i] = '#'
		self.ycoor[i] = '#'
	def	extend_coor(self, xlst, ylst):
		self.xcoor.extend(xlst)
		self.ycoor.extend(ylst)

def	Fill_ants_list(ants, antnb, room, phase):
	if antnb > len(ants) - 1:
		ants.append(Ant(phase))
	ants[antnb].append_room(room)

def	set_ant(line, ants, phase):
	elems = line.split(' ')
	totalAnts = 0
	for elem in elems:
		antRoom = re.split('L|-', elem)
		Fill_ants_list(ants, int(antRoom[1]), antRoom[2], phase)
		if int(antRoom[1]) > totalAnts : totalAnts = int(antRoom[1])
	return totalAnts







def	print_ants(ants):
	for i in range(1, 14):
		print("ant_name=", i, " path=", ants[i].path, " start_phase=", ants[i].start_phase, sep='')
