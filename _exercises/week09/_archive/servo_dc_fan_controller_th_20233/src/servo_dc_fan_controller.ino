const int AIN1 = D3;
const int AIN2 = D4;
const int PWMA = D5;
const int POT = A0;

//create servo pin
const int SERVO_PIN = D2;

//create the servo object
Servo servoObj;

void setup() {
    Serial.begin(9600);
    pinMode(POT, INPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    //connect the pin to the servo object
    servoObj.attach(SERVO_PIN);
}

void potControlDcMotor() {
    // what 3 things do we have to set to make motor move?
    /*
            AIN1            AIN2        Motor
            H               L           spins one dir
            L               H           spins opposite dir
            L               L           nothing / off
            H               H           DAMAGE!

            PWMA pin 0-255
    */

    //    //motors spins one direction at full speed
    //    digitalWrite(AIN1, HIGH);
    //    digitalWrite(AIN2, LOW);
    //    analogWrite(PWMA, 255);
    //    delay(5000);
    //    // spin opposite direction at half speed
    //    digitalWrite(AIN1, LOW);
    //    digitalWrite(AIN2, HIGH);
    //    analogWrite(PWMA, 127);
    //    delay(5000);
    //    //off
    //    digitalWrite(AIN1, LOW);
    //    digitalWrite(AIN2, LOW);
    //    analogWrite(PWMA, 0);
    //    delay(5000);

    // use the pot to control the speed of the motor
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

    int potVal = analogRead(POT);
    int motorSpeed = map(potVal, 0, 4095, 0, 255);
    analogWrite(PWMA, motorSpeed);
}
void potControServo() {
    // servoObj.write(15);     //rotate to 15 deg
    // delay(500);
    // servoObj.write(100);    //100 deg
    // delay(500);
    // servoObj.write(165);    //165 deg
    // delay(500);

    //how could we use the potentiometer to control rotation position of fan?
    int potval = analogRead(POT);
    int servoPos = map(potval, 0, 4095, 15, 165);
    servoObj.write(servoPos);

}

void simpleFan() {
    //have the fan rotate automatically, and the pot controls the speed of the fan blade rotation
    //two ways! for loop, OR millis timer
    for (int servoPos = 15; servoPos <= 165; servoPos = servoPos + 5){
        servoObj.write(servoPos);
        potControlDcMotor();
        delay(100);
    }
    for (int servoPos = 165; servoPos >= 15; servoPos = servoPos - 5) {
        servoObj.write(servoPos);
        potControlDcMotor();
        delay(100);
    }


}
void loop() {
     potControlDcMotor();
    // potControServo();
    // simpleFan();
}