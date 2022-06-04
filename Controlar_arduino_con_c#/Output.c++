const int Pin_Led = 10;

void setup(){
    Serial.begin(9600);
    pinMode(Pin_Led, OUTPUT);
}

void loop() {
    if (Serial.available() > 0)
    {
        int character = Serial.read();

        if (character == 'ON')
        {
            digitalWrite(Pin_Led, HIGH);
        }else if (character == 'OFF')
        {
            digitalWrite(Pin_Led, LOW);
        }
    }
}