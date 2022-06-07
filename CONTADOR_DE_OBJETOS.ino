  #include<LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int pinoirent = 7;     
int valorirent = 0; 
int led=13;
int content = 0; 
int content1 = 0;   
int total =0;
void setup()
{
  Serial.begin(9600);            
  pinMode(pinoirent, INPUT); ; 
  lcd.begin(16,2);
  pinMode (led,OUTPUT);
  lcd.setCursor(0,0);            
  lcd.print("ARTICULOS: "); 
  
}

void loop()
{
   valorirent=digitalRead(pinoirent);
  if(valorirent!=1)
  {
    content++; 
    total++;
     while(digitalRead(pinoirent)!=1) {
        delay(100);     
      }
    lcd.setCursor(10,0); 
    lcd.print(content); 
    lcd.setCursor(0,1);
    lcd.println("TOTAL:          ");
    lcd.setCursor(7,1); 
    lcd.print(total);
  
   if(content==4){
          
     lcd.clear();
          lcd.setCursor(3,1); 
          
          lcd.println("LISTO           ");{
          digitalWrite(led,1);
          delay (700);
          digitalWrite(led,0);
          delay (700);
          digitalWrite(led,1);
          delay (700);
          digitalWrite(led,0);
          delay (700);
          digitalWrite(led,1);
          delay (700);
          digitalWrite(led,0);
          delay (700);
          digitalWrite(led,1);
          delay (700);
          digitalWrite(led,0);
          delay (700);
   }
          delay (1100);
          
          content=0;          
          lcd.clear();
          digitalWrite(led,0);
          lcd.setCursor(0,0);            
          lcd.print("ARTICULOS: ");
          lcd.setCursor(0,1);
          lcd.print("TOTAL:      "); 
          lcd.setCursor(7,1);
          lcd.print(total);
          
}
  }
}

