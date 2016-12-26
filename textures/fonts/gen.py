#!/usr/bin/python3
from PIL import Image
import sys, os

text = sys.argv[1]
file_out = text + ".png"
letters = {}
w = 0
h = 0
for letter in text:
    if letter not in letters:
        if os.path.isfile("%c.bmp" % letter):
            letters[letter] = Image.open("%c.bmp" % letter).convert("RGBA")
        else:
            letters[letter] = None
    l = letters[letter]
    if l is not None:
        if l.size[1] > h:
            h = l.size[1]
        w += l.size[0]
    else:
        w += 35
print (w, h)
x = 0
out = Image.new("RGBA", (w, h), color=0)
for letter in text:
    img = letters[letter]
    if img is not None:
        out.paste(img, (x, int((h - img.size[1]) / 2)))
        x += img.size[0]
    else:
        x += 35
pixels = out.load()
for y in range(h):
    for x in range(w):
        r,g,b,a = pixels[x, y]
        if r >= 252 and g >= 252 and b >= 252:
            pixels[x, y] = (0,0,0,0)
out.save(file_out)
