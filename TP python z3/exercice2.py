from z3 import *

p1 = Int("1ct")
p2 = Int("2cts")
p3 = Int("5cts")
p4 = Int("10cts")
p5 = Int("20cts")
p6 = Int("50cts")
p7 = Int("1eur")
p8 = Int("2eur")

eq1 = p1*1 + p2*2 + p3*5 + p4*10 + p5*20 + p6*50 + p7*100 + p8*200 == 320
eq2 = And(p1>=0, p2>=0, p3>=0, p4>=0, p5>=0, p6>=0, p7>=0, p8>=0)

solver = Solver()
solver.add(eq1)
solver.add(eq2)

i = 0

while solver.check() == sat:
    i+=1
    print("\nSolution", i)
    model = solver.model()
    block = []
    for var in model:
        block.append(var() != model[var])
        solver.add(Or(block))
    print(p1, " = ", model[p1])
    print(p2, "= ", model[p2])
    print(p3, "= ", model[p3])
    print(p4, "= ", model[p4])
    print(p5, "= ", model[p5])
    print(p6,"= ", model[p6])
    print(p7, "= ", model[p7])
    print(p8,"= ", model[p8])

    block = []
    for var in model:
        block.append(var != model[var])
        solver.add(block)