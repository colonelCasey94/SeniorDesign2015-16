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

/*Global Variables for recieved data*/
byte ByteHighRec;
byte ByteLowRec;
byte lowNibleRec;
byte highNibleRec;

/*The above function returns prints the Gyro data for a given axis 0:x 1:y 3:z*/
void getGyroData(int axis);
void getGyroAll();


/*The above function returns prints the Accelerometer data for a given axis 0:x 1:y 3:z*/
void getAccelData(int axis);
void getAccelAll();

/*This function sets a prop speed using two inputs int prop: the prop number 1-4 int value: the prop speed from a value of 0-180 for 0 being lowest speed and 180 being full speed*/
void setPropSpeed(int prop, int value);

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
  digitalWrite(13,LOW);
  
  //Serial.println("Successfull bootup");
  prop1.write(10);
  delay(1000);
  prop1.write(170);
  delay(1000);
  prop1.write(10);
  
}

void loop(void) 
{ 
  if(Serial.available() == 2){
    ByteHighRec = byte(Serial.read());
    ByteLowRec = byte(Serial.read());
    highNibleRec = (ByteHighRec>>4)&0xF;
    lowNibleRec = ByteHighRec&0xF;
    if(ByteHighRec == 0x55){
      /*This function input stands for read with the second input being sensor*/
      highNibleRec = (ByteLowRec>>4)&0xF;
      lowNibleRec = ByteLowRec&0xF;
      switch(highNibleRec){
        case 4:
        switch(lowNibleRec){
              case 0:
              case 1:
              case 2: 
                getAccelData(int(lowNibleRec));
                break;
              case 3:
                getAccelAll();
                break;
              default:
                getAccelAll();
                break;
            }
          break;
        case 3:
          switch(lowNibleRec){
              case 0:
              case 1:
              case 2: 
                getGyroData(int(lowNibleRec));
                break;
              case 3:
                getGyroAll();
                break;
              default:
                getGyroAll();
                break;
            }
          break;
        default:
          //Serial.print("Error: sensor ");Serial.print(highNibleRec,HEX);Serial.print(" not programmed");
          break; 
      }
    } else if(highNibleRec == 0x6) {
      setPropSpeed(int(lowNibleRec),int(ByteLowRec));
    } else {
      /*Print function error*/
      //Serial.print("Error: Recieved Fucntion ");Serial.print(ByteHighRec,HEX);Serial.print(" not programmed");
    }
    
    
    /*Serial print a new line as well as flush the input*/
    Serial.println("");
    Serial.flush();
  }

}

void getGyroData(int axis){
  /* Get a new sensor event */
   sensors_event_t event;
   gyro.getEvent(&event);
 
  /* Display the results (speed is measured in rad/s) */
  switch(axis){
    case 0:
      Serial.print(event.gyro.x);
      break;
    case 1:
      Serial.print(event.gyro.y);
      break;
    case 2:
      Serial.print(event.gyro.z);
      break;
    default:
      //Serial.print("Input axis not valid please select 0-2");
      break;
  }
}

void getGyroAll(){
  /* Get a new sensor event */
   sensors_event_t event;
   gyro.getEvent(&event);
   
   /*Print all axis value in order x y z*/
   Serial.print(event.gyro.x);
   Serial.print(event.gyro.y);
   Serial.print(event.gyro.z);
}

void getAccelData(int axis){
  /* Get a new sensor event */
   sensors_event_t event;
   accel.getEvent(&event);
  
  
  switch(axis){
    case 0:
      Serial.print(event.acceleration.x);
      break;
    case 1:
      Serial.print(event.acceleration.y);
      break;
    case 2:
      Serial.print(event.acceleration.z);
      break;
    default:
      //Serial.print("Input axis not valid please select 0-2");
      break;
  }
}

void getAccelAll(){
  /* Get a new sensor event */
   sensors_event_t event;
   accel.getEvent(&event);
   
   /*Print all axis value in order x y z*/
   Serial.print(event.acceleration.x);
   Serial.print(event.acceleration.y);
   Serial.print(event.acceleration.z);
}

void setPropSpeed(int prop, int value){
 Serial.print(prop,HEX);
 switch (prop) {
        case 0:
           
           Serial.print(value);
           prop1.write(value);
           break;
        case 0x1:
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
