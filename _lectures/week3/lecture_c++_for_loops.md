---
marp: true
theme: itp

week: 3
category: lectures
title: For Loops in C++
---

<!-- headingDivider: 2 -->

# For Loops in C++

## For Loops

- Useful for code that repeats a set number of times
- Uses a counter to control the loop

Basic Syntax

```c++
for (initialization; condition; update){
	statement(s);
}
```

## Basic Syntax

```c++
for (initialization; condition; update)
```

##### Initialization

Create and initialize variables only at the beginning of loop (ofter a counter)

## Basic Syntax

```c++
for (initialization; condition; update)
```

##### Condition

- Boolean expression that is checked at the end of each loop iteration.
- Continue looping as long as this is true

## Basic Syntax

```c++
for (initialization; condition; update)
```

##### Update

- Increment (or decrement) your loop variables at the end of each loop iteration.

## Example

`for (`**int i = 0**`; i < 10; i++) {`

`____if (i % 2 == 0) {`

`________Serial.println(i);
`



**Initialize variables**

## Example

`for (int i = 0`; **i < 10**`; i++) {`

`____if (i % 2 == 0) {`

`________Serial.println(i);
`



**Check condition (even the first time)**

- **If true, run loop**
- **If false, exit loop**

## Example

`for (int i = 0; i < 10; i++) {`

____**if (i % 2 == 0) {**

__________**Serial.println(i);**



**Run loop body (all the code in the loop)**

## Example

`for (int i = 0; i < 10; `**i++**`) {`

`____if (i % 2 == 0) {`

`________Serial.println(i);
`




**Update the variable**

## Example

`for (int i = 0`; **i < 10**`; i++) {`

`____if (i % 2 == 0) {`

`________Serial.println(i);
`



**Check condition again**

- **If true, run loop**
- **If false, exit loop**