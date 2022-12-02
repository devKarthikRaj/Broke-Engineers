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
String ans = "0";
String qn;

void setup() {
  Serial.begin(115200);

}

void loop() {
  delay(3000);
  Serial.println(math_problem());
  while(1);
}

String math_problem(){

  //Randomly choose questions
  i = random(1,10);

  if(i == 1){
    qn = "1 + 3";
    ans = "4";
  }

  else if(i == 2){
    qn = "3 * 3";
    ans = "9"; 
  }

  else if(i == 3){
    qn = "3";
    ans = "3";
  }

  else if(i == 4){
    qn = "4";
    ans = "4";
  }

  else if(i == 5){
    qn = "5";
    ans = "5";
  }

  else if(i == 6){
    qn = "6";
    ans = "6";
  }
 
  else if(i == 7){
    //Serial.setCursor(2,0);
    qn = "56 / 7";
    
    ans = "8";
  }

  else if(i == 8){
    qn = "8";
    ans = "8";
  }

  else if(i == 9){
    qn = "9";
    ans = "9";
  }

  else if(i == 10){
    qn = "21 / 3";
    
    ans = "7";
  }

  Serial.println(qn);

  return ans;
}
