

def exp():
    x = [i for i in range(10)]

    try:
        for i in range(20):
            print(x[i] * 2)
    except IndexError:
        pass



for i in range(-1,2):
    for j in range(-1,2):
        if not (i == 0 and j == 0):
            print(i,j)

