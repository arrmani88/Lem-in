class Ant:
	def __init__(self, start_phase):
		self.start_phase = start_phase #ma dihach f hadi
		self.path = []
	def	append_room(self, name):
		self.path.append(name)

def	Fill_ants_list(ants, antnb, room, phase):
	if antnb > len(ants) - 1: #if mkantch chi nemla f la case antnb .. =>
		ants.append(Ant(phase)) #=> .. creeiha w appendiha felakher dial list
	ants[antnb].append_room(room)

ants = [] #list an3emeroha b les objets li homa nnmel

ants.append(0) #7it makaynach nemla ra9m zero donc ankheliw ants[0] khawya

data = [[1, "a"], #list fiha:
		[2, "c"], #      1. Smeya dial nemla Li hya lindex dial list ants
		[3, "e"], #          (ant[1] fiha l'objet li howa nmla ra9em 1)
		[1, "d"], #      2. smia dial room li ghan appendiha 3la lpath dial l'objet nemla
		[4, "a"], # data = [[smeya nemla, room li ghan appendiha 3la had nemla], ...etc]
		[2, "f"],
		[3, "c"],
		[3, "h"],
		[4, "e"]]
for i in range(9):
	#had func hya li kat 3ammar lina list ants b men data[]
	Fill_ants_list(ants, data[i][0], data[i][1], i) #ma dihach f had arg lekkher "i"

for i in range(1, 5): #hadi bach nchofo kola nemla w lpath li msejjel fiha
	print("ant_name=", i, " ", "path=", ants[i].path, sep='')


