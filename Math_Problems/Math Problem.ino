#include <Keypad.h>

#define ROW_NUM     4 // four rows
#define COLUMN_NUM  4 // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM]      = {19, 18, 5, 17}; // GIOP19, GIOP18, GIOP5, GIOP17 connect to the row pins
byte pin_column[COLUMN_NUM] = {16, 4, 0, 2};   // GIOP16, GIOP4, GIOP0, GIOP2

Keypad customKeypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

int i = 0;
int retry = 0;
String ans = "0";
String input_ans  = "0";

void setup() {
  Serial.begin(115200);

}

void loop() {

/* Useless

  int anskey[10] = {4, 9, 24, 30, 74, 47, 8, 144, 73, 7}
  int stop = 0;
  int i = 0;

  ans0 = 4;   // 1 + 3
  ans1 = 9;   // 3 * 3
  ans2 = 24;  // 144 / 6
  ans3 = 30;  // 23 + 7
  ans4 = 74;  // 81 - 7
  ans5 = 47;  // 84 - 37
  ans6 = 8;   // 56 / 7 
  ans7 = 144; // 12 * 12
  ans8 = 73;  // 46  + 27
  ans9 = 7;   // 21 / 3
*/

  /*
  // Get key value if pressed
  char customKey = customKeypad.getKey();
 
  if (customKey) {
    // Print key value to serial monitor
    Serial.println(customKey);
  }
  */

  i = random(1,10);

  String input_ans = "0";
  
  if(i == 1){
    //Serial.setCursor(2,0);
    Serial.println("1 + 3");

    ans = "4";
  }

  else if(i == 2){
    //Serial.setCursor(2,0);
    Serial.println("3 * 3");
    
    ans = "9"; 
  }

  else if(i == 3){
    //Serial.setCursor(2,0);
    Serial.print("144 / 6");
      
    ans = "24";
  }

  else if(i == 4){
    //Serial.setCursor(2,0);
    Serial.println("23 + 7");
    
    ans = "30";
  }

  else if(i == 5){
    //Serial.setCursor(2,0);
    Serial.println("81 - 7");
    
    ans = "74";
  }

  else if(i == 6){
    //Serial.setCursor(2,0);
    Serial.println("84 - 37");
    
    ans = "47";
  }
 
  else if(i == 7){
    //Serial.setCursor(2,0);
    Serial.println("56 / 7");
    
    ans = "8";
  }

  else if(i == 8){
    //Serial.setCursor(2,0);
    Serial.println("12 * 12");
    
    ans = "144";
  }

  else if(i == 9){
    //Serial.setCursor(2,0);
    Serial.println("46 + 27");
    
    ans = "73";
  }

  else if(i == 10){
    //Serial.setCursor(2,0);
    Serial.println("21 / 3");
    
    ans = "7";
  }

/*
  while(retry == 0){

    if(ans == input_ans){
      //Serial.setCursor(2,0);
      Serial.println("Correct!");
      delay(1000);
      retry = 1;
      
      //stop buzzer idk
    }

    else{
      //Serial.setCursor(2,0);
      Serial.println("Wrong! Try again.");
      delay(1000);
    }

*/
}
