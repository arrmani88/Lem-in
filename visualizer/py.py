class Ant:
	def __init__(self, start_phase):
		self.start_phase = start_phase

ants = []

for i in range(9):
    ants.append(Ant(i))

for ant in ants:
    print(ant.start_phase)