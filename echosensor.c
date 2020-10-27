/****************************************************************************************************************************************
* 
* Class: CSC-615-01 Spring 2020
*
* Name: Daisy Sanchez
* 
* Project: Echo Sensor - Tapeless Ruler 
* 
* File: echosensor.c
*
* Desription: We are going to measure the distance of an object by using the Echo Sensor (HC-SR04). We will display the distance
* in centimeters. We will connect the echo sensor to the ultrasonic pins. 
*
*****************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

//set GPIO pins
#define echo 22
#define trig 21

//measures distance
double distance (){

//set trig to LOW
 digitalWrite(trig, LOW);

 //delays trig
 delay(500);

 //set trig to HIGH
 digitalWrite(trig, HIGH);

 //delays trig
  delay(0.05);

 //set trig to LOW
 digitalWrite(trig, LOW);

clock_t start_t;
clock_t end_t;
double total_t;

//saves start time 
while(digitalRead(echo) == 0){
    start_t = clock();
    
}

//saves end time
while(digitalRead(echo) == 1){
   end_t = clock();
  
} 

//saves the total time 
total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   
//measures distance
return (total_t * 17000);

}


int main (void){

     if( wiringPiSetup() == -1){
       exit(0);
     
     }else{
        pinMode(echo, INPUT);
      pinMode(trig, OUTPUT);
    }
    while(1){
        double dist = distance();
        printf("Distance: %f\n", dist);
        
    }
  return  0;
} 
