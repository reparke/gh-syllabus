/*
Rob Parke
Viterbi School of Engineering
University of Southern California
Java, C++, and Python Review
*/


//default constructor
Order::Order() {
  name = "";
  pounds = 0;
  costPerPound = 0.0;
}

// get / set methods
string Order::getName(){ return name;   }
int Order::getPounds() { return pounds; }
double Order::getCostPerPound() { return costPerPound;   }

void Order::setName(string newName) { name = newName;   }
void Order::setPounds(int newPounds) {  pounds = newPounds;  }
void Order::setCostPerPound(double newCostPerPound){ costPerPound = newCostPerPound;
}

// methods
/* calcCost
 * input: none
 * output: returns pounds * costPerPound
 */
double Order::calcCost(){
  return pounds * costPerPound;
} 

/* displayOrder
 * input: none
 * output: none
 * side-effect: prints a summary of the order to the screen
 */
void Order::displayOrder(){
  cout << "Order: "
	<< name 
	<< " for " 
	<< pounds 
	<< " lbs @ $"
	<< costPerPound
	<< "/lb";
}














