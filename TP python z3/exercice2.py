from z3 import *

money = 37

p1 = Int("1ct")
p2 = Int("2cts")
p3 = Int("5cts")
p4 = Int("10cts")
p5 = Int("20cts")
p6 = Int("50cts")
p7 = Int("1eur")
p8 = Int("2eur")

eq1 = p1*1 + p2*2 + p3*5 + p4*10 + p5*20 + p6*50 + p7*100 + p8*200 == money
eq2 = And(p1>=0, p2>=0, p3>=0, p4>=0, p5>=0, p6>=0, p7>=0, p8>=0)

solver = Solver()
solver.add(eq1)
solver.add(eq2)

solution = (0, 1000000000, [])
i = 0
while solver.check() == sat:
    model = solver.model()
    block = []
    l = [model[p1].as_long(), model[p2].as_long(), model[p3].as_long(), model[p4].as_long(), model[p5].as_long(), model[p6].as_long(), model[p7].as_long(), model[p8].as_long()]
    
    solver.add(Or(p1 != model[p1].as_long(), 
               p2 != model[p2].as_long(), 
               p3 != model[p3].as_long(), 
               p4 != model[p4].as_long(), 
               p5 != model[p5].as_long(),
               p6 != model[p6].as_long(),
               p7 != model[p7].as_long(),
               p8 != model[p8].as_long())
               )

    current_sum = sum(l)

    if current_sum < solution[1]:
        solution = (i, current_sum, l)

i, number, solut = solution 
print("\n--- MEILLEURE SOLUTION ---")
print("Meilleur solution :")
print(f'- Solution n°{i}')
print(f'- {number} pièces')
print(solution)