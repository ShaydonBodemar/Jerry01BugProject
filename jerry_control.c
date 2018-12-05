//ENGR 102 Bug Project    Shaydon, Erick, Cononor, Daniella   Jerry the Bug
//Motor Controls
//This is the program directly interacting with the bug (back-end)

#include<stdio.h>
#include<wiringPi.h>

//Use a global variable "flag" to indicate motor CW, CCW, STOP.
int flag1;
int flag2;
//Define function prototypes for running motor CW, CCW, and STOP

void motor1CW(void);
void motor1CCW(void);
void motor1STOP(void);

void motor2CW(void);
void motor2CCW(void);
void motor2STOP(void);

int main(){
  wiringPiSetup();
  //Set up GPIO 23 and GPIO 26 as PWM outputs

  pinMode(23,PWM_OUTPUT);
  pinMode(26,PWM_OUTPUT);

  //Set up GPIO4, GPIO5, and GPIO6 as inputs for button inputs

  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  while(1){
    //ISR when GPIO4, GPIO5, and GPIO6 exhibits a HIGH to LOW transition
    wiringPiISR(4,INT_EDGE_FALLING,&motorCW);
    wiringPiISR(5,INT_EDGE_FALLING,&motorSTOP);
    //ENGR 102 Button Activated Motor Program 2
    wiringPiISR(6,INT_EDGE_FALLING,&motorCCW);
    //Conditional using switch statement depending on variable "flag"
    switch(flag){
      case 0:{ //STOP
      pwmWrite(23,0);
      pwmWrite(26,0);
      delay(200);
      printf(" 1--stop ");
      break;
      }
      
      case 1:{ //CW rotation
      pwmWrite(23,0);
      pwmWrite(26,0);
      delay(200);
      pwmWrite(23,1000);
      printf(" 2--CW ");
      break;
      }
      
      case 2:{ //CCW rotation
      pwmWrite(23,0);
      pwmWrite(26,0);
      delay(200);
      pwmWrite(26,1000);
      printf(" 3--CCW ");
      
      break;
      }
      
    default: printf("\n\n---ERROR---\n\n");
    }
    
  }

return(0);
}

//The functions set the flag variable that is used in the switch conditional
//in the main program
void motorCW(void){
  flag=1;
}

void motorCCW(void){
  flag=2;
}

void motorSTOP(void){
  flag=0;
}
