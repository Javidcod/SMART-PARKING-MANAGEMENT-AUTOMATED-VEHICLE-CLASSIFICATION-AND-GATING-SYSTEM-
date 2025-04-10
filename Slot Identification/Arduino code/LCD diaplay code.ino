#include <LiquidCrystal.h>

// Define LCD pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
    Serial.begin(9600); // Start Serial Communication
    lcd.begin(16, 2);   // Initialize 16x2 LCD
    lcd.print("Waiting...");
}

void loop() {
    if (Serial.available() > 0) {
        String data = Serial.readStringUntil('\n'); // Read data from Python
        int availableSlots = data.toInt();  // Convert to integer

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Slots Available:");
        lcd.setCursor(5, 1);
        lcd.print(availableSlots);  // Display number of slots
    }
}
