# Rob Parke
# Viterbi School of Engineering
# University of Southern California
# Java, C++, and Python Review

# import Order class
from Order import Order

# define CONSTANT
COST_PER_POUND = 7.99

# define main function
def main():

  order1 = Order()
  tempName = ""
  tempPounds = 0

  tempName = input("Enter coffee name (one word please): ")
  order1.setName(tempName)

  tempPounds = int(input("Enter # of pounds: "))
  order1.setPounds(tempPounds)

  order1.setCostPerPound(COST_PER_POUND)

  finalizeOrder(order1)



def finalizeOrder(newOrder):
  cost = 0

  newOrder.displayOrder()
  cost = newOrder.calcCost()
  print("Your order costs $" + str(cost))



# call main function
main()