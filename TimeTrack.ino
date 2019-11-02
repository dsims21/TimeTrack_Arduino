
#include <Console.h>
#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" 

const String DATABASE_SERVER = "xxx.us-east-1.rds.amazonaws.com";
const String DATABASE_NAME = "xxx";
const String DATABASE_USERNAME = "xxx";
const String DATABASE_PASSWORD = "xxx";
const String DATABASE_TABLE_NAME = "TimeTrack";

unsigned char buttonOneState = 0;
unsigned char buttonTwoState = 0; 
unsigned char buttonThreeState = 0; 
unsigned char buttonFourState = 0; 
unsigned char buttonFiveState = 0; 
unsigned char buttonSixState = 0;

unsigned char buttonOneStateLast = 0;
unsigned char buttonTwoStateLast = 0; 
unsigned char buttonThreeStateLast = 0; 
unsigned char buttonFourStateLast = 0; 
unsigned char buttonFiveStateLast = 0; 
unsigned char buttonSixStateLast = 0;

unsigned short buttonOnePushCounter = 3;
unsigned short buttonTwoPushCounter = 3;
unsigned short buttonThreePushCounter = 3;
unsigned short buttonFourPushCounter = 3;
unsigned short buttonFivePushCounter = 3;
unsigned short buttonSixPushCounter = 3;

unsigned short buttonOneOffPushCounter = 2;
unsigned short buttonTwoOffPushCounter = 2;
unsigned short buttonThreeOffPushCounter = 2;
unsigned short buttonFourOffPushCounter = 2;
unsigned short buttonFiveOffPushCounter = 2;
unsigned short buttonSixOffPushCounter = 2;

const unsigned char buttonOneLED = 2;
const unsigned char buttonTwoLED = 3;
const unsigned char buttonThreeLED = 4;
const unsigned char buttonFourLED = 5;
const unsigned char buttonFiveLED = 6;
const unsigned char buttonSixLED = 7;

const unsigned char buttonOnePin = 8;
const unsigned char buttonTwoPin = 9;
const unsigned char buttonThreePin = 10;
const unsigned char buttonFourPin = 11;
const unsigned char buttonFivePin = 12;
const unsigned char buttonSixPin = 13;

String buttonOneStartTime;
String buttonTwoStartTime;
String buttonThreeStartTime;
String buttonFourStartTime;
String buttonFiveStartTime;
String buttonSixStartTime;

String accountOne = "Am";
String accountTwo = "Ce";
String accountThree = "F";
String accountFour = "I";
String accountFive = "M";
String accountSix = "T";

void setup() {
  
  Bridge.begin();
  Serial.begin(9600);
  delay(1000);
  
  pinMode(buttonOnePin, INPUT);
  pinMode(buttonTwoPin, INPUT);
  pinMode(buttonThreePin, INPUT);
  pinMode(buttonFourPin, INPUT);
  pinMode(buttonFivePin, INPUT);
  pinMode(buttonSixPin, INPUT);
 
  pinMode(buttonOneLED,OUTPUT);
  pinMode(buttonTwoLED,OUTPUT);
  pinMode(buttonThreeLED,OUTPUT);
  pinMode(buttonFourLED,OUTPUT);
  pinMode(buttonFiveLED,OUTPUT);
  pinMode(buttonSixLED,OUTPUT);
  
  digitalWrite(buttonOnePin, LOW);
  digitalWrite(buttonTwoPin, LOW);
  digitalWrite(buttonThreePin, LOW);
  digitalWrite(buttonFourPin, LOW);
  digitalWrite(buttonFivePin, LOW);
  digitalWrite(buttonSixPin, LOW);

}

