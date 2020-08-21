# Rob Parke
# Viterbi School of Engineering
# University of Southern California
# Java, C++, and Python Review

'''
  Note carefully what happens in the constructor.
  By giving the constructor an optional (default) argument,
    we care in effect creating two "versions" of the constructor,
    one where the user gives in an input
      myShape = Shape("Tetrahedron")
    and another where they do NOT give it input
    myShape = Shape()

  This concept is used frequently in C++ / Java and it is called
  "overloading". However, in C++ / Java, it is accomplished by
  creating two separate functions, one with no inputs
  and a second with one input.
'''
class Shape(object):
  # constructor
  def __init__(self, inputName = "unnamed"):
  #instance variables
  self.__name = inputName

  #accessor / mutator
  def getName(self):
  return self.__name

  def setName(self, inputName):
  self.__name = inputName

  #methods
  def display(self):
  print("name =  " + self.__name)