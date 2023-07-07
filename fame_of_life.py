# Create an NxN grid with 50 extra squares in each direction

import pygame
SCREEN_WIDTH, SCREEN_HEIGHT = (800, 800)
BLUE = (0, 138, 255)
WHITE = (255, 255, 255)
WIN = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

# We will not have grid corner problems when we make it larger in each direction (it will be off screen)

GRID_SIZE = int(input("GRID SIZE: "))
def create_grid(GRID_SIZE):
    GRID_WIDTH = SCREEN_WIDTH // GRID_SIZE

    for i in range(GRID_SIZE):
        pygame.draw.line(WIN, BLUE, (GRID_WIDTH * i, 0), (GRID_WIDTH * i, SCREEN_WIDTH))
        pygame.draw.line(WIN, BLUE, (0, GRID_WIDTH * i), (SCREEN_WIDTH, GRID_WIDTH * i))
"""
We do not need a full grid linked list because when checking selected square neighbors, we can obviously
assume if it is not in SELECTED_SQUARES, then it is dead. Therefore the only (partially) linked list we
need to track is SELECTED_SQUARES
"""


# Be able to select and deselct squares in that grid 

# If the square is selected, its coordinates are added to an array

# The game starts and a timestep increases once per unit time (n seconds)

# For i in selected squares array, check rules. If a cell becomes alive, add it to
# the array 

# continue indefinetly 

# run program
def main():
    run = True
    while run:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        create_grid(GRID_SIZE)
        pygame.display.update()


main()



