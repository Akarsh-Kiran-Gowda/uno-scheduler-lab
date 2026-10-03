const int LED = LED_BUILTIN;

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {

    // Task A: slow operation
    digitalWrite(LED, HIGH);
    delay(1000);

    digitalWrite(LED, LOW);
    delay(1000);

    // Task B: supposed to be a fast heartbeat
    Serial.println("Task B");
    delay(100);
}