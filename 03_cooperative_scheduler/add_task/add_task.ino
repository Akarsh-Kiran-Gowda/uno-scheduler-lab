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

void runTaskC() {
    Serial.println("Task C");
}

Task tasks[] = {
    {runTaskA, 1000, 0},
    {runTaskB, 100, 0},
    {runTaskC, 500, 0}
};

const int taskCount = sizeof(tasks) / sizeof(tasks[0]);

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {

    unsigned long now = millis();

    for (int i = 0; i < taskCount; i++) {

        if (now - tasks[i].lastRun >= tasks[i].period) {

            tasks[i].lastRun = now;

            tasks[i].function();
        }
    }
}