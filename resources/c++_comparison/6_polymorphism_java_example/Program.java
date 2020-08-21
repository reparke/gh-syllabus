/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

public class Program {

	public static void main (String args[]) {	
		Shape s = new Shape(); 
		s.display(); 
		s = new Circle(); 
		s.display(); 

		Circle funShape;
		Shape s = new Shape(); 
		funShape = (Circle) s; //ERROR! auto is a Shape, not a Circle! auto.display();

		s = new Circle(); 
		Circle funShape = (Circle) s; //Works! auto is a Circle 
		s.display();
	}

}