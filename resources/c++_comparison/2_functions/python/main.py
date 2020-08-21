# Rob Parke
# Viterbi School of Engineering
# University of Southern California
# Java, C++, and Python Review

#define main function

def main():
  a = 0
  b = 0
  result = 0

  print("Enter two integers: ")
  a = int(input())
  b = int(input())

  result = calcSumSquares(a, b)
  displayResult(a, b, result)


def calcSumSquares(num1, num2):
  return num1 * num1 + num2 * num2


def displayResult(num1, num2, result):
  print("The sum of squares of " +
      str(num1) + " and " + str(num2) +
      " is " + str(result))


# call main function
main()