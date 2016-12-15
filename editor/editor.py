#!/usr/bin/python3
import os

import pygame
import sys

WIDTH = int(1920 * 3 / 4)
HEIGHT = int(1080 * 3 / 4)

textures = []


def load_textures(path, res):
    global textures
    tileset = pygame.image.load(path).convert_alpha()
    for y in range(0, tileset.get_height(), res):
        for x in range(0, tileset.get_width(), res * 2):
            chop = tileset.subsurface((x, y, res, res))
            textures.append(chop)
    textures = textures[:-3]
    print("Loaded %d tiles!" % len(textures))


def load_map(path):
    if os.path.isfile(path):
        f = open(path, 'r')
        lines = f.readlines()
        w = len(lines[0].split(','))
        h = len(lines)
        map = Map(w, h)
        for x in range(w):
            for y in range(h):
                map.tiles[x][y] = int(lines[y].split(',')[x])
        f.close()
        return map
    else:
        return None


class Map:
    def __init__(self, w, h):
        self.w = w
        self.h = h
        self.tiles = [[0 for y in range(h)] for x in range(w)]
        for x in range(w):
            self.tiles[x][0] = 1
            self.tiles[x][h - 1] = 1
        for y in range(h):
            self.tiles[0][y] = 1
            self.tiles[w - 1][y] = 1

    def save(self, path):
        f = open(path + '.w3m', 'w')
        for y in range(self.h):
            line = ""
            for x in range(self.w):
                line += "%d," % self.tiles[x][y]
            f.write(line[:-1] + '\n')
        f.close()
        print("Successfully saved file as: " + f.name)


class Grid:
    def __init__(self, size, bounds, count_x, count_y, color=(255, 255, 255), map=None):
        self.size = size
        self.bounds = bounds
        self.count_x = count_x
        self.count_y = count_y
        self.offset_x = 0
        self.offset_y = 0
        self.color = color
        if map is None:
            self.map = Map(count_x, count_y)
        else:
            self.map = map
        self.selected = 0

    def update(self, delta):
        self.left = max(self.bounds[0] - (self.size - self.offset_x) % self.size, self.bounds[0] + self.offset_x)
        self.top = max(self.bounds[1] - (self.size - self.offset_y) % self.size, self.bounds[1] + self.offset_y)
        self.right = min(self.bounds[2], self.count_x * self.size + self.offset_x + self.bounds[0])
        self.bottom = min(self.bounds[3], self.count_y * self.size + self.offset_y + self.bounds[1])

    def render(self, screen):
        for x in range(0, self.map.w):
            for y in range(0, self.map.h):
                tile = self.map.tiles[x][y] - 1
                if tile >= 0:
                    resized = pygame.transform.scale(textures[tile], (self.size, self.size))
                    screen.blit(resized, (self.bounds[0] + x * self.size + self.offset_x,
                                          self.bounds[1] + y * self.size + self.offset_y))
        self.render_mouse_hover(screen)
        for x in range(self.left, self.right + 1, self.size):
            pygame.draw.line(screen, self.color, (x, self.top), (x, self.bottom))
        for y in range(self.top, self.bottom + 1, self.size):
            pygame.draw.line(screen, self.color, (self.left, y), (self.right, y))

    def render_mouse_hover(self, screen):
        mouse_pos = pygame.mouse.get_pos()
        if max(self.bounds[0], self.left) < mouse_pos[0] < self.bounds[2] and self.bounds[1] < mouse_pos[1] < \
                self.bounds[3]:
            tx = int((mouse_pos[0] - self.left) / self.size)
            ty = int((mouse_pos[1] - self.top) / self.size)
            hover = textures[self.selected].copy()
            hover = pygame.transform.scale(hover, (self.size, self.size))
            screen.blit(hover, (tx * self.size + self.left, ty * self.size + self.top))
            tx -= min(0, int(self.offset_x / self.size))
            ty -= min(0, int(self.offset_y / self.size))
            if pygame.mouse.get_pressed()[0]:
                self.map.tiles[tx][ty] = self.selected + 1
            elif pygame.mouse.get_pressed()[2]:
                self.map.tiles[tx][ty] = 0


class Editor:

    @staticmethod
    def from_map(tilemap, name):
        editor = Editor(tilemap.w, tilemap.h, name, tilemap)
        return editor

    def __init__(self, count_x, count_y, name, tilemap=None):
        self.keys_prev = pygame.key.get_pressed()
        self.hover_rect = pygame.Surface((64, 64))
        self.clock = pygame.time.Clock()
        self.name = name
        self.screen = pygame.display.set_mode((WIDTH, HEIGHT))
        self.grid = Grid(50, [64 * 6 + 10, 0, self.screen.get_width(), self.screen.get_height()], count_x, count_y, map=tilemap)
        self.running = True
        self.init()

    def init(self):
        pygame.display.set_caption("Wolf3D map editor")
        logo = pygame.image.load("assets/logo.png").convert_alpha()
        pygame.display.set_icon(logo)
        load_textures("assets/tileset.png", 64)
        self.hover_rect.set_alpha(128)
        self.hover_rect.fill((255, 255, 255))
        while self.running:
            delta = self.clock.tick()
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.running = False
            self.update(delta / 1000)
            self.render()

    def update(self, delta):
        self.update_keys(delta)
        self.grid.update(delta)

    def update_keys(self, delta):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_UP]:
            self.grid.offset_y += int(1000 * delta)
        if keys[pygame.K_DOWN]:
            self.grid.offset_y -= int(1000 * delta)
        if keys[pygame.K_LEFT]:
            self.grid.offset_x += int(1000 * delta)
        if keys[pygame.K_RIGHT]:
            self.grid.offset_x -= int(1000 * delta)
        if keys[pygame.K_s] and not self.keys_prev[pygame.K_s]:
            self.grid.map.save(self.name)
        if keys[pygame.K_ESCAPE]:
            self.running = False
        self.keys_prev = keys

    def render(self):
        self.screen.fill((0, 0, 0))
        self.grid.render(self.screen)
        pygame.draw.rect(self.screen, (128, 128, 128), (0, 0, 64 * 6, HEIGHT))
        pygame.draw.rect(self.screen, (64, 64, 64), (64 * 6, 0, 10, HEIGHT))
        self.render_tiles()
        self.render_mouse_over()
        pygame.display.flip()

    def render_mouse_over(self):
        mouse_pos = pygame.mouse.get_pos()
        tx = int(mouse_pos[0] / 64)
        ty = int(mouse_pos[1] / 64)
        if tx < 6 and ty < len(textures) / 6:
            self.screen.blit(self.hover_rect,    (tx * 64, ty * 64))
            if pygame.mouse.get_pressed()[0]:
                self.grid.selected = ty * 6 + tx
        pygame.draw.rect(self.screen, (255, 255, 255),
                         (self.grid.selected % 6 * 64, int(self.grid.selected / 6) * 64, 62, 62), 2)

    def render_tiles(self):
        for i in range(len(textures)):
            self.screen.blit(textures[i], (i % 6 * 64, int(i / 6) * 64))


if __name__ == "__main__":
    args = sys.argv
    if len(args) == 2:
        map = load_map(args[1])
        if map is not None:
            pygame.init()
            Editor.from_map(map, args[1].split('.')[0])
        else:
            print("Map couldn't be loaded")
    elif len(args) == 1:
        print("You must specify a size for your map")
    elif len(args) < 4:
        print("You must specify a name for your map")
    else:
        pygame.init()
        Editor(int(args[1]), int(args[2]), args[3])
