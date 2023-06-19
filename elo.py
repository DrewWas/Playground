# Elo rating

R1 = int(input("Player A: "))
R2 = int(input("Player B: "))



def probA(x,y):
    
    Ea = 1/(1 + 10 ** ((R2 - R1) / 400))
    Eb = 1/(1 + 10 ** ((R1 - R2) / 400))

    print("Player A Win Probability : " + str(Ea) + "\n" +
"Player B Win Probability : " + str(Eb))

    return Ea


def probB(x,y):
    
    Ea = 1/(1 + 10 ** ((R2 - R1) / 400))
    Eb = 1/(1 + 10 ** ((R1 - R2) / 400))

    print("Player A Win Probability : " + str(Ea) + "\n" +
"Player B Win Probability : " + str(Eb))

    return Eb




def update_ranking(initial_score, expected_prob, outcome):
    # Outcomes: Win - 1, Draw - 0.5, Loss - 0
    K = 32
    updated_score =  initial_score + K * (outcome -
expected_prob)
    
    return updated_score


print(probA(R1, R2))

print(update_ranking(900, probA(R1, R2), 1))





