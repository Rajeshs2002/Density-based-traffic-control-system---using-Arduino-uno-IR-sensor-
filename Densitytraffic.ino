

#define ledA1 2
#define ledA2 3
#define ledA3 4

#define ledB1 5
#define ledB2 6
#define ledB3 7

#define ledC1 8
#define ledC2 9
#define ledC3 10

#define ledD1 11
#define ledD2 12
#define ledD3 13

int a, b, c, d;

void setup() {

  Serial.begin(9600);

  pinMode(ledA1, OUTPUT);
  pinMode(ledA2, OUTPUT);
  pinMode(ledA3, OUTPUT);

  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);
  pinMode(ledB3, OUTPUT);
    
  pinMode(ledC1, OUTPUT);
  pinMode(ledC2, OUTPUT);
  pinMode(ledC3, OUTPUT);

  pinMode(ledD1, OUTPUT);
  pinMode(ledD2, OUTPUT);
  pinMode(ledD3, OUTPUT);
}

void loop() {

  readSensor();

  if (a == 1) {
    roadAopen();
  } else if (b == 1 && (a == 0)) {
    roadBopen();
    if ( a == 1) {
      roadAopen();
    }
  } else if (c == 1 && (b == 0 || a == 0)) {
    roadCopen();
    if (a == 1) {
      roadAopen();
    } else if (b == 1 && (a == 0)) {
      roadBopen();
    }
  } else if (d == 1 && (b == 0 || a == 0 || c == 0)) {
    roadDopen();
    if (b == 1) {
      roadBopen();
    } else if (b == 1 && (a == 0 )) {
      roadBopen();
    }
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if ((a == 1) && (d == 1 || b == 1 || c == 1)) {
    roadAopen();
  } else if ((b == 1) && (d == 1 || c == 1) && (a == 0)) {
    roadBopen();
  } else if ((c == 1) && (d == 1) && (b == 0) && (a == 0)) {
    roadCopen();
  } else if ((d == 1) && (a == 0) && (b == 0) && (c == 0)) {
    roadDopen();
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if ((a == 1) && (d == 0) && (b == 0) && (c == 0)) {
    roadAopen();
  } else if ((b == 1) && (d == 0) && (a == 0 ) && (c == 0)) {
    roadBopen();
  } else if((c == 1) && (d == 0) && (a == 0 ) && (b == 0)) {
    roadCopen();
  }
  else if ((d == 1) && (a == 0) && (b == 0) && (c == 0)) {
    roadDopen();
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if (c == 0 && a == 0 && d == 0 && b == 0) {
    roadAopen();
    if (c == 0 && a == 0 && d == 0 && b == 0) {
      roadBopen();
    }
    if (a == 0 && b == 0 && c == 0 && d == 0) {
      roadCopen();
    }
    if (a == 0 && b == 0 && c == 0 && d == 0) {
      roadDopen();
    }
  }
}

void readSensor() {
  a = analogRead(A0);
  b = analogRead(A1);
  c = analogRead(A2);
  d = analogRead(A3);

   if (a < 400) Serial.print("\n Road 1 = High density\n");
  else Serial.print("\n Road 1 = normal density \n");
  if (a < 400) a =1;
  else a =0;
   if (b < 400) Serial.print("Road 2 = High density\n");
  else Serial.print("Road 2 = normal density \n");
  if (b < 400) b = 1; 
  else b = 0;
   if (c < 400) Serial.print("Road 3 = High density\n");
  else Serial.print("Road 3 = normal density \n");
  if (c < 400) c = 1;
  else c = 0;
   if (d < 400) Serial.print("Road 4 = High density\n");
  else Serial.print("Road 4 = normal density \n");
  if (d < 400) d = 1;
  else d = 0;

  Serial.print(a);
  Serial.print("\t");
  Serial.print(b);
  Serial.print("\t");
  Serial.print(c);
  Serial.print("\t");
  Serial.print(d);
  Serial.print("\t");
}

void roadAopen() {
  digitalWrite(ledA3, LOW);

  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledA2, HIGH);
  delay(1000);
  digitalWrite(ledA2, LOW);
  readSensor();
}

void roadBopen() {
  digitalWrite(ledB3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledB1, LOW);
  digitalWrite(ledB2, HIGH);
  delay(1000);
  digitalWrite(ledB2, LOW);
  readSensor();
}

void roadCopen() {
  digitalWrite(ledC3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledC1, LOW);
  digitalWrite(ledC2, HIGH);
  delay(1000);
  digitalWrite(ledC2, LOW);
  readSensor();
}

void roadDopen() {
  digitalWrite(ledD3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD1, HIGH);
  delay(10000);
  digitalWrite(ledD1, LOW);
  digitalWrite(ledD2, HIGH);
  delay(1000);
  digitalWrite(ledD2, LOW);
  readSensor();
}
