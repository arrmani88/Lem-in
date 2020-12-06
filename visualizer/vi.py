import networkx as nx
import matplotlib.pyplot as ppt

g = nx.Graph()

g.add_node(1)
g.add_node(2)
g.add_node(3)
g.add_node(4)
g.add_node(5)
g.add_node(0)
g.add_edges_from([(1, 2), (1, 3), (2, 4), (3,5), (5, 0), (4, 0)])

print(nx.info(g))

nx.draw(g)

ppt.show()