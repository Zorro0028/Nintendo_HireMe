import tkinter
from PIL import Image, ImageDraw, ImageFont

arr32 = [
0xf26cb481,0x16a5dc92,0x3c5ba924,0x79b65248,0x2fc64b18,0x615acd29,0xc3b59a42,0x976b2584,
0x6cf271b4,0xa51692dc,0x5b3c24a9,0xb6794852,0xc62f184b,0x5a6129cd,0xb5c3429a,0x6b978425,
0xb481f26c,0xdc9216a5,0xa9243c5b,0x524879b6,0x4b182fc6,0xcd29615a,0x9a42c3b5,0x2584976b,
0x81b46cf2,0x92dca516,0x24a95b3c,0x4852b679,0x184bc62f,0x29cd5a61,0x429ab5c3,0x84256b97
]

filename = "xorbits"

ss = 27
w = ss*32
h = ss*32
bb = 2

root = tkinter.Tk()
root.title(filename)
root.geometry(str(w)+"x"+str(h)+"+470+76")

canvas = tkinter.Canvas(root, width=w, height=h)
canvas.pack()

img_pil = Image.new("RGBA", (w, h), (255, 255, 255, 0))
canvas_pil = ImageDraw.Draw(img_pil)

img = tkinter.PhotoImage(width = w, height = h)
canvas.create_image((0, 0), image = img, state = "normal", anchor = "nw")

bgc = "#272727"
for i in range(32):
    for n in range(32):
        if arr32[i] & (2**n) > 0:
            fillc = "#e070b0"
        else:
            fillc = "#405050"
        canvas.create_rectangle(n*ss, i*ss, n*ss+ss, i*ss+ss, outline=bgc, fill=bgc)
        canvas.create_rectangle(n*ss+bb, i*ss+bb, n*ss+ss-bb, i*ss+ss-bb, outline=fillc, fill=fillc)
        canvas_pil.rectangle((n*ss, i*ss, n*ss+ss, i*ss+ss), fill=bgc)
        canvas_pil.rectangle((n*ss+bb, i*ss+bb, n*ss+ss-bb, i*ss+ss-bb), fill=fillc)
    print()

canvas.create_line(w>>1, 0   , w>>1, h    , width=bb*5)
canvas.create_line(0   , h>>1, w   , h>>1 , width=bb*5)
canvas_pil.line(  (w>>1, 0   , w>>1, h   ), width=bb*5, fill="black")
canvas_pil.line(  (0   , h>>1, w   , h>>1), width=bb*5, fill="black")


for i in range(32//4):
    canvas.create_line(ss*i*4, 0     , ss*i*4, h      , width=bb*3)
    canvas.create_line(0     , ss*i*4, w     , ss*i*4 , width=bb*3)
    canvas_pil.line(  (ss*i*4, 0     , ss*i*4, h     ), width=bb*3, fill="black")
    canvas_pil.line(  (0     , ss*i*4, w     , ss*i*4), width=bb*3, fill="black")


img_pil.save(filename + ".png")

root.mainloop()
