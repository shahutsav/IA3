Servo myServo;

int fsr = A2;
int fsrValue = 0;    // Variable to hold the analog value.
int Servo_Pin = A5;
int servoPos = 100;
//proximity sensor
int proximity = A0;
int proximityValue = 0;

boolean door = false;

void setup() {
 Serial.begin(9600);
 myServo.attach( Servo_Pin );
 myServo.write(servoPos);

}

void loop() {
    proximityValue = analogRead(proximity);
    fsrValue = analogRead(fsr);
    //Serial.println(fsrValue);
    // Delay 10 milliseconds before the next reading:
    delay(1000);
    Serial.println(proximityValue);
    
    if(proximityValue > 1700){
    Serial.println("Four");
    for(servoPos = 100; servoPos < 200; servoPos+=1){
        myServo.write(servoPos);
        delay(40);
    }
    
        if(fsrValue > 50 && door == true){
        for(servoPos = 200; servoPos < 100; servoPos-=1){
        myServo.write(servoPos);
        delay(45);
            }
            
    }
    
    
        
    }
}
