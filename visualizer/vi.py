import networkx as nx
import matplotlib.pyplot as plt
import string

def     room_or_link(line):
	for c in line:
		if c == ' ':
			return 'r'
		elif c == '-':
			return 'l'

def     append_to_edges(line, edges):
	tmp = line.split('-')
	edges.append((tmp[0], tmp[1]))

def		append_to_nodes(line, nodes):
	tmp = line.split(' ')
	nodes[tmp[0]] = (int(tmp[1]), int(tmp[2]))

edges = []
nodes = {}
fd = open(0, "r")
lines = fd.readlines()
for line in lines:
	if line[0] != '#':
		var = room_or_link(line)
		if var == 'r':
			append_to_nodes(line[0:-1], nodes)
		elif var == 'l':
			append_to_edges(line[0:-1], edges)

g = nx.Graph()
g.add_edges_from(edges)
plt.figure(1,figsize=(30, 30))
# nx.draw(g, pos=None, with_labels="True", node_size=500)
nx.draw(g, pos=nodes, with_labels=True, node_size=700,
node_color="skyblue", node_shape="s", alpha=0.5, linewidths=4,
font_size=10, font_color="grey", font_weight="bold", width=2, edge_color="grey")

# nx.draw(g, with_labels=True, node_size=700, node_color="skyblue", 
# node_shape="s", alpha=0.5, linewidths=10)
plt.show()



