---
week: 9
category: assignments
title: Guide to Smart Watch Assembly
show_in_list: false

---

## Smart Watch Assembly

### Items You will Need: 

1. Scissors
2. Strip of red loop-side (soft) Velcro (2" x 14")
3. Strip of clear hook-side (rough) Velcro (1" x 10")
4. Small black strip of hook-side (rough) Velcro (1/2" x 2")
4. Breadboard
5. LiPo battery
6. Argon

### STEP 1:

Cut the red velcro to go around your wrist. The velcro will need to wrap around your wrist so make it longer at first to test. The strip should comfortably wrap around your arm. Then, attach the small black strip of velcro to one end. This will serve as the "clasp" of your smart watch. 

Note: Inspect the velcro and notice the two sides. You want the soft side (right side in picture below) with loops sticking out. The other side (left in picture below) is just a vinyl backing and isn't part of the velcro connection. The vinyl side should touch your wrist. 

![watch_v3_1](guide_build_watch.assets/watch_v3_1.jpg)
![watch_v3_2](guide_build_watch.assets/watch_v3_2.jpg)

### STEP 2:

Cut velcro strips. You will need 4 pieces of velcro (2 for the battery and 2 for the breadboards). You might want to look ahead before you do this step; if you already have velcro attached to your battery and breadboard, you won't need to cut all of these strips.

* 1 or 2 - 1"x1" squares
* 2 - 2"x1" strip 

### STEP 3:

Attach a 2"x1" strip of velcro to the LiPo battery (may have been done in a previous project). Place a 1"x1" square of velcro in the center on top and bottom of the battery. Wrap the red velcro strip around your wrist so that it is clasped and comfortable. Take note of where the "center" is, and attach the battery there with velcro. 

![watch_v3_3](guide_build_watch.assets/watch_v3_3.png)

![watch_v3_4](guide_build_watch.assets/watch_v3_4.png)



### STEP 4:

Attach velcro to bottom of breadboard (may have been done in a previous project). Carefully peel off adhesive covering on bottom of breadboard (**don't take off actual foam-like adhesive**) and place** a 1"x1" square of velcro on the bottom of the breadboard. You may need to use two breadboards for this assignment, so you can put the velcro closer to the edges of the breadboards and connect both together if you'd like instead. Connect the breadboards with velcro on the bottoms to the velcro on the top of the LiPo battery.

![watch_v3_5](guide_build_watch.assets/watch_v3_5.png)
![watch_v3_6](guide_build_watch.assets/watch_v3_6.png)


### Step 7

Wire the components. Below are two diagrams for wiring. The second design uses a switch and is optional.

*OLED Wiring*

```c++
MicroOLED --------------- Argon
  GND ------------------- GND
  VCC ------------------- 3.3V
  D1/MOSI --------------- MO
  D0/SCK ---------------- SCK
  D2  ------------------- unused
  D/C ------------------- A0 (can be changed)
  RST ------------------- A1 (can be changed)
  CS  ------------------- A2 (can be changed)
```

*Additional Wiring*

```c++
Button: D3
Switch: 
  Pin 1 -- GND
  Pin 2 -- EN
```



*Fritzing design*

![watch_bb](guide_build_watch.assets/watch_bb.png)

*Fritizing design with switch*

![watch_with_switch_bb](guide_build_watch.assets/watch_with_switch_bb.png)

### Completed Assembly

![watch_v3_7](guide_build_watch.assets/watch_v3_7.png)

![watch_v3_8](guide_build_watch.assets/watch_v3_8.png)

![watch_v3_9](guide_build_watch.assets/watch_v3_9.png)

## Credits

* Diagrams made with [Fritzing](https://fritzing.org/home/)