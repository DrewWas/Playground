# Conways game of life

import pygame

# Set up
pygame.init()
WIN = pygame.display.set_mode((800,800))
pygame.display.set_caption("Game of Life")


# GRID 
GRID = [[i for i in range(25)] for j in range(25)]


def draw():
    for i in GRID:
        for j in i:
            pygame.draw.line(WIN, (255,255,255), (j * 32, 0), (j * 32, 800))
            pygame.draw.line(WIN, (255,255,255), (0, j * 32), (800, j * 32))



def main():
    run = True

    while run:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        draw()
        pygame.display.update()


main()
