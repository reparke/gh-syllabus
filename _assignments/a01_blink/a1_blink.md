---
week_assigned: 1
number: 1
category: assignment
title: Basic Blink
date_due: Aug 25 @ 11:59 pm
---

Assignment 1 – Basic Blink
==========================

*[Submit on Blackboard](https://blackboard.usc.edu)*


Goals
-----

-   Test software installation

-   Test device configuration

**Requirements**

-   Connect to additional Wifi networks (optional)

-   Create a Workbench project

-   Setup project settings

-   Flash firmware to device

### Connect to additional Wifi networks

-   The Argon can remember the settings for multiple Wifi networks (just like a
    phone). If you need to configure for a different network than the one you
    first connected it, simply follow the instructions in the video again at https://docs.particle.io/quickstart/argon/#1-set-up-your-argonassignment when your phone is on the new Wifi network.
    

### Create Workbench Project

-   Follow the instructions to create a Workbench project:  
    <https://docs.particle.io/quickstart/workbench/#create-a-project>

-   Complete only the first step (do not move onto **Compile Project**

### Setup device settings

-   In Workbench, Go to View \> Command Palette

-   Type **Particle: Configure Project for Device.**

<img src="media/f46090a33a8cda9b07b6586a5328fb12.png" alt="command palette" style="width:400px" />


-   Select the device OS version you want to like to build for. It is
    recommended to use the latest stable version (this means the highest
    numbered version *without* **rc** or **beta** in the name). This means you
    are using the newest version of the operating system that is not being test
    (and so presumably it does not have bugs or errors). In the picture below,
    the latest stable version has been noted.

<img src="media/9e6b2684205c5b77cad0a7087031fec3.png" alt="target OS" style="width:400px" />

-   Select the type of device to you want to build for. For our course, we will
    always use **argon**

<img src="media/e800ce2f3ca3d6bda3d9378540418825.png" alt="target device" style="width:400px" />

-   Enter the name of the device you want to flash to. This will be the name
    gave your device when you initially connected it to your Particle account.

<img src="media/b45548e97ee3520b8fcb9fdf7e3a2e64.png" alt="target name" style="width:400px" />



### Creating Your Firmware

<img src="media/abff6159b011e556f68ec286cbd333cb.png" alt="IDE" style="width:400px" />



- In the INO file that opened when you created a project, paste the following
  code:

  ```c++
  void setup() {
      pinMode(D7, OUTPUT);
  }
  
  void loop() {
      digitalWrite(D7, HIGH);
      delay(1000);
  	digitalWrite(D7, LOW);
      delay(1000);
  }
  ```

  

### Flash Firmware to Device

-   In the Command Palette, type **Particle: Cloud Flash**
-   It may take a few minutes to successfully complete. When the firmware has
    been successfully installed, you should see the light on the device near the
    USB port blinking blue.

<img src="media/IMG_8666.jpg" alt="Argon blinking" style="width:400px" />



Deliverables
------------

*[Submit on Blackboard](https://blackboard.usc.edu)*


1.  A compressed file containing your project. Follow the guidelines for full
    credit.

    *Here are the instructions for submission*

2.  Navigate to your project folder.

3.  Include the *entire* folder in a zip file

4.  Rename the zip file so it follows this convention: *A\#.lastname.firstname*

5.  Upload zip file to Blackboard site for our course

6.  A photograph of your device connected to USB with the blue light on.

Grading
-------

| Item         | Points |
|--------------|--------|
| Project code | 5      |
| Device photo | 5      |
|              |        |
| Total        | 10     |
