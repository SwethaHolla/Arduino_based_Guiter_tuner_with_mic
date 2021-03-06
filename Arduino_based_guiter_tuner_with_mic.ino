/*
  LiquidCrystal Library - Hello World
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

// include library code:
#include <Wire.h>  
#include <LiquidCrystal.h>
#include "arduinoFFT.h"
#define SAMPLES 128
#define SAMPLING_FREQUENCY 1000

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
arduinoFFT FFT = arduinoFFT();
unsigned int sampling_period_us;
unsigned long microseconds;

double vReal[SAMPLES];
double vImag[SAMPLES];

//tuning variables 
String tune = "IN TUNE";
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);   
  //lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print(" Guitar Tuner");
  delay(3000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Play a note!");
  sampling_period_us = round(1000000*(1.0/SAMPLING_FREQUENCY));
}

void loop() {
  //Sampling
  for(int i = 0; i<SAMPLES; i++)
  {
    microseconds = micros();

    vReal[i] = analogRead(0);
    vImag[i] = 0;
    
    while(micros() < (microseconds + sampling_period_us)){
    }
  }

   FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);

    double frequency = peak;

if(frequency == -1)
  {
    return;
  }
 //E2
 if(frequency >= 75 && frequency <= 90)
{
  lcd.clear();
  lcd.setCursor(7,1); //center it
  lcd.print("E2");
  if(frequency < 81)
  {
    lcd.setCursor(2,0);//to the left
    lcd.print("b");
  }
  if(frequency > 83.5)
  {
    lcd.setCursor(14,0); //to the right
    lcd.print("#");
  }
  if(frequency >= 81 && frequency <= 83.5)
  {
    lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("E2");
    lcd.setCursor(4,1);
    lcd.print(tune);
  }
}
//A3
 else if(frequency <= 120.00 && frequency >= 100.00)
{
  lcd.clear();
  lcd.setCursor(7,1); //center it
  lcd.print("A3");
  if(frequency < 109.00)
  {
    lcd.setCursor(2,0);//to the left
    lcd.print("b");
  }
  if(frequency > 111.00)
  {
    lcd.setCursor(14,0); //to the right
    lcd.print("#");
  }
  if(frequency >= 109.00 && frequency <= 111.00)
  {
    lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("A3");
    lcd.setCursor(4,1);
    lcd.print(tune);
  }
}
//D3
else if(frequency >= 130.00 && frequency <= 150.00)
{
  lcd.clear();
  lcd.setCursor(7,1); //center it
  lcd.print("D3");
  if(frequency < 146)
  {
    lcd.setCursor(2,0);//to the left
    lcd.print("b");
  }
  if(frequency > 148)
  {
    lcd.setCursor(14,0); //to the right
    lcd.print("#");
  }
  if(frequency >= 146 && frequency <= 148)
  {
    lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("D3");
    lcd.setCursor(4,1);
    lcd.print(tune);
  }
}
//G3
else if(frequency >= 180.00 && frequency <= 210.00)
{
  lcd.clear();
  lcd.setCursor(7,1); //center it
  lcd.print("G3");
  if(frequency < 195.00)
  {
    lcd.setCursor(2,0);//to the left
    lcd.print("b");
  }
  if(frequency > 197.00)
  {
    lcd.setCursor(14,0); //to the right
    lcd.print("#");
  }
  if(frequency >= 195.00 && frequency <= 197.00)
  {
    lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("G3");
    lcd.setCursor(4,1);
    lcd.print(tune);
  }
}
//B3
else if(frequency >= 230.00 && frequency <= 260.00)
{
  lcd.clear();
  lcd.setCursor(7,1); //center it
  lcd.print("B3");
  if(frequency < 245)
  {
    lcd.setCursor(2,0);//to the left
    lcd.print("b");
  }
  if(frequency > 248)
  {
    lcd.setCursor(14,0); //to the right
    lcd.print("#");
  }
  if(frequency >=245 && frequency <= 248)
  {
    lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("B3");
    lcd.setCursor(4,1);
    lcd.print(tune);
  }
}
//E4
else if(frequency >= 310.00 && frequency <= 350.00)
{
  lcd.clear();
  lcd.setCursor(7,0); //center it
  lcd.print("E4");
  if(frequency < 328)
  {
    lcd.setCursor(2,0);//to the left
    lcd.print("b");
  }
  if(frequency > 330)
  {
    lcd.setCursor(14,0); //to the right
    lcd.print("#");
  }
  if(frequency >= 328 && frequency <= 330)
  {
    lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("E4");
    lcd.setCursor(4,1);
    lcd.print(tune);
  }
}
}
 
