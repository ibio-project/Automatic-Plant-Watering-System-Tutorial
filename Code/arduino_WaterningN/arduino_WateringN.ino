// N-way Plant Watering System
// refactored by T. Endo 2024.1.24
// note: pins 2 & 3 should be reserved for interrupt,
// if moisture level adjustment is planned.

const char* Title = "MOISTURE LEVEL:";
const int Sensor[] = {A0, A1, A2, A3, 0};
const int Pump[] = {2, 3, 4, 5}; //{4, 5, 6, 7};
int level = 750; // ajustable by adding some code.
enum {On = LOW, Off = HIGH, Interval = 1000};

void setup() {
  Serial.begin(9600);
  for (int i = 0; Sensor[i]; i++) {
    pinMode(Sensor[i], INPUT);
    pinMode(Pump[i], OUTPUT);
    digitalWrite(Pump[i], Off);
  }
  delay(500);
}
void loop() {
  Serial.print(Title);
  for (int i = 0; Sensor[i]; i++) {
    int val = analogRead(Sensor[i]);
    Serial.println(val);
    digitalWrite(Pump[i], (val > level) ? On : Off );
    // the higher, the drier
    Serial.println();
  }
  delay(Interval);
}
