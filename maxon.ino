const int dir = 8;
const int pwm = 2;
char read;
const int standardPWM = 10;
volatile int count = 0;
volatile int setCount = -1;

//void incrementCount(void);

void setup()
{
  Serial.begin(57600);
  pinMode(dir, OUTPUT);
  pinMode(pwm, OUTPUT);
  //digitalWrite(dir, LOW); LOW = down, HIGH = up
  //analogWrite(pwm, 255);  pwm range 30-255

  attachInterrupt(digitalPinToInterrupt(20), incrementCount, CHANGE);
  attachInterrupt(digitalPinToInterrupt(21), incrementCount, CHANGE);
}

void loop()
{
  //Serial.println("loop");
  while (Serial.available()) 
  {
    Serial.println("read");
    char c = Serial.read();  //gets one byte from serial buffer
    read = c;
    
    if(read == 'D')
    {
      Serial.println("Drive to?");
      while(!Serial.available())
      {}
      int angle = Serial.parseInt();  //gets one byte from serial buffer
      if(angle > 0)
      {
        digitalWrite(dir, HIGH); 
      }
      else
      {
        digitalWrite(dir, LOW);
      }
      //int angle = read;
      count = 0;     
      setCount = angle/.36;  //1000 counts/rev 

      Serial.print("angle:");Serial.print(angle);
      Serial.print(" set:");Serial.println(setCount);
      analogWrite(pwm, standardPWM);
    }

    if(read == 'u') //UP
    {
      Serial.println('u');
      analogWrite(pwm, standardPWM);
      digitalWrite(dir, HIGH);
      setCount = 1000;
    }

    if(read == 'd') //DOWN
    {
      Serial.println('d');
      analogWrite(pwm, standardPWM);
      digitalWrite(dir, LOW);
      setCount = 1000; 
    }

    if(read == 'o') //OFF
    {
      Serial.println('o');
      analogWrite(pwm, 0);
    }
    Serial.println("exit");
  }
}

void incrementCount()
{
  if(setCount <= 0)
  {
    return;
  }
  Serial.println(count);
  count += 1;
  if(count > setCount)
  {
    Serial.println("target reached");
    analogWrite(pwm, 0);
    setCount = -1;
    count = 0;        
  }
}
