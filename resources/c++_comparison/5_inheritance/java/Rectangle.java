/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/


public class Rectangle extends Shape {
  //instance variables
  private double width;
  private double length;
  
  //default constructor
  public Rectangle() {
    super();
    width = 0.0;
    length = 0.0;
  }
  
  //overloaded constructor
  public Rectangle(String inputName, double inputWidth, double inputLength) {
    super(inputName);
    width = inputWidth;
    length = inputLength;
  }
  
  //accessor / mutator
  public void setWidth(double inputWidth) { width = inputWidth; }
  public void setLength(double inputLength) { length = inputLength; }

  public double getWidth() {  return width; }
  public double getLength() {  return length;  }

  //methods
  public double calcArea() {
    return length * width;
  }
  
  public void display() {
    super.display();
    System.out.println("length = " + length);
    System.out.println("width = " + width);
  }
}
