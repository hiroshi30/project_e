import sys

import pygame


window_width = 16 * 75
window_height = 9 * 75

pygame.init()
window = pygame.display.set_mode((window_width, window_height))

dots = (
    (100, 0),
    (150, 200),
    (200, 100)
)


def f(x, y):
    pos1 = (x - dots[0][0]) * (dots[1][1] - dots[0][1]) - (y - dots[0][1]) * (dots[1][0] - dots[0][0])
    pos2 = (x - dots[1][0]) * (dots[2][1] - dots[1][1]) - (y - dots[1][1]) * (dots[2][0] - dots[1][0])
    pos3 = (x - dots[2][0]) * (dots[0][1] - dots[2][1]) - (y - dots[2][1]) * (dots[0][0] - dots[2][0])

    if pos1 >= 0 and pos2 >= 0 & pos3 >= 0:
        return 1
    return 0


while True:
    window.fill((0, 0, 0))

    for i in range(window_height):
        for j in range(window_width):
            if f(j, i) == 1:
                window.set_at((j, i), (255, 255, 255))

    pygame.display.flip()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
