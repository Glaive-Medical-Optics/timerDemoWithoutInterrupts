/* 
 *    This demo program shows how to call a routine periodically every n seconds (for a specified value of n)
 *    on an Arduino Giga R1 board without using interrupts.
 *    
 *    Author: Glaive Software Group
 *    Revised: 8/1/2024.
 *    
 *    The routine "doIt" will get called repeatedly.
 *    For this demo, it will get called every 10 seconds.
 *    You can change the interval by setting the variable "interval" to the 
 *    desired time in milliseconds.
 *    
 *    You must open the Serial Monitor.
 *    This demo prints "Routine called." on the serial monitor every 10 seconds.
 *    
 *    This program is Free Software and has ABSOLUTELY NO WARRANTY.
 */

uint32_t  interval = 10000;     // Interval in milliseconds (10 seconds by default)
uint32_t  prevTime  = 0;        // last time doit() was called
uint32_t  currTime  = 0;

/*
 *    This routine will get called every 10 seconds.
 */

void doIt()
{
      Serial.println("Routine called.");
}

void setup()
{
      Serial.begin(9600);
      while (!Serial) ; // Wait for serial monitor to open
      Serial.println("starting!");
}

void loop()
{
    // Check if 10 seconds have passed since last doit() call
    currTime=millis();
    if (currTime - prevTime > interval)
    {
        doIt();
        prevTime=currTime;
    }
}
