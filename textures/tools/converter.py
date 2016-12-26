#!/usr/bin/python3
from PIL import Image
import sys

file_in = sys.argv[1]
file_out = file_in.split('.')[0] + ".w3t"
im = Image.open(file_in).convert("RGBA")
pixels = im.load()
stream_out = open(file_out, 'w')
w = im.size[0]
h = im.size[1]
stream_out.write("%d,%d\n" % (w, h))
for x in range(w):
    for y in range(h):
        pix = pixels[x, y]
        r = pix[0]
        g = pix[1]
        b = pix[2]
        a = pix[3]
        stream_out.write("%03d%03d%03d%03d" % (r,g,b,a))
stream_out.close()
