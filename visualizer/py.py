lst = [[1, 2, 3], ['a', 'b', 'c'], ['!', '@', '#']]
sm = []
la = []

for i in lst:
    sm.extend(i)
    la.append(sm.copy())
    print(la)
    sm.clear()

print(la)

