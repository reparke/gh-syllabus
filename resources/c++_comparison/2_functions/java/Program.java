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
    int a = 0, b = 0, result = 0;

    System.out.println("Enter two integers: ");
    a = input.nextInt();
    b = input.nextInt();

    result = calcSumSquares(a, b);

    displayResult(a, b, result);

  }

  public static int calcSumSquares(int num1, int num2) {
    return num1 * num1 + num2 * num2;
  }

  public static void displayResult(int num1, int num2, int result) {
    System.out.println("The sum of squares of " + num1 + " and " + num2
        + " is " + result);
  }
}
