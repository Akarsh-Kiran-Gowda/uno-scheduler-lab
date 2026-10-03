const int LED = LED_BUILTIN;

struct Task {
    void (*function)();
    unsigned long period;
    unsigned long lastRun;
};

void runTaskA() {
    digitalWrite(LED, !digitalRead(LED));
}

void runTaskB() {
    Serial.println("Task B");
}

Task taskA = {runTaskA, 1000, 0};
Task taskB = {runTaskB, 100, 0};

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {

    unsigned long now = millis();

    // Task A
    if (now - taskA.lastRun >= taskA.period) {
        taskA.lastRun = now;
        taskA.function();
    }

    // Task B
    if (now - taskB.lastRun >= taskB.period) {
        taskB.lastRun = now;
        taskB.function();
    }
}