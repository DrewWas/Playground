# Conways game of life

import pygame

# Set up
pygame.init()
WIN = pygame.display.set_mode((800,800))
pygame.display.set_caption("Game of Life")


# GRID 
GRID = [[[i  * 32, False] for i in range(25)] for j in range(25)]


# NEED TO GET POINTER (X,Y), IF CLICK DETECTED, SQUARE WITH THOSE COORDINATES ARE NOW COLORED

# NEED TO DO 1s/0s for GRID Linked List so that we can do evaluations for the actual game rules


def draw_grid():
    for i in GRID:
        for j in i:
            pygame.draw.line(WIN, (255,255,255), (j[0], 0), (j[0], 800))
            pygame.draw.line(WIN, (255,255,255), (0, j[0]), (800, j[0]))



def update_blocks():

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

    else:
        #dead --> alive
        pygame.draw.rect(WIN, (0, 138, 255), pygame.Rect(x_pos, y_pos, 32, 32))
        GRID[y_pos // 32][x_pos // 32][1] = True 


    print(GRID, cell_status)





# If block is already blue, and clicked again, it goes back to black



def main():
    run = True


    #for i in GRID:  # delete
     #   print(i)    # delete


    while run:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

            if event.type == pygame.MOUSEBUTTONDOWN:
                update_blocks()

        draw_grid()
        pygame.display.update()


main()





