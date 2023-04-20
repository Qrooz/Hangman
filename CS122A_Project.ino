#include <LiquidCrystal.h>

//setup for LCD display
LiquidCrystal lcd(7,8,9,10,11,12);

//setup for joystick
int xValue = 0 ;
int yValue = 0 ; 
int bValue = 0 ;
char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int counter = 0;
int lives = 3;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);

lcd.print("???      HangMan");
lcd.setCursor(10,1);
lcd.print(alphabet[counter]);
  pinMode(2,INPUT); 
  digitalWrite(2,HIGH); 
}

void loop() {
  // put your main code here, to run repeatedly:
  xValue = analogRead(A0);  
  yValue = analogRead(A1);  
  bValue = digitalRead(2);

  if(yValue <= 400 && counter < 25){
  ++counter;
  lcd.setCursor(5,1);
  lcd.print(alphabet[counter]);
  }
  else if(yValue >= 500 && counter > 0){
  --counter;
  lcd.setCursor(5,1);
  lcd.print(alphabet[counter]);
  }


if((bValue == 0) && (alphabet[counter] == 'D')){
    lcd.setCursor(0,0);
    lcd.print('D');
  }
else if((bValue == 0) && (alphabet[counter]  =='O')){
    lcd.setCursor(1,0);
    lcd.print('O');
  }
else if((bValue == 0) && (alphabet[counter] == 'G')){
    lcd.setCursor(2,0);
    lcd.print('G');
  }
else if(bValue == 0 && lives == 3){
    --lives;
    lcd.setCursor(0,1);
    lcd.print('X');
  }
else if(bValue == 0 && lives == 2){
    --lives;
    lcd.setCursor(1,1);
    lcd.print('X');
  }
else if(bValue == 0 && lives == 1){
    --lives;
    lcd.setCursor(0,1);
    lcd.print("Game Over :(");
  }
delay(500);
}
