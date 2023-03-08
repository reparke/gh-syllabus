// motor A control
const int AIN1 = D3;
const int AIN2 = D4;
const int PWMA = D5;
const int POT = A0;  // please note A0, not D2

const int SERVO_PIN = D2;
// #1 create the servo object
Servo servo;  // no need to #include library

unsigned long prevMillis = 0;
unsigned long increment = 20;
int position = 15;          // servo position
bool posIncreasing = true;  // true -> 15,30,...165
                            // false -> 165, 150, ... 15

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
}

// version from class
void simpleFanControl() {
    for (int angle = 15; angle <= 165; angle = angle + 5) {
        servo.write(angle);
        potControlDcMotor();
        delay(50);
    }
    for (int angle = 165; angle >= 15; angle = angle - 5) {
        servo.write(angle);
        potControlDcMotor();
        delay(50);
    }
}

void millisFanControl() {
    unsigned long curMillis = millis();
    if (curMillis - prevMillis > increment) {
        // check what direction servo is moving
        // because we are either going to increase or decrease the servo angle
        if (posIncreasing == true) {
            position++;  // C++ notation that means postion = position + 1
            servo.write(position);
            if (position >= 165) {
                posIncreasing = false;  // change direction
            }
        } else {  // posIncreasing = false
            position--;
            servo.write(position);
            if (position <= 0) {
                posIncreasing = true;
            }
        }
        prevMillis = curMillis;
    }
    potControlDcMotor();  // keeps the pot controller the fan speed
}

void potContolServo() {
    int potVal = analogRead(POT);
    int servoAngle = map(potVal, 0, 4095, 15, 165);
    servo.write(servoAngle);
}

void setup() {
    pinMode(AIN1, OUTPUT);  // what does AIN1 represent?
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(POT, INPUT);
    Serial.begin(9600);

    // #2 for servo "attach" the pin
    servo.attach(SERVO_PIN);
}

void loop() {
    millisFanControl();
    // fan to rotate automaticlaly. back and forth
    // we want to pot to control speed

    // for (int angle = 15; angle <= 165; angle = angle + 5) {
    //     servo.write(angle);
    //     potControlDcMotor();
    //     delay(50);
    // }
    // for (int angle = 165; angle >= 15; angle = angle -5) {
    //     servo.write(angle);
    //     potControlDcMotor();
    //     delay(50);
    // }

    // potContolServo();

    // #3 change angle
    //  servo.write(15);        //15 deg angle
    //  delay(200);
    //  servo.write(100);
    //  delay(200);
    //  servo.write(165);
    //  delay(200);

    // potControlDcMotor();

    // what are the three things we need to make the motor spin?
    // #1 speed in PWM
    // #2, #3 are direction
    //  digitalWrite(AIN1, HIGH);
    //  digitalWrite(AIN2, LOW);
    //  analogWrite(PWMA, 255);
    //  delay(2000);
    //  digitalWrite(AIN1, LOW);
    //  digitalWrite(AIN2, LOW);
    //  analogWrite(PWMA, 255);
    //  delay(2000);
    //  digitalWrite(AIN1, LOW);
    //  digitalWrite(AIN2, HIGH);
    //  analogWrite(PWMA, 255);
    //  delay(2000);
    //  digitalWrite(AIN1, LOW);
    //  digitalWrite(AIN2, LOW);
    //  analogWrite(PWMA, 255);
    //  delay(2000);
}
