---
marp: true
theme: itp

week: 7
category: lectures
title: Enum in C++
---

<!-- headingDivider: 2 -->

# Enum in C++

## Recall

In an early discussion, we were trying to give driving direction, and there was a finite set of actions *(these are simplified)*:

* turn right
* turn left
* continue straight
* arrive



## RecallConsider

* We found a 'switch' provided a convenient way to choose between  a way to choose among specific, finite values



## Switch 

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

## Another improvement

* This was looking cleaning and easier to read
* However, the actions *(or states*) are still a little confusing to read
  * Ex: We need to remember that **2*1 means **turn left**

```c++
 case 1:					//turn left
    Serial.println("Turn left (wait for arrow)");
 
```

## Enum

* `enum` is a user-defined data type 
  * We get to decide what its values will be
* `enum` that allows us to give labels to literal (constant) values
* It can make our code much more self-explanatory and logical

## Enum Syntax

```c++
enum <<Enum_Name>> { <<value1>>, <<value2>>, ...}
```

* `enum` is the type keyword 
* `<<Enum_Name>>` is a name we define (it will become like `int` or `String`)
* `<<value1>>` ... `<<value2>>` are the allowed value we will let our variable take
* By default, C++ treats each of these **values** as starting at `0` and increasing by

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

## Enum Example

* There are four actions or states we need to represent
  * Turn Left, Turn Right, Go Straight, Arrive

```c++
Enum Directions {LEFT, RIGHT, STRAIGHT, ARRIVE};
```

* `Direction` value of `LEFT` is equivalent to `0`
* `Direction` value of `RIGHT` is equivalent to `1`
* `Direction` value of `STRAIGHT` is equivalent to `2`
* `Direction` value of `ARRIVE` is equivalent to `3`

## Enum Example

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

## Enum Example

```c++
Direction action = ...; 	
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

## Enum Example

```c++
Enum Directions {LEFT, RIGHT, STRAIGHT, ARRIVE};
Direction action = ...; 	
switch (action) {			
    case RIGHT:					
    	Serial.println("Turn right (you can turn on red)");
```

* When `Direction action == RIGHT`, it means that `action` is equivalent to 