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
      Serial.println((int)(event1.gyro.y*100));
      break;
      
     case 9:  // send back the IMU data
      
      Serial.println((int)(event.acceleration.x*100)); 
      Serial.println((int)(event.acceleration.y*100)); 
      Serial.println((int)(event.acceleration.z*100)); 
      Serial.println((int)(event1.gyro.x*100));
      Serial.println((int)(event1.gyro.y*100));
      Serial.println((int)(event1.gyro.z*100));
      //Serial.flush();
      break;
      
     case 10:   // read the current value of the prop1 position
      int pos1 = prop1.read();
      int pos2 = prop2.read();
      Serial.println(pos1);
      Serial.println(pos2);
     // Serial.flush();
      break;
     }
  }
//     setP = 0;
//     readP = 0;
  //Serial.flush();
  }
  Serial.flush();
}
