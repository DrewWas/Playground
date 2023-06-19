# Elo rating

R1 = int(input("Player A: "))
R2 = int(input("Player B: "))



def f(x,y):
    
    Ea = 1/(1 + 10 ** ((R2 - R1) / 400))
    Eb = 1/(1 + 10 ** ((R1 - R2) / 400))

    return "Player A Rating : " + str(Ea) + "\n" + " Player B Rating: " + str(Eb)


print(f(R1, R2))
