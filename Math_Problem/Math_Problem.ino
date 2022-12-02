//Variables for math_problem()
int i = 0;
String ans = "0";
String qn = "0";

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
  i = random(1,9);

  if(i == 1){
    qn = "1 + 3";
    ans = "4";
  }

  else if(i == 2){
    qn = "3 * 3";
    ans = "9"; 
  }

  else if(i == 3){
    qn = "30 / 10";
    ans = "3";
  }

  else if(i == 4){
    qn = "74 - 73";
    ans = "1";
  }

  else if(i == 5){
    qn = "2 + 3";
    ans = "5";
  }

  else if(i == 6){
    qn = "2 * 3";
    ans = "6";
  }
 
  else if(i == 7){
    qn = "56 / 7";
    ans = "8";
  }

  else if(i == 8){
    qn = "21 / 3";
    ans = "7";
  }

  else if(i == 9){
    qn = "78 / 39";
    ans = "2";
  }

  //Print the Question
  Serial.println(qn);
  //Return answer to Question
  return ans;
}
