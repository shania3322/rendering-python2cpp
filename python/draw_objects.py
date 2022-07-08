#https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html
from PIL import Image, ImageDraw
from typing import List, Tuple
import numpy as np
import time
#from geometry import Vector2, Vector3
#from numba import jit

Vector2 = Tuple[int, int]

RED = (255,0,0,255)
WHITE = (0,0,0,0)
GREEN = (0,255,0,255)
BLUE = (0,0,255,255)
BACKGROUND = (0,0,0,255)
folder = 'out/'

# test with ImageDraw Module Pillow model
def draw(pixels: List[Vector2], image:[None|str]=None, form="tga",
        color=RED) -> None:
    try:
        img = Image.open(image)
    except FileNotFoundError:
        img = Image.new('RGBA', (200, 200), BACKGROUND)

    img=img.transpose(method=Image.Transpose.FLIP_TOP_BOTTOM)
    #a = np.asarray(img)
    out = ImageDraw.Draw(img, mode='RGBA')
    out.point(pixels, fill=color)
    img=img.transpose(method=Image.Transpose.FLIP_TOP_BOTTOM)
    name = image.split('.')[0]
    img.save(name+"."+form, format=form)
    img.close()
    del img
    del out


# Draw a pixel
# draw([(49,50)])
#@jit(nopython=True)
def line(v0:Vector2, v1:Vector2) -> List[Vector2]:
    """
    The basic Bresenham algorithm(1)
    : eps:error
    : (x1,y1),(x2,y2): start point and end point

    """
    pixels =[]

    # Find the direction of the Vector
    (x1,y1),(x2,y2) = v0, v1

    if x1 == x2 and y1 == y2:
        #print("It is a point.")
        pixels.append((x1,y1))
        return pixels

    e = [1,0]
    xy = [x2-x1,y2-y1]
    if np.dot(e,xy) < 0:
        x1, x2 = x2, x1
        y1, y2 = y2, y1

    eps = 0
    dy = y2 -y1
    dx = x2 -x1

    # The 1st octant and the 5th octant, stepping along positive x axis
    if dy >=0 and dy <= dx:
        y = y1
        for x in range(x1, x2+1):
            pixels.append((x, y))
            if 2*(eps+dy) < dx:
                eps = eps+dy
            else:
                y = y+1
                eps = eps+dy-dx
    # The 8th octant and the 4th octant, stepping along positive x axis
    elif dy <= 0 and -dy <= dx:
        y = y1
        for x in range(x1, x2+1):
            pixels.append((x,y))
            if 2*(eps+dy) > -dx:
                eps = eps+dy
            else:
                y = y-1
                eps = eps+dy+dx

    # The 2nd octant and 6th octant, stepping along positive y axis
    elif  dx >= 0 and dy > dx:
        x = x1
        for y in range(y1,y2+1):
            pixels.append((x,y))
            if 2*(eps+dx) < dy:
                eps = eps+dx
            else:
                x = x+1
                eps = eps+dx-dy

    # The 3rd octant and 7th octant, stepping along negative y axis
    elif dx >= 0 and -dy > dx:
        x = x1
        for y in range(y1,y2-1,-1):
            pixels.append((x,y))
            if 2*(eps-dx) > dy:
                eps = eps-dx
            else:
                x = x+1
                eps = eps-dx-dy
    else:
        print("something wrong")
        raise ValueError

    return pixels


def triangle(v0:Vector2, v1:Vector2, v2:Vector2,
        image:[None|str]=None, color=RED) -> None:

    l1 = line(v0, v1)
    l2 = line(v1, v2)
    l3 = line(v2, v0)
    draw([*l1,*l2,*l3], image=image, color=color)


def triangle_filled(v0:Vector2, v1:Vector2, v2:Vector2,
        image:[None|str]=None, color=RED) -> None:

    pixels = []
    v = [v0,v1,v2]
    v.sort(key=lambda t:t[1])
    (L_v,R_v) = (v[1],v[2]) if v[1][0]<v[2][0] else (v[2],v[1])

    # line sweep
    l1 = line(v[0],L_v)
    l2 = line(v[0],R_v)
    l3 = line(L_v,R_v)
    draw([*l1,*l2,*l3],image=image)

    # sweep from l1 to l2
    t = 0
    p = 0
    for y in range(v[0][1],v[1][1]+1):
        while t < len(l1):
            if l1[t][1] == y: # find the leftest pixel
                break
            t = t+1
        while p < len(l2):
            if l2[p][1] == y: # TO be fixed -find the rightest pixel
                break
            p = p+1
        l = line(l1[t],l2[p])
        pixels.extend(l)

    draw(pixels, image=image, color=color)

    next_l = l1 if L_v[1] > R_v[1] else l2
    p = t if next_l==l1 else p
    l3_ = line(v[1],v[2])
    print("vertex", v)
    print(next_l[0],next_l[-1])
    print("l3_",l3_[0], l3_[-1])
    print(l3_[80])

    # sweep from l1 or l2(the long one) to l3,
    q = 0
    for y in range(v[1][1],v[2][1]+1):
        while q < len(l3_):
            if l3_[q][1] == y:
                break
            q = q+1
        while p < len(next_l):
            if next_l[p][1] == y:
                break
            p = p+1
        print(q, l3_[q])
        print(p, next_l[p])
        l = line(l3_[q],next_l[p])
        pixels.extend(l)

    draw(pixels, image=image, color=color)






