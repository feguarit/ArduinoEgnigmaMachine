# Arduino Enigma Machine

<p align="center"><img src="https://s32.postimg.org/q8vxwypth/01_Enigma_Aparencia.jpg"></p>

### [Projeto Livre]

Algumas regras básicas devem ser seguidas para que o dado à ser criptografado ou descriptografado seja feita com sucesso:

* Se você apertou a letra A e ela foi codificada para a letra G, por exemplo, não adianta alterar todas as letras A para G diretamente na sua palavra que isso não vai funcionar. Repare que se você pressionar a letra A para ser critografada várias vezes consecutivamente, cada vez ela será criptografada de uma forma.
* Você deve anotar a sequencia das três letras iniciais de configuração, elas são a chave da criptografia que você deve trocar com o seu leitor, ou então, configurar com essa sequencia para descriptografar uma determinada mensagem.

`EnigmaMachineTesteSerial.ino`

Trata-se de uma versão onde não existe a necessidad de acoplar nenhum periférico ao Arduino, pois a entrada de dados é feito através do setup() chamando uma determinada função e a saída é feita no LOG da Serial. Basta colar o conteúdo desse arquivo dentro de um novo projeto no seu Arduino e mandar executar. Verifique o Monitor Serial para identificar as saídas. Lembre-se de verificar os comentários dentro desse arquivo para fazer a correta configuração do mesmo na hora de criptografar ou descriptografar uma mensagem.

Para configurar a chave de criptografia que você vai trocar com o seu leitor, ou caso já tenha recebido uma mensagem e queira descriptografá-la, você deverá registrar essa chave nas variáveis abaixo listadas. Por exemplo, para registrar a chave de criptografia FER, deve-se configurar da seguinte forma:

    char caracterInicialRotorLeft[]   = "F";
    char caracterInicialRotorCenter[] = "E";
    char caracterInicialRotorRight[]  = "R";

Após a configuração da chave de criptografia, você terá que passar letra por letra que deseja criptografar ou descripografar. Veja que dentro do "void setup()" existem comandos dessa forma:

    Serial.print(codifica("A"));
    Serial.print(codifica("R"));
    Serial.print(codifica("D"));
    Serial.print(codifica("U"));
    Serial.print(codifica("I"));
    Serial.print(codifica("N"));
    Serial.print(codifica("O"));

Isso significa que o programa vai criptografar a palavra "ARDUINO" e a saída (criptografada) será exibida no Monitor Serial. Veja que existe a necessidade de passar letra à letra para que o processo seja concluído com sucesso e na sequencia certa. O que for exibido no Monitor Serial deve ser enviado ao seu leitor junto com a chave que você usou para que ele possa, posteriormente, descriptografar. Para esse exemplo, você deverá enviar à ele a seguinte mensagem:

    FER
    LUUBQDP


`TesteLeds.ino`

Trata-se de um arquivo onde é usado para testar o teclado e os LED´s. O que ele faz é acender o LED respectivo à tecla pressionada e com isso é possível fazer um teste se todos os botões e seus respectivos LED´s estão funcionando.

O teclado que foi confeccionado para esse projeto utiliza 3 entradas analógicas e a diferenciação entre os botões que estão vinculados à uma mesma entrada foi feita por resistores em série, sempre usando a segunda tecla um resistor com valor em dobro do anterior. Para esse projeto, iniciei com um resistor de 47hms, o segundo um valor próximo à 100, o próximo 200 e assim sucessivamente, sempre levando em conta resistores que existem no mercado e que são fáceis de encontrar.
