#include <WiFi.h>
#include "esp_wpa2.h"
#include <WiFiUdp.h>
#include <NTPClient.h>               
#include <TimeLib.h>                
#include <LiquidCrystal_I2C.h>      
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Include the Keypad library
#include <Keypad.h>

#define EAP_ANONYMOUS_IDENTITY  ""
#define EAP_IDENTITY  " "
#define EAP_PASSWORD  " "

const char *ssid     = "Siddhangana's Galaxy S20+ 5G"; // place your home address here
// int wifi_reconnect_counter = 0;
// unsigned long last_disconnected_time = 0;
// int HTTP_TIMEOUT = 30 * 1000;
const char *password = "kpyd3182"; // password
 
WiFiUDP ntpUDP; 
 
NTPClient timeClient(ntpUDP, "time.nist.gov", 28800, 60000); // according to Singapore's time UTC+8 = 28800 minutes

char Time[] = "TIME:00:00:00";
char Date[] = "DATE:00/00/2000";
byte last_second, second_, minute_, hour_, day_, month_;
int year_;

char alarm[] = "******"

// for buzzer input 
int buzzerPin = 15;

// for keypad input 
char page = 'A';
// Constants for row and column sizes
const byte ROWS = 4;
const byte COLS = 4;

// to check alarm
int alarm_flag = 0;
int alarm_enable = 1;

// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
// Connections to esp32
byte rowPins[ROWS] = {13, 12, 14, 27};
byte colPins[COLS] = {26, 25, 33, 32};
 
// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
 
void setup() {
 
  Serial.begin(115200);
  lcd.init();
  //lcd.begin(21, 22);                 // Initialize I2C LCD module (SDA = GPIO21, SCL = GPIO22)
  lcd.backlight();                   
  lcd.setCursor(0, 0);
  lcd.print(Time);
  lcd.setCursor(0, 1);
  lcd.print(Date); 
  
  WiFi.mode(WIFI_STA);   //Set WiFi mode to station mode - ESP32 connects to an access point
  WiFi.begin(ssid, password);
  //WiFi.begin(ssid, WPA2_AUTH_PEAP, EAP_ANONYMOUS_IDENTITY, EAP_IDENTITY, EAP_PASSWORD);
  Serial.print("Connecting...");
  
/*  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
    Serial.print("Hello World");
  } */
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      Serial.print(".");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000); //Removing this delay will cause the ESP32 to crash while connecting to a wifi network
      } 
      Serial.println("\nConnected.");
    }
    
  timeClient.begin();
  // Serial.println("connected");
  // timeClient.begin();
}
 
void loop(){


 main_menu();

 
}
 
void clock_page() {

    lcd.setCursor(0, 0);
    lcd.print(Time);
    lcd.setCursor(0, 1);
    lcd.print(Date);
    
}

void main_menu()
{
      if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      Serial.print(".");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000); //Removing this delay will cause the ESP32 to crash while connecting to a wifi network
      } 
      Serial.println("\nConnected.");
    }
    
  timeClient.update();
  unsigned long unix_epoch = timeClient.getEpochTime();    // Get Unix epoch time from the NTP server
 
  second_ = second(unix_epoch);
  if (last_second != second_) {
 
 
    minute_ = minute(unix_epoch);
    hour_   = hour(unix_epoch);
    day_    = day(unix_epoch);
    month_  = month(unix_epoch);
    year_   = year(unix_epoch);
 
 
 
    Time[12] = second_ % 10 + 48;
    Time[11] = second_ / 10 + 48;
    Time[9]  = minute_ % 10 + 48;
    Time[8]  = minute_ / 10 + 48;
    Time[6]  = hour_   % 10 + 48;
    Time[5]  = hour_   / 10 + 48;
 
 
 
    Date[5]  = day_   / 10 + 48;
    Date[6]  = day_   % 10 + 48;
    Date[8]  = month_  / 10 + 48;
    Date[9]  = month_  % 10 + 48;
    Date[13] = (year_   / 10) % 10 + 48;
    Date[14] = year_   % 10 % 10 + 48;
 
    Serial.println(Time);
    Serial.println(Date);
  
 /*   lcd.setCursor(0, 0);
    lcd.print(Time);
    lcd.setCursor(0, 1);
    lcd.print(Date); */
    last_second = second_;
 
  }    
    
    // Get key value if pressed, valid page values being A, B and C
    page = customKeypad.getKey();
        
    switch (page)
    {
    case 'A':
        clock_page(); // main page displaying current time
        break;
        
    case 'B':
        alarm_page();     // page to set alarm
        page = 'A';
        break;
        
    case 'C':
        offalarm_page(); // page to switch off alarm, we revert to 'A' after carrying out so it goes back to main page later
        page = 'A';
        break;
        
    default:
        break;
    }

    //Check alarm clock
    if (Time[5] == alarm[0] && Time[6] == alarm[1] && Time[8] == alarm[2] && Time[9] == alarm[3] && Time[11] == alarm[4] && Time[12] == alarm[5] 
    && alarm_enable == 1) // comparing each individually cuz it was giving errors if tried other ways, feel free to edit
    {
        if (alarm_flag == 0)
            alarming(); // can add function to set off buzzer here and compare curr Time with alarm to play buzzer during that duration
        alarm_flag = 1;
    }
    
    else
    {
        alarm_flag = 0;
    }

delay(1000);
    
}

void alarm_page()
{
    lcd.setCursor(0, 0);
    lcd.print("ALARM TIME:   ");
    lcd.setCursor(0, 1);

    int i = 0; // counter to keep track of alarm indices HHMMSS
    alarm = "******";
    lcd.print(alarm);
    
    while (i<=5) {
        
        while (alarm[i]=="*") {
            alarm[i] = customKeypad.getKey();
        }

        if (alarm[i] == "#") {  // press # if you want to abort and exit current page (set alarm)
          alarm = "******";
          break;
        }
        lcd.print(alarm);
        
        i = i+1;
    }

    lcd.setCursor(0, 0);
    lcd.print("ALARM SET AT:");
    lcd.setCursor(0, 1);
    lcd.print(alarm);
    delay(2000);
}

void offalarm_page() {

    lcd.setCursor(0, 0);
    lcd.print("ALARM TIME: ");
    lcd.setCursor(0, 1);
    lcd.print(alarm);
    delay(1000);

    while true {

      lcd.setCursor(0, 0);
      lcd.print("PRESS * TO OFF");
      lcd.setCursor(0, 1);

      char key = customKeypad.getKey();
      
      if (key == '*') {

          alarm = "******";
          break;
        
        }
      else if (key == '#') break;
  
    }

  
}

void alarming() {
  
   // can place buzzer and display math problem here
   
}
