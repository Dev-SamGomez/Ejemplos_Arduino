

#include <ESP8266WiFi.h>
#include <Espalexa.h>
Espalexa espAlexa;
////////////////////////////
#define led D4

const char* ssid = "TU_SSID";
const char* password = "TU_PASS";

void setup() {
  Serial.begin(115200);
  pinMode(led,OUTPUT); 
  digitalWrite(led,HIGH); //inicia apagado
  ConectarWifi(); 
  espAlexa.addDevice("LED",foco);
  espAlexa.begin();
}
///////////////////// VOID LOOP ////////////////////////////////////////////////////
void loop(){
  ConectarWifi();
  espAlexa.loop();
  delay(1);}
   
/////////////////// FUNCION PARA CONECTAR EL WIFI ///////////////////////////////////
void ConectarWifi() {
  if(WiFi.status() != WL_CONNECTED) {
     WiFi.mode(WIFI_STA);
     WiFi.begin(ssid, password);
     Serial.println("");
     Serial.println("Connecting to WiFi");
     while(WiFi.status() != WL_CONNECTED) {
           delay(500);
           Serial.print(".");}
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());}}
/////////////////// FUNCION PARA  LED /////////////////////////////
void foco(uint8_t brillo){
     if(brillo){
      digitalWrite(led, LOW);}
     else{
      digitalWrite(led, HIGH);}}   

/*
------------------------------------
CONFIGURAR ESP8266 CON ALEXA
------------------------------------

> Descargar IDE de Arduino.
> Pegar en preferencias este link (https://arduino.esp8266.com/stable/package_esp8266com_index.json) 
y seleccionar casilla compilacion.
> Buscar tarjetas ESP8266 y descargar.
> En programa, añadir libreria espalexa en formato zip, dar click en Añadir biblioteca zip.
> Seleccionar el archivo zip con el nombre Espalexa.
> Seleccionar la tarjeta NodeMCU 1.0.
> Abrir Sketch y agregar ID de tu red wifi y la contraseña, luego compilar.
> Subir archivo al compilar, siempre teniendo y asegurandose que la tarjeta sea NodeMCU 1.0.
> Una vez subido, abre monitor serial, selecciona 115200 badios.
> Resetea la tarjeta ESP8266.
> En monitor serial, debera verse que esta conectado y su direccion IP.
> Configuralo en tu app Alexa.
*/
