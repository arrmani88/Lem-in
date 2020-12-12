# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    class_ant.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/11 14:00:26 by anel-bou          #+#    #+#              #
#    Updated: 2020/12/12 01:15:31 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import re

class Ant:
	def __init__(self, start_phase):
		self.start_phase = start_phase
		self.path = []
	def	append_room(self, name):
		self.path.append(name)

def	Fill_ants_list(ants, antnb, room, phase):
	if antnb > len(ants) - 1:
		ants.append(Ant(phase))
	ants[antnb].append_room(room)

def	set_ant(line, ants, phase):
	elems = line.split(' ')
	for elem in elems:
		antRoom = re.split('L|-', elem)
		Fill_ants_list(ants, int(antRoom[1]), antRoom[2], phase)








	# 	print(int(antRoom[1]), antRoom[2], " <> ", end = '')
	# print("@", phase, "@", sep='')
def	print_ants(ants):
	for i in range(1, 14):
		print("ant_name=", i, " path=", ants[i].path, " start_phase=", ants[i].start_phase, sep='')
