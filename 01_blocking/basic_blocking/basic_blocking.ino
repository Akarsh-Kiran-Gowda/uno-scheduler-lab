const int LED = LED_BUILTIN;

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {

    // Task A: blink the LED
    digitalWrite(LED, HIGH);
    delay(1000);

    digitalWrite(LED, LOW);
    delay(1000);

    // Task B: heartbeat
    Serial.println("Heartbeat");
}