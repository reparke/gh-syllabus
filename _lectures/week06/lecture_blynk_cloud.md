---

marp: true
theme: itp

week: 
category: lectures
title: Creating IoT Mobile Apps with Blynk
---

<!-- headingDivider: 2 -->

# Blynk

![bg opacity:.75](lecture_blynk.assets/blynk.jpg)
# New Blynk cloud config

Note to self: need to create a new template for each project; need to create datastream for each variable ahead of time; need to create device for each project	 

### Create template

![image-20210905203811218](lecture_blynk_cloud.assets/image-20210905203811218.png)

![image-20210905203331216](lecture_blynk_cloud.assets/image-20210905203331216.png)



### Create datastreams

![image-20210905212827674](lecture_blynk_cloud.assets/image-20210905212827674.png)



![image-20210905213011243](lecture_blynk_cloud.assets/image-20210905213011243.png)

![image-20210905213103832](lecture_blynk_cloud.assets/image-20210905213103832.png)

Click **Save**

 

### Create new device

![image-20210905214437218](lecture_blynk_cloud.assets/image-20210905214437218.png)



![image-20210905214659317](lecture_blynk_cloud.assets/image-20210905214659317.png)

![image-20210905214734120](lecture_blynk_cloud.assets/image-20210905214734120.png)

Copy config info

​	![image-20210905215009623](lecture_blynk_cloud.assets/image-20210905215009623.png)

### Create Sketch

Start with this template

```c++
#define BLYNK_TEMPLATE_ID "ADD_YOURS"
#define BLYNK_DEVICE_NAME "ADD_YOURS"

#define BLYNK_PRINT Serial 

#include <blynk.h>

#define BLYNK_IP IPAddress(64, 225, 16, 22)  // https://ny3.blynk.cloud/ – New York
char auth[] = "ADD_YOURS";

void setup() {
    Serial.begin(9600);
    Blynk.begin(auth, BLYNK_IP);
}
void loop() { Blynk.run(); }
```



Change `BLYNK_AUTH_TOKEN` to be a `char[]`

`#define BLYNK_AUTH_TOKEN "z31PRR2NbCeR91OvDzvNTEQzLC_Bezwg";`

to

`char auth[] = "z31PRR2NbCeR91OvDzvNTEQzLC_Bezwg";`



### Test

Device should appear connected 



### Build interface in Blynk mobile app



### Code sketch