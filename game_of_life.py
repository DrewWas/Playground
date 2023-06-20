# Conways game of life

import pygame

# Set up
pygame.init()
WIN = pygame.display.set_mode((800,800))
pygame.display.set_caption("Game of Life")


# GRID 
GRID = [[i for i in range(25)] for j in range(25)]



# NEED TO GET POINTER (X,Y), IF CLICK DETECTED, SQUARE WITH THOSE COORDINATES ARE NOW COLORED

# HIGHLIGHT BLOCK CURSER IS OVER 

# NEED TO DO 1s/0s for GRID Linked List so that we can do evaluations for the actual game rules


def draw():
    for i in GRID:
        for j in i:


            # fix this shit looking like its up and to the right 4 or 5 too many pixels
            pygame.draw.rect(WIN, (0,138,255), pygame.Rect(225, 255, 32, 32))   # delete

            pygame.draw.line(WIN, (255,255,255), (j * 32, 0), (j * 32, 800))
            pygame.draw.line(WIN, (255,255,255), (0, j * 32), (800, j * 32))



def main():
    run = True


    while run:
        mouse_x,mouse_y = pygame.mouse.get_pos()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
            if event.type == pygame.MOUSEBUTTONDOWN:

                # Fix this 

                print("click")
                x_pos = mouse_x - (mouse_x % 25)
                y_pos = mouse_y - (mouse_y % 25)
                pygame.draw.rect(WIN, (0,138,255), pygame.Rect(x_pos, y_pos, 32, 32))

                print((mouse_x,mouse_y), (x_pos, y_pos))


        draw()
        
        pygame.display.update()


main()
