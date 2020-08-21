/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

import java.util.Scanner;
public class Program {

  public static void main(String[] args) {
    final double COST_PER_POUND = 7.99;
    
    Scanner input = new Scanner(System.in);
    Order order1 = new Order();
    String tempName = "";
    int tempPounds = 0;
    
    System.out.println("Enter coffee name (one word please): ");
    tempName = input.next();
    order1.setName(tempName);
    
    System.out.println("Enter # of pounds: ");
    tempPounds = input.nextInt();
    order1.setPounds(tempPounds);
    
    order1.setCostPerPound(COST_PER_POUND);

    finalizeOrder(order1);
    
  }
  
  public static void finalizeOrder(Order newOrder){
    double cost = 0;
    
    newOrder.displayOrder();
    cost = newOrder.calcCost();
    System.out.println("Your order costs $" + cost);
    
  }
}





