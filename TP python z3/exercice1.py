from z3 import *

s = Int('s')
e = Int('e')
n = Int('n')
d = Int('d')
m = Int('m')
o = Int('o')
r = Int('r')
y = Int('y')

eq1 = And((s > 0), (s <= 9),
           (m > 0), (m <= 9), 
           (e >= 0), (e <= 9), 
           (n >= 0), (n <= 9), 
           (d >= 0), (d <= 9), 
           (o >= 0), (o <= 9), 
           (r >= 0), (r <= 9), 
           (y >= 0), (y <= 9))

eq2 = (d+e)+(n+r)*10+(e+o)*100+(s+m)*1000 == y+e*10+n*100+o*1000+m*10000

solver = Solver()

solver.add(eq1)
solver.add(eq2)
solver.add(Distinct(s, e, n, d, m, o, r, y))

while solver.check() == sat:
    print("---")
    model = solver.model()
    print(model[s])
    print(model[e])
    print(model[n])
    print(model[d])
    print(model[m])
    print(model[o])
    print(model[r])
    print(model[y])
    block = []
    for var in model:
        block.append(var() != model[var])
        solver.add(Or(block))