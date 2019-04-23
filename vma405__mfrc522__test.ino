#include "Employees.h"
#include <RFID.h>

#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN);
Employee e;

int power = 7;
int led = 8;
int serNum[5];
/*
  This integer should be the code of Your Mifare card / tag
*/
//int cards[][5] = {{117,222,140,171,140}};
int cards[][5] = {{205, 189, 160, 89, 137}};


bool access = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  /*
    define VMA100 (UNO) pins 7 & 8 as outputs and put them LOW
  */
  pinMode(led, OUTPUT);
  pinMode (power, OUTPUT);
  digitalWrite(led, LOW);
  digitalWrite (power, LOW);
  menu();
}

void loop() {
  if (rfid.isCard()) {
    e.setFirstName();
    e.setLastName();
    if (rfid.readCardSerial()) {
      Serial.print(rfid.serNum[0]);
      Serial.print(" ");
      Serial.print(rfid.serNum[1]);
      Serial.print(" ");
      Serial.print(rfid.serNum[2]);
      Serial.print(" ");
      Serial.print(rfid.serNum[3]);
      Serial.print(" ");
      Serial.print(rfid.serNum[4]);
      Serial.println("");

      for (int x = 0; x < sizeof(cards); x++) {
        for (int i = 0; i < sizeof(rfid.serNum); i++ ) {
          if (rfid.serNum[i] != cards[x][i]) {
            access = false;
            break;
          } else {
            access = true;
          }
        }
        if (access) break;
      }

    }
    if (access) {
      Serial.println("Welcome " + e.getFirstName() + " " + e.getLastName());
      /*
        Valid card : Switch ON the LED for 1000 ms (1 second)
      */
      digitalWrite(led, HIGH);
      delay(1000);
      /*
        Valid card : Switch ON the POWER PIN for 2000 ms (2 seconds)), the POWER PIN can activate for example a relais, controlling a doorlock)
      */
      digitalWrite(power, HIGH);
      delay(2000);
      digitalWrite(power, LOW);
      digitalWrite(led, LOW);
      access = false;
    }
    else {
      /*
        NON-Valid card : switch ON and OFF the LED twice for 0,5 seconds
      */
      Serial.println("Not allowed!");
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
    }
  }
  rfid.halt();
}

void menu() {
  Serial.print("Main Menu\n");
  Serial.print("1.Clock In/Out\n");
  Serial.print("2.Inquiry\n");
  Serial.print("3.Create new employee\n");
  while(Serial.available()==0);
  int num = Serial.parseInt();
  Serial.print("Present your tag to the reader.");
  if(num == 1){
    
  }else if(num == 2){
    
  }else if(num == 3){
    if(e.getIsManager()){
      //Present new menu
    }else{
      Serial.print("Manager Access Needed.");
    }
  }
}
