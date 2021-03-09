int LED1 = 0, LED2 = 1, LED3 = 13;

boolean LED1State=LOW;
boolean LED2State=LOW;
boolean LED3State=LOW;

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    Serial.println(data);

    if (data == 1){
      LED1State = !LED1State;
      digitalWrite(LED1,LED1State);
    }
    
    if (data == 2){
      LED2State = !LED2State;
      digitalWrite(LED2,LED2State);
  }
  
  if (data == 3){
      LED3State = !LED3State;
      digitalWrite(LED3,LED3State);
      }
  }
}
