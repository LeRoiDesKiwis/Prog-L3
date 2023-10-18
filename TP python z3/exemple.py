from z3 import *

m_age = Int('m_age')
f_age = Int('f_age')

eq1 = (m_age - 6) == 2 * (f_age - 6)
eq2 = (m_age + 5) + (f_age + 5) == 40

solver = Solver()

solver.add(eq1)
solver.add(eq2)
solver.add(Distinct(m_age, f_age))
print("Résumé: ", solver)

if solver.check() == sat:
    print("On a trouvé une solution")
    model = solver.model()
    print("Mon age est de ", model[m_age])
    print("L'âge de mon frère est de ", model[f_age])
    print("En effet:", model[m_age].as_long()-6," = 2*", model[f_age].as_long()-6, " et ", model[m_age].as_long()+5, "+", model[f_age].as_long()+5, "= 40")