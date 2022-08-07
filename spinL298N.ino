
/*
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 

                    
                     A T M O S  C O M P U T E R 
                     

This is an program that will spin a L298N Motor with an arduino for Sai



/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
*/

// Motor A connections
int enA = 7;
int in1 = 8;
int in2 = 6;

int pizo = 2;


const int red = A2;
int r;


void setup() {
  
  Serial.begin(9600);
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(red, INPUT);
	pinMode(pizo, OUTPUT);

	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void loop() {
  

  analogRead(red);
  Serial.println(analogRead(red));
  delay(0);
  
  analogWrite(enA, 150);
  
  for (int i = 100; i < 150; i++) {
	  analogWrite(enA, i);
	  delay(0);
	}
  

	// Turn on motor
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	
	if (analogRead(red) >= 300){
  
    for (r = 0; r < 1; r++){
      
      tone(pizo, 1000);
      delay(10);
      noTone(pizo);
      digitalWrite(in1, LOW);
	    digitalWrite(in2, LOW);
	    analogWrite(enA, 0);
      delay(20);
      tone(pizo, 1000);
      delay(10);
      noTone(pizo);
        
        
   }
  }
  else{
    
  }
	
  
	//directionControl();
	//delay(1000);
	//speedControl();
	//delay(1000);
}

// This function lets you control spinning direction of motors
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 250);
	
	//speed up 
	for (int i = 0; i < 250; i++) {
	analogWrite(enA, i);
	delay(1);
	}

	// Turn on motor
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	
	//delay(2000);
	
	// Now change motor directions
//	digitalWrite(in1, LOW);
//	digitalWrite(in2, HIGH);
//	delay(2000);
	
	// Turn off motors
	//digitalWrite(in1, LOW);
	//digitalWrite(in2, LOW);
}

// This function lets you control speed of the motors
void STOP() {
	// Turn on motors

	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	
	delay(5000);

}
