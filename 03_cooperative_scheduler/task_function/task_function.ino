const int LED = LED_BUILTIN;

struct Task {
    unsigned long period;
    unsigned long lastRun;
};

Task taskA = {1000, 0};
Task taskB = {100, 0};

void runTaskA() {
    digitalWrite(LED, !digitalRead(LED));
}

void runTaskB() {
    Serial.println("Task B");
}

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {

    unsigned long now = millis();

    // Task A
    if (now - taskA.lastRun >= taskA.period) {
        taskA.lastRun = now;
        runTaskA();
    }

    // Task B
    if (now - taskB.lastRun >= taskB.period) {
        taskB.lastRun = now;
        runTaskB();
    }
}