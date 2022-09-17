// viral science
// calculator
// viral dodhia
// https://www.youtube.com/watch?v=XXonpVubg94&list=PLUWZpHJMEu-Dv5Va5AmPeZH-E8-v9038u&index=152
// https://www.viralsciencecreativity.com/post/arduino-calculator-display
#include <LiquidCrystal.h>
#include <Keypad.h>

const int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte ROWS = 4;
const byte COLS = 4;

char keys [ROWS] [COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


boolean presentValue = false;
boolean next = false;
boolean final = false;
String num1, num2;
int answer;
char op;

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" An Awesome");
  lcd.setCursor(0, 1);
  lcd.print("   Calculator");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("       by     ");
  lcd.setCursor(0, 1);
  //lcd.print("  Viral Dodhia"    );
  lcd.print("  Faniel Yemane"    );
  delay(3000);
  lcd.clear();
}

void loop() {
  char key = myKeypad.getKey();

  if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0'))
  {
    if (presentValue != true)
    {
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(15 - numLength, 0); //to adjust one whitespace for operator
      lcd.print(num1);
    }
    else
    {
      num2 = num2 + key;
      int numLength = num2.length();
      lcd.setCursor(15 - numLength, 1);
      lcd.print(num2);
      final = true;
    }
  }

  else if (presentValue == false && key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+'))
  {
    if (presentValue == false)
    {
      presentValue = true;
      op = key;
      lcd.setCursor(15, 0);
      lcd.print(op);
    }
  }

  else if (final == true && key != NO_KEY && key == '=') {
    if (op == '+') {
      answer = num1.toInt() + num2.toInt();
    }
    else if (op == '-') {
      answer = num1.toInt() - num2.toInt();
    }
    else if (op == '*') {
      answer = num1.toInt() * num2.toInt();
    }
    else if (op == '/') {
      answer = num1.toInt() / num2.toInt();
    }
    lcd.clear();
    lcd.setCursor(15, 0);
    lcd.autoscroll();
    lcd.print(answer);
    lcd.noAutoscroll();
  }
  else if (key != NO_KEY && key == 'C') {
    lcd.clear();
    presentValue = false;
    final = false;
    num1 = "";
    num2 = "";
    answer = 0;
    op = ' ';
  }
}
