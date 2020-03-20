import turtle
happy=turtle.Screen()
happy.bgcolor("black")
turtle=turtle.Turtle()
turtle.shape("circle")
turtle.color("peru")
turtle.width(9)
turtle.speed(11)
colors=["white","ivory","dark orange","coral","cyan","hot pink","gold","ivory","yellow","red","pink","green","blue","light blue","light green",]

def move(x,y):
   turtle.up()
   turtle.setposition(0,0)
   turtle.setheading(90)
   turtle.rt(90)
   turtle.fd(x)
   turtle.lt(90)
   turtle.fd(y)
   turtle.pendown()

def mov(x,y):
   turtle.up()
   turtle.setposition(0,0)
   turtle.setheading(90)
   turtle.lt(90)
   turtle.fd(x)
   turtle.rt(90)
   turtle.fd(y)
   turtle.pendown()

def M():
	turtle.fd(80)
	turtle.rt(145)
	turtle.fd(60)
	turtle.lt(120)
	turtle.fd(70)
	turtle.rt(155)
	turtle.fd(85)
  
def ballon(size):
   turtle.color(colors[size%8])
   turtle.begin_fill()
   turtle.circle(size)
   turtle.end_fill()
   for i in range(17):
      turtle.lt(10)
      turtle.fd(3)
   turtle.fd(120)

def draw_happy(i,x,y):
    turtle.pencolor("linen")
    turtle.color(colors[i%7])
    turtle.begin_fill()
    turtle.lt(70)
    turtle.penup()
    turtle.goto(x,y)
    turtle.pendown()
    turtle.circle(33)
    turtle.end_fill()

def f1():  
  for i in range(9):
    turtle.pensize(5)
    turtle.pencolor('light blue')
    turtle.color(colors[i%19])
    turtle.begin_fill()
    turtle.left(330)
    turtle.forward(55)
    turtle.begin_fill()
    turtle.rt(110)
    turtle.circle(33)
    turtle.end_fill()
    turtle.rt(11)
    turtle.backward(33)
    turtle.end_fill()

def cake(x,y):
   turtle.fd(x)
   turtle.rt(90)
   turtle.fd(y)
   turtle.rt(90)
   turtle.fd(x)
   turtle.rt(90)
   turtle.fd(y)

def heart():
   for i in range(43):
         turtle.pencolor(colors[i%9])
         turtle.rt(5)
         turtle.fd(5)      
   turtle.fd(150)
   turtle.penup()
   turtle.rt(140)
   turtle.fd(150)
   turtle.pendown()
   for i in range(43):
         turtle.pencolor(colors[i%9])
         turtle.lt(5)
         turtle.fd(5)
   turtle.lt(7)
   turtle.fd(150)

def A(size):
  turtle.rt(16)
  turtle.forward(size)
  turtle.rt(150)
  turtle.fd(size)
  turtle.backward(size/2)
  turtle.rt(105)
  turtle.fd(size/3)   

def B():
   turtle.forward(60)
   turtle.rt(90)
   for i in range(18):
      turtle.rt(9)
      turtle.fd(3)
   for i in range(18):
      turtle.rt(13)
      turtle.backward(3)

def m():
   turtle.forward(30)
   for i in range(20):
      turtle.rt(9)
      turtle.fd(3)
   turtle.forward(5)
   turtle.backward(5)   
   turtle.lt(180)
   for i in range(20):
      turtle.rt(9)
      turtle.fd(3)
   turtle.forward(30)
         
def i(size):
   turtle.fd(size)

def t(size):
   turtle.fd(size)
   turtle.backward(size/2)
   turtle.lt(90)
   turtle.fd(10)
   turtle.backward(20)

def H():
   turtle.fd(60)
   turtle.backward(30)
   turtle.rt(90)
   turtle.fd(30)
   turtle.lt(90)
   turtle.fd(30)
   turtle.backward(60)

def H1():
   turtle.fd(75)
   turtle.backward(50)
   turtle.rt(90)
   turtle.fd(35)
   turtle.lt(90)
   turtle.fd(25)
   turtle.backward(75)

def P():
   turtle.fd(60)
   turtle.rt(90)
   turtle.fd(7)
   for i in range(8):
       turtle.rt(20)
       turtle.fd(5)

def Y():
   turtle.fd(40)
   turtle.left(60)
   turtle.fd(20)
   turtle.backward(20)
   turtle.rt(90)
   turtle.fd(35)

def a():
   for i in range(18):
       turtle.rt(20)
       turtle.fd(9)   
   for i in range(9):
       turtle.rt(20)
       turtle.fd(9)
   turtle.fd(20)
   for i in range(6):
       turtle.lt(30)
       turtle.fd(4)   

def R():
   turtle.fd(60)
   turtle.rt(90)
   turtle.fd(7)
   for i in range(15):
      turtle.rt(12)
      turtle.fd(3)
   turtle.lt(120)
   turtle.fd(49)

def D():
   turtle.fd(60)
   turtle.rt(90)
   turtle.fd(9)
   for i in range(13):
      turtle.rt(13)
      turtle.fd(7) 

def brd1():
   turtle.lt(90)
   turtle.forward(100)
   turtle.lt(90)
   turtle.forward(1000)
   turtle.lt(90)
   turtle.forward(100)

def brd2():
   turtle.rt(90)
   turtle.forward(100)
   turtle.rt(90)
   turtle.forward(1000)
   turtle.rt(90)
   turtle.forward(100)

turtle.pencolor("cyan")
turtle.width(11)   
mov(220,300) 
H()
mov(180,300)
A(65)
mov(135,300)
P()
mov(100,300)
P()
mov(52,300)
Y()
mov(25,300)
B()
move(12,300)
i(60)
move(36,300)
R()
move(80,300)   
t(100)
move(102,300)
H()
move(150,300)
D()
move(190,300)
A(65)
move(250,300)
Y()
turtle.pencolor("hot pink")
turtle.width(15)
mov(185,400)
M()
mov(105,400)
A(100)   
mov(35,415)
H1()
move(30,400)
i(76)
move(60,400)
turtle.pencolor("white")
m()
move(160,425)
a()
turtle.pencolor("hot pink")
move(430,400)
ballon(69)
move(-250,400)
ballon(72)

turtle.speed(12)
mov(90,20)
turtle.width(17)
turtle.color(colors[8%5])
turtle.begin_fill()
cake(40,180)
turtle.end_fill()
mov(80,55)
turtle.color(colors[8%3])
turtle.begin_fill()
cake(40,160)
turtle.end_fill()
mov(70,90)
turtle.color("hot pink")
turtle.begin_fill()
cake(40,133)
turtle.end_fill()
mov(-10,133)
turtle.width(11)
turtle.pencolor("red")
turtle.circle(7)
turtle.pencolor("black")
move(-15,90)
turtle.write("20" ,font=("Cambria",25,"bold"))

for i in range(5):
    draw_happy(i,-189,200)  
    
for i in range(6):
   draw_happy(i,189,200) 
for i in range(7):
   draw_happy(i,123,-100)
for i in range(5):
   draw_happy(i,-123,-100) 
mov(10,-80)
turtle.width(19)
heart() 
mov(10,-400)
f1()
turtle.pencolor("cyan")
move(-350,500)
brd1()
turtle.pencolor("white")
move(360,500)
brd2()
happy.exitonclick()