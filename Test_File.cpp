#include "UW_GENE_121.h"
void LEDnumInitialise()
{
  for (int i=0; i<8; i++)
  {
    LEDnum(i);
    wait1Msec(10);
  }
  for (int i=7; i>=0; i--)
  {
    LEDnum(i);
    wait1Msec(10);
  }
}
//makes all the LEDs flash simultaneously, used to see if your code
//has reached a certain point.
void LEDflash()
{
  for(int i = 0;i<5; i++)
  {
    for(int i = 0;i<50; i++)
    {
      for(int i=0; i<8; i++)
      {
        LEDnum(i);
        wait1Msec(1);
      }
    }
    wait10Msec(50);
  }
}

//Button and Bumper test. Pressing the button or bumper will turn
//on an LED.  Once both are pressed, program terminates.
void testBUMPERandBUTTON()
{
  bool doneBump = false, doneBtn = false;
  while(!getSensor(BUMPER) && !getSensor(BUTTON))
    LEDnumInitialise();
  while(!doneBump && !doneBtn)
  {
    wait10Msec(10);
    LEDoff(RED_LED);
    LEDoff(GREEN_LED);
    LEDnum(0);
    if (getSensor(BUMPER))
    {
      LEDon(GREEN_LED);
      LEDnum(1);
      while(getSensor(BUMPER)) {}
      doneBump = true;
    }
    if (getSensor(BUTTON))
    {
      LEDon(RED_LED);
      LEDnum(2);
      while (getSensor(BUTTON)){}
      doneBtn = true;
    }
  }
}

void main(void)
{
  initialize();
  //Run the test you want here:
  //testBUMPERandBUTTON();
  //testMotor(MOTOR_A);
  //testMotor(MOTOR_B);
  //testREFLECT(1);
  //testREFLECT(2);
}


