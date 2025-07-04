#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

VR myVR(2,3);    // 2:RX, 3:TX

uint8_t records[7]; // save record
uint8_t buf[64];

int L_EN1 = 5; // LED for forward/backward commands (LED1)
int R_EN1 = 7; // LED for right/left commands (LED2)
int RPWM1 = 8; // Pin connected to relay module for DC motor control
int LPWM1 = 6;
int L_EN2 = 10; // LED for forward/backward commands (LED1)
int R_EN2 = 11; // LED for right/left commands (LED2)
int RPWM2 = 12; // Pin connected to relay module for DC motor control
int LPWM2 = 13;

#define COMMAND_FORWARD (0) // Command for turning on LED1 (b)
#define COMMAND_BACKWARD (1) // Command for turning off LED1 (r)
#define COMMAND_LEFT (2) // Command for turning on LED2 (k)
#define COMMAND_RIGHT (3)
#define COMMAND_OFF (4)


void printSignature(uint8_t *buf, int len) {
    for(int i = 0; i < len; i++) {
        if(buf[i] > 0x19 && buf[i] < 0x7F) {
            Serial.write(buf[i]);
        } else {
            Serial.print("[");
            Serial.print(buf[i], HEX);
            Serial.print("]");
        }
    }
}

void printVR(uint8_t *buf) {
    Serial.println("VR Index\tGroup\tRecordNum\tSignature");

    Serial.print(buf[2], DEC);
    Serial.print("\t\t");

    if(buf[0] == 0xFF) {
        Serial.print("NONE");
    } else if(buf[0] & 0x80) {
        Serial.print("UG ");
        Serial.print(buf[0] & (~0x80), DEC);
    } else {
        Serial.print("SG ");
        Serial.print(buf[0], DEC);
    }
    
    Serial.print("\t");
    Serial.print(buf[1], DEC);
    
    Serial.print("\t\t");
    
    if(buf[3] > 0) {
        printSignature(buf + 4, buf[3]);
    } else {
        Serial.print("NONE");
    }
    
    Serial.println("\r\n");
}

void setup() {
    /** initialize */
    myVR.begin(9600);
  
    Serial.begin(115200);
    Serial.println("Elechouse Voice Recognition V3 Module\r\nControl LED and DC Motor sample");
  
    pinMode(L_EN1, OUTPUT);
    pinMode(R_EN1, OUTPUT);
    pinMode(RPWM1, OUTPUT);
    pinMode(LPWM1, OUTPUT);
    pinMode(L_EN2, OUTPUT);
    pinMode(R_EN2, OUTPUT);
    pinMode(RPWM2, OUTPUT);
    pinMode(LPWM2, OUTPUT);

    digitalWrite(L_EN1, HIGH);
    digitalWrite(R_EN1, HIGH);
    digitalWrite(L_EN2, HIGH);
    digitalWrite(R_EN2, HIGH);
    
  
    
    
    if(myVR.clear() == 0) {
        Serial.println("Recognizer cleared.");
    } else {
        Serial.println("Not find VoiceRecognitionModule.");
        Serial.println("Please check connection and restart Arduino.");
        while(1);
    }
  
    // Load commands: b, r, k, i
    if(myVR.load((uint8_t)COMMAND_FORWARD) >= 0) {
        Serial.println("Command '0' loaded");
    }
  
    if(myVR.load((uint8_t)COMMAND_BACKWARD) >= 0) {
        Serial.println("Command '1' loaded");
    }

    if(myVR.load((uint8_t)COMMAND_LEFT) >= 0) {
        Serial.println("Command '2' loaded");
    }

    if(myVR.load((uint8_t)COMMAND_RIGHT) >= 0) {
        Serial.println("Command '3' loaded");
    }

    if(myVR.load((uint8_t)COMMAND_OFF) >= 0) {
        Serial.println("Command '4' loaded");
    }

     }

void loop() {
   int ret = myVR.recognize(buf, 50);
    
    if(ret > 0) {
        switch(buf[1]) {
            case COMMAND_FORWARD:
                /** turn on LED1 and activate motor */
                analogWrite(RPWM1, 0);
                analogWrite(LPWM1, 255);
                analogWrite(RPWM2, 0);
                analogWrite(LPWM2, 255);
                //  delay(180000);
                break;
            case COMMAND_BACKWARD:
                /** turn off LED1 and deactivate motor */
                analogWrite(RPWM1, 255);
                analogWrite(LPWM1, 0);
                analogWrite(RPWM2, 255);
                analogWrite(LPWM2, 0);
                //  delay(180000);
                break;

            case COMMAND_LEFT:
                /** turn on LED2 and activate motor */
                analogWrite(RPWM1, 255);
                analogWrite(LPWM1, 0);
                analogWrite(RPWM2, 0);
                analogWrite(LPWM2, 255);
                delay(3000);
                analogWrite(RPWM1, 0);
                analogWrite(LPWM1, 0);
                analogWrite(RPWM2, 0);
                analogWrite(LPWM2, 0);

                break;

            case COMMAND_RIGHT:
                /** turn on LED2 and activate motor */
                analogWrite(RPWM1, 0);
                analogWrite(LPWM1, 255);
                analogWrite(RPWM2, 255);
                analogWrite(LPWM2, 0);
                delay(3000);
                analogWrite(RPWM1, 0);
                analogWrite(LPWM1, 0);
                analogWrite(RPWM2, 0);
                analogWrite(LPWM2, 0);
                break;
            
            case COMMAND_OFF:
                /** turn on LED2 and activate motor */
                analogWrite(RPWM1, 0);
                analogWrite(LPWM1, 0);
                analogWrite(RPWM2, 0);
                analogWrite(LPWM2, 0);
                break;

                

                Serial.println("Record function undefined");
                break;
        }

        /** voice recognized */
        printVR(buf);
        
        // No delay needed here since we want LEDs and the motor to stay on/off based on commands.
     }
}