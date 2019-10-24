---
week_assigned: 7
number: 7
category: assignment
title: Alarm  Clock
date_due: Oct 29 @ 11:59 pm

---
Assignment 7 – Alarm Clock
==========================

[Submit on Blackboard](https://blackboard.usc.edu/)

Goals
-----

-   Connect speaker and play tones

-   Connect device to Particle cloud

-   Connect to IFTTT and control device

**Overview**

This assignment is to create an alarm clock that has a speaker that can play a
song or a buzzer sound as well as a snooze button. The alarm set time and
whether it is enabled / disabled will be controlled from a mobile device via
IFTTT.

**Components**

-   Argon

-   Breadboard

-   1 x speaker

-   1 x LED

-   2 x push buttons (plus any necessary resistors)

-   Jumper wire (standard male-male)

**Requirements**

-   Create a Fritzing breadboard prototype layout of your design. Once you’re
    satisfied with the design, connect the device

-   It is recommended to code the device in stages, and test at each stage

>   **Global variables**

-   You can create other variables as needed, but these are required

-   **int melodyNotes[16]** and **int melodyNotesDuration[16]** to store the
    pattern of notes for the melodies your alarm will play

>   **Stage 1: Speaker and Tones**

-   Connect the speaker, LED, and push button (push button discussed later)

-   Create three different “songs” for the alarm. One can be a simple alarm
    buzzer, but the other two should have distinct melodies (at least 16 notes).
    You can use the list of musical notes and frequencies (or do something
    different).

-   Test the system playing the notes

>   **Stage 2: Configure Alarm Settings via IFTTT**

-   Create an IFTTT applet that allows a button press to enable / disable the
    alarm on the argon. This means if the alarm time arrives but the alarm
    status is disabled, then the alarm will NOT sound

    -   Hint: Using the IFTTT **Button widget** trigger

-   Create a IFTTT applet that allows you to choose between the song or the
    buzzer sound that will play on the argon when the alarm goes off

    -   Hint: Using the IFTTT **Button widget** trigger

>   **Stage 3: Set Alarm Time via IFTTT**

-   Create an IFTTT applet to set a time and start an alarm on the argon.

    -   Hint: Using the IFTTT **Date & Time** trigger, you can create a
        **Particle** function action)

-   IFTTT only allows time triggers at :00, :15:, :30, and :45 minutes each
    hour. It is recommended (not required) to create another **Button widget**
    trigger that you can use for testing

>   **Stage 4: Configure timing and buttons (Stop and Snooze)**

-   The logic of alarm is as follows (note these are not meant to necessary be
    exact coding, just a general flow)

    -   If alarm is disabled

        -   Snooze button, stop button, and alarm time trigger have no effect

    -   If alarm is enabled

        -   If alarm time trigger goes off

            -   The selected song will play indefinitely until the stop button
                is pressed

            -   If the snooze button is pressed, the song will be paused for a
                short time (probably 10 min, but for testing you can use a few
                seconds)

-   Hint: In order to manage the timing of events, use **millis()** instead of
    **delay()**. Note that a delay of few milliseconds between individual notes
    is fine

**Extra Credit**

-   IFTTT does not allow for arbitrary alarm times. Use the Particle console (or
    app) to set an arbitrary alarm time (e.g. 4:58 pm).

**Required naming convention** (replace \# with the current assignment number)

-   **Project Name**

    -   itp348_a\#_lastname_firstname

-   **Zip File** (include entire project folder)

    -   itp348_a\#_lastname_firstname.zip

Deliverables
------------

1.  A compressed file containing your project. Follow the guidelines for full
    credit.

    *Here are the instructions for submission*

2.  Navigate to your project folder.

3.  Include the *entire* folder in a zip file

4.  Rename the zip file based on naming convention

5.  Upload zip file to Blackboard site for our course

6.  A photograph of your device connected to USB with the blue light on.

7.  A (very) short video demonstrating your project functioning

Grading
-------

| Item                                        | Points |
|---------------------------------------------|--------|
| Fritzing layout                             | 5      |
| Stage 1: Speaker and Tones                  | 10     |
| Stage 2: Configure Alarm Settings via IFTTT | 5      |
| Stage 3: Set Alarm Time via IFTTT           | 5      |
| Stage 4: Configure timing and buttons       | 15     |
| Total                                       | 40     |



### Code Attachment: Music Notes as Constants

**Instructions**

* It can be helpful to create melodies with musical notes instead of frequencies. The following code file lists the musical notes as frequencies.

* In the `src` folder for your project, create a file called `pitches.h` and copy / paste the code below there. In your main `.ino` sketch, you can then include this file and use the constants to play musical notes.

```c++
#include "pitches.h"

// example
tone(D6, NOTE_D4, 500);	//play the D note above middle C
```

**Code**

```c++
// from https://www.arduino.cc/en/Tutorial/toneMelody

/*************************************************
 * Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
```

