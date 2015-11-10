#include <Wire.h>
#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20_U.h>

/*Accelerometer instance*/
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
/*Gyro instance*/ 
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);
/*Servo instances for props*/
Servo prop1;
Servo prop2;
Servo prop3;
Servo prop4;

byte Byte1;
byte Byte2;
byte Byte3;

/*Sensor event for arduino*/
sensors_event_t event;
  
/*The above function returns prints the Gyro data for a given axis 0:x 1:y 3:z*/
void getGyroData(byte axis);
void getGyroAll();


/*The above function returns prints the Accelerometer data for a given axis 0:x 1:y 3:z*/
void getAccelData(byte axis);
void getAccelAll();

/*This function sets a prop speed using two inputs int prop: the prop number 1-4 int value: the prop speed from a value of 0-180 for 0 being lowest speed and 180 being full speed*/
void setPropSpeed(byte prop, int value);

void setup(void) 
{
  Serial.begin(9600);
  
  /* Enable auto-ranging */
  gyro.enableAutoRange(true);
  
  /* Initialise the sensors */
  if(!gyro.begin())
  {
    /* There was a problem detecting the L3GD20 ... check your connections */
    //Serial.println("Ooops, no L3GD20 detected ... Check your wiring!");
    while(1);
  }
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    //Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
  
  
  prop1.attach(2);
  prop2.attach(5);
  prop3.attach(8);
  prop4.attach(11);
  
  pinMode(3,OUTPUT);
  digitalWrite(3,HIGH);
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
  
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);
  
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  
  //Serial.println("Successfull bootup");
  prop1.write(10);
  delay(1000);
  prop1.write(170);
  delay(1000);
  prop1.write(10);
  prop2.write(10);
  delay(1000);
  prop2.write(170);
  delay(1000);
  prop2.write(10);
  
}

void loop(void) 
{ 
 // if(Serial.available() == 3){
    Byte1 = Serial.read();
    Byte2 = Serial.read();
    Byte3 = Serial.read();
    //digitalWrite(13,HIGH);
    //delay(500);
    //digitalWrite(13,LOW);
    /*if(Byte1 == 0){
      /*This function input stands for read with the second input being sensor*/
      /*switch(Byte2){
        case 0:
        switch(Byte3){
              case 0:
              case 1:
              case 2: 
                getAccelData(Byte3);
                break;
              case 3:
                getAccelAll();
                break;
              default:
                getAccelAll();
                break;
            }
          break;
        case 1:
          switch(Byte3){
              case 0:
              case 1:
              case 2: 
                getGyroData(Byte3);
                break;
              case 3:
                getGyroAll();
                break;
              default:
                getGyroAll();
                break;
            }
          break; 
      }
    } else if(Byte1 == 1) {
      setPropSpeed(Byte2,Byte3);
    }
    */
    
    /*Serial print a new line as well as flush the input*/
   // Serial.println("");
   // Serial.flush();
 // }

}

void getGyroData(byte axis){
  /* Get a new sensor event */
   gyro.getEvent(&event);
 
  /* Display the results (speed is measured in rad/s) */
  switch(axis){
    case 0:
      Serial.print(int(event.gyro.x*100));
      break;
    case 1:
      Serial.print(int(event.gyro.y*100));
      break;
    case 2:
      Serial.print(int(event.gyro.z*100));
      break;
    default:
      //Serial.print("Input axis not valid please select 0-2");
      break;
  }
}

void getGyroAll(){
  /* Get a new sensor event */
   gyro.getEvent(&event);
   
   /*Print all axis value in order x y z*/
   Serial.print(int(event.gyro.x*100));
   Serial.print(int(event.gyro.y*100));
   Serial.print(int(event.gyro.z*100));
}

void getAccelData(byte axis){
  /* Get a new sensor event */
  accel.getEvent(&event);
  
  
  switch(axis){
    case 0:
    Serial.print(int(0.256*100));
//      Serial.print(int(event.acceleration.x*100));
      break;
    case 1:
      Serial.print(int(event.acceleration.y*100));
      break;
    case 2:
      Serial.print(int(event.acceleration.z*100));
      break;
  }
}

void getAccelAll(){
  /* Get a new sensor event */
   
   accel.getEvent(&event);
   
   /*Print all axis value in order x y z*/
   Serial.print(int(event.acceleration.x*100));
   Serial.print(int(event.acceleration.y*100));
   Serial.print(int(event.acceleration.z*100));
}

void setPropSpeed(byte prop, int value){
 switch (prop) {
        case 0:
           prop1.write(value);
           break;
        case 0x1:
           prop2.write(value);
           break;
        case 0x2:
           break;
        case 0x3:
           break;
        default:
          //Serial.print("Error: Prop ");Serial.print(prop,HEX);Serial.print(" not programmed");
          break;  
 }
}
