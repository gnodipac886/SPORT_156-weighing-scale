#include "HX711.h"
#define calibration_factor 8000.0 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define DOUT  3
#define CLK  2
HX711 scale(DOUT, CLK);
void setup() {
    Serial.begin(9600);
    Serial.println("HX711 scale demo");
    scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
    scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
    Serial.println("Readings:");
}
void loop() {
    Serial.print("Reading: ");
    float w8 = scale.get_units();
    if (abs(w8) < 0.5) { //resets w8 to 0 if sensor automatically increments w8, wrong readings
        Serial.print(0.0, 1);
    }
    else {
        Serial.print(w8, 1); //scale.get_units() returns a float
    }
    Serial.print(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
    Serial.println();
}
