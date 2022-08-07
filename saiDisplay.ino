/*
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

                    
                                           A T M O S  C O M P U T E R 
                     
This is an program that will control the LEDS on the Sai With one of the two on-control board arduino nanos.


                                                  .    .    .
                              
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
*/



#include <SPI.h>
#include <Adafruit_DotStar.h>

#define NUMPIXELS 200

//create the strip 

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG) ;

void setup() {
  
  strip.begin() ; //initializes the strip
  strip.show() ;  //turn off leds within pixels
    
}

// BOUNCE IS CURRENTLY PLACED IN THE MAIN AND SET UP LOOP
// TO ALTER THIS ALL YOU NEED TO DO IS TITLE THESE AS FUNCTIONS OTHER THAT MAIN AND SETUP AND CALL THEM RESPECTFULLY


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - B O U N C E


void bounceBetween(uint32_t color, uint16_t start, uint16_t finish, uint16_t len) {
  
  int path_length = finish - start ;
  
  //get the light snake moving forward
  for(int i=0 ; i < path_length ; i++){
    
      //populate the snake
    for (int j=0 ; j < len ; j++){
      strip.setPixelColor(i+j+start, color) ;
      strip.show() ;
    }
    
    //write the end of the snake off
    if ( (i+start) <= (finish-len) ){
      strip.setPixelColor(i+start, 0) ;
      strip.setPixelColor(1, 0) ;
      delay(1) ;
    }
  }
  //get the snake moving backwards
  for(int i=0 ; (-1)*i < path_length ; i--){
    
      //populate the snake
    for (int j=0 ; (-1)*j < len ; j--){
      strip.setPixelColor(i+j+finish, color) ;
      strip.show() ;
    }
    
    //write the end of the snake off
    if ( (i+finish) >= (len+start) ){
      strip.setPixelColor(i+finish, 0) ;
      delay(1) ;
    }
  }
}

void bounceBetween2(uint32_t color2, uint16_t start2, uint16_t finish2, uint16_t len2) {
  
  int path_length = finish2 - start2 ;
  
  //get the light snake moving forward
  for(int i=0 ; i < path_length ; i++){
    
      //populate the snake
    for (int j=0 ; j < len2 ; j++){
      strip.setPixelColor(i+j+start2, color2) ;
      strip.show() ;
    }
    
    //write the end of the snake off
    if ( (i+start2) <= (finish2-len2) ){
      strip.setPixelColor(i+start2, 0) ;
      delay(1) ;
    }
  }
  //get the snake moving backwards
  for(int i=0 ; (-1)*i < path_length ; i--){
    
      //populate the snake
    for (int j=0 ; (-1)*j < len2 ; j--){
      strip.setPixelColor(i+j+finish2, color2) ;
      strip.show() ;
    }
    
    //write the end of the snake off
    if ( (i+finish2) >= (len2+start2) ){
      strip.setPixelColor(i+finish2, 0) ;
      delay(1) ;
    }
  }
}


void loop() {
  
  
  uint32_t color = 0x300000 ;
  uint16_t start = 180 ;
  uint16_t finish = 199 ;
  uint16_t len = 2 ;
  
  uint32_t color2 = 0x300000 ;
  uint16_t start2 = 0 ;
  uint16_t finish2 = 9 ;
  uint16_t len2 = 2 ;
  
  
  bounceBetween(color, start, finish, len) ;
  bounceBetween2(color, start, finish, len) ;
    
}


 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - A L L   O N



// Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG) ;

// void setup() {
 //  strip.begin() ; //initializes the strip
  //  strip.show() ;  //turn off leds within pixels
//}


void simple0n(uint32_t color, int tail, int head) {
  
  
  
   
   for (int i=tail; i<head; i++){
     strip.setBrightness(20);
     
     strip.setPixelColor(i, color);
   }  
   
  strip.show() ; 
  
}


