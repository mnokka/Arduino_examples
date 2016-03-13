/*
Small Arduino Uno example

2 leds connected to Pins 12 and 11 (via 1k resistors)
Button connected to Pin 7 (10k pull-up, 100ohm to pin)

Leds are happily blinking (1s interval)
Pressing button echoes state change into Serial Monitor (long press)

This example is in public domain
mika.nokka1@gmail.com
 
 */

#define LED1 12  // Pin12
#define LED2 11  // Pin11
#define BUTTON 7 // Pin7

int i;  // first button read 
int i2; // second button read
int state; // current button state
int button=BUTTON; // Pin7 reads the button
int counter=0; // delay to print separator line 

// Reset initializing code
void setup() {
  pinMode(LED1, OUTPUT);  // Led1
  pinMode(LED2, OUTPUT);  // Led2
  pinMode(BUTTON, INPUT);    // Button
  Serial.begin(9600);
  state = 0; // set initial state
  Serial.println("Hello world! This is Arduino");
}

// Neverending loop
void loop() {
  i=digitalRead(button);
  delay(10);  // read twice with small delay to be sure
  i2=digitalRead(button);
  
  if (i==i2) {  
    if (i !=state) {  // Buttton state has been changed
        if (i == LOW) { // Pressed?
        Serial.println("*** Button pressed");
      } 
       if(i==HIGH) { // Released?
       Serial.println("--- Button released");
      }
      state=i2; // set new button state
    }
  }
  digitalWrite(12, HIGH);   // Led1 ON Led2 OFF
  digitalWrite(11, LOW);
  delay(1000);   // 1s wait
  counter=counter+1;
  if (counter>=10) {
    Serial.println("----------");  // sepator line every 10th time
    counter=0;
    }

  digitalWrite(12, LOW);    // Led1 OFF Led2 ON
  digitalWrite(11, HIGH);
  delay(1000);   // 1s wait
  
}
