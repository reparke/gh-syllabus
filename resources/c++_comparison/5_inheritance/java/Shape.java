/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/


public class Shape {
  //instance variables
  private String name;
  
  //default constructor
  public Shape() {
    name = "unnamed";
  }
  
  //overloaded constructor
  public Shape(String inputName) {
    name = inputName;
  }
  
  //accessor / mutator
  public String getName() { return name;   }

  public void setName(String inputName) { name = inputName; }
  

  //methods 
  public void display() {
    System.out.println("name =  " + name);
  }

}