void solid() {
  
  int tail = 0 ;
  int head = 199 ;
  uint32_t color = 0x100010 ;
  
  simple0n(color, tail, head) ;
   
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - T E X T

void letter_a(){
  
  
  strip.setPixelColor(193, 0, 0, 255);
  strip.setPixelColor(194, 0, 0, 255);
  strip.setPixelColor(195, 0, 0, 255);
  strip.setPixelColor(196, 0, 0, 255);
  strip.show();
  strip.clear();
  delay(0.66);
  strip.setPixelColor(196, 0, 0, 255);
  strip.show();
  strip.clear();
  delay(0.66);
  strip.setPixelColor(193, 0, 0, 255);
  strip.setPixelColor(194, 0, 0, 255);
  strip.setPixelColor(195, 0, 0, 255);
  strip.setPixelColor(196, 0, 0, 255);
  strip.show();
  strip.clear();
  delay(0.66);
  
}

void letter_t(){
  
  
  strip.setBrightness(20);
  
  delay(2);
  strip.setPixelColor(183, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.66);
  strip.setPixelColor(183, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.4);
  strip.setPixelColor(183, 0, 100, 255);
  strip.setPixelColor(184, 0, 100, 255);
  strip.setPixelColor(185, 0, 100, 255);
  strip.setPixelColor(186, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.4);
  strip.setPixelColor(183, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.4);
  strip.setPixelColor(183, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.4);
  
}


void letter_h(){
  
  
  strip.setBrightness(20);
  strip.setPixelColor(186, 0, 100, 255);
  strip.setPixelColor(189, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.5);
  strip.setPixelColor(186, 0, 100, 255);
  strip.setPixelColor(189, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.5);
  strip.setPixelColor(186, 0, 100, 255);
  strip.setPixelColor(187, 0, 100, 255);
  strip.setPixelColor(188, 0, 100, 255);
  strip.setPixelColor(189, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.5);
  strip.setPixelColor(186, 0, 100, 255);
  strip.setPixelColor(189, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.5);
  strip.setPixelColor(186, 0, 100, 255);
  strip.setPixelColor(189, 0, 100, 255);
  strip.show();
  strip.clear();
}


void shape(){
  
  strip.setBrightness(20);
  
  strip.setPixelColor(189, 0, 100, 255);
  strip.setPixelColor(188, 0, 100, 255);
  strip.setPixelColor(187, 0, 100, 255);
  strip.setPixelColor(186, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.5);
  strip.setPixelColor(189, 0, 0, 0);
  strip.setPixelColor(188, 0, 0, 0);
  strip.setPixelColor(187, 0, 0, 0);
  strip.setPixelColor(186, 0, 0, 0);
  strip.show();
  strip.clear();
  delay(30);
  strip.setPixelColor(196, 0, 100, 255);
  strip.setPixelColor(197, 0, 100, 255);
  strip.setPixelColor(198, 0, 100, 255);
  strip.setPixelColor(199, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.4);
  strip.setPixelColor(177, 0, 100, 255);
  strip.setPixelColor(178, 0, 100, 255);
  strip.show();
  strip.setPixelColor(178, 0, 0, 0);
  strip.setPixelColor(177, 0, 0, 0);
  strip.show();
  strip.clear();
  delay(0.3);
  strip.setPixelColor(167, 0, 100, 255);
  strip.setPixelColor(168, 0, 100, 255);
  strip.show();
  strip.setPixelColor(168, 0, 0, 0);
  strip.setPixelColor(167, 0, 0, 0);
  strip.show();
  strip.clear();
  delay(0.2);
  strip.setPixelColor(157, 0, 100, 255);
  strip.setPixelColor(158, 0, 100, 255);
  strip.show();
  strip.setPixelColor(158, 0, 0, 0);
  strip.setPixelColor(157, 0, 0, 0);
  strip.show();
  strip.clear();
  delay(0.1);
  strip.setPixelColor(147, 0, 100, 255);
  strip.setPixelColor(148, 0, 100, 255);
  strip.show();
  strip.setPixelColor(148, 0, 0, 0);
  strip.setPixelColor(147, 0, 0, 0);
  strip.show();
  strip.clear();
  delay(0.05);
  strip.setPixelColor(137, 0, 100, 255);
  strip.setPixelColor(138, 0, 100, 255);
  strip.show();
  strip.setPixelColor(138, 0, 0, 0);
  strip.setPixelColor(137, 0, 0, 0);
}


void something(){
  strip.setBrightness(20);
  
  strip.setPixelColor(190, 0, 100, 255);
  strip.show();
  delay(3.0);
  strip.clear();
  //strip.setPixelColor(190, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(170, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  //strip.setPixelColor(170, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(151, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  //strip.setPixelColor(151, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(132, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  //strip.setPixelColor(132, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(113, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  //strip.setPixelColor(113, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(94, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  //strip.setPixelColor(94, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(75, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  //strip.setPixelColor(75, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(55, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  //strip.setPixelColor(55, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(36, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  //strip.setPixelColor(36, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(17, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  //strip.setPixelColor(17, 0, 0, 0);
  strip.show();
  delay(30);
  strip.setPixelColor(18, 0, 100, 255);
  strip.setPixelColor(19, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
  strip.setPixelColor(29, 0, 100, 255);
    strip.show();
  delay(30);
  strip.clear();
  strip.setPixelColor(39, 0, 100, 255);
    strip.show();
  delay(30);
  strip.clear();
  strip.setPixelColor(49, 0, 100, 255);
  strip.setPixelColor(59, 0, 100, 255);
    strip.show();
  delay(30);
  strip.clear();
    strip.setPixelColor(69, 0, 100, 255);
  strip.setPixelColor(79, 0, 100, 255);
    strip.show();
  delay(30);
  strip.clear();
    strip.setPixelColor(89, 0, 100, 255);
  strip.setPixelColor(99, 0, 100, 255);
    strip.show();
  delay(30);
  strip.clear();
    strip.setPixelColor(109, 0, 100, 255);
  strip.setPixelColor(119, 0, 100, 255);
    strip.show();
  delay(30);
  strip.clear();
    strip.setPixelColor(129, 0, 100, 255);
  strip.setPixelColor(139, 0, 100, 255);
    strip.show();
  delay(30);
  strip.clear();
    strip.setPixelColor(149, 0, 100, 255);
  strip.setPixelColor(159, 0, 100, 255);
    strip.show();
  delay(30);
  strip.clear();
    strip.setPixelColor(169, 0, 100, 255);
  strip.setPixelColor(179, 0, 100, 255);
    strip.show();
  delay(30);
  strip.clear();
    strip.setPixelColor(189, 0, 100, 255);
  strip.setPixelColor(199, 0, 100, 255);
  strip.show();
  delay(30);
  strip.clear();
}

void hello(){
  
  strip.setBrightness(20);
  
  /*
  
  holo in matrix
  ^^^^
  o - - o - - o o o o [ - - - ] o - - - - - o o o o
  o o o o - - o - - o [ - O - ] o - - - - - o - - o
  o o o o - - o - - o [ - - - ] o - - - - - o - - o
  o - - o - - o o o o [ - - - ] o o o o - - o o o o
  
  holo with matrix delay positioning
  ^^^^
  [189] o - - o - - o o o o [ - - - ] [191] o - - - - o o o o
  delay(0.5);
  [189] o o o o - - o - - o [ - O - ] [191] o - - - - o - - o
  delay(0.5);
  [189] o - - o - - o - - o [ - - - ] [191] o - - - - o - - o
  delay(0.5);
  [189] o - - o - - o o o o [ - - - ] [191] o o o - - o o o o
  delay(0.5);
  
  */
  
  //this is the first line o - - o - - o o o o [ - | - ] o - - - - - o o o o
  strip.setPixelColor(189, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.03);
  strip.setPixelColor(189, 0, 0, 0);
  strip.show();
  strip.clear();
   delay(0.03);
  strip.setPixelColor(186, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.03);
  strip.setPixelColor(186, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.3);
  strip.setPixelColor(180, 0, 100, 255);
  strip.setPixelColor(181, 0, 100, 255);
  strip.setPixelColor(182, 0, 100, 255);
  strip.setPixelColor(183, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.03);
  strip.setPixelColor(180, 0, 0, 0);
  strip.setPixelColor(181, 0, 0, 0);
  strip.setPixelColor(182, 0, 0, 0);
  strip.setPixelColor(183, 0, 0, 0);
  strip.show();
  strip.clear();
  delay(0.03);
  strip.setPixelColor(180, 0, 0, 0);
  strip.setPixelColor(181, 0, 0, 0);
  strip.setPixelColor(182, 0, 0, 0);
  strip.setPixelColor(183, 0, 0, 0);
  strip.setPixelColor(190, 0, 0, 0);
  strip.show();
  strip.clear();
  delay(0.03);
  strip.setPixelColor(190, 0, 100, 255);
  strip.show();
  strip.clear();
  strip.setPixelColor(190, 0, 0, 0);
  strip.show();
  strip.clear();
  delay(0.03);
  strip.setPixelColor(196, 0, 100, 255);
  strip.setPixelColor(197, 0, 100, 255);
  strip.setPixelColor(198, 0, 100, 255);
  strip.setPixelColor(199, 0, 100, 255);
  strip.show();
  strip.clear();
  delay(0.03);
  strip.setPixelColor(196, 0, 0, 0);
  strip.setPixelColor(197, 0, 0, 0);
  strip.setPixelColor(198, 0, 0, 0);
  strip.setPixelColor(199, 0, 0, 0);
  strip.show();
  strip.clear();
  
  
  //this is the second line o - - o - - o o o o [ - | - ] o - - - - - o o o o
}


void loop2() {
  
  strip.show();
  
  if (analogRead(hall) <= 500){
  
    for (i = 0; i < 1; i++){
      
        hello();
        delay(2);
        
        strip.clear();
        
   }
  }
  else{
    
  }

  strip.show();
}
