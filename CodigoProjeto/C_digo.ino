#include "LiquidCrystal.h"
#include "Limits.h"
// portas dos sensores
const int sensorLuz  = 0; // pino analogico A0
const int sensorTemp = 1; // pino analogico A1
const int sensorUmidade = 2; // pino analogico A2

// valores para cada sensor
int valorSensorUmidade = 0; //usada para ler o valor do sensor de umidade.
int valorSensorLuz  = 0;  //usada para ler o valor do sensor de luz.
int valorSensorTemp = 0;  //usada para ler o valor do sensor de temperatura.
int menorValorTemp = INT_MAX; //usada para armazenar o menor valor da temperatura.

//portas dos botoes
int botao_mais = 7;
int botao_menos = A5;
int botao_planta = A4;

int valor_menu_plantas = 1;
int valor_menu = 0;
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  // Configuração dos botão
  
  pinMode(botao_mais, INPUT);
  pinMode(botao_menos, INPUT);
  pinMode(botao_planta, INPUT);
  lcd.begin(16, 2);
}

void loop() {
   //Para evitar as grandes variações de leitura do componente 
  //LM35 são feitas 8 leituras e o menor valor lido prevalece.  
  menorValorTemp  = INT_MAX; //Inicializando com o maior valor int possível
  for (int i = 1; i <= 8; i++) {
    //Lendo o valor do sensor de temperatura.
    valorSensorTemp = analogRead(sensorTemp);   
  
    //Transformando valor lido no sensor de temperatura em graus celsius aproximados.
    valorSensorTemp *= 0.54 ; 
     
    //Mantendo sempre a menor temperatura lida
    if (valorSensorTemp < menorValorTemp) {
      menorValorTemp = valorSensorTemp;
    }
    
   delay(150); 
  }   
  
  //Lendo o valor do sensor de luz
  valorSensorLuz  = analogRead(sensorLuz);
  //Lendo o valor do sensor de umidade
  valorSensorUmidade = analogRead(sensorUmidade);

  if (digitalRead(botao_mais) == HIGH) { 
    valor_menu++;                           //valor_menu = valor_menu + 1
  }
  if (digitalRead(botao_menos) == HIGH) {
    valor_menu--;
  }
  if (digitalRead(botao_planta) == HIGH) {
    valor_menu_plantas = valor_menu_plantas + 1;    
    valor_menu = 0;
  }
  if (valor_menu > 3) {                  
    valor_menu = 0;
  }
  if (valor_menu < 0) {
    valor_menu = 3;
  }
  if(valor_menu_plantas > 3){
    valor_menu_plantas = 1;
  }

  lcd.clear();
  //switch (valor_menu)
    switch (valor_menu_plantas)
    {
      case 1: //Inicio da planta 1 e seus 3 sensores
      lcd.setCursor(0, 0);  
      lcd.print("> Pimenteira");
      switch (valor_menu){
        case 1:   //switch dos 3 sensores
        lcd.setCursor(0, 0);  
        valorSensorUmidade = map( valorSensorUmidade, 1023, 0, 0, 100); //mapeamento para transformar 1023 em 0, e 100
        lcd.print("Umidade em:");
        lcd.print(valorSensorUmidade);
        lcd.print(" %");
        lcd.setCursor(0, 1);
        lcd.print("Umi ideal:40%");
      break;

        case 2:
        lcd.setCursor(0, 0);  
        lcd.print("Lum atual:");
        lcd.print(valorSensorLuz);
        lcd.setCursor(0, 1);
        lcd.print("Lum ideal:300");
      break;
     
        case 3:
        lcd.setCursor(0, 0);  
        lcd.print("Temp atual: ");                   
        lcd.print(menorValorTemp);
        lcd.write(B11011111); //Simbolo de graus celsius
        lcd.print("C");
        lcd.setCursor(0, 1);
        lcd.print("Temp ideal: 27");
        lcd.write(B11011111); //Simbolo de graus celsius
      lcd.print("C");
      break; //fim dos sensores da planta 1     
     }
      break; // break da planta 1
      
    
      case 2: //inicio da planta 2 e seus sensores
      lcd.setCursor(0, 0);  
      lcd.print("> Imbe");
      switch (valor_menu){ //sensores da planta 2
        case 1:   //switch dos 3 sensores
        lcd.setCursor(0, 0);  
        valorSensorUmidade = map( valorSensorUmidade, 1023, 0, 0, 100); //mapeamento para transformar 1023 em 0, e 100
        lcd.print("Umidade em:");
        lcd.print(valorSensorUmidade);
        lcd.print(" %");
        lcd.setCursor(0, 1);
        lcd.print("Umi ideal:70%");
      break;

        case 2:
        lcd.setCursor(0, 0);  
        lcd.print("Lum atual:");
        lcd.print(valorSensorLuz);
        lcd.setCursor(0, 1);
        lcd.print("Lum ideal:400");
      break;
     
        case 3:
        lcd.setCursor(0, 0);  
        lcd.print("Temp atual: ");                   
        lcd.print(menorValorTemp);
        lcd.write(B11011111); //Simbolo de graus celsius
        lcd.print("C");
        lcd.setCursor(0, 1);
        lcd.print("Temp ideal: 27");
        lcd.write(B11011111); //Simbolo de graus celsius
      lcd.print("C");
      break; //fim dos sensores da planta 2   
     }
      break;  //break da planta 2
      
      case 3: //planta 3 e seus 3 sensores
      lcd.setCursor(0, 0);  
      lcd.print("> Cacto");
      switch (valor_menu){
        case 1: //switch dos 3 sensores
        lcd.setCursor(0, 0);  
        valorSensorUmidade = map( valorSensorUmidade, 1023, 0, 0, 100); //mapeamento para transformar 1023 em 0, e 100
        lcd.print("Umidade em:");
        lcd.print(valorSensorUmidade);
        lcd.print(" %");
        lcd.setCursor(0, 1);
        lcd.print("Umi ideal:10%");
      break;

        case 2:
        lcd.setCursor(0, 0);  
        lcd.print("Lum atual:");
        lcd.print(valorSensorLuz);
        lcd.setCursor(0, 1);
        lcd.print("Lum ideal:700");
      break;
     
        case 3:
        lcd.setCursor(0, 0);  
        lcd.print("Temp atual: ");                   
        lcd.print(menorValorTemp);
        lcd.write(B11011111); //Simbolo de graus celsius
        lcd.print("C");
        lcd.setCursor(0, 1);
        lcd.print("Temp ideal: 28");
        lcd.write(B11011111); //Simbolo de graus celsius
      lcd.print("C");
      break; //fim dos sensores da planta 3
     }
      break; //break da planta 3
    
  }
}
