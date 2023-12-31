from tabulate import tabulate

R1 = int(input("Player A: "))
R2 = int(input("Player B: "))


def probA(x,y):
    Ea = 1/(1 + 10 ** ((R2 - R1) / 400))
    return Ea


def probB(x,y):
    Eb = 1/(1 + 10 ** ((R1 - R2) / 400))
    return Eb

A_prob = probA(R1, R2)
B_prob = probB(R1, R2)


def update_ranking(initial_score, expected_prob, outcome):
    # Outcomes: Win - 1, Draw - 0.5, Loss - 0

    """
    This is the K-Factor Algorithm according to FIDE, it differs to USCF and Chess.com

    For most players ( 700 <= ELO >= 1500 ), on Chess.com (For 10-min Games)                                the K-Factor is closer to K = 16
    """

    if initial_score < 2400:
        K = 20
    else:
        K = 10
    updated_score = initial_score + K * (outcome -
expected_prob)
    
    return updated_score


def dataFrame():
    #This could be cleaned 
    tabs = [["Player A Win Probability: ", A_prob, str(int(A_prob * 100)) + "%"],
            ["Player A Updated Elo for Win: ", round(update_ranking(R1, A_prob, 1))],
            ["Player A Updated Elo for Draw: ", round(update_ranking(R1, A_prob, 0.5))],
            ["Player A Updated Elo for Loss: ", round(update_ranking(R1, A_prob, 0))],
            ["Player B Win Probability: ", B_prob, str(int(B_prob * 100)) + "%"],
            ["Player B Updated Elo for Win: ", round(update_ranking(R2, B_prob, 1))],
            ["Player B Updated Elo for Draw: ", round(update_ranking(R2, B_prob, 0.5))],
            ["Player B Updated Elo for Loss: ", round(update_ranking(R2, B_prob, 0))]] 
            

    print(tabulate(tabs))


dataFrame()

