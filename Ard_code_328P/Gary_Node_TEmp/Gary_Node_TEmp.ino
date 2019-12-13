#include <OneWire.h>        //Temp (install from library manager)
#include <DallasTemperature.h>  //Temp (install from library manager)
#include <DS3231.h> //RTC  (install from library manager)
#include "SD.h"   //SD card (install from library manager)
#include "LowPower.h" // low power consumption (cpp and h files included)

int Sample_Number=6;   // everytime you sample, take 6 samples.
int minutes_to_wake = 15;  // number of minutes between samples
int wake_counter = 0;
//RTC Setup
DS3231 rtc(SDA, SCL);
//End of RTC setup

//Temp sensor setup
// add a 4.7k Ohm resistor between 5V and data wire
#define TempSensor A0    //Temp
OneWire oneWire(TempSensor);
DallasTemperature sensors(&oneWire);
float Celcius = 0;
float Fahrenheit = 0;

//SD Card setup
const int chipSelect = 10; // for data logging shield
File logfile;
char filename[] = "GaryUW00.txt";
//End of SD Card setup

//Light Sensor Setup
#define LightSensor A3
int Light;
float Lux = 0;
float RawLuxRange = 69666.3 ; // 1024
float LogLuxRange = 500;

#define LEDR 4
#define LEDB 3
//////////////////////////////////////////////////////////////////////////
void setup(void)
{
  pinMode(LEDB,OUTPUT);
  pinMode (LightSensor, INPUT);
  pinMode(chipSelect, OUTPUT);
  //pinMode(LEDR,OUTPUT);
  
//  Serial.begin(9600); //Serial port 9600 Baud rate
  rtc.begin(); //RTC begin
//  setDateTime();  // Uncomment to reset the date and time of the RTC
  sensors.begin(); // Temp sensor

//  Serial.println("Starting SD card init");
  while (!SD.begin(chipSelect)) {
//    digitalWrite(LEDR, HIGH);
//    digitalWrite(LEDB, LOW);
//    Serial.println("Card failed, or not present");
  }
//  Serial.println("SD card initialized.");
  
  //  digitalWrite(LEDR, LOW);
  digitalWrite(LEDB, HIGH);
  delay(800);
  digitalWrite(LEDB,LOW);
 
  //create new log file:
  for (uint8_t i = 0; i < 100; i++) {
    filename[6] = i / 10 + '0';
    filename[7] = i % 10 + '0';
    if (! SD.exists(filename)) {
      // only open a new file if it doesn't exist
      logfile = SD.open(filename, FILE_WRITE);
//      Serial.print("Log file created: ");
//      Serial.print(filename);
//      Serial.println("");
      break;  // leave the loop!
    } else {
//      Serial.print("Log file already exists: ");
//      Serial.print(filename);
//      Serial.println("");
    }
  }
//  Serial.println("Beginning Loop");
}

void loop()
{
 if (wake_counter < minutes_to_wake*60/8) {  // Sleep for: (60s/m * minutes_to_wake)/8s (LowPower max setting)
    wake_counter += 1;
    
//    String ts = generateTimestamp();
//    Serial.println("Sleeping: ");
//    Serial.print(wake_counter);
//    Serial.print(" of ");
//    Serial.print(minutes_to_wake*60/8);
    delay(100);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);  //sleep in 8 seconds
  } else {
    wake_counter = 0;
//    Serial.println("Sense time");
    String ts = generateTimestamp();
  
//    Serial.println("Logging to SD");
    logfile = SD.open(filename, FILE_WRITE);
    logfile.print(ts);
      
    for(int j=0;j<Sample_Number;j++){
      sensors.requestTemperatures();
      Celcius = sensors.getTempCByIndex(0);
      Fahrenheit = sensors.toFahrenheit(Celcius);
      Light = analogRead(LightSensor);
      Lux = RawToLux(Light);
      
      logfile.print(" Temp  ");
      logfile.print(Fahrenheit);
      logfile.print(" F  ");
      logfile.print(" Lux ");
      logfile.println(Lux);
      
//      Serial.print(" Temp: ");
//      Serial.print(Fahrenheit);
//      Serial.print(" F; ");
//      Serial.print("Lux: ");
//      Serial.println(Lux);
      delay(100);
    }
    logfile.close();
//    Serial.println("log file closed");
  
      
    
//    Serial.println("Going to sleep");
    delay(100);
    // Sleep for 8 s with ADC module and BOD module off
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);  //sleep in 8 seconds
  }
}

float RawToLux(int raw)
{
  float logLux = raw * LogLuxRange / RawLuxRange; // rescale
  return pow(10, logLux); // log function 
}

void setDateTime() {
  rtc.setDOW(WEDNESDAY);     // Set Day-of-Week 
  rtc.setTime(22, 14, 0);     // Set the time 
  rtc.setDate(11, 12, 2019);   // Set the date (day, month, year)
}

String generateTimestamp() {
  String s = rtc.getDOWStr();
  s += " ";
  s += rtc.getDateStr();
  s += " -- ";
  s += rtc.getTimeStr();
  s += ":";
//  Serial.print("The time is: ");
//  Serial.print(s);
  return s;
}
