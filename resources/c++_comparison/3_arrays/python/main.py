# Rob Parke
# Viterbi School of Engineering
# University of Southern California
# Java, C++, and Python Review

# define main function
def main():
  numbers = []  # create empty list (no size necessary)
  sizeOfList = 4
  
  # fill list with user input
  for i in range(sizeOfList):
    numbers.append(int(input("Enter num: ")))

  # print list
  print("The numbers in the list are:" )
  for i in range(len(numbers)):
    print(numbers[i])

  # # the following for loop also works
  # # but in C++, a for loop is more similar
  # # to the loop above
  # print("The numbers in the list are:" )
  # for num in numbers:
  #   print(num)


  # call function calcSum and store the return value
  total = calcSum(numbers)
  print("The sum of the numbers is " + str(total))


'''
  calcSum
  input: list of ints
  output: int
  desc: adds all the values in the list and returns the sum
'''
def calcSum(nums):
  total = 0
  for i in range(len(nums)):
    total += nums[i]

  return total


# call main function
main()