void setup() {
  Serial.begin(9600);
  for (int i = 2; i<=13; i++) {
    pinMode(i, OUTPUT);  
  }
}

void loop() {

  int botaoA0 = analogRead(A0);
  int botaoA1 = analogRead(A1);
  int botaoA2 = analogRead(A2);

  //Canal Analogico 0
  if (botaoA0 == 0) {
    apagaTodosLEDS();
    acendeLED(3,1);
  } else if (botaoA0 <= 80) {
    apagaTodosLEDS();
    acendeLED(3,2);    
  } else if (botaoA0 <= 200) {
    apagaTodosLEDS();
    acendeLED(3,3);    
  } else if (botaoA0 <= 350) {
    apagaTodosLEDS();
    acendeLED(3,4);    
  } else if (botaoA0 <= 500) {
    apagaTodosLEDS();
    acendeLED(3,5);    
  } else if (botaoA0 <= 600) {
    apagaTodosLEDS();
    acendeLED(3,6);    
  } else if (botaoA0 <= 700) {
    apagaTodosLEDS();
    acendeLED(3,7);    
  } else if (botaoA0 <= 800) {
    apagaTodosLEDS();
    acendeLED(3,8);    
  } else if (botaoA0 <= 900) {
    apagaTodosLEDS();
    acendeLED(3,9);    
  }
  //Canal Analogico 1
  if (botaoA1 == 0) {
    apagaTodosLEDS();
    acendeLED(2,2);
  } else if (botaoA1 <= 80) {
    apagaTodosLEDS();
    acendeLED(2,3);    
  } else if (botaoA1 <= 200) {
    apagaTodosLEDS();
    acendeLED(2,4);    
  } else if (botaoA1 <= 350) {
    apagaTodosLEDS();
    acendeLED(2,5);    
  } else if (botaoA1 <= 500) {
    apagaTodosLEDS();
    acendeLED(2,6);    
  } else if (botaoA1 <= 600) {
    apagaTodosLEDS();
    acendeLED(2,7);    
  } else if (botaoA1 <= 700) {
    apagaTodosLEDS();
    acendeLED(2,8);    
  } else if (botaoA1 <= 800) {
    apagaTodosLEDS();
    acendeLED(2,9);    
  } 
  //Canal Analogico 2
  if (botaoA2 == 0) {
    apagaTodosLEDS();
    acendeLED(1,1);
  } else if (botaoA2 <= 80) {
    apagaTodosLEDS();
    acendeLED(1,2);    
  } else if (botaoA2 <= 200) {
    apagaTodosLEDS();
    acendeLED(1,3);    
  } else if (botaoA2 <= 350) {
    apagaTodosLEDS();
    acendeLED(1,4);    
  } else if (botaoA2 <= 500) {
    apagaTodosLEDS();
    acendeLED(1,5);    
  } else if (botaoA2 <= 600) {
    apagaTodosLEDS();
    acendeLED(1,6);    
  } else if (botaoA2 <= 700) {
    apagaTodosLEDS();
    acendeLED(1,7);    
  } else if (botaoA2 <= 800) {
    apagaTodosLEDS();
    acendeLED(1,8);    
  } else if (botaoA2 <= 900) {
    apagaTodosLEDS();
    acendeLED(1,9);    
  }  

  delay(50);

}

void apagaTodosLEDS() {
  for (int i = 2; i<=13; i++) {
    digitalWrite(i, LOW);  
  }
}

void acendeLED(int linha, int coluna) {
  digitalWrite(linha+1, HIGH);
  digitalWrite(coluna+4, HIGH);
}

