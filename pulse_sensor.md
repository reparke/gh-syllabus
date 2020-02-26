* sensor: PulseSensor.com
* [example code](https://pulsesensor.com/pages/installing-our-playground-for-pulsesensor-arduino) (doesn't work with Argon)
* How to wear
  * attach velcro circle to back of sensor
  * attach vinyl circle to front of sensor
  * use longer velcro strip to wrap sensor on finger
    * finger tip and under side of finger like ring work well
    * wrist does NOT work well
* [working particle code](https://community.particle.io/t/boron-pulse-sensor-and-spark-interval-timer/48132/10) (links to [web IDE code](https://go.particle.io/shared_apps/5c94423c5893c4000ab8a158))
* can't use particle library code for pulse sensor because it uses a library that is incompatible with mesh devices
* Extensions
  * connect servo to `rawSignal` to make provide a visual display of heart rate
  * connect LED to pin D6 to see heart fading as a light
  * connect LED to pin D7 to see single blink on heart beat
  * connect buzzer to produce a sound on heart beat
  * could this work with bluetooth and bluefruit app
* Wrist sensor idea - MAX30102 
  * [particle post](https://community.particle.io/t/best-pulse-sensor/43979)
  * purchase part from [AliExpress](https://www.aliexpress.com/item/32902336311.html?spm=2114.search0104.3.1.6b9968e5vyqGpu&ws_ab_test=searchweb0_0,searchweb201602_4_5017015_10065_10068_10130_10547_10059_10548_10696_100031_5016813_10084_10083_5017115_10103_451_10618_452_5016913_10139_10307,searchweb201603_45,ppcSwitch_5&algo_expid=b21e847c-2d88-4a2d-a96f-10be2de7d572-0&algo_pvid=b21e847c-2d88-4a2d-a96f-10be2de7d572&transAbTest=ae803_1&priceBeautifyAB=0)
  * [library](https://github.com/xcoder123/MAX30100)