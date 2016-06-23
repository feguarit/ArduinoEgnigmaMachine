//As configurações dos Rotores e do Notch Position não devem ser alteradas
//Usado como base os rotores do modelo Commercial Enigma de 1924:
//https://en.wikipedia.org/wiki/Enigma_rotor_details
char Entradas[]         = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char Rotor_Right_Dir[]  = "DMTWSILRUYQNKFEJCAZBPGXOHV";
char Rotor_Right_Esq[]  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char Rotor_Center_Dir[] = "HQZGPJTMOBLNCIFDYAWVEUSRKX";
char Rotor_Center_Esq[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char Rotor_Left_Dir[]   = "UQNTLSZFMREHDPXKIBVYGJCWOA";
char Rotor_Left_Esq[]   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char Refletor[]         = "ABCDEFGDIJKGMKMIEBFTCVVJAT";
char notchPositionRotorRight[]  = "W";
char notchPositionRotorCenter[] = "F";

/* 
 * A regra tanto para criptografar ou para descriptografar um caracter é a mesma.
 * 
 * Deve-se combinar com o seu leitor uma senha de três letras que será a posição inicial dos 3 rotores.
 * Por exemplo, se você combinar a senha FER, significa que: 
 *    O rotor da esquerda fica com F
 *    O rotor do centro fica com E
 *    O rotor da direita com R
 * Esses valores são definidos nas variáveis "caracterInicialRotorLeft"
 *                                           "caracterInicialRotorCenter"
 *                                           "caracterInicialRotorRight"
 * 
 * A sequencia de lógia que o programa faz é ao iniciar a codificação, avançamos uma posição no rotor da Direita e:
 * 1) Buscamos a letra no vetor Entradas[] e guardamos o número da posição;
 * 2) Com o numero da posição, buscamos a letra correspondente na mesma posição do vetor Rotor_Right_Dir[];
 * 3) Com base na letra encontrada, buscamos qual é a posição dessa letra no vetor Rotor_Right_Esq[];
 * e assim sucessivamente...
 * Quando chegar no Reflector[] basta buscar a mesma letra em uma outra posição que não foi a entrada
 * e fazer o procedimento de 1 à 3 na forma inversa.
 * Por fim, é exibido ao usuário a letra correspondente no vetor de Entradas.
 * 
 * Para decodificar, basta seguir a mesma lógica.
 */

char caracterInicialRotorLeft[]   = "M";
char caracterInicialRotorCenter[] = "E";
char caracterInicialRotorRight[]  = "V";

void setup() { 
  Serial.begin(9600);
  inicializaEnigmaMachine();
  
  Serial.print(codifica("A"));
  Serial.print(codifica("R"));
  Serial.print(codifica("D"));
  Serial.print(codifica("U"));
  Serial.print(codifica("I"));
  Serial.print(codifica("N"));
  Serial.print(codifica("O"));
}

void loop() {
   
}

char codifica(char* letra) {
  preparaParaCodificar();
  int posicao;
  char buscaLetraPosicao[] = " ";
  //Caminho até o Reflector
  posicao = buscaPosicao(Entradas,letra);
  buscaLetraPosicao[0] = Rotor_Right_Dir[posicao];
  posicao = buscaPosicao(Rotor_Right_Esq,buscaLetraPosicao);
  buscaLetraPosicao[0] = Rotor_Center_Dir[posicao];
  posicao = buscaPosicao(Rotor_Center_Esq,buscaLetraPosicao);
  buscaLetraPosicao[0] = Rotor_Left_Dir[posicao];
  posicao = buscaPosicao(Rotor_Left_Esq,buscaLetraPosicao);
  //Testando o Reflector
  buscaLetraPosicao[0] = Refletor[posicao];
  for (int i=0; i <= 25; i++){
    if ((Refletor[i] == buscaLetraPosicao[0]) and (i != posicao)) {
      posicao = i;
      break;
    }
  }
  //Caminho de retorno
  buscaLetraPosicao[0] = Rotor_Left_Esq[posicao];
  posicao = buscaPosicao(Rotor_Left_Dir,buscaLetraPosicao);  
  buscaLetraPosicao[0] = Rotor_Center_Esq[posicao];  
  posicao = buscaPosicao(Rotor_Center_Dir,buscaLetraPosicao);    
  buscaLetraPosicao[0] = Rotor_Right_Esq[posicao];  
  posicao = buscaPosicao(Rotor_Right_Dir,buscaLetraPosicao); 
  //Retorna letra trocada
  return (Entradas[posicao]);
}

int buscaPosicao(char* vetor, char* letra) {
  int posicao = 99;
  for (int i=0; i <= 25; i++){
    if (vetor[i] == letra[0]) {
      posicao = i;
      break;
    }
  } 
  return posicao; 
}

void preparaParaCodificar() {
  //Antes de qualquer codificação, o primeiro rotor é avançado
  moveRotor(Rotor_Right_Esq);
  moveRotor(Rotor_Right_Dir);  
  //Regra baseada no "notch positions" onde a seguinte regra é aplicada:
  //Rotor Right  - Se o rotor anda de V para W, Rotor Center é avançado.
  //Rotor Center - Se o rotor anda de E para F, Rotor Left é avançado.
  if (Rotor_Right_Esq[0] == notchPositionRotorRight[0]) {
    moveRotor(Rotor_Center_Esq);
    moveRotor(Rotor_Center_Dir);   
    if (Rotor_Center_Esq[0] == notchPositionRotorCenter[0]) {
      moveRotor(Rotor_Left_Esq);
      moveRotor(Rotor_Left_Dir);
    }
  }  
}

void inicializaEnigmaMachine() {
  for (int i=0; i <= 25; i++){  
    if (Rotor_Right_Esq[0] != caracterInicialRotorRight[0]) {
      moveRotor(Rotor_Right_Esq);
      moveRotor(Rotor_Right_Dir);
    }
    if (Rotor_Center_Esq[0] != caracterInicialRotorCenter[0]) {
      moveRotor(Rotor_Center_Esq);
      moveRotor(Rotor_Center_Dir);
    }
    if (Rotor_Left_Esq[0] != caracterInicialRotorLeft[0]) {
      moveRotor(Rotor_Left_Esq);
      moveRotor(Rotor_Left_Dir);
    }            
  }  
}

void moveRotor(char* conteudoRotor) {
  char primeiraVogal = conteudoRotor[0];
  for (int i=0; i <= 24; i++){
    conteudoRotor[i] = conteudoRotor[i+1];
  }
  conteudoRotor[25] = primeiraVogal;
}

void imprimeRotoresNaSerial() {
  Serial.print("------------------------------------");Serial.print("\n");    
  Serial.print("Entrada");Serial.print("\n");
  Serial.print(Entradas);Serial.print("\n");
  Serial.print("Rotor III");Serial.print("\n");
  Serial.print(Rotor_Right_Dir);Serial.print("\n");    
  Serial.print(Rotor_Right_Esq);Serial.print("\n");
  Serial.print("Rotor II");Serial.print("\n");
  Serial.print(Rotor_Center_Dir);Serial.print("\n");
  Serial.print(Rotor_Center_Esq);Serial.print("\n");
  Serial.print("Rotor I");Serial.print("\n");
  Serial.print(Rotor_Left_Dir);Serial.print("\n");
  Serial.print(Rotor_Left_Esq);Serial.print("\n");
  Serial.print("Reflector");Serial.print("\n");
  Serial.print(Refletor);Serial.print("\n");  
  Serial.print("------------------------------------");Serial.print("\n");    
}

