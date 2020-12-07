import networkx as nx
import matplotlib.pyplot as ppt

def     room_or_link(line):
	for c in line:
		if c == ' ':
			return 'r'
		elif c == '-':
			return 'l'

def     append_to_edges(line, edges):
	lst = line.split('-')
	edges.append((lst[0], lst[1]))

	return

edges = []
fd = open(0, "r")
lines = fd.readlines()
for line in lines:
	if line[0] != '#':
		var = room_or_link(line)
		if var == 'l':
			append_to_edges(line[0:-1], edges)


g = nx.Graph()
g.add_edges_from(edges)
print(edges)
# print(nx.info(g))
nx.draw(g, with_labels="True")
ppt.show()




