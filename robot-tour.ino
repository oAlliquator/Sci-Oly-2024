#define PWMA 5    // Controls power to right motor
#define PWMB 6    // Controls power to left motor
#define AIN 7     // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define BIN 8     // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define STBY 3    // Place H-Bridge in standby if LOW, Run if HIGH

#define modeSwitch 2 // Mode Switch input
//init the car
void setup() {
  
  pinMode(PWMA, OUTPUT);     //set IO pin mode OUTPUT
  pinMode(PWMB, OUTPUT);
  pinMode(BIN, OUTPUT);
  pinMode(AIN, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);  //Enable Motors to run
  digitalWrite(PWMA, LOW);  // Fully on 
 // digitalWrite(PWMA, HIGH);  // Fully on
}



void stopTime(int mS){
  digitalWrite(STBY, LOW);   // Go into standby
  delay(mS);                //  Wait defined time
  digitalWrite(STBY, HIGH);  //  Come out of standby
}

// max speed is 255
// manually input time and speed
void forward(int dist){
  digitalWrite(AIN, HIGH);    // Forward direction on Right
  digitalWrite(BIN, HIGH);    // Forward direction on Left
  if (dist == 25){
    analogWrite(PWMA, 140);   // Full power on Right
    analogWrite(PWMB, 140);
    delay(700);   
    stopTime(700);
    digitalWrite(PWMA, LOW);   // No power on Right
    digitalWrite(PWMB, LOW);   // No power on Left
    delay(2000);
  } else if (dist == 50){
    analogWrite(PWMA, 140);   // Full power on Right
    analogWrite(PWMB, 140);
    delay(910);   
    stopTime(910);
    digitalWrite(PWMA, LOW);   // No power on Right
    digitalWrite(PWMB, LOW);   // No power on Left
    delay(2000);
  }
}

void backward(int dist){
  digitalWrite(AIN, LOW);    // backward direction on Right
  digitalWrite(BIN, LOW);    // backward direction on Left
  if (dist == 25){
    analogWrite(PWMA, 140);   // Full power on Right
    analogWrite(PWMB, 140);
    delay(700);   
    stopTime(700);
    digitalWrite(PWMA, LOW);   // No power on Right
    digitalWrite(PWMB, LOW);   // No power on Left
    delay(2000);
  } else if (dist == 50){
    analogWrite(PWMA, 140);   // Full power on Right
    analogWrite(PWMB, 140);
    delay(910);   
    stopTime(910);
    digitalWrite(PWMA, LOW);   // No power on Right
    digitalWrite(PWMB, LOW);   // No power on Left
    delay(2000);
  }
}

void left(){
  digitalWrite(AIN, HIGH);    // Forward direction
  analogWrite(PWMA, 150);   // Full power
  delay(585);              //delay 2000mS
  stopTime(585);
  digitalWrite(PWMA, LOW);   // No power on Right
  delay(2000);              //delay 2000mS
}

void right(){
  digitalWrite(BIN, HIGH);    // Forward direction
  analogWrite(PWMB, 150);   // Full power
  delay(540);
  stopTime(540);
  digitalWrite(PWMB, LOW);
  delay(2000);              //delay 2000mS
}

void loop() {
  while (digitalRead(modeSwitch) == 1);
  delay(2000);
  forward(50);
  forward(50);
  forward(50);
  delay(100000);
  forward(25);
  right();
  forward(50);
  left();
  forward(50);
  right();
  forward(50);
  left();
  forward(50);
  left();
  forward(50);
  right();
  forward(50);
  backward(50);
  left();
  forward(50);
  forward(50);
  right();
  forward(50);
  right();
  forward(50);
}