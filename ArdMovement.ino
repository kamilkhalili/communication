// Setup PWM Pins
int pwmL1=3, pwmL2=5, pwmR1=9, pwmR2=10;  

void setup() {
  // put your setup code here, to run once:

/*-------------Setup Motor----------------*/
pinMode(pwmL1,OUTPUT);digitalWrite(pwmL1,LOW);
pinMode(pwmL2,OUTPUT);digitalWrite(pwmL2,LOW);
pinMode(pwmR1,OUTPUT);digitalWrite(pwmR1,LOW);
pinMode(pwmR2,OUTPUT);digitalWrite(pwmR2,LOW);

/*-------------Setup Serial----------------*/
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    Serial.println(data);

    if (data == 'w'){
     forward(150,150);
    }
    
    if (data == 'a'){
      left(150,150);
  }
  
  if (data == 's'){
      backwards(150,150);
      }
      
  if (data == 'd'){
      right(150,150);
      }
  }
}

/*-------------Setup Movement-------------*/

void forward (int speed1,int speed2){
  digitalWrite(pwmL2,0); analogWrite(pwmL1,speed1);
  digitalWrite(pwmR2,0); analogWrite(pwmR1,speed1);
}

void backwards (int speed1,int speed2){
  digitalWrite(pwmL1,0); analogWrite(pwmL2,speed1);
  digitalWrite(pwmR1,0); analogWrite(pwmR2,speed1);
}

void left (int speed1,int speed2){
  digitalWrite(pwmL1,0); analogWrite(pwmL2,speed1);
  digitalWrite(pwmR2,0); analogWrite(pwmR1,speed1);
}

void right (int speed1,int speed2){
  digitalWrite(pwmL2,0); analogWrite(pwmL1,speed1);
  digitalWrite(pwmR1,0); analogWrite(pwmR2,speed1);
}
