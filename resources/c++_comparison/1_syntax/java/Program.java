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

    // variable declarations
    int a = 8;
    double x;
    x = 3.14;
    String message = "Hello World!";
    boolean gotMilk = true;

    // Output
    System.out.println("This will print to the console");
    System.out.println(message);
    System.out.println("The value of X is " + x);
    System.out.println("----------------------------");

    // input
    System.out.println("Enter a integer: ");
    a = input.nextInt();
    System.out.println(a);

    System.out.println("Enter a single word: ");
    message = input.next();
    input.nextLine(); // clear extra newline
    System.out.println(message);

    System.out.println("Enter multiple words: ");
    message = input.nextLine();
    System.out.println(message);
    System.out.println("----------------------------");

    // If statements
    if (gotMilk == true) {
      System.out.println("You've got milk!");
    } else if (gotMilk == false) {
      System.out.println("There is an absence of milk!");
    } else {
      System.out
          .println("This will never execute because boolean variables can only be T or F");
    }
    System.out.println("----------------------------");

    // while loops
    a = 7;
    while (a != 0) {
      System.out.println("This loop will continue until you enter 0.");
      System.out.println("Enter a number: ");
      a = input.nextInt();
    }
    System.out.println("----------------------------");

    
    // for loops
    System.out.println("Enter a positive number to sum: ");
    a = input.nextInt();
    int total = 0;
    for (int i = 0; i <= a; i++) {
      total += i;
    }
    System.out.println("The summation of " + a + " is " + total);
    System.out.println("----------------------------");

  }
}
