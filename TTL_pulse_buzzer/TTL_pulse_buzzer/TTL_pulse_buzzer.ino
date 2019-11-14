
int TTL_PIN = 13; // pull high to output
int BUZZER = 9; // buzzzer to arduino pin 9
int START_PIN = 12; // pulse on at start of trial
int SYNC_PIN = 11 ; // pulse on at start of buzzer
int SYNC_PIN_2 = 10 ; // pulse on a start of water delivery 

int PAUSE = 2000;

void setup() {
  // otuput pins:
  pinMode(TTL_PIN, OUTPUT); // TTL pin to output
  pinMode(BUZZER, OUTPUT); // buzzer pin to output
  pinMode(SYNC_PIN, OUTPUT); // 
  pinMode(SYNC_PIN_2, OUTPUT); // 

  //
}

void loop() {
  // put your main code here, to run repeatedly:
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
  delay(6000);
  // sync pins off
  digitalWrite(SYNC_PIN, LOW);
  digitalWrite(SYNC_PIN_2, LOW);
  // buzzer off
  noTone(BUZZER);
  // syringe trigger off
  digitalWrite(TTL_PIN, LOW);
  // start inter trial interval 
  delay(30000);
}
