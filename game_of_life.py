# Conways game of life
# https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

"""
HOW TO PLAY:
-----------------------------------------------------------------------------------
* Use your mouse to select or deselect blocks you would like to start off as 'alive'
    - Blue is alive, black is dead

* To begin the simulation, press RETURN
"""

#EXPAND THE GRID!!!!!
#IMPLEMENT TIME STEP!!!


import pygame

# Set up
pygame.init()
WIN = pygame.display.set_mode((800,800))
pygame.display.set_caption("Game of Life")

dimension = int(input("Select dimensions (ex 5 --> 5x5 grid):  "))
square_size = 800 // dimension
extra_squares = dimension if dimension <= 50 else 50

# GRID 
GRID = [[[(i  * square_size), False] for i in range(dimension + extra_squares)] for j in range(dimension + extra_squares)]
SELECTED_SQUARES = []


def draw_grid():
    for i in GRID:
        for j in i:
            pygame.draw.line(WIN, (255,255,255), (j[0], 0), (j[0], 800))
            pygame.draw.line(WIN, (255,255,255), (0, j[0]), (800, j[0]))



def select_blocks():

    # False = Dead | True = Alive

    # get positions
    mouse_x,mouse_y = pygame.mouse.get_pos()
    x_pos = mouse_x - (mouse_x % square_size)
    y_pos = mouse_y - (mouse_y % square_size)

    cell_status = GRID[y_pos // square_size][x_pos // square_size][1]

    if cell_status:  
        #alive --> dead
        pygame.draw.rect(WIN, (0, 0, 0), pygame.Rect(x_pos, y_pos, square_size, square_size))
        GRID[y_pos // square_size][x_pos // square_size][1] = False
        #SELECTED_SQUARES.remove( ( (x_pos // square_size) - 200, (y_pos // square_size) - 200 ) )
        SELECTED_SQUARES.remove( ( (x_pos // square_size), (y_pos // square_size), True) )

    else:
        #dead --> alive
        pygame.draw.rect(WIN, (0, 138, 255), pygame.Rect(x_pos, y_pos, square_size, square_size))
        GRID[y_pos // square_size][x_pos // square_size][1] = True 
        #SELECTED_SQUARES.append( ( (x_pos // square_size) - 200, (y_pos // square_size) - 200 ) )
        SELECTED_SQUARES.append( ( (x_pos // square_size) , (y_pos // square_size), True ) )


    #   print(SELECTED_SQUARES)

    return SELECTED_SQUARES 



# HOW DO WE ENSURE THAT BLOCKS CANNOT BE SELECTED AFTER THE EVOLVE FUNCTION HAS STARTED


def get_neighbors(square):
    # ---- Implementation 1 -------
    # All cells have 8 neighbors, but for cells on the edge, they're non-present neighbors are assumed
    # to be dead 
    x_cord = square[0]
    y_cord = square[1] 


    #neighbors = [ square,    [(square[0] + 1, square[1], GRID[x_cord][y_cord][1])                ]  ]
    neighbors = [square]

    # fix edge cases

    try:
        for i in range(-1,2):
            for j in range(-1,2):
                if not (i == 0 and j == 0):
                    neighbors.append( [x_cord + i, y_cord + j] )
    except IndexError:
        pass

    #if not there, then dont append to list
    # try ____ --> except ____

    print(neighbors)
    # print(x_cord, y_cord)

    #neighbors = [ (3, 4, False), [(3,5,False), (3,3, True), (4,3, True), (5,3, False)] ]




def evolve():
    """
    for i in selected_squares:
        get_neighbors(i)
    """    				# something like this 


    print(GRID)
    return None
    """
    RULES: 
    * 

    """

"""   --> FINISH AFTER GET NEIGHBORS FUNCTION IS DONE
def testing():
        y_pos = 40
        x_pos = 0
    
        SELECTED_SQUARES.append( ( (x_pos // square_size)  + 20, (y_pos // square_size) ) )
        select_blocks()
        #del SELECTED_SQUARES[0]
        print(SELECTED_SQUARES)
"""

def main():
    run = True
    clock = pygame.time.Clock()


    while run:
        for event in pygame.event.get():
            clock.tick(60)
            if event.type == pygame.QUIT:
                run = False

            if event.type == pygame.MOUSEBUTTONDOWN:
                select_blocks()
                if len(SELECTED_SQUARES) > 0: #delete
                    get_neighbors(SELECTED_SQUARES[0])    # testing code... delete later


            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    print("START\n\n")  

                #if event.key == pygame.K_DOWN:    # delete
                    #testing()    # delete
 

        draw_grid()
        pygame.display.update()


main()




