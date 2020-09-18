#define PIN_LED 7
unsigned int count, toggle, cnt;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200); // Initialize serial port
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  Serial.println("Hello World!");
  count = toggle = cnt = 0;
  digitalWrite(PIN_LED, toggle); // turn off LED.
}

void loop() {
  while(cnt < 1) {
    Serial.println(++cnt);
    toggle = 0;
    digitalWrite(PIN_LED, toggle);
    delay(1000);
  }
  
  Serial.println(++count);
  toggle = toggle_state(toggle); //toggle LED value.
  digitalWrite(PIN_LED, toggle); // update LED status.
  delay(100); // wait for 1,000 milliseconds
  

  while(count > 10) {
    digitalWrite(PIN_LED, 1);
  }


}

int toggle_state(int toggle) {
  if (toggle == 0) {
    toggle = 1;
  }
  else {
    toggle = 0;
  }
  return toggle;
}
