#include <Servo.h>
#include <LiquidCrystal.h>

const int rs = 14, en = 15, d4 = 16, d5 = 17, d6 = 18, d7 = 19;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//LCD Custom Stuff

byte DownCurve[] = {B00000,B01110,B10001,B10001,B00000,B00000,B00000,B00000};
byte UpCurve[] = {B00000,B00000,B00000,B00000,B00001,B10001,B01110,B00000};
byte DollarSign[] = {B00100,B01110,B10101,B10100,B01110,B00101,B10101,B01110};
byte LeftSmile[] = {B00000,B00000,B10000,B11000,B01100,B00111,B00011,B00000};
byte RightSmile[] = {B00000,B00000,B00001,B00011,B00110,B11100,B11000,B00000};
byte MiddleSmile[] = {B00000,B00000,B00000,B00000,B00000,B11111,B11111,B00000};
byte LeftHeart[] = {B00000,B01110,B11111,B11111,B11111,B01111,B00111,B00001};
byte RightHeart[] = {B00000,B01110,B11111,B11111,B11111,B11110,B11100,B10000};
byte LeftEyebrow[] = {B11000,B01100,B00110,B00011,B00001,B00000,B00000,B00000};
byte RightEyebrow[] = {B00011,B00110,B01100,B11000,B10000,B00000,B00000,B00000};
byte IdleLips[] = {B01110,B10001,B00001,B00110,B00001,B00001,B10001,B01110};
byte Wink[] = {B00000,B00000,B00000,B10001,B10001,B01110,B00000,B00000};
byte MiniHeart[] = {B00000,B00000,B11011,B11111,B01110,B00100,B00000,B00000};




//Servo Pins Declare!!! ALWAYS FIRST DO RESET SERVO AFTER APPLYING NEW POWER
int Micro_servo_attach = 10;  //The little servo on the top
int Micro_servo_pos = 0;
int Left_servo_attach = 11;
int Left_servo_pos = 0;
int Right_servo_attach = 12;
int Right_servo_pos = 0;
int Servo_delay_time = 7;
int Motor_delay_time = 15;
int Dance_delay_time = 500; //This controls the movement time for car's every dance

char Previous_input = '0'; //Initialize the previous input, so we dont mess things up

//Motor Pins Declare!!!
int wheel1_1 = 2;  //wheel 1 is the front right wheel
int wheel1_2 = 3;
int wheel2_1 = 4;  // wheel 2 is the rear right wheel
int wheel2_2 = 5; //The pins declare is to be continued
int wheel3_1 = 6;
int wheel3_2 = 7;
int wheel4_1 = 8;
int wheel4_2 = 9; 

// Keyboard Bindings Declare!!
char All_servo_reset_key = 'f';
char Micro_servo_reset_key = 'g';
char Micro_servo_forward_key = 'r';
char Micro_servo_backward_key = 'v';
char Left_servo_forward_key = 'q';
char Left_servo_backward_key = 'z';
char Right_servo_forward_key = 'e';
char Right_servo_backward_key = 'c'; 

char Car_forward_key = 'w';
char Car_backward_key = 's';
char Car_left_key = 'a';
char Car_right_key = 'd';
char Car_stop_key = 'p';

char Car_dance_key = 'l'; //Lower case 'L'

Servo microservo;
Servo leftservo;
Servo rightservo;


//SERVO CONTROL FUNCTION HERE
void All_servo_reset(int *Micro_pos, int *Left_pos, int *Right_pos){  //This will set all motors to the original position, which is 0.
  //It will also set the Servo position variable to 0!
  int Previous_micro = microservo.read();  //Where's the last position of the servo?
  int Previous_right = rightservo.read();
  int Previous_left = leftservo.read();

  for(Previous_micro = microservo.read(); Previous_micro > 0; Previous_micro--){
    Serial.println("Servo reset progress");
    microservo.write(Previous_micro);
    delay(Servo_delay_time);
    }
  for(Previous_right = rightservo.read(); Previous_right > 0; Previous_right--){
    rightservo.write(Previous_right);
    delay(Servo_delay_time);
    }  

  for(Previous_left = leftservo.read(); Previous_left > 0; Previous_left--){
    leftservo.write(Previous_left);
    delay(Servo_delay_time);
    }
    // Reset the Servo position in the main scope:
  *Micro_pos = 0;
  *Left_pos = 0;
  *Right_pos = 0;

  
  
  
  }

void Micro_servo_reset (int *Micro_pos){
  int Previous_micro = microservo.read();
  for(Previous_micro = microservo.read(); Previous_micro > 0; Previous_micro--){
    microservo.write(Previous_micro);
    delay(Servo_delay_time);
    }
  *Micro_pos = 0;
  
  }

