#include <Servo.h>

// Define servo objects for three gates
Servo gate1;  // Gate for Cars & Vans
Servo gate2;  // Gate for Motorbikes & Three-wheelers
Servo gate3;  // Gate for Trucks & Buses

void setup() {
    Serial.begin(9600);  // Start Serial Communication
    gate1.attach(9);  // Attach Gate 1 Servo (Cars, Vans)
    gate2.attach(10); // Attach Gate 2 Servo (Motorbikes, Three-wheelers)
    gate3.attach(11); // Attach Gate 3 Servo (Trucks, Buses)

    // Set gates to the initial closed position
    gate1.write(0);
    gate2.write(0);
    gate3.write(0);
    
    Serial.println("System Ready. Waiting for vehicle type...");
}

void loop() {
    if (Serial.available() > 0) {
        String vehicleType = Serial.readStringUntil('\n');  // Read vehicle type
        vehicleType.trim();  // Remove any trailing whitespace

        Serial.print("Vehicle Detected: ");
        Serial.println(vehicleType);

        if (vehicleType == "Car" || vehicleType == "Van") {
            openGate(gate1, "Gate 1 (Car/Van)");
        } 
        else if (vehicleType == "motorbike" || vehicleType == "threewheel") {
            openGate(gate2, "Gate 2 (Motorbike/Three-wheel)");
        } 
        else if (vehicleType == "truck" || vehicleType == "bus") {
            openGate(gate3, "Gate 3 (Truck/Bus)");
        } 
        else {
            Serial.println("Unknown vehicle type. No action taken.");
        }
    }
}

void openGate(Servo gate, String gateName) {
    Serial.print(gateName);
    Serial.println(" is opening...");

    gate.write(90);   // Rotate 90 degrees to open
    delay(3000);      // Keep the gate open for 3 seconds

    Serial.print(gateName);
    Serial.println(" is closing...");
    
    gate.write(0);    // Close the gate
}
