/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

// This file defines the prototype (aka outline) of the Order class
 
#pragma once      // Required at the top of new header (.h) files

public class Order {
  // variables declaration
  private:
    String name;
    int pounds;
    double costPerPound;
  
  public:
    //default constructor
    Order();
    
    // get / set methods
    string getName();
    int getPounds();
    double getCostPerPound();
    
    void setName(string newName);
    void setPounds(int newPounds);
    void setCostPerPound(double newCostPerPound);
    
    // methods
    /* calcCost
     * input: none
     * output: returns pounds * costPerPound
     */
    double calcCost();
    
    /* displayOrder
     * input: none
     * output: none
     * side-effect: prints a summary of the order to the screen
     */
    void displayOrder();
}













