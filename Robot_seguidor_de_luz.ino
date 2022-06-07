  int valorA2; //variable sensor luz izquierdo, controla motor derecho
 int valorA1; //variable sensor luz derecho, controla motor izquierdo
 int motorderecho=11;
 int motorizquierdo=10; 
     void setup () 
{
     pinMode (10, OUTPUT); //Salida digital control motor izquierdo
     pinMode (11, OUTPUT); //Salida digital control motor derecho
     pinMode(7, OUTPUT);
     pinMode(8,OUTPUT);
     Serial.begin (9600); // Comunicación ARDUINO ordenador
}
    void loop() {
      digitalWrite(7,HIGH);
      delay(100);
      digitalWrite(7,LOW);
      delay(100);
      digitalWrite(8,HIGH);
      delay(100);
      digitalWrite(8,LOW);
      delay(100);
    valorA2=analogRead(A2); //Valor señal de entrada sensor izquierdo
    valorA1=analogRead(A1); // Valor señal de entrada sensor derecho
    Serial.println (valorA1); //Visualizar valor señal en ordenador
    Serial.println (valorA2); // Visualizar valor señal en ordenador

    if (valorA2>=500) {
    digitalWrite (11, HIGH); //Activa motor derecho
 }
    else {
    digitalWrite (11, LOW); //Desactiva motor derecho
 }

    if (valorA1>=500) {
    digitalWrite (10, HIGH); //Activa motor izquierdo
 }
    else {
    digitalWrite (10, LOW); // Desactiva motor izquierdo
 }
 }
