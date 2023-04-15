
#include <Pixy2.h>
#include <Adafruit_MotorShield.h>

Pixy2 pixy;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
 
 
Adafruit_DCMotor *UR = AFMS.getMotor(4);
Adafruit_DCMotor *UL = AFMS.getMotor(3);
Adafruit_DCMotor *DL = AFMS.getMotor(2);
Adafruit_DCMotor *DR = AFMS.getMotor(1);
  
void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  
  pixy.init();

  AFMS.begin();

}

void loop()
{ 
  int i; 
 
  pixy.ccc.getBlocks();
  
  
  if (pixy.ccc.numBlocks)
  {
    if (pixy.ccc.blocks[i].m_x > 200 ){
      Serial.println("turn right");
UR->setSpeed(255);
 UL->setSpeed(255);
 DR->setSpeed(255);
 DL->setSpeed(255);  
  UR->run(FORWARD);
 UL->run(BACKWARD);
 DL->run(FORWARD);
 DR->run(BACKWARD);
    }
    else if (pixy.ccc.blocks[i].m_x  < 130){
      Serial.println("turn left");
 
     UR->setSpeed(255);
 UL->setSpeed(255);
 DR->setSpeed(255);
 DL->setSpeed(255);  
  UR->run(BACKWARD);
 UL->run(FORWARD);
 DL->run(BACKWARD);
 DR->run(FORWARD);
    }
    else if (pixy.ccc.blocks[i].m_width < 130 && pixy.ccc.blocks[i].m_height < 90){
      Serial.println("go forward");
   UR->setSpeed(255);
 UL->setSpeed(255);
 DR->setSpeed(255);
 DL->setSpeed(255);  
 UR->run(FORWARD);
 UL->run(FORWARD);
 DL->run(FORWARD);
 DR->run(FORWARD);
    }
    else if (pixy.ccc.blocks[i].m_width > 200 && pixy.ccc.blocks[i].m_height > 130){
      Serial.println("go backward"); 
   
    UR->setSpeed(255);
 UL->setSpeed(255);
 DR->setSpeed(255);
 DL->setSpeed(255);  
  UR->run(BACKWARD);
 UL->run(BACKWARD);
 DL->run(BACKWARD);
 DR->run(BACKWARD);
  }  else {
    UR->setSpeed(0);
 UL->setSpeed(0);
 DR->setSpeed(0);
 DL->setSpeed(0);  
 UR->run(RELEASE);
 UL->run(RELEASE);
 DL->run(RELEASE);
 DR->run(RELEASE);
  }
  }
}
