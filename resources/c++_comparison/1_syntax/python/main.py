# Rob Parke
# Viterbi School of Engineering
# University of Southern California
# Java, C++, and Python Review




#define main function

def main():
  # variable declarations
  a = 8
  # x   # there is no point in Python to declare a variable 
      # without initializing it
  x = 3.14
  message = "Hello World!"
  gotMilk = True

  #  Output
  print("This will print to the console")
  print(message)
  print("The value of X is " + str(x))
  print("----------------------------")

  #  input
  a = int(input("Enter a integer: "))
  print(a)

  message = input("Enter a single word: ")
  print(message)

  message = input("Enter multiple words: ")
  print(message)
  print("----------------------------")

  #  If statements
  if gotMilk == True:
    print("You've got milk!")
  elif gotMilk == False:
    print("There is an absence of milk!")
  else:
    print("This will never execute because boolean variables can only be T or F")
  
  print("----------------------------")

  #  while loops
  a = 7
  while a != 0:
    print("This loop will continue until you enter 0.")
    a = int(input("Enter a number: "))
  print("----------------------------")

  
  #  for loops
  a = int(input("Enter a positive number to sum: "))
  total = 0
  for i in range(a + 1):
    total += i
  
  print("The summation of " + str(a) + " is " + str(total))
  print("----------------------------")


# call main function
main()