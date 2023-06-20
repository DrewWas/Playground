# Conways game of life

import pygame

# Set up
pygame.init()
WIN = pygame.display.set_mode((800,800))
pygame.display.set_caption("Game of Life")


# GRID 
GRID = [[i for i in range(50)] for j in range(50)]


def draw():
    for i in GRID:
        for j in GRID:
            pygame.draw.line(WIN, (255,255,255), (0,0), (800, 800))



def main():

    run = True

    while run:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        draw()
        pygame.display.update()


main()
