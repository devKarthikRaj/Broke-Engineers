#include <WiFi.h>
#include "esp_wpa2.h"
#include <WiFiUdp.h>
#include <NTPClient.h>               
#include <TimeLib.h>                
#include <LiquidCrystal_I2C.h>      
LiquidCrystal_I2C lcd(0x27, 16, 2); 
 
#define EAP_ANONYMOUS_IDENTITY  ""
#define EAP_IDENTITY  " "
#define EAP_PASSWORD  " "

const char *ssid     = "Siddhangana's Galaxy S20+ 5G";
// int wifi_reconnect_counter = 0;
// unsigned long last_disconnected_time = 0;
// int HTTP_TIMEOUT = 30 * 1000;
const char *password = "kpyd3182";
 
WiFiUDP ntpUDP; 
 
NTPClient timeClient(ntpUDP, "time.nist.gov", 28800, 60000);
 
char Time[50] = "TIME:00:00:00";
char Date[50] = "DATE:00/00/2000";
byte last_second, second_, minute_, hour_, day_, month_;
int year_;
 
 
 
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
  Serial.print("Hello World");
  WiFi.begin(ssid, password);
  //WiFi.begin(ssid, WPA2_AUTH_PEAP, EAP_ANONYMOUS_IDENTITY, EAP_IDENTITY, EAP_PASSWORD);
  Serial.print("Hello World");
  Serial.print("Connecting.");
  
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
 
 
void loop() {

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
 
    lcd.setCursor(0, 0);
    lcd.print(Time);
    lcd.setCursor(0, 1);
    lcd.print(Date);
    last_second = second_;
 
  }
  delay(1000);
}
