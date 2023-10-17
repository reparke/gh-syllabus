// dc motor
const int AIN1 = D3;
const int AIN2 = D4;
const int PWMA = D5;

// pot
const int POT = A0;

//servo
const int SERVO_PIN = D2;

//create object to commmuniate with servo
Servo servoObj;

void setup() {
    Serial.begin(9600);
    pinMode(POT, INPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    //connect Servo to pin
    servoObj.attach(SERVO_PIN);
}

void potControlServo() {
    //pot range: 0-4095
    //servo range: 15-165
    int potVal = analogRead(POT);
    int servoAngle = map(potVal, 0, 4095, 15, 165);
    servoObj.write(servoAngle);

//     servoObj.write(15); //15 degrees
//     delay(500);
//     servoObj.write(100);
//     delay(500);
//     servoObj.write(165);
//     delay(500);
}

void potControlDcMotor() {
    // use the ponentiomter to control fan speed
    // pick direction
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

    int potVal = analogRead(POT);
    int motorSpeed = map(potVal, 0, 4095, 0, 255);
    // map function converts one input range to another
    // input: analog signal from 0 to 4095
    // output: PWM value from 0 to 255

    analogWrite(PWMA, motorSpeed);

    //     //use the potentiometer to control the fan speed

    //  //what three things do we change to make more spin?
    //  // AIN1 and AIN2 -- determine direction
    //  // AIN1 HIGH and AIN2 LOW --> one direction
    //  // AIN1 LOW and AIN2 HIGH --> opposite direction
    //  // AIN1 LOW and AIN2 low --> OFF
    //  // AIN1 HIGH and AIN2 HIGH --> BAD!
    //  //PWMA controls the speed

    //  digitalWrite(AIN1, HIGH);  //one direction
    //  digitalWrite(AIN2, LOW);
    //  analogWrite(PWMA, 255);
    //  delay(2000);
    //  digitalWrite(AIN1, LOW);   //opposite direction
    //  digitalWrite(AIN2, HIGH);
    //  analogWrite(PWMA, 255);
    //  delay(2000);
    //  digitalWrite(AIN1, LOW);   // stop motor
    //  digitalWrite(AIN2, LOW);
    //  analogWrite(PWMA, 0);
    //  delay(2000);
}

void loop() {
    // potControlDcMotor();
    // potControlServo();

    //to create a fan, we could a for loop to rotate servo
    //              OR you could use millis timer!
    for (int angle = 15; angle <= 165; angle = angle + 5) {
        servoObj.write(angle);
        potControlDcMotor();
        delay(50);      
    }
    for (int angle = 165; angle >= 15; angle = angle - 5) {
        servoObj.write(angle);
        potControlDcMotor();
        delay(50);
    }
}