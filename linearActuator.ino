const int dir = 10;
const int pwm = 9;
char read;
const int standardPWM = 200;


void setup()
{
  Serial.begin(9600);
  pinMode(dir, OUTPUT);
  pinMode(pwm, OUTPUT);
  //digitalWrite(dir, LOW); LOW = down, HIGH = up
  //analogWrite(pwm, 255);  pwm range 30-255
}

void loop()
{  
  while (Serial.available()) 
  {
    char c = Serial.read();  //gets one byte from serial buffer
    read = c;
    
    if(read == 'u') //UP
    {
      Serial.println('u');
      analogWrite(pwm, standardPWM);
      digitalWrite(dir, HIGH); 
    }

    if(read == 'd') //DOWN
    {
      Serial.println('d');
      analogWrite(pwm, standardPWM);
      digitalWrite(dir, LOW); 
    }

    if(read == 'o') //OFF
    {
      Serial.println('o');
      analogWrite(pwm, 0);
    }
  }
}

