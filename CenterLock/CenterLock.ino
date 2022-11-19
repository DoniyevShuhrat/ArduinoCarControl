#define btnPin1 2
#define btnPin2 3
#define out1 5
#define out2 6
short durationOfTime = 500;
unsigned long timeTaken;
unsigned long timeTakenBlink;
bool statusR = false;
bool statusL = false;
void RightMotor(){
  digitalWrite(out1, HIGH);
  digitalWrite(out2, LOW);
}
void LeftMotor(){
  digitalWrite(out1, LOW);
  digitalWrite(out2, HIGH);
}
void StopMotor(){
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
}
void setup() {
  pinMode(btnPin1, INPUT_PULLUP);
  pinMode(btnPin2, INPUT_PULLUP);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(14, OUTPUT);

  Serial.begin(9600);
  Serial.println("Setup End...");
}
void loop() {
  if(millis() - timeTakenBlink >= 500){
    digitalWrite(14, !digitalRead(14));
    timeTakenBlink = millis();
  }
  bool btnStatus1 = false;
  bool btnStatus2 = false;
  
  //------------Button1 Push----------------------
  if(!digitalRead(btnPin1) == true){
    Serial.println("RightBtn = Clicked");
    btnStatus1 = true;
  }
  if(btnStatus1 == true && !digitalRead(btnPin1) == false){
    btnStatus1 = false;
    statusR = true;
    timeTaken = millis();
    RightMotor();
    Serial.print("statusR:");
    Serial.print(statusR);
    Serial.print("\tmillis():");
    Serial.print(millis());
    Serial.println("\tRightBtn => durationOfTime = millis()");
  }
  //------------Button2 Push----------------------
  if(!digitalRead(btnPin2) == true){
    btnStatus2 = true;
    Serial.println("\tLeftBtn = Clicked");
  }
  if(btnStatus2 == true && !digitalRead(btnPin2) == false){
    btnStatus2 = false;
    statusL = true;
    timeTaken = millis();
    LeftMotor();
    Serial.print("statusL:");
    Serial.print(statusL);
    Serial.print("\tmillis():");
    Serial.print(millis());
    Serial.println("\tLeftBtn => durationOfTime = millis()");
  }
  //----------------------------------------------
  if(millis() - timeTaken >= durationOfTime && statusR == true){
    StopMotor();
    statusR = false;
    Serial.print("statusR:");
    Serial.print(statusR);
    Serial.print("\tmillis():");
    Serial.print(millis());
    Serial.println("\tRightBtn => StopMotor()");
  }
  if(millis() - timeTaken >= durationOfTime && statusL == true){
    StopMotor();
    statusL = false;
    Serial.print("statusL:");
    Serial.print(statusL);
    Serial.print("\tmillis():");
    Serial.print(millis());
    Serial.println("\tLeftBtn => StopMotor()");
  }
}
