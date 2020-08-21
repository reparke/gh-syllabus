# Rob Parke
# Viterbi School of Engineering
# University of Southern California
# Java, C++, and Python Review


class Order(object):
  # default constructor
  def __init__(self):
    # create instance variables for the objects
    self.__name = ""
    self.__pounds = 0
    self.__costPerPound = 0.0
	
	# get / set methods
  def getName(self):
    return self.__name

  def getPounds(self):
    return self.__pounds

  def getCostPerPound(self):
    return self.__costPerPound

  def setName(self, newName):
    self.__name = newName

  def setPounds(self, newPounds):
    self.__pounds = newPounds

  def setCostPerPound(self, newCostPerPound):
    self.__costPerPound = newCostPerPound


  # methods
  '''
   calcCost
   input: none
   output: returns pounds * costPerPound
  '''
  def calcCost(self):
    return self.__pounds * self.__costPerPound


  '''
   displayOrder
   input: none
   output: none
   side-effect: prints a summary of the order to the screen
  '''
  def displayOrder(self):
    print("Order: " + self.__name + " for " +
        str(self.__pounds) + " lbs @ $" +
        str(self.__costPerPound) + "/lb")