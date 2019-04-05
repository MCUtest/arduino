const int dir = 10;
const int pwm = 9;
char read;
const int standardPWM = 255;
const int pwrSwitch = 7;
const int dirSwitch = 13;


void setup()
{
  Serial.begin(9600);
  pinMode(dir, OUTPUT);
  pinMode(pwm, OUTPUT);
  //digitalWrite(dir, LOW); LOW = down, HIGH = up
  //analogWrite(pwm, 255);  pwm range 30-255

  pinMode(pwrSwitch, INPUT_PULLUP);
  pinMode(dirSwitch, INPUT_PULLUP);
}

void loop()
{
  if (!digitalRead(dirSwitch))  //if on position
  {
    digitalWrite(dir, HIGH);
  }
  else {
    digitalWrite(dir, LOW);
  }

  if (!digitalRead(pwrSwitch))  //if on position
  {
    analogWrite(pwm, standardPWM);
    Serial.print("on");
    Serial.println(digitalRead(pwrSwitch));    
  }
  else {
    analogWrite(pwm, 0);
  }
}
