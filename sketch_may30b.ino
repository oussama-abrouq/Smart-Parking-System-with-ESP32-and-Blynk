// Definition of Blynk connection information
#define BLYNK_TEMPLATE_ID "*********"
#define BLYNK_TEMPLATE_NAME "********"
#define BLYNK_AUTH_TOKEN "*******************************"
#define BLYNK_PRINT Serial

// Including necessary libraries
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h> // Include the LiquidCrystal_I2C library
#include <Wire.h>

// Initializing the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Declaration of the Blynk timer
BlynkTimer timer;

// Wi-Fi connection information
char ssid[] = "*********";
char pass[] = "*********";

// Declaration of pins for LEDs and IR sensors
int led1, led2, led3;
int servoPin1 = 23;
int servoPin2 = 18;
int ir_enter = 5;
int ir_back = 4;
int ir_car1 = 32;
int ir_car2 = 35;
int ir_car3 = 34;

// Variables for IR sensor states
int car1, car2, car3;

// Number of available parking slots
int slot = 3;

// Declaration of Servo objects
Servo servo1;
Servo servo2;

// Function to send IR sensor data to Blynk
void myTimerEvent() {
    Blynk.virtualWrite(V0, car1);
    Blynk.virtualWrite(V1, car2);
    Blynk.virtualWrite(V2, car3);
    if(car2 == 0){
      Serial.print("car1 read");
    }
    if(car3 == 0){
      Serial.print("car2 read");
    }
    if(car1 == 0){
      Serial.print("car3 read");
    }
}

void setup() {
  Serial.begin(9600);

  // Initializing the LCD display
  lcd.init();
  lcd.backlight();

  // Connecting to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Configuring IR sensor pins as inputs
  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);
  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);

  // Attaching the servos to the respective pins
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

  // Setting a time interval for sending data to Blynk
  timer.setInterval(500L, myTimerEvent);

  // Displaying a welcome message on the LCD screen
  lcd.setCursor(0, 0);
  lcd.print("     oussama's    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING SYSTEM ");
  delay(2000);
  lcd.clear();
  delay(3000);
}

void loop() {
    // Reading the states of the IR sensors
    car1 = digitalRead(ir_car1);
    car2 = digitalRead(ir_car2);
    car3 = digitalRead(ir_car3);

    // Executing Blynk and timer functions
    Blynk.run();
    timer.run();

    // Managing the back barrier
    if (digitalRead(ir_back) == 0 ) {
        servo1.write(90);
        delay(2000);
        slot++;
    } 
    if (digitalRead(ir_back) == 1 ) {
        servo1.write(0);
        delay(1000);
    } 

    // Managing the front barrier
    if (digitalRead(ir_enter) == 0 ) {
      if(slot > 0){
        servo2.write(90);
        delay(2000);
        slot--;
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print("    SORRY :(    ");  
        lcd.setCursor(0, 1);
        lcd.print("  Parking Full  "); 
        delay(3000);
        lcd.clear(); 
      }
    } 
    if (digitalRead(ir_enter) == 1 ) {
        servo2.write(0);
        delay(1000);
    }

    // Updating the LCD display
    lcd.setCursor(0, 0);
    lcd.print("    WELCOME!    ");
    lcd.setCursor(0, 1);
    lcd.print("Slot Left: ");
    lcd.print(slot);
}
