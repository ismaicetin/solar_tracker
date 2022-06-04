/* This program has been written (poorly) by Dan of the Simple Electronics Youtube channel
   (www.SimpleElectronics.ca) and is available for you to do whatever you want with it as
   long as you don't hold me responsible. But if you want to send me money for my terrible
   coding, feel free! (www.patreon.com/SimpleElectronics)
*/

//Include the Arduino stepper library
#include <Stepper.h>

//Set how many steps it takes to make a full revolution
//Divide the degrees per step by 360 to get the steps
const int stepsPerRevolution =  48;  //motor 48 adım atınca 1 tur dönuyor demek bunu step motor ozelligi belirliyor
//360/48=7,5  motor 1 step atınca 7,5 derece donuyor


int ldrlt = A0; //LDR top left//top
int ldrrt = A3; //LDR top rigt// bottom
int ldrld = A2; //LDR down left //left
int ldrrd = A1; //ldr down rigt//right

 

//Use pin 8-11 to IN1-IN4

Stepper sagsolStepper  = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper  ilerigeriStepper = Stepper(stepsPerRevolution, 4, 6, 5, 7);

void setup() {
  Serial.begin(9600);
  //Set the RPM of the stepper motor
  sagsolStepper.setSpeed(50); //  motorun rpm hızı = 50
  ilerigeriStepper.setSpeed(50);

}

void loop() {



  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt

  //    Serial.print(lt);
  //    Serial.print(" ");
  //    Serial.print(rt);
  //    Serial.print(" ");
  //    Serial.print(ld);
  //    Serial.print(" ");
  //    Serial.print(rd);
  //    Serial.print("   ");
  //    Serial.println(" ");



  // int dtime = analogRead(4)/20; // read potentiometers
  // int tol = analogRead(5)/4;
  int dtime = 10;
  int tol = 10; // 20;//hassasiyet

  //    int avt = (lt + rt) / 2; // average value top
  //    int avd = (ld + rd) / 2; // average value down
  //    int avl = (lt + ld) / 2; // average value left
  //    int avr = (rt + rd) / 2; // average value right




  int avt = lt; // average value top
  int avd =  ld  ; // average value down
  int avl =  rd  ; // average value left
  int avr = rt; // average value right


  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt



  Serial.print(avt);
  Serial.print(" ");
  Serial.print(avd);
  Serial.print(" ");
  Serial.print(avl);
  Serial.print(" ");
  Serial.print(avr);
  Serial.print("   ");
  Serial.print(tol);
  Serial.println(" ");


  if (-1 * tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
  {
    if (avl > avr)
    { sagsolStepper.step(-1);
    }
    else if (avl < avr)
    { sagsolStepper.step(1);


    }

  }

  if (-1 * tol > dvert || dvert > tol) // check if the diffirence is in the tolerance else change vertical angle
  {
    if (avt > avd)
    { ilerigeriStepper.step(1);

    }
    else if (avt < avd)
    {
      ilerigeriStepper.step(-1);
    }
  }





  //stepMotor.step(24); // motor 24 step dönecek // 24*7,5=180 derece dönecek

  delay(dtime);

}




//https://www.robocombo.com/blog/icerik/arduino-ile-step-motor-kontrolu#:~:text=Arduino'daki%205V%20
//https://elektrikelektronikprojeleri.blogspot.com/2015/04/arduino-step-motor-kontrolu.html

 
