<!-- headingDivider: 2 -->

# `switch`and `enum` Statements in C++

## Consider

We are trying to design a self-driving car, and it has a finite set of actions *(these are simplified)*:

* turn right
* turn left
* continue straight
* arrive

## Consider

To give instructions to the user, we need conditional logic

```c++
int action = ...; 	
if (action == 1) {			//turn right
    Serial.println("Turn right (you can turn on red)");
} else if (action == 2)  { 	//turn left
    Serial.println("Turn left (wait for arrow)");
} else if (action == 3)  { 	//continue
    Serial.println("Keep going straight");
} else if (action == 4)  { 	//arrived
    Serial.println("You have arrived!");
}
else {
    Serial.println("Error!")
}
```

## Consider

* Using `if` this way is a perfectly fine way to handle conditional logic
* However, for a finite set of options, there is an easier way
* `switch` statements provide a way to choose between specific, finite values

## `switch` Statement Syntax

```c++
switch (<<variable>>) {
    case <<FIRST_VALUE>>:
        # do some code if variable == VALUE_1
    break;
    case <<SECOND_VALUE>>:
        # do some code if variable == VALUE_2
    break;
    default:
        # do some code if variable is anything else 
}
```

## `switch`Statement Syntax

```c++
switch (<<variable>>)
```

* `variable` can be an `int ` (or `short`, `byte`, `char`)
* `variable` can **not** be a `string`

## `switch` Statement Syntax

```c++
switch (<<variable>>) {
    case <<FIRST_VALUE>>:
        # do some code if variable == FIRST_VALUE
    break;
```

* `switch` will attempt to match `variable` to the value specified by each case label (e.g. `VALUE_3`)
* When a match is found, the code is executed
* This is the equivalent of `if ... else if`
* `break;` **is required** after executing the code for that case

## `switch` Statement Syntax

```c++
switch (<<variable>>) {
	# ...
    default:
    # do some code if variable is anything else 
```

* `default` will execute if none of the cases match `variable`
* This is the equivalent of `else`

## Partially Code: `switch`compared to `if`
```c++
if (action == 0) {			//turn right
    Serial.println("Turn right");
} else if (action == 1)  { 	        //turn left
    Serial.println("Turn left");     //...more else if...
else {
    Serial.println("Error!")
}
```
```c++
switch (action) {			
    case 0:					//turn right
    	Serial.println("Turn right (you can turn on red)");
    break;      //...more cases...
    default:
	    Serial.println("Error!");
}
```

## Full `switch` Example

```c++
int action = ...; 	
switch (action) {			
    case 0:					//turn right
    	Serial.println("Turn right (you can turn on red)");
    break; 
    case 1:					//turn left
    	Serial.println("Turn left (wait for arrow)");
    break;
    case 2:	 				//continue
    	Serial.println("Keep going straight");
    break;
    case 3:	 				//arrived
    	Serial.println("You have arrived!");
    break;
    default:
	    Serial.println("Error!");
}
```



## Summary

* `switch` provides a simplified structure to decided between a small number fixed values (`int` typically)
* `switch` does not work with `string`



## Another improvement

* Though `switch` helped, the actions *(or states*) are still a little confusing 
  * Ex: We need to remember that **case 2** means **continue straight**

```c++
case 2:	 				//continue
	Serial.println("Keep going straight");
 
```

* These is another improvement we can make

## `enum`

* `enum` is a user-defined data type 
  * This means **we** get to decide what its values will be
* `enum` that allows us to give labels to literal (constant) values
* It can make our code much more self-explanatory and logical

## `enum` Syntax

```c++
enum <<enum_name>> { <<value1>>, <<value2>>, ...}
```

* `enum` is the type keyword 
* `<<enum_Name>>` is a name we define (it will become like `int` or `String`)
* `<<value1>>` ... `<<value2>>` are the allowed value we will let our variable take
* By default, C++ treats each of these **values** as starting at `0` and increasing by 1

## Recall

```c++
int action = ...; 	
switch (action) {			
    case 0:					//turn right
    	Serial.println("Turn right (you can turn on red)");
    break; 
    case 1:					//turn left
    	Serial.println("Turn left (wait for arrow)");
    break;
    case 2:	 				//continue
    	Serial.println("Keep going straight");
    break;
    case 3:	 				//arrived
    	Serial.println("You have arrived!");
    break;
    default:
	    Serial.println("Error!");
}
```

## `enum ` Example

* There are four actions or states we need to represent
  * Turn Left, Turn Right, Go Straight, Arrive
* Let's define our `enum` and call it `Operation`

```c++
enum Operation {LEFT, RIGHT, STRAIGHT, ARRIVE};
```

* `Operation` value of `LEFT` is equivalent to `0`
* `Operation` value of `RIGHT` is equivalent to `1`
* `Operation` value of `STRAIGHT` is equivalent to `2`
* `Operation` value of `ARRIVE` is equivalent to `3`

## `enum ` Example

* Now we can create a `Operation` variable

```c++
Operation action;
```

* `action` would be given a value from some function we write
* You could also assign a literal value to `action` like this

```c++
Operation action = STRAIGHT;	//equivalent to int value of 2
```

* We can now use our `Operation` value to control the `switch`

## Partially Code Comparison
```c++
int action = ...; 	
switch (action) {			
    case 0:					//turn right
    	Serial.println("Turn right (you can turn on red)");
    break; // ... more cases ...
}
```

```c++
Operation action = ...; 	
switch (action) {			
    case RIGHT:					
    	Serial.println("Turn right (you can turn on red)");
    break; 
    case LEFT:
    	Serial.println("Turn left (wait for arrow)");
    break; //... more cases ...
    }
```

## Full `enum ` Example

```c++
//globally create enum type
enum Operation {LEFT, RIGHT, STRAIGHT, ARRIVE};

//this code goes within loop() or other function
Operation action = ...; 	
switch (action) {			
    case RIGHT:					
    	Serial.println("Turn right (you can turn on red)");
    break; 
    case LEFT:
    	Serial.println("Turn left (wait for arrow)");
    break;
    case STRAIGHT:
    	Serial.println("Keep going straight");
    break;
    case ARRIVE:
    	Serial.println("You have arrived!");
    break;
    default:
	    Serial.println("Error!");
}
```