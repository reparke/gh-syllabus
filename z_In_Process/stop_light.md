* tips
  * give students a wiring diagram (or fritzing)
  * give students a sample program that turns all lights on (or is a pattern) so they can test wiring before coding (`examples/light_test.ino`)
* suggestions
  * need to cover enum, switch, delta timing, fsm
  * give students wiring diagrams
  * give students starting code that has light test and base code for starting project
  * lecture: switch
  * lab: start with delta timing to blink lights in one direction
  * lecture: FSM and enum
  * lab: draw out different states for one direction + pedestrians
  * lab: students code state transition 
  * lab: students try to add second direction of traffic; make states diagram and code
* need to:
  * change solution code to use prevMillis
  * create wiring diagram
  * create basic slides on enum, switch, fsm, delta (this one might already be made)
* Role of `loop()`
  * calculate new state
  * output traffic signal LEDs based on state
  * independently flash walk signal *(later)*
* Stage 1: NS traffic light ==(do together with class)==
  * Lights transition from NSGreen, NSYellow, NSRed
  * States: NSG, NSY, NSR
  * Duration: 
    * NSG, NSR = GO_TIME (5000)
    * NSY = TRANSITION_TIME (1000)

| State            | NS Stoplight |
| ---------------- | ------------ |
| Traffic Flows    | Green        |
| Traffic Stopping | Yellow       |
| Traffic Stopped  | Red          |

* Stage 2: add pedestrians
  * Lights transition from NSGreen, NSYellow, Ped Walk, Ped Don't Walk
  * States: NSG, NSY, **PED, PEDDW**
    * NSR is replaced by two new states for pedestrians
  * Duration: 
    * NSG, NSR, **PED** = GO_TIME (5000)
    * NSY, **PEDDW** = TRANSITION_TIME (1000)

| State                | NS Stoplight | Pedestrian Light |
| -------------------- | ------------ | ---------------- |
| NS Traffic Flows     | Green        | Don’t walk       |
| NS Traffic Stopping  | Yellow       | Don’t walk       |
| Pedestrians Go       | Red          | Walk             |
| Pedestrians Stopping | Red          | Don’t walk       |

* Stage 3: add don't walk blinking
  * add another state timer for blink rate
  * Question: When should we blink?
    * DW light should blink in every state except PED
    * if we are after blink rate, then blink light

| State                | NS Stoplight | Pedestrian Light      |
| -------------------- | ------------ | --------------------- |
| NS Traffic Flows     | Green        | Don’t walk (flashing) |
| NS Traffic Stopping  | Yellow       | Don’t walk (flashing) |
| Pedestrians Go       | Red          | Walk                  |
| Pedestrians Stopping | Red          | Don’t walk (flashing) |

* Stage 4: add WE light
  * Lights transition from NSGreen, NSYellow, **WEGreen, WEYellow**, Ped Walk, Ped Don't Walk
  * States: NSG, NSY, **WEG, WEY**, PED, PEDDW**
    * NSR is replaced by two new states for pedestrians
  * Duration: 
    * NSG, NSR, **WEG**, PED = GO_TIME (5000)
    * NSY, **WEY,** PEDDW = TRANSITION_TIME (1000)

| State                | NS Stoplight | WE Stoplight | Pedestrian Light      |
| -------------------- | ------------ | ------------ | --------------------- |
| NS Traffic Flows     | Green        | Red          | Don’t walk (flashing) |
| NS Traffic Stopping  | Yellow       | Red          | Don’t walk (flashing) |
| WE Traffic Flow      | Red          | Green        | Don’t walk (flashing) |
| WE Traffic Stopping  | Red          | Yellow       | Don’t walk (flashing) |
| Pedestrians Go       | Red          | Red          | Walk                  |
| Pedestrians Stopping | Red          | Red          | Don’t walk (flashing) |



