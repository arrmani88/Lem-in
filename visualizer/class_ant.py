# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    class_ant.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/11 14:00:26 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/11 21:52:59 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import re

class Ant:
	name = 0
	path = []
	def __init__(self, start_phase):
		self.start_phase = start_phase
	def	append_room(self, name):
		self.path.append(name)

def	append_ant(name, ants, phase):
	ants[name] = (Ant(phase))

def	handleOriganizedData(ants, antnb, room, phase):
	if antnb > len(ants) - 1:
		ants.append(Ant(phase))
	ants[antnb].append_room(room)

def	set_ant(line, ants, phase):
	elems = line.split(' ')
	for elem in elems:
		antRoom = re.split('L|-', elem)
		handleOriganizedData(ants, int(antRoom[1]), antRoom[2], phase)










	# 	print(int(antRoom[1]), antRoom[2], " <> ", end = '')
	# print("@", phase, "@", sep='')