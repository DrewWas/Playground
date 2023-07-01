# Conways game of life
# https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

# * This program uses the Moore neighborhood system *


"""
HOW TO PLAY:
-----------------------------------------------------------------------------------
* Use your mouse to select or deselect blocks you would like to start off as 'alive'
    - Blue is alive, black is dead

* To begin the simulation, press RETURN
"""



"""
TO DO:

* expand grid ((0,0) is technically like (20,20), centered!!!! --> Implement rules/evolution first, because we might not
* have to 

* Implement rules 
* Implement evolution/generations (timestep)
	* Make sure that no user input can be taken once evolution starts

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
        #this is for readjusting the grid relative to the window 
        SELECTED_SQUARES.remove( ( (x_pos // square_size), (y_pos // square_size), True) )

    else:
        #dead --> alive
        pygame.draw.rect(WIN, (0, 138, 255), pygame.Rect(x_pos, y_pos, square_size, square_size))
        GRID[y_pos // square_size][x_pos // square_size][1] = True 
        #SELECTED_SQUARES.append( ( (x_pos // square_size) - 200, (y_pos // square_size) - 200 ) )
        #this is for readjusting the grid relative to the window 
        SELECTED_SQUARES.append( ( (x_pos // square_size) , (y_pos // square_size), True ) )


    return SELECTED_SQUARES 



# HOW DO WE ENSURE THAT BLOCKS CANNOT BE SELECTED AFTER THE EVOLVE FUNCTION HAS STARTED


def get_neighbors(square):
    x_cord = square[0]
    y_cord = square[1] 

    neighbors = [square, [] ]


    try:
        for i in range(-1,2):
            for j in range(-1,2):
                if not (i == 0 and j == 0):
                    neighbors[1].append( (x_cord + i, y_cord + j, GRID[y_cord + j][x_cord + i][1]) )

        #print(neighbors, "\n") 	# delete after debug

    except IndexError:
        pass

    return neighbors



def update_board():

    """
    RULES:
    * Any live cell with fewer than 2 neighbors dies
    * Any live cell with more than 3 neighbors dies
    * Any live cell with 2 or 3 live neighbors lives 
    * Any dead cell with exactly 3 neighbors comes to life
    """


    for i in SELECTED_SQUARES:
        alive = 0
        dead = 0
        cell = get_neighbors(i)
        for i in cell[1]:
            if i[2] == False:
                dead += 1
            if i[2] == True:
                alive += 1

        print("alive: " + str(alive), "dead: " + str(dead) )

     # if a cell that was dead become alive, we have to append it to SELECTED_SQUARES
        print(cell)
        print("\n")
        

        





def evolve():

    time_step = 0

    """
    if keydown == p (automate later):
        -- turn off inputs -- 
        time_step += 1
        update_board()
        
    """


    return None








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
                update_board()
  
 

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    # evolve()
                    print("START\n\n")  

                if event.key == pygame.K_DOWN:    # delete
                    pass
                    #testing()    # delete
 

        draw_grid()
        pygame.display.update()


main()




