/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/

public class Circle extends Shape { 

   // override the parent's definition.    
   public void display() {        
		System.out.println("Top down!");
        // optionally use a superclass method        
		super.display();
        System.out.println("Got the radio on!");   
		
	} 
}