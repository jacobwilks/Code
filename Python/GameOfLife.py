from tkinter import Tk, Canvas, Frame, Button, BOTH
from random import randrange


def percent(p):
     return (randrange(100) < p)

class Example(Frame):

 def __init__(self, parent):
   Frame.__init__(self, parent)
   self.parent = parent
   self.initUI()
   self.new = 0
   self.normal = 0
   self.aged = 0
   self.defective = 0

 def nextState(self):
     for i in range(0,20):
         for j in range(0,20):
             if frame[i][j] == 0:
                 count=0
                 for k in range(0,20):
                     for l in range(0,20):
                         if frame[k][l] == 0:
                             count = count+1 #neighbors infected
                 repair = (count *100 ) / 400 #chance for an infected to reapir
                 if percent(repair) == True:
                     frame[i][j] = 1
                #     self.new = self.new + 1
             elif frame[i][j] == 1: #if new
                 if percent(5) == True:
                     frame[i][j] = 0#defective (lemon)
                #     self.defective = self.defective + 1
                 if percent(40) == True:
                     frame[i][j] = 2#normal - install
                    # self.normal = self.normal + 1
             elif frame[i][j] == 2: #if normal
                 if percent(15) == True:
                     frame[i][j] = 1#new - prevention
                 if percent(5) == True:
                     frame[i][j] = 3#aged - wear and tear
                    # self.aged = self.aged + 1
                 if frame[i+1][j] == 0 or frame[i][j-1] == 0 or frame[i+1][j-1] == 0 or frame[i-1][j] == 0 or frame[i-1][j-1] == 0:
                    if percent(40) == True:# if a neighbor infected and 20% is true
                        frame[i][j] = 0#defective - neighbor
                        #self.defective = self.defective + 1
             elif frame[i][j] == 3: #if aged
                  if percent(10) == True:
                      frame[i][j]=0 #decay
                      #self.defective = self.defective + 1
     k=0
     for i in range(0,20):
      for j in range(0,20):
       if frame[i][j] == 0: #defective
         color = "red"
       elif frame[i][j] == 1: #new
         color = "dark green"
       elif frame[i][j] == 2: #normal
         color = "green"
       else:
         color = "light green" #aged
       canvas.itemconfig(rectangles[k],fill=color)
       k = k+1

 def oneHunderedDays(self):
   for i in range(0,99):
     self.nextState()

 def xDays(self):
   print('enter how many days you want to simulate')
   input1 = int(input())
   for i in range(0,input1):
     self.nextState()

 def reset(self):
    self.aged = 0
    self.defective = 0
    self.normal = 0
    self.new = 0
    for i in range(0,20):
        for j in range(0,20):
            frame[i][j] = randrange(0,4)
    for i in range(0,20):
        for j in range(0,20):
            if frame[i][j] == 0:
                color = "red"
            elif frame[i][j] == 1:
                color = "dark green"
            elif frame[i][j] == 2:
                color = "green"
            else:
                color = "light green"
            rectangles.append(canvas.create_rectangle(j*20,i*20,(j+1)*20,(i+1)*20,fill=color))
    return

 def print_stats(self):
    for i in range(0,20):
        for j in range(0,20):
            if frame[i][j] == 0:
                self.defective = self.defective + 1
            elif frame[i][j] == 1:
                self.new = self.new + 1
            elif frame[i][j] == 2:
                self.normal = self.normal+ 1
            else:
                self.aged = self.aged + 1
    print("NEW       : ", self.new, "      %", (self.new*100)/400)
    print("NORMAL    : ", self.normal, "       %", (self.normal*100)/400)
    print("AGED      : ", self.aged, "     %", (self.aged*100)/400)
    print("DEFECTIVE : ", self.defective, "      %", (self.defective*100)/400)

 def initUI(self):
    self.parent.title("GAMEOFLIFE")
    self.pack(fill=BOTH,expand=1)
    global canvas
    global rectangles
    global frame
    color = 'yellow'
    canvas = Canvas(self)
    rectangles=[]
    frame = [[0 for x in range(21)] for x in range(21)]

    for i in range(0,20):
        for j in range(0,20):
            frame[i][j] = randrange(0,4)
    for i in range(0,20):
        for j in range(0,20):
            if frame[i][j] == 0:
                color = "red"
            elif frame[i][j] == 1:
                color = "dark green"
            elif frame[i][j] == 2:
                color = "green"
            else:
                color = "light green"
            rectangles.append(canvas.create_rectangle(j*20,i*20,(j+1)*20,(i+1)*20,fill=color))

    self.button = Button(self.parent, text="Next", fg="blue", command=self.nextState)
    self.button.pack()
    canvas.pack(fill=BOTH, expand=1)
    self.button = Button(self.parent, text="100 Days of Simulation", fg="blue", command=self.oneHunderedDays)
    self.button.pack()
    canvas.pack(fill=BOTH, expand=1)
    self.button = Button(self.parent, text="X amount of Days of Simulation", fg="blue", command=self.xDays)
    self.button.pack()
    canvas.pack(fill=BOTH, expand=1)
    self.button = Button(self.parent, text="Stats", fg="blue", command=self.print_stats)
    self.button.pack()
    canvas.pack(fill=BOTH, expand=1)
    self.button = Button(self.parent, text="Reset to new Configuration", fg="blue", command=self.reset)
    self.button.pack()
    canvas.pack(fill=BOTH, expand=1)
    self.button = Button(self.parent, text="Quit", fg="blue", command=quit)
    self.button.pack()
    canvas.pack(fill=BOTH, expand=1)
    return

def main():

  root = Tk()
  ex = Example(root)
  root.geometry("400x500+300+200")
  root.mainloop()

if __name__ == '__main__':
  main()