void loop()
{
  buttonOneState = digitalRead(buttonOnePin);
  buttonTwoState = digitalRead(buttonTwoPin);
  buttonThreeState = digitalRead(buttonThreePin);
  buttonFourState = digitalRead(buttonFourPin);
  buttonFiveState = digitalRead(buttonFivePin);
  buttonSixState = digitalRead(buttonSixPin);
  
  ////////////////////BUTTON ONE///////////////////////
  if(buttonOneState != buttonOneStateLast){
      if (buttonOneState == HIGH) {
      buttonOnePushCounter++;
      } 
      else {
      ///Console.println("off"); 
      buttonOneOffPushCounter++;
      if (buttonOneOffPushCounter % 2 == 0) {
      appendRow(accountOne,buttonOneStartTime,getTimeStamp());
      buttonOneStartTime = "";
      ///Console.println(F("Data Sent"));
      } else {
        
        buttonOneStartTime = getTimeStamp();
        ///Console.println(buttonOneStartTime);
      }
      }
  }
  
  buttonOneStateLast = buttonOneState;
  
  if (buttonOnePushCounter % 2 == 0) {
     digitalWrite(buttonOneLED, HIGH);
   }  else {
     digitalWrite(buttonOneLED, LOW);
     }
     
  //////////////////BUTTON TWO///////////////////////////  
  
 if(buttonTwoState != buttonTwoStateLast){
      if (buttonTwoState == HIGH) {
      buttonTwoPushCounter++;
      } 
      else {
      ///Console.println("off"); 
      buttonTwoOffPushCounter++;
      if (buttonTwoOffPushCounter % 2 == 0) {
      appendRow(accountTwo,buttonTwoStartTime,getTimeStamp());
      buttonTwoStartTime = "";
      ///Console.println(F("Data Sent"));
      } else {
        
        buttonTwoStartTime = getTimeStamp();
        ///Console.println(buttonTwoStartTime);
      }
      }
  }
  
  buttonTwoStateLast = buttonTwoState;
  
  if (buttonTwoPushCounter % 2 == 0) {
     digitalWrite(buttonTwoLED, HIGH);
   }  else {
     digitalWrite(buttonTwoLED, LOW);
     }
     
////////////////////BUTTON THREE///////////////////////
     
if(buttonThreeState != buttonThreeStateLast){
      if (buttonThreeState == HIGH) {
      buttonThreePushCounter++;
      } 
      else {
      ///Console.println("off"); 
      buttonThreeOffPushCounter++;
      if (buttonThreeOffPushCounter % 2 == 0) {
      appendRow(accountThree,buttonThreeStartTime,getTimeStamp());
      buttonThreeStartTime = "";
      } else {
        
        buttonThreeStartTime = getTimeStamp();
        ///Console.println(buttonThreeStartTime);
      }
      }
  }
  
  buttonThreeStateLast = buttonThreeState;
  
  if (buttonThreePushCounter % 2 == 0) {
     digitalWrite(buttonThreeLED, HIGH);
   }  else {
     digitalWrite(buttonThreeLED, LOW);
     }
     
/////////////////////BUTTON FOUR     
 
if(buttonFourState != buttonFourStateLast){
      if (buttonFourState == HIGH) {
      buttonFourPushCounter++;
      } 
      else {
      ///Console.println("off"); 
      buttonFourOffPushCounter++;
      if (buttonFourOffPushCounter % 2 == 0) {
      appendRow(accountFour,buttonFourStartTime,getTimeStamp());
      
      ///Console.println(F("Data Sent"));
      } else {
        
        buttonFourStartTime = getTimeStamp();
        ///Console.println(buttonFourStartTime);
      }
      }
  }
  
  buttonFourStateLast = buttonFourState;
  
  if (buttonFourPushCounter % 2 == 0) {
     digitalWrite(buttonFourLED, HIGH);
   }  else {
     digitalWrite(buttonFourLED, LOW);
     }
     
////////////////////BUTTON FIVE//////////////////// 

if(buttonFiveState != buttonFiveStateLast){
      if (buttonFiveState == HIGH) {
      buttonFivePushCounter++;
      } 
      else {
      ///Console.println("off"); 
      buttonFiveOffPushCounter++;
      if (buttonFiveOffPushCounter % 2 == 0) {
      appendRow(accountFive,buttonFiveStartTime,getTimeStamp());
      buttonFiveStartTime = "";
      ///Console.println(F("Data Sent"));
      } else {
        
        buttonFiveStartTime = getTimeStamp();
        ///Console.println(buttonFiveStartTime);
      }
      }
  }
  
  buttonFiveStateLast = buttonFiveState;
  
  if (buttonFivePushCounter % 2 == 0) {
     digitalWrite(buttonFiveLED, HIGH);
   }  else {
     digitalWrite(buttonFiveLED, LOW);
     }

     
 ////////////////////BUTTON SIX////////////////////    



//if(buttonSixState != buttonSixStateLast){
//      if (buttonSixState == HIGH) {
//      buttonSixPushCounter++;
//      } 
//      else {
//      ///Console.println("off"); 
//      buttonSixOffPushCounter++;
//      if (buttonSixOffPushCounter % 2 == 0) {
//      appendRow(accountSix,buttonSixStartTime,getTimeStamp());
//      buttonSixStartTime = "";
//      ///Console.println(F("Data Sent"));
//      } else {
//        
//        buttonSixStartTime = getTimeStamp();
//        ///Console.println(buttonSixStartTime);
//      }
//      }
//  }
//  
//  buttonSixStateLast = buttonSixState;
//  
//  if (buttonSixPushCounter % 2 == 0) {
//     digitalWrite(buttonSixLED, HIGH);
//   }  else {
//     digitalWrite(buttonSixLED, LOW);
//     }     



}


//==========FUNCTIONS===========

unsigned int appendRow(String Company, String Start_Time, String End_Time) {
  
  String sql = "INSERT " + DATABASE_TABLE_NAME + F(" (Company, Start_Time, End_Time) VALUES ('") + Company + "', '" + Start_Time + "' , ' " + End_Time + "');";
  
  unsigned char result = executeSQLCommand(sql, false);
  
  return result;
}

unsigned char executeSQLCommand(String sql, bool showOutput) {

  TembooChoreo choreo;

  choreo.begin();

  choreo.setAccountName(F("xxx"));
  choreo.setAppKeyName(F("xxx"));
  choreo.setAppKey(F("xxx"));

  choreo.setChoreo(F("/Library/MySQL/RunCommand"));

  choreo.addInput(F("Server"), DATABASE_SERVER);
  choreo.addInput(F("DatabaseName"), DATABASE_NAME);
  choreo.addInput(F("Username"), DATABASE_USERNAME);
  choreo.addInput(F("Password"), DATABASE_PASSWORD);
  choreo.addInput(F("SQL"), sql);
  
  unsigned char returnCode = choreo.run();

  if (returnCode == 0) {
    
    if (showOutput) {
      while (choreo.available()) {
        char c = choreo.read();
        Console.print(c);
      }
    }
  } else {
    while (choreo.available()) {
      char c = choreo.read();
    }
  }

  choreo.close();

  return returnCode;
}

 
 String getTimeStamp() {
  String result;
  Process time;

  time.begin(F("date"));
  time.addParameter(F("+%F %T"));
     
  time.run();

  // read the output of the command
  while(time.available()>0) {
    char c = time.read();
    if(c != '\n')
      result += c;
  }

  return result;
 }
