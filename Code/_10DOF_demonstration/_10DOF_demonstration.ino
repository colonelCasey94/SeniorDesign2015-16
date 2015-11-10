#include <Wire.h>
#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);

Servo prop1;
Servo prop2;
int readP1;
int readP2;
int setP;
int pos1,pos2;

void printFloat(float temp);

void setup(void) 
{
  Serial.begin(230400);  
  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("No LSM303 detected");
    while(1);
  }
  
  /* Enable auto-ranging */
  gyro.enableAutoRange(true);
  
  /* Initialise the sensor */
  if(!gyro.begin())
  {
    /* There was a problem detecting the L3GD20 ... check your connections */
    Serial.println("Ooops, no L3GD20 detected ... Check your wiring!");
    while(1);
  }
  Serial.println('a');
  char a = 'b';
  while(a != 'a')
  {
    a = Serial.read();
  }
  prop1.attach(3);
  prop2.attach(9);
  prop1.write(0);
  prop2.write(0);
  delay(500);
}

void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);
  sensors_event_t event1;
  gyro.getEvent(&event1);
  if(Serial.available() >= 3){
    setP = Serial.parseInt();
    readP1 = Serial.parseInt();
    readP2 = Serial.parseInt();
    Serial.flush();
  if(setP > 0)
  {   
     switch(setP)
     {
     case 1: // set the postion or velocity to the motors
      prop1.write(readP1);
      prop2.write(readP2);
      printFloat(event.acceleration.y);
      break;
      
      
      
     case 9:  // send back the IMU data
      
      printFloat(event.acceleration.x); 
      printFloat(event.acceleration.y); 
      printFloat(event.acceleration.z); 
      printFloat(event1.gyro.x);
      printFloat(event1.gyro.y);
      printFloat(event1.gyro.z);
      //Serial.flush();
      break;
      
     case 10:   // read the current value of the prop1 position
      pos1 = prop1.read();
      pos2 = prop2.read();
      Serial.println(pos1);
      Serial.println(pos2);
     // Serial.flush();
      break;
      
      case 11:
      printFloat(4.3);
      printFloat(3.4);
      break;
     }
  }
//     setP = 0;
//     readP = 0;
  //Serial.flush();
  }
  Serial.flush();
}

void printFloat(float temp){
 byte *b = (byte *) &temp;
 Serial.write(b,4);
 return; 
}
