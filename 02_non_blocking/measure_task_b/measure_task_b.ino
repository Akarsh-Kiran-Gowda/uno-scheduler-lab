const int LED = LED_BUILTIN;

unsigned long lastA = 0;
unsigned long lastB = 0;
unsigned long previousB = 0;

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {

    unsigned long now = millis();

    // Task A: CPU-heavy work every 1000 ms
    if (now - lastA >= 1000) {
        lastA = now;

        digitalWrite(LED, !digitalRead(LED));

        for (volatile unsigned long i = 0; i < 500000; i++) {
            // deliberately consume CPU time
        }
    }

    // Task B: expected every 100 ms
    if (now - lastB >= 100) {
        lastB = now;

        unsigned long interval = now - previousB;
        previousB = now;

        Serial.print("Task B interval: ");
        Serial.print(interval);
        Serial.println(" ms");
    }
}