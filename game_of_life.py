# Conways game of life

"""
HOW TO PLAY:
-----------------------------------------------------------------------------------
* Use your mouse to select or deselect blocks you would like to start off as 'alive'
    - Blue is alive, black is dead

* To begin the simulation, press RETURN
"""

import pygame

# Set up
pygame.init()
WIN = pygame.display.set_mode((800,800))
pygame.display.set_caption("Game of Life")


# GRID 
GRID = [[[i  * 32, False] for i in range(25)] for j in range(25)]
SELECTED_SQUARES = []



def draw_grid():
    for i in GRID:
        for j in i:
            pygame.draw.line(WIN, (255,255,255), (j[0], 0), (j[0], 800))
            pygame.draw.line(WIN, (255,255,255), (0, j[0]), (800, j[0]))



def setUp_blocks():

    # False = Dead | True = Alive

    # get positions
    mouse_x,mouse_y = pygame.mouse.get_pos()
    x_pos = mouse_x - (mouse_x % 32)
    y_pos = mouse_y - (mouse_y % 32)

    cell_status = GRID[y_pos // 32][x_pos // 32][1]

    if cell_status:  
        #alive --> dead
        pygame.draw.rect(WIN, (0, 0, 0), pygame.Rect(x_pos, y_pos, 32, 32))
        GRID[y_pos // 32][x_pos // 32][1] = False
        SELECTED_SQUARES.remove( (x_pos // 32, y_pos // 32) )

    else:
        #dead --> alive
        pygame.draw.rect(WIN, (0, 138, 255), pygame.Rect(x_pos, y_pos, 32, 32))
        GRID[y_pos // 32][x_pos // 32][1] = True 
        SELECTED_SQUARES.append( (x_pos // 32, y_pos // 32) )


    print(SELECTED_SQUARES)

    return SELECTED_SQUARES 



# HOW DO WE ENSURE THAT BLOCKS CANNOT BE SELECTED AFTER THE EVOLVE FUNCTION HAS STARTED


def get_neighbors():
    return None



def evolve():
    print(GRID)
    return None
    """
    RULES: 
    * 

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
                setUp_blocks()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    print("START\n\n")  

        draw_grid()
        pygame.display.update()


main()





