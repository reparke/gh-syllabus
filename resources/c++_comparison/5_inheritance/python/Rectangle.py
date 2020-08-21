# Rob Parke
# Viterbi School of Engineering
# University of Southern California
# Java, C++, and Python Review

# import Shape class so Rectangle can be derived from it
from Shape import Shape

class Rectangle(Shape): # Rectangle class is derived from Shape
  # constructor
  def __init__(self, inputName = "", inputWidth = 0.0, inputLength = 0.0):
    if inputName == "":   # if no inputName argument is given
       super().__init__()   # call the parent const. with no input

    else:               # if inputName argument given,
      super().__init__(inputName) # pass that argument to parent const.

    self.__width = inputWidth
    self.__length = inputLength

  #accessor / mutator
  def setWidth(self, inputWidth):
    self.__width = inputWidth
  def setLength(self, inputLength):
    self.__length = inputLength

  def getWidth(self):
    return self.__width
  def getLength(self):
    return self.__length

  #methods
  def calcArea(self):
    return self.__length * self.__width

  def display(self):
    super().display()           #call parent version of display
    print("length = " + str(self.__length))
    print("width = " + str(self.__width))
