#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define capteur 6

MFRC522 rfid(SS_PIN,RST_PIN);
LiquidCrystal_I2C lcd(0X27,16,2);


byte nuidPICC[4];
int valeur=0; //valeur de capteur
String nom="";



void setup() {
  Serial.begin(9600); //init RS22
  pinMode(capteur,INPUT);
  SPI.begin(); //init SPI bus
  rfid.PCD_Init(); //init MFRC522
  lcd.begin(); //init lcd
  lcd.backlight(); //on the blacknight
  lcd.setCursor(3,0);
  lcd.print("Welcome!");
  
}

void loop() {

  /*
  //*****************capteur de gaz*************************
  valeur=digitalRead(capteur); //valeur de capteur
  if(valeur==1){
    Serial.println('1');
  }
  */
  //******************rfid**********************************
  
  //initializer le boucle si aucun badge n'est present 
  if(!rfid.PICC_IsNewCardPresent())
  return;

  //verifier la presence d'un nouveau badge
  if(!rfid.PICC_ReadCardSerial())
  return;

  //enregistrer le id de badge 
  for(byte i=0;i<4;i++){
    nuidPICC[i]=rfid.uid.uidByte[i];
  }
   String rf="";
  //affichage de l'id
   for(byte i=0;i<rfid.uid.size;i++){
    rf.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    rf.concat(String(rfid.uid.uidByte[i],HEX));
    }

    rf.toUpperCase();

    if(rf.substring(1)=="13 0A 7C A7"){
      Serial.print("1");
    }else if(rf.substring(1)=="73 14 E3 91"){
      Serial.print("2");
    }

  nom=Serial.readString();

  lcd.setCursor(0,1);
  lcd.print(nom);
  delay(5000);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Welcome!");
  delay(2000);

  //re_initialisationde rfid
  rfid.PICC_HaltA(); //halt picc
  rfid.PCD_StopCrypto1(); //stop encryption on pcd
}
