#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 4, 5, 6, 7, 8); //Colocamos los pines del LCD

#include <dht11.h> //Incluimos la libreria DHT11
dht11 DHT; //Creamos el objeto DHT
#define DHT11_PIN 2  //Asignamos el pin digital #2    

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); //Inicializamos la pantalla LCD
}

void loop()
{
  int chk;
  chk = DHT.read(DHT11_PIN);   //Leemos los datos del sensor

 // Mostramos la humedad
  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(DHT.humidity,1);
  lcd.print(" %");
  //Mostramos la temperatura
  lcd.setCursor(0, 1);
  lcd.print("Tempera ");
  lcd.println(DHT.temperature,1);
  lcd.print(" C*");
  delay(1000); // pequeño retardo para una buena lectura
}

