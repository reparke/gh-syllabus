---
marp: true
theme: itp

week: 8
category: lectures
title: Audio
---

<!-- headingDivider: 2 -->

# Audio and Piezo Speakers

Generates a square wave of the specified frequency and duration (and  50% duty cycle) on a timer channel pin which supports PWM. Use of the  tone() function will interfere with PWM output on the selected pin.  tone() is generally used to make sounds or music on speakers or piezo  buzzers.

On Gen 3 Feather devices (Argon, Boron, Xenon), pins A0, A1, A2, A3,  D2, D3, D4, D5, D6, and D8 can be used for tone(). Pins are assigned a  PWM group. Each group must share the same frequency. Thus you can only  output 3 different frequencies at the same time.

* Group 3: Pins D2, D3, A4, and A5.
* Group 2: Pins A0, A1, A2, and A3.
* Group 1: Pins D4, D5, D6, and D8.

`tone()` takes three arguments, `pin`: the pin on which to generate the tone, `frequency`: the frequency of the tone in hertz and `duration`: the duration of the tone in milliseconds (a zero value = continuous tone).

The frequency range is from 20Hz to 20kHz. Frequencies outside this range will not be played.

`tone()` does not return anything.



## Documentation

* [Particle IFTTT Tutorial](https://docs.particle.io/tutorials/integrations/ifttt/#introduction)
