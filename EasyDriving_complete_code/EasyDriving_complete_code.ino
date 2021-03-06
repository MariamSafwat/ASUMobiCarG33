 char state;
int IN_1=4; //left motor
int IN_2=5; //left motor
int IN_3=6; //right motor
int IN_4=7; //right motor
int TriggerPin=13;
int EchoPin=12;
long duration , distance;
void setup() {
 pinMode(IN_1,OUTPUT);
 pinMode(IN_2,OUTPUT);
 pinMode(IN_3,OUTPUT);
 pinMode(IN_4,OUTPUT);
 pinMode(TriggerPin,OUTPUT);
 pinMode(EchoPin,INPUT);
 Serial.begin(9600);
}

void left()
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,HIGH);
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,LOW);
  }

 void right()
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,HIGH);
  }

  void forward()
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,LOW);
  }
   void rightforward()
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,LOW);
  }
   void rightbackward()
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,HIGH);
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,HIGH);
  }
  void backward()
  {
    digitalWrite(IN_1,LOW);
    digitalWrite(IN_2,HIGH);
    digitalWrite(IN_3,LOW);
    digitalWrite(IN_4,HIGH);
  }

  void leftforward()
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,LOW);
  }
  void leftbackward()
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,HIGH);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,HIGH);
  }
   void Stop()
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,LOW);
  }
  
void loop() {
  while(Serial.available()>0)
  {
    state=Serial.read();
    if (state=='L')
    {
     left();
     
      }

      if (state=='R')
    {
      right();
      }

      if (state=='G')
    {
      leftforward();
      }

     if(state=='F')
     {
      forward();
     }
     if (state=='B')
     {
      backward();]
     }

      if (state=='S')
    {
       Stop();
      }
      if (state=='J')
      {
        rightbackward();
      }
      if (state=='I')
      {
        rightforward();
      }
      if (state=='H')
      {
        leftbackward();
        
      }
      
    }
 digitalWrite(TriggerPin,LOW);
 delayMicroseconds(2);
 digitalWrite(TriggerPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(TriggerPin,LOW);
 duration= pulseIn(EchoPin,HIGH);
 distance = duration*0.034/2;
 if ( distance <= 10 )
 {
  Stop();
 }

}
