int led1 = D7; // on-board LED
int photoTransistor = A0; // photoTransistor
int lightLevel; // var for photoTransistor

void setup() {
    
    pinMode(led1, OUTPUT);
    pinMode(photoTransistor, INPUT); // input = read

}

void loop() {
    
    lightLevel = analogRead(photoTransistor); // 0 = no light to 255 = a lot of light
    
    digitalWrite(led1, HIGH); //Turn on LED
    Particle.publish("lightLevel", String(lightLevel), PRIVATE); // Trigger the integration
    delay(15000); // wait 15 seconds
    
    digitalWrite(led1, LOW); //Turn off LED
    delay(15000); // wait 15 seconds
  
}

