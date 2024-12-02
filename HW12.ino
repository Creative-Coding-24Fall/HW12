int potentiometerPin = A0;
int button1Pin = 5;
int button2Pin = 6;
int button1State = 1;
int button2State = 1;
int greenLEDPin = 2;
int redLEDPin   = 3;
int passwordProgress = 0;  //progress of password
void setup() {
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(A0, INPUT);
}

void loop() {
  int potentiometerValue = analogRead((potentiometerPin));
  int s1 = digitalRead(button1Pin);  //0-1
  int s2 = digitalRead(button2Pin);
  if (button1State != s1) {
    button1State = s1;
    if (s1 == 0) {
      //button press to trigger the content
      if (passwordProgress == 0) {
        passwordProgress += 1;
      } else {
        passwordProgress = 0;
      }
    }
  }
  if (button2State != s2) {
    button2State = s2;
    if (s2 == 0) {
      //button press second or third time
      if (passwordProgress == 1 || passwordProgress == 2) {
        passwordProgress += 1;
      } else {
        passwordProgress = 0;
      }
    }
  }
  if (passwordProgress == 3) {
    if (potentiometerValue < 50) {
      passwordProgress += 1;
    }
  }
  if (passwordProgress == 4) {
    if (potentiometerValue > 4000) {
      passwordProgress += 1;
    }
  }
  Serial.print("Button1:");
  Serial.println(button1State);
  Serial.print("Button2:");
  Serial.println(button2State);
  Serial.print("potentiometer:");
  Serial.println(potentiometerValue);


  if (passwordProgress == 5) {
    //if password correct, green light on
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  } else {
    //if password incorrect, red light on
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }
  delay(100);
}
