"""
import unittest

# test line drawing in 8 directions
class TestLineDrawing(unittest.TestCase):
    def test_octant_1(self):
        ...
"""

from draw_objects import line, draw, triangle, triangle_filled

RED = (255,0,0,255)
WHITE = (0,0,0,0)
GREEN = (0,255,0,255)
BLUE = (0,0,255,255)
BACKGROUND =(0,0,0,255)


def test_draw_lines():
    # 8 octants
    # slopes that are greater than 1. Some cases won't pass, eg. steep slopes
    l1 = [(10,10),(90,70)] # 0 - pi/4
    l2 = [(10,10),(70,90)] # pi/4 - pi/2
    l3 = [(70,10),(10,90)] # pi/2 - 3/4*pi
    l4 = [(90,10),(10,70)] # 3/4*pi - pi
    l5 = [(90,70),(10,10)]
    l6 = [(70,90),(10,10)]
    l7 = [(10,90),(70,10)]
    l8 = [(10,70),(90,10)] # 7/4*pi - 2*pi

    # special cases
    l01 = [(10,10),(10,90)]
    l02 = [(10,90),(10,10)]
    l03 = [(10,10),(90,10)]
    l04 = [(90,10),(10,10)]
    #begin = time.time()

    print("Test started")

    line1 = line(*l1)
    draw(line1,name="line1")

    line2 = line(*l2)
    draw(line2,name="line2")

    line3 = line(*l3)
    draw(line3,name="line3")

    line4 = line(*l4)
    draw(line4,name="line4")

    line5 = line(*l5)
    draw(line5,name="line5")

    line6 = line(*l6)
    draw(line6,name="line6")

    line7 = line(*l7)
    draw(line7,name="line7")

    line8 = line(*l8)
    draw(line8,name="line8")

    line_01 = line(*l01)
    draw(line_01,name="line_01")

    line_02 = line(*l02)
    draw(line_02,name="line_02")

    line_03 = line(*l03)
    draw(line_03,name="line_03")

    line_04 = line(*l04)
    draw(line_04,name="line_04")

    print("Test completed.")

    #print(time.time()-begin)

def test_draw_a_triangle():
    l1 = [(5,10),(85,5)]
    l2 = [(85,5),(90,90)]
    l3 = [(90,90),(5,10)]
    line1 = line(*l1)
    line2 = line(*l2)
    line3 = line(*l3)
    draw(line1, name="l1")
    draw(line2, image="out/l1.tga", name="l2")
    draw(line3, image="out/l2.tga", name="l3")

def test_draw_triangle(same_image=True, path='out/'):
    t0 = [(10,70),(50,160),(70,80)]
    t1 = [(180,50),(150,1),(70,180)]
    t2 = [(180,150),(120,160),(130,180)]
    if same_image:
        triangle(t0[0],t0[1],t0[2], image=path+"triangle.tga", color=RED)
        triangle(t1[0],t1[1],t1[2], image=path+"triangle.tga", color=GREEN)
        triangle(t2[0],t2[1],t2[2], image=path+"triangle.tga", color=WHITE)
    else:
        triangle(t0[0],t0[1],t0[2], image=path+"triangle1.tga", color=RED)
        triangle(t1[0],t1[1],t1[2], image=path+"triangle2.tga", color=GREEN)
        triangle(t2[0],t2[1],t2[2], image=path+"triangle3.tga", color=BLUE)

def test_draw_filled_triangle(path='out/'):
    t0 = [(10,70),(50,160),(70,80)]
    triangle_filled(t0[0],t0[1],t0[2], image=path+"triangle_fill.tga",
            color=GREEN)

if __name__ =="__main__":
    #test_draw_lines()
    #test_draw_a_triangle()
    #test_draw_triangle()
    test_draw_filled_triangle()
