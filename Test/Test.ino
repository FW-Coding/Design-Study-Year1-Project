#include <Stepper.h>
#include <Servo.h>
#include <Keypad.h>

//Keyboard setup
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','A','3'},
  {'4','5','B','6'},
  {'7','8','C','9'},
  {'*','0','D','#'}
};

byte rowPins[ROWS] = {24, 26, 28, 30}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {32, 34, 36, 38}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// change this to the number of steps on your motor
#define STEPS 100

//define the number of steps for a full rotation of the servo motors
int StepsPerRevolution = 2048;
int motSpeed = 10;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);
Stepper stepper2(STEPS, 17, 16, 15, 14);
Servo feed_servo;
Servo test_servo;

// the previous reading from the analog input
int previous = 0;

void setup() {
  Serial.begin(9600);
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(200);
  stepper2.setSpeed(200);
  feed_servo.attach(4);
  test_servo.attach(5);
  delay(100);

  


  
}

void loop() {
  //feed_servo.write(10);
  //test_servo.write(20);
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }

  if (key == '#') {
    for (int i = 0; i < 1; i++ ){
 //   delay(1000);
      feed_servo.write(0);
      delay(2000);
      feed_servo.write(180);
      delay(2000);
      test_servo.write(0);
      delay(2000);
      test_servo.write(180);
      delay(2000);
      stepper.step(StepsPerRevolution*3);
    }
  }
 }