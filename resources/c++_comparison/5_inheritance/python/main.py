# Rob Parke
# Viterbi School of Engineering
# University of Southern California
# Java, C++, and Python Review

# import Rectangle class
from Rectangle import Rectangle

def main():
  rect1 = Rectangle()
  rectTennisCourt = Rectangle("tennis court", 78, 36)

  area = 0

  print("Calling 'display()' on rect1 results in the following output:")
  rect1.display()
  print()

  print("Calling 'display()' on rectTennisCourt results in the following output:")
  rectTennisCourt.display()
  print()

  area = rectTennisCourt.calcArea()
  print("The area of " + rectTennisCourt.getName() +
      " is " + str(area) + " feet")

# call main function
main()