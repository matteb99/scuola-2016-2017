char let[3] = {'r', 'g', 'v'};
int pins[3] = {3, 5, 6};
int value[3] = {0, 0, 0};
int nled = 3;
int x;
int f = 0;
int R = 0;
int control = 1;
int G = 0;
int V = 0;
unsigned long tempo_last;
void setup() {
  int i;
  Serial.begin(9600);
  for (i = 0; i < nled; i++) {
    pinMode(i, OUTPUT);
  }
}
void loop() {
  int i;
  if (Serial.available() > 0) {
    String led = Serial.readStringUntil('\n');
    x = led.substring(1).toInt();
    x = constrain(x, 0, 255);
    if (led.charAt(0) == 'f') {
      if (x != 0) {
        f = ((1 / x) / 2) * 1000;
      }
      else {
        for (i = 0; i < nled; i++) {
          analogWrite(pins[i], value[i]);
        }
        control == 0;
      }
    }
    else
    {
      for (i = 0; (i < nled) && (led.charAt(0) != let[i]); i++);
      if (i < nled) {
        analogWrite(pins[i], x);
        Serial.print(let[i]);
        Serial.println(x);
        value[i] = x;
      }
    }
    Serial.println(led);
  }
  if (millis() >= tempo_last + f && control == 1) {
    for (i = 0; i < nled; i++) {
      analogWrite(pins[i], value[i]);
    }
  }
}





