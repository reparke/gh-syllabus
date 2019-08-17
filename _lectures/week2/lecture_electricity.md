---
marp: true
theme: itp
paginate: true

week: 2
category: lectures  
title: Electricity
---

<!-- headingDivider: 2 -->

# Electricity

## What happens?

<img src="assets/1564541287879.png" alt="width:400px" style="width:400px" />

## Why? 

## How We Approach Electricity

- Electricity can be beautifully describe with physics and mathematics
  - These approaches are rich and important
- We will focus on building an intuitive understanding and applying principles to build devices
  - There will be some basic math, but that is not our focus
- Rules of Thumbs

## Which is Stronger?

<img src="assets/1564543352673.png" alt="height:500px" style="width:400px" />	<img src="assets/1564543461389.png" alt="height:500px" style="width:400px" />

## Common Analogy

- Electricity can be thought of as water flowing down a pipe

- The higher the water falls from, the greater the pressure

- More water can flow (and flow faster) through a larger and smoother pipe

- If the water is stored in a container / vat, it will pour out until it is empty

## Common Analogy

- The "pressure" (or height) of the water is the ***voltage***
  - Measured in units called **volts (V)** 
  - Higher voltage means more potential energy
  - Our circuits will typically consider voltages 0v - 5v

## Common Analogy

- The "rate of flow" of the electricity is the ***current***
  - Measured in units called amperes or amps (A)
  - Higher amperage means electrons are flowing faster
  - In equations, current with be denoted with the letter **I**
- Note: 1 A is a lot! Our projects will consider smaller values such as 0.2 A.
  - Instead, we will say 0.2 A is 200 **milli**amps (mA)

## Compare

Two equal water jugs connected to each of these. Which has greater flow?

<img src="assets/1564544624407.png" alt="height:500px" style="width:400px" /> <img src="assets/47730722082_bfcae57ea0.jpg" alt="height:500px" style="width:400px" />

## Resisting the Flow

- The narrower pipes restrict or **resist** the flow of water
- The measure of how well something resist or allows electricity is **resistance**
  - Measured in units called **Ohms (Ω)**
  - More Ohms means more resistance, which means less current (flow)

## Key Concepts

- Electrons are negatively-charged particles
- Electricity is the flow of **electrons** from **positive** to **negative **(flow of energy)
- Electronics is the study of devices that control / interact with the flow of electricity

## Circuits

- Electricity will only flow if there is a **circuit** 

- A circuit is a complete loop from a positive voltage source to a negative (lesser) source, through a conductive material

  <img src="assets/1564541287879.png" alt="width:300px" style="width:400px" />

## Voltage as Difference

- When we describe voltage, we are measuring the **difference** between two points
- In the water analogy, water could fall from 500 ft to 400 ft, or from 100 ft to 0 ft
  - In both cases, water fell a difference of 100 ft, but the *reference point* changed
- In a circuit, we commonly call the reference point **Ground (GND) **and say it is **0V**

- In homes and buildings, **ground** is literally connected into the earth (ground)

## Voltage Source

- In our circuits, we will use a voltage source to provide energy potential
  - USB power: 5v
  - 9V battery: 9v
  - Rechargeable lithium battery: 3.3v
- Our circuits will have a positive voltage (e.g. 3.3v or 5v) and ground voltage (0v)
- We will consider that current flows from the positive part of the circuit to the negative

## Resistors

- Resistors conduct electricity, but are used to restrict / slow the flow of current
- They can be connected either direction
- We measure values from 0Ω to 10,000Ω
  - 10,000 Ohms is 10 **kilo**Ohms (10 KΩ)



<img src="assets/1565140772469.png" alt="" style="height:200px" />

<img src="assets/1565140731484.png" alt="" style="height:200px" />

## Ohm's Law

- There are only a couple electrical laws that we need to know
- There is a relationship between **voltage (V)**, **current (I)**, and **resistance (R)**

```mathematica
V = I * R
R = V / I
I = R / V
```

- If you know two, you can solve for the other one

## Example

<img src="assets/1565141579356.png" alt="height:400px" style="width:400px" />

1. The voltage source is 9v. If we have a resistor that is 300 Ohms, what is the current?
2. The voltage source is 9v and you want to provide a current of 9mA. What size resistor should we use?

<!-- 1. 30 mA; 2. 1kOhm -->

## Breadboard

- We will use **breadboards** to connect our circuits
- The **power rails **  (on the long ends of the board) are all connected together
- On the interior, each group of 5 pins are connected

<!-- Open Fritzing to show connected pins -->

<img src="assets/1564547904128.png" alt="" style="height:300px" />

## Credits

- <a href="https://www.flickr.com/photos/59275783@N04/47522354472/">Mabacam</a> Flickr via <a href="http://compfight.com">Compfight</a> <a href="https://creativecommons.org/licenses/by-nc-nd/2.0/">cc</a> 
- <a href="https://www.flickr.com/photos/161816492@N07/47312501852/">PickComfort</a> Flickr via <a href="http://compfight.com">Compfight</a> <a href="https://creativecommons.org/licenses/by/2.0/">cc</a> 
- <a href="https://www.flickr.com/photos/160866001@N07/46688229715/">verchmarco</a> Flickr via <a href="http://compfight.com">Compfight</a> <a href="https://creativecommons.org/licenses/by/2.0/">cc</a> 
- <a href="https://www.flickr.com/photos/34327409@N04/47730722082/">Craig Walkowicz</a> Flickr via <a href="http://compfight.com">Compfight</a> <a href="https://creativecommons.org/licenses/by-nc-sa/2.0/">cc</a> 

