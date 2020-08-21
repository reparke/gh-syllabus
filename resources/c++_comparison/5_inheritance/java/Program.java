/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

public class Program {

  public static void main(String[] args) {

    Rectangle rect1 =  new Rectangle();
    Rectangle rectTennisCourt = new Rectangle("tennis court", 78, 36);
    
    double area = 0;
    
  
    System.out.println("Calling 'display()' on rect1 results in the following output:");
    rect1.display();
    System.out.println();
    
    System.out.println("Calling 'display()' on rectTennisCourt results in the following output:");
    rectTennisCourt.display();
    System.out.println();
    
    area = rectTennisCourt.calcArea();
    System.out.println("The area of " + rectTennisCourt.getName() + 
              " is " + area + " feet");

  }

}
/*
public class Program {

  public static void main(String[] args) {
    Shape shapeUnnamed = new Shape();
    Shape shapeJellybean = new Shape("jellybean");
    
    Rectangle rectTennisCourt = new Rectangle("tennis court", 78, 36);
    
    double area = rectTennisCourt.calcArea();
    
    System.out.println("The default constructor shape has the following name: " + 
              shapeUnnamed.getName() + "\n");
    
    System.out.println("Calling 'display()' on the shapeJellybean results in the following output:");
    shapeJellybean.display();
    System.out.println();
    
    System.out.println("Calling 'display()' on the rectTennisCourt results in the following output:");
    rectTennisCourt.display();
    System.out.println();
    
    System.out.println("The area of " + rectTennisCourt.getName() + 
              " is " + area + " feet");

  }

}
*/