void Micro_servo_half (int *Micro_pos){
  int Previous_micro = microservo.read();
  for(Previous_micro = microservo.read(); Previous_micro < 90; Previous_micro++){
    microservo.write(Previous_micro);
    delay(Servo_delay_time);
    }
  *Micro_pos = 90;
  
  
  }
int Check_all_reset(char Keyboard_input){
  if (Keyboard_input == All_servo_reset_key)
    return 1;
  else
    return 0;
  }

int Check_micro_reset(char Keyboard_input){
  if(Keyboard_input == Micro_servo_reset_key)
    return 1;
  else
    return 0;
  }


int Check_micro_forward(char Keyboard_input){
  if(Keyboard_input == Micro_servo_forward_key)
    return 1;
  else
    return 0;
  }

void Micro_servo_forward(int *Micro_pos){  //Micro servo will go forward by 1 degree.
                                            //Everytime it receives an input.
  if(*Micro_pos < 180){
    Serial.print("Micro forward");
    Serial.println(*Micro_pos);
    *Micro_pos += 1;
    microservo.write(*Micro_pos);  
    Serial.print("Turning forward:");
    Serial.println(*Micro_pos);
    delay(Servo_delay_time);
    }
  else
    Serial.println("Micro Servo Max reached!");
  
  }

int Check_micro_backward(char Keyboard_input){
  if(Keyboard_input == Micro_servo_backward_key)
    return 1;
  else
    return 0;
  }

void Micro_servo_backward(int *Micro_pos){

  if(*Micro_pos > 0){
    *Micro_pos -= 1;
    Serial.println("Servo backward!");
    microservo.write(*Micro_pos);
    delay(Servo_delay_time);
    }
  }


int Check_left_forward(char Keyboard_input){
  if(Keyboard_input == Left_servo_forward_key)
    return 1;
  else
    return 0;
  
  }

void Left_servo_forward(int *Left_pos){
  if(*Left_pos < 180){
    *Left_pos += 1;
    leftservo.write(*Left_pos);
    delay(Servo_delay_time);
    }
  
  }

int Check_left_backward(char Keyboard_input){
  if(Keyboard_input == Left_servo_backward_key)
    return 1;
  else
    return 0;
  }

void Left_servo_backward(int *Left_pos){
  if(*Left_pos > 0){
    *Left_pos -= 1;
    leftservo.write(*Left_pos);
    delay(Servo_delay_time);
    
    }
  
  }

int Check_right_forward(char Keyboard_input){
  if(Keyboard_input == Right_servo_forward_key)
    return 1;
  else
    return 0;
  
  }


void Right_servo_forward(int *Right_pos){
  if(*Right_pos < 180){
    *Right_pos += 1;
    rightservo.write(*Right_pos);
    delay(Servo_delay_time);
    
    }
  }

int Check_right_backward(char Keyboard_input){
  if(Keyboard_input == Right_servo_backward_key)
    return 1;
  else
    return 0;
  }

void Right_servo_backward(int *Right_pos){
  if(*Right_pos > 0){
    *Right_pos -=1;
    rightservo.write(*Right_pos);
    delay(Servo_delay_time);
    }
  }


// MOTOR CONTROLS FUNCTION HERE

//The motor controls only set the state of the car(forward, backward, etc.)
//Unlike motor, it will not auto stop. (Motor only turn 1 deg at the time and will only turn continuously when there are continuous inputs.)

void Car_forward(int wheel1_1, int wheel1_2, int wheel2_1, int wheel2_2, int wheel3_1 , int wheel3_2, int wheel4_1, int wheel4_2){


  
  digitalWrite(wheel1_1, LOW);
  digitalWrite(wheel1_2, HIGH);
  digitalWrite(wheel2_1, LOW);
  digitalWrite(wheel2_2, HIGH);
  digitalWrite(wheel3_1, HIGH);
  digitalWrite(wheel3_2, LOW);
  digitalWrite(wheel4_1, HIGH);
  digitalWrite(wheel4_2, LOW);
  
  }

void Car_backward(int wheel1_1, int wheel1_2, int wheel2_1, int wheel2_2, int wheel3_1 , int wheel3_2, int wheel4_1, int wheel4_2){
  
  
  digitalWrite(wheel1_1, HIGH);
  digitalWrite(wheel1_2, LOW);
  digitalWrite(wheel2_1, HIGH);
  digitalWrite(wheel2_2, LOW);
  digitalWrite(wheel3_1, LOW);
  digitalWrite(wheel3_2, HIGH);
  digitalWrite(wheel4_1, LOW);
  digitalWrite(wheel4_2, HIGH);
  
  }




void Car_left(int wheel1_1, int wheel1_2, int wheel2_1, int wheel2_2, int wheel3_1 , int wheel3_2, int wheel4_1, int wheel4_2){
  digitalWrite(wheel1_1, HIGH);
  digitalWrite(wheel1_2, LOW);
  digitalWrite(wheel2_1, HIGH);
  digitalWrite(wheel2_2, LOW); 
  digitalWrite(wheel3_1, HIGH);
  digitalWrite(wheel3_2, LOW);
  digitalWrite(wheel4_1, HIGH);
  digitalWrite(wheel4_2, LOW);
  }


void Car_right(int wheel1_1, int wheel1_2, int wheel2_1, int wheel2_2, int wheel3_1 , int wheel3_2, int wheel4_1, int wheel4_2){
  digitalWrite(wheel1_1, LOW);
  digitalWrite(wheel1_2, HIGH);
  digitalWrite(wheel2_1, LOW);
  digitalWrite(wheel2_2, HIGH);
  digitalWrite(wheel3_1, LOW);
  digitalWrite(wheel3_2, HIGH);
  digitalWrite(wheel4_1, LOW);
  digitalWrite(wheel4_2, HIGH);
  }

void Car_stop(int wheel1_1, int wheel1_2, int wheel2_1, int wheel2_2, int wheel3_1 , int wheel3_2, int wheel4_1, int wheel4_2){
  digitalWrite(wheel1_1, LOW);
  digitalWrite(wheel1_2, LOW);
  digitalWrite(wheel2_1, LOW);
  digitalWrite(wheel2_2, LOW);
  digitalWrite(wheel3_1, LOW);
  digitalWrite(wheel3_2, LOW);
  digitalWrite(wheel4_1, LOW);
  digitalWrite(wheel4_2, LOW);
  
  }

int Check_car_forward(char Keyboard_input){
  if(Keyboard_input == Car_forward_key)
    return 1;
  else
    return 0;
  
  }

int Check_car_backward(char Keyboard_input){
  if(Keyboard_input == Car_backward_key)
    return 1;
  else
    return 0;
  
  }

int Check_car_left(char Keyboard_input){
  if(Keyboard_input == Car_left_key)
    return 1;
  else
    return 0;
  
  }

int Check_car_right(char Keyboard_input){
  if(Keyboard_input == Car_right_key)
    return 1;
  else
    return 0;
  
  
  }


int Check_car_stop(char Keyboard_input){
  if(Keyboard_input == Car_stop_key)
    return 1;
  else
    return 0;
  
  }

int Check_car_dance(char Keyboard_input){
  if(Keyboard_input == Car_dance_key)
    return 1;
  else
    return 0;
  
  }

