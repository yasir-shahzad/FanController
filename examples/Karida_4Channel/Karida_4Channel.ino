// Testing sketch for 50Hz !!!

#include <TimerOne.h>

unsigned char channel_1 = 7;    // Output to Opto Triac pin, channel 1
unsigned char channel_2 = 6;    // Output to Opto Triac pin, channel 2
unsigned char channel_3 = 5;    // Output to Opto Triac pin, channel 3
unsigned char channel_4 = 4;    // Output to Opto Triac pin, channel 4
unsigned char CH1, CH2, CH3, CH4;
unsigned char i=0;
unsigned char delay_time=25;     // delay ms or flashing SPEED
unsigned char clock_tick;        // variable for Timer1
unsigned char CHANNEL_SELECT;    // variable for channel select

unsigned char CH[]={CH1,CH2,CH3,CH4};

unsigned char dim_level[]={5,8,10,12,15,18,20,25,30,35,45,50,55,60,65,70,75,80,82,85,88,92,95};   // don't use this massive for 60Hz
                                                                                                  // create new massive for 60Hz
void setup() {

  pinMode(channel_1, OUTPUT);// Set AC Load pin as output
  pinMode(channel_2, OUTPUT);// Set AC Load pin as output
  pinMode(channel_3, OUTPUT);// Set AC Load pin as output
  pinMode(channel_4, OUTPUT);// Set AC Load pin as output
  attachInterrupt(1, zero_crosss_int, RISING);
  Timer1.initialize(100); // set a timer of length 100 microseconds for 50Hz or 83 microseconds for 60Hz; 
  Timer1.attachInterrupt( timerIsr ); // attach the service routine here
    
}

void timerIsr()
{    
    clock_tick++;
   
      if (CH[0]==clock_tick)
    {
      digitalWrite(channel_1, HIGH);   // triac firing
      delayMicroseconds(10);           // triac On propogation delay (for 60Hz use 8.33)
      digitalWrite(channel_1, LOW);    // triac Off 
    }  
    
      if (CH[1]==clock_tick)
    {
      digitalWrite(channel_2, HIGH);   // triac firing
      delayMicroseconds(10);           // triac On propogation delay (for 60Hz use 8.33)
      digitalWrite(channel_2, LOW);    // triac Off 
    }  
        
      if (CH[2]==clock_tick)
    {
      digitalWrite(channel_3, HIGH);   // triac firing
      delayMicroseconds(10);           // triac On propogation delay (for 60Hz use 8.33)
      digitalWrite(channel_3, LOW);    // triac Off 
    }  
    
      if (CH[3]==clock_tick)
    {
      digitalWrite(channel_4, HIGH);   // triac firing
      delayMicroseconds(10);           // triac On propogation delay (for 60Hz use 8.33)
      digitalWrite(channel_4, LOW);    // triac Off 
    }   
}

 

void zero_crosss_int()  // function to be fired at the zero crossing to dim the light
{
  // Every zerocrossing interrupt: For 50Hz (1/2 Cycle) => 10ms  ; For 60Hz (1/2 Cycle) => 8.33ms 
  // 10ms=10000us , 8.33ms=8330us
  
    clock_tick=0;        
}



void loop() {
 
 
for (CHANNEL_SELECT=0;CHANNEL_SELECT<4;CHANNEL_SELECT++)  // fade up
 {
  for (i=22;i>1;i--)
  {
    CH[CHANNEL_SELECT]=dim_level[i];
    delay(delay_time);
  } 
 }

delay(2000);

for (CHANNEL_SELECT=0;CHANNEL_SELECT<4;CHANNEL_SELECT++)  // fade down
 {
  for (i=0;i<22;i++)
  {
    CH[CHANNEL_SELECT]=dim_level[i];
    delay(delay_time);
  } 
 }
delay(1000);

}