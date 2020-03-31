---
marp: true
theme: itp

week: 11
category: lectures
title: Ultrasonic Distance Sensor
---

<!-- headingDivider: 2 -->

## OLED Screen Graphics

<img src="lecture_oled_graphics.assets/IMG_9092.jpg" alt="IMG_9092" style="width:500px;" />



describe in one slide image vs canvas size



## Screen Parameters

* OLED screen consists of 64 (W) x 48 (H) pixels (3,072 total pixels)
* 3,072 pixels means 3,072 bits (ON or OFF) are needed to display a full image
  * 3,072 bits is 384 bytes (8 bits = 1 byte)
* Each pixel is either ON (HIGH) or OFF (LOW) because there is only one color
* We can display images on the screen in a **bitmap** format

## Pixels

| Original Image                                               | Image Closeup to Show Pixels                                 |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| <img src="lecture_oled_graphics.assets/image-20200330213307376.png" alt="image-20200330213307376" style="width:400px;" /> | <img src="lecture_oled_graphics.assets/image-20200330213239875.png" alt="image-20200330213239875" style="width:400px;" /> |

## Bitmap

* Bitmaps are stored as large arrays of bytes
* In a monochrome image, there is one bit per pixel
  * 64 pixel x 48 pixel images = 3,072 bits = 384 bytes
* Ex:

```c++
const uint8_t heart_bmp[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xfc, ... }; 
```



## Creating Bitmaps

* Use a tool to convert image to byte array
* Color Restrictions
  * Each image to be converted should be black and white
  * Color and greyscale can work but not well
* Image Size
  * Sparkfun library requires that each bitmap be specified as 64x48 pixels or 384 bytes
  * This applies even if parts of the image is blank



## Output Restrictions

* For SparkFun OLED, draw mode is `vertical - 1 byte per pixel`
* If you're using the SparkFun library, the final **canvas size** must be 



## Ex: Converting Image with [Image2CPP](https://javl.github.io/image2cpp/)

<img src="lecture_oled_graphics.assets/image-20200317223318751.png" alt="image-20200317223318751" style="width:500px;" />

## 

<img src="lecture_oled_graphics.assets/image-20200317223350648.png" alt="image-20200317223350648" style="width:500px;" />

## 

<img src="lecture_oled_graphics.assets/image-20200317223446692.png" alt="image-20200317223446692" style="width:500px;" />

## 

<img src="lecture_oled_graphics.assets/image-20200317223504443.png" alt="image-20200317223504443" style="width:500px;" />

## Storing Byte Array 

* Create a `const uint8_t` array (byte array)

```c++
const uint8_t heart_bmp[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xfc, ... }; 
```

* Use library to display bitmap

## Lab

* 

## Tools for converting images to bitmaps

* Online: [Image2CPP](https://javl.github.io/image2cpp/)
* Windows: [LCD Assistant](http://en.radzio.dxp.pl/bitmap_converter/)
* Mac: [bitmapToC](https://github.com/hoiberg/bitmapToC)

