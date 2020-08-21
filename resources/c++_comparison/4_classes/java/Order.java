/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/


public class Order {
  // variables declaration
  private String name;
  private int pounds;
  private double costPerPound;
  
  //default constructor
  public Order() {
    name = "";
    pounds = 0;
    costPerPound = 0.0;
  }
  
  // get / set methods
  public String getName(){ return name;   }
  public int getPounds() { return pounds; }
  public double getCostPerPound() { return costPerPound;   }
  
  public void setName(String newName) { name = newName;   }
  public void setPounds(int newPounds) {  pounds = newPounds;  }
  public void setCostPerPound(double newCostPerPound){ costPerPound = newCostPerPound;
  }
  
  // methods
  /* calcCost
   * input: none
   * output: returns pounds * costPerPound
   */
  public double calcCost(){
    return pounds * costPerPound;
  } 
  
  /* displayOrder
   * input: none
   * output: none
   * side-effect: prints a summary of the order to the screen
   */
  public void displayOrder(){
    System.out.println("Order: " + name + " for " + pounds +
              " lbs @ $" + costPerPound + "/lb");
  }
}













