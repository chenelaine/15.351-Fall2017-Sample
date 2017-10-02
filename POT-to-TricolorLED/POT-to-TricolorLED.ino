#define POTENTIOMETER A0
#define BLUEPIN    10
#define GREENPIN   11
#define REDPIN     12
#define YELLOWLED  13

#define POTRES 1023
#define POTMIDPOINT 512
#define MAXCOLOR 255


void setup() {
  // setup LEDs to be output pins
  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

 // turn on the yellow LED
  digitalWrite( YELLOWLED, HIGH);
  
}

//writeRGB(enter a hex number)
void writeRGB(int R, int G, int B)
{
  analogWrite(REDPIN, R);
  analogWrite(GREENPIN, G);
  analogWrite(BLUEPIN, B);
}

// truncate with limits
int truncate (int input, int lowerLimit, int upperLimit)
{
  int output;
  output = (input < lowerLimit) ? lowerLimit : input;
  output = (input > upperLimit) ? upperLimit : input;
  return output;
}

void loop() {
  // put your main code here, to run repeatedly:
  float analogIn = analogRead (POTENTIOMETER);
 
  int R, G, B;

  // between 0 and 512 - interpolate between red and green
  if (analogIn < POTMIDPOINT)
  {
    // integer math!!
    G =  (float)(analogIn  * MAXCOLOR ) / (float) POTMIDPOINT;
    R = MAXCOLOR - G;
    B = 0;
  }
  else 
  {
    R = 0;
    B = (float)(analogIn - POTMIDPOINT)  * (float)MAXCOLOR / (float)POTMIDPOINT;
    G = MAXCOLOR - B;
   
  }  

  // now write the RGB based on the pot input
  writeRGB (R, G, B);

  // delay
  delay(100);

}
