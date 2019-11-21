
// output pins
int TTL_PIN = 13; // pull high to output
int BUZZER = 9; // buzzzer to arduino pin 9
int START_PIN = 12; // pulse on at start of trial
int SYNC_PIN = 11 ; // pulse on at start of buzzer
int SYNC_PIN_2 = 10 ; // pulse on a start of water delivery 

// intertrial interval
int PAUSE = 30000;

// incoming byte on serial port
int incomingByte = 0; 

// whether to start sequence
int run ; 

void setup() {
  // open serial port
  Serial.begin(9600); 
  // otuput pins:
  pinMode(TTL_PIN, OUTPUT); // TTL pin to output
  pinMode(BUZZER, OUTPUT); // buzzer pin to output
  pinMode(SYNC_PIN, OUTPUT); // 
  pinMode(SYNC_PIN_2, OUTPUT); // 
  //
  run = 0 ;
}

void loop() {
  // put your main code here, to run repeatedly:
  // wait for signal from serial port then begin sequence
  if (run == 0) {
  if (Serial.available() > 0) {
  // read incoming byte
  incomingByte = Serial.read();  
  if (incomingByte == 49) // ACSII 49 is 1 
  {
    if (run == 0) // start running if not previously running
    { 
      run = 1 ;  
    }
    else
    {
      run = 1 ; // remain in 0 if no signal from pyserial
    }
  }
  }
  }
  if (run > 0) 
  { // run seqeunce indefinitely 
  // tone sync pin on
  digitalWrite(SYNC_PIN, HIGH);
  // buzeer on
  tone(BUZZER, 8000);
  // delay
  delay(1300);
  // water delivery sync pin on 
  digitalWrite(SYNC_PIN_2, HIGH);
  // syringe trigger/water delivery pin on 
  digitalWrite(TTL_PIN, HIGH);
  // water delivery delay
  delay(2000);
  // sync pins off
  digitalWrite(SYNC_PIN, LOW);
  digitalWrite(SYNC_PIN_2, LOW);
  // buzzer off
  noTone(BUZZER);
  // syringe trigger off
  digitalWrite(TTL_PIN, LOW);
  // start inter trial interval 
  delay(PAUSE);
  run =0 ;
  }
}
