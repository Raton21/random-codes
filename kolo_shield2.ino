/*
 * Code for exhibition of animated film in Prague, Czech Republic.
 * 
 * Using Motor Shield L298P controld 2 LED strips. 
 * 
 * After falling pulse, turns LED for specified time
 */
#define LEDPulse 1300  //LED on time (in microseconds)


#define sensorPin 2 
//Pins for L298P shield
#define enablePin1 12
#define brakePin1 9
#define enablePin2 13
#define brakePin2 8
#define LED1Pin 3
#define LED2Pin 11
//Determines status of LEDs
bool led = 0;


void setup() {
//Setting LED1
pinMode(enablePin1, OUTPUT); 
pinMode(brakePin1, OUTPUT); 
digitalWrite(enablePin1, HIGH); 
digitalWrite(brakePin1, LOW);  
//Setting LED2
pinMode(enablePin2, OUTPUT); 
pinMode(brakePin2, OUTPUT); 
digitalWrite(enablePin2, HIGH); 
digitalWrite(brakePin2, LOW);
//Setting sensor
pinMode(sensorPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(sensorPin), sensor, FALLING);  //Interrupt.. triggers, whenever switch is toggled
//turn off led on start
    digitalWrite(LED1Pin, LOW);
    digitalWrite(LED2Pin, LOW);

//Serial.begin(9600);
}
void LEDControl()
{
    digitalWrite(LED1Pin, led);
    digitalWrite(LED2Pin, led);
  //  Serial.println(led); 
}
void sensor()
{
  led = 1;
     // Serial.println("led"); 

}
void loop(){
  if (led == 1)
  {

    LEDControl();
    //delay(LEDPulse);
    delayMicroseconds(LEDPulse);
    led = 0;
    LEDControl();
  }
//Serial.println(digitalRead(sensorPin));
}