void Car_dance(int wheel1_1, int wheel1_2, int wheel2_1, int wheel2_2, int wheel3_1 , 
int wheel3_2, int wheel4_1, int wheel4_2, int *Micro_pos, int *Left_pos, int *Right_pos){
  Car_forward(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  Car_stop(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  Car_left(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  Car_stop(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  Car_backward(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  Car_stop(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  Car_right(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  Car_stop(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  Car_forward(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  Car_stop(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
  delay(Dance_delay_time);
  int i = 0;
  for(i = 0; i < Dance_delay_time / Motor_delay_time; i ++){
    Left_servo_forward(&(*Left_pos));
    Right_servo_forward(&(*Right_pos));
    }
  delay(Dance_delay_time);
  for(i = 0; i < Dance_delay_time / Motor_delay_time; i ++){
    Left_servo_forward(&(*Left_pos));
    Right_servo_forward(&(*Right_pos));
    }
  delay(Dance_delay_time);
  for(i = 0; i < Dance_delay_time / Motor_delay_time; i ++){
    Left_servo_forward(&(*Left_pos));
    Right_servo_forward(&(*Right_pos));
    }
  delay(Dance_delay_time);
  for(i = 0; i < Dance_delay_time / Motor_delay_time; i ++){
    Left_servo_backward(&(*Left_pos));
    Right_servo_backward(&(*Right_pos));
    }
  delay(Dance_delay_time);
  Micro_servo_reset(&(*Micro_pos));
  Micro_servo_half(&(*Micro_pos));
  Micro_servo_reset(&(*Micro_pos));
  Micro_servo_half(&(*Micro_pos));
  delay(Dance_delay_time);
  delay(Dance_delay_time);

  All_servo_reset(&(*Micro_pos), &(*Left_pos), &(*Right_pos));
    
    
  
  
  }


//LCD_function declare

void Forward() {  
  //when Block-E moves forward
  //A sinister look... what's Block-E up to...
  
  lcd.createChar(1,LeftEyebrow);
  lcd.setCursor(4,0);
  lcd.write(1);
  
  lcd.createChar(2,RightEyebrow);
  lcd.setCursor(11,0);
  lcd.write(2);
  
  lcd.createChar(3,LeftSmile);
  lcd.setCursor(6,1);
  lcd.write(3);
  
  lcd.createChar(4,MiddleSmile);
  lcd.setCursor(7,1);
  lcd.write(4);
  
  lcd.createChar(5,MiddleSmile);
  lcd.setCursor(8,1);
  lcd.write(5);
  
  lcd.createChar(6,RightSmile);
  lcd.setCursor(9,1);
  lcd.write(6);

   lcd.setCursor(3,0);
    lcd.print("o");
    lcd.setCursor(12,0);
    lcd.print("o");
    
   }

void nauseous() {  
  //when Block-E moves in the reverse direction
  //this makes Block-E kinda nauseous :(
  
  lcd.createChar(byte(0), UpCurve);
  lcd.setCursor(4,1);
  lcd.write(byte(0));
  
  lcd.createChar(1, DownCurve);
  lcd.setCursor(5,1);
  lcd.write(1);
  
  lcd.createChar(2, UpCurve);
  lcd.setCursor(6,1);
  lcd.write(2);
  
  lcd.createChar(3, DownCurve);
  lcd.setCursor(7,1);
  lcd.write(3);
  
  lcd.createChar(4, UpCurve);
  lcd.setCursor(8,1);
  lcd.write(4);
  
  lcd.createChar(7, DownCurve);
  lcd.setCursor(9,1);
  lcd.write(7);
  
  lcd.createChar(5, UpCurve);
  lcd.setCursor(10,1);
  lcd.write(5);
  
  lcd.createChar(6, DownCurve);
  lcd.setCursor(11,1);
  lcd.write(6);

  lcd.setCursor(3,0);
    lcd.print("o");
  lcd.setCursor(12,0);
    lcd.print("o");
  
}


void Left() {
  lcd.setCursor(4,0);
    lcd.print("-->  -->");
    lcd.setCursor(7,1);
    lcd.print("--");
}


void Right() {
  lcd.setCursor(4,0);
    lcd.print("<--  <--");
    lcd.setCursor(7,1);
    lcd.print("--");
}

void MiniServoMoves() {  
  //when Block-E moves its miniservo
  //This is Block-E’s money-makin’ face
  
  lcd.createChar(2, DollarSign);
  lcd.setCursor(3,0);
  lcd.write(2);
  
  lcd.createChar(3, DollarSign);
  lcd.setCursor(12,0);
  lcd.write(3);
  
  lcd.createChar(4,LeftSmile);
  lcd.setCursor(6,1);
  lcd.write(4);
  
  lcd.createChar(5,MiddleSmile);
  lcd.setCursor(7,1);
  lcd.write(5);
  
  lcd.createChar(6,MiddleSmile);
  lcd.setCursor(8,1);
  lcd.write(6);
  
  lcd.createChar(7,RightSmile);
  lcd.setCursor(9,1);
  lcd.write(7);
}

void ArmsMove() {  
  //when Block-E moves its BIG Servos (Either Arm)
  
  lcd.createChar(1,LeftHeart);
  lcd.setCursor(3,0);
  lcd.write(1);
  
  lcd.createChar(2,RightHeart);
  lcd.setCursor(4,0);
  lcd.write(2);
  
  lcd.createChar(3,LeftHeart);
  lcd.setCursor(10,0);
  lcd.write(3);
  
  lcd.createChar(4,RightHeart);
  lcd.setCursor(11,0);
  lcd.write(4);
  
  lcd.createChar(5,LeftSmile);
  lcd.setCursor(6,1);
  lcd.write(5);
  
  lcd.createChar(6,MiddleSmile);
  lcd.setCursor(7,1);
  lcd.write(6);
  
  lcd.createChar(7,RightSmile);
  lcd.setCursor(8,1);
  lcd.write(7);
}


void Idle() {
  //Block-E is a big flirter
  lcd.setCursor(11,0);
  lcd.print("o");
  
  lcd.createChar(2, Wink);
  lcd.setCursor(5,0);
  lcd.write(2);
    
  lcd.createChar(3, IdleLips);
  lcd.setCursor(8,1);
  lcd.write(3);
  
  lcd.createChar(4,MiniHeart);
  lcd.setCursor(9,1);
  lcd.write(4);
}


char Get_keyboard_input(){  //This is unused, the get keyboard input is done in main loop.
  
  
  }


void setup() {
  // put your setup code here, to run once:
  microservo.attach(Micro_servo_attach);
  leftservo.attach(Left_servo_attach);
  rightservo.attach(Right_servo_attach);

//LCD pins
  lcd.begin(16, 2);
  lcd.home();   //Set the cursor to top left corner.
  
  
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);

  
  pinMode(wheel1_1, OUTPUT);
  pinMode(wheel2_2, OUTPUT);
  pinMode(wheel2_1, OUTPUT);
  pinMode(wheel2_2, OUTPUT);
  pinMode(wheel3_1,OUTPUT);
  pinMode(wheel3_2,OUTPUT);
  pinMode(wheel4_1, OUTPUT);
  pinMode(wheel4_2,OUTPUT);
  Serial.begin(115200);
while(!Serial){
  ;
}
}

void loop() {
  // put your main code here, to run repeatedly:

  /*or (Micro_servo_pos = 0; Micro_servo_pos < 70; Micro_servo_pos++){
    microservo.write(Micro_servo_pos);
    delay(20);
    }*/
  
    char Keyboard_input = Serial.read();

  

  if(Serial.available()){ 
    //testing only
    Keyboard_input = Serial.read();
    //testing only
   if(Check_all_reset(Keyboard_input) == 1)  // By pressing r, we reset all motors to 0. 
     All_servo_reset(&Micro_servo_pos, &Left_servo_pos, &Right_servo_pos);

   

   if(Check_micro_reset(Keyboard_input) == 1)
     Micro_servo_reset(&Micro_servo_pos);


   if(Check_micro_forward(Keyboard_input) == 1){

    if(Keyboard_input != Previous_input){
      lcd.clear();
      MiniServoMoves();
      }
     Micro_servo_forward(&Micro_servo_pos);  //Make the servo forward for 1 degree. 
     
     
     }

   if(Check_micro_backward(Keyboard_input) == 1){
    if(Keyboard_input != Previous_input){
      lcd.clear();
      MiniServoMoves();
      }
    
     Micro_servo_backward(&Micro_servo_pos);
     
     }

   if(Check_left_forward(Keyboard_input)== 1){
    if(Keyboard_input != Previous_input){
      lcd.clear();
      ArmsMove();
      
      
      }
    
     Left_servo_forward(&Left_servo_pos);
     
     }
   
   if(Check_left_backward(Keyboard_input) == 1){
      if(Keyboard_input != Previous_input){
      lcd.clear();
      ArmsMove();
      
      
      }
    
     Left_servo_backward(&Left_servo_pos);
     }

   if(Check_right_forward(Keyboard_input) == 1){
    if(Keyboard_input != Previous_input){
      lcd.clear();
      ArmsMove();
      
      
      }
     Right_servo_forward(&Right_servo_pos);
     }

   if(Check_right_backward(Keyboard_input) == 1){
    if(Keyboard_input != Previous_input){
      lcd.clear();
      ArmsMove();
      
      
      }
     Right_servo_backward(&Right_servo_pos);
     
     }


   if(Check_car_forward(Keyboard_input) == 1){
    if(Keyboard_input != Previous_input){
      lcd.clear();
      Forward();
      
      
      }
    
     Car_forward(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
     
     }

   if(Check_car_backward(Keyboard_input) == 1){
    if(Keyboard_input != Previous_input){
      lcd.clear();
      
      nauseous();
      
      
      }
    
     Car_backward(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
     }

   if(Check_car_left(Keyboard_input) == 1){
    if(Keyboard_input != Previous_input){
      lcd.clear();
      
      Left();
      
      
      }

    
     Car_left(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
     
     }

   if(Check_car_right(Keyboard_input) == 1){
    if(Keyboard_input != Previous_input){
      lcd.clear();
      
      Right();
      
      
      }
    
     Car_right(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2); 
     }

   if(Check_car_stop(Keyboard_input) == 1){
    if(Keyboard_input != Previous_input){
      lcd.clear();
      
      Idle();
      
      
      }
    
     Car_stop(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
     
     }

   if(Check_car_dance(Keyboard_input) == 1)
     Car_dance(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2,&Micro_servo_pos, &Left_servo_pos, &Right_servo_pos);


   char Previous_input = Keyboard_input;
     
     
     }

 /*else{
    Car_stop(wheel1_1, wheel1_2, wheel2_1, wheel2_2, wheel3_1, wheel3_2, wheel4_1, wheel4_2);
    Serial.println("Car stowawwwwps!");
   }

 */  
    


    
    

  
}
