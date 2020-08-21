/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

import java.util.Scanner;

public class Program {

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    
    //create array of numbers of size 4
    int sizeOfArray = 4;
    int [] numbers = new int [sizeOfArray];
    
    //fill array with user input
    for (int i = 0; i < numbers.length; i++) {
      System.out.println("Enter num: ");
      numbers[i] = input.nextInt();
    }
    
    //print array
    System.out.println("The numbers in the array are:" );
    for (int i = 0; i < numbers.length; i++){
      System.out.println(numbers[i]);
    }
    
    //call method calcSum and store the return value
    int sum = calcSum(numbers);
    System.out.println("The sum of the numbers is " + sum);
  }
  
  /*
   * calcSum
   * input: array of ints
   * output: int
   * desc: adds all the values in the array and returns the sum
   */
  public static int calcSum(int[] nums) {
    int sum = 0;
    for (int i = 0; i < nums.length; i++) {
      sum += nums[i];
    }
    return sum;
  }

}
