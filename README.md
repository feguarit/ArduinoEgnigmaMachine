# Arduino Egnigma Machine

### [Projeto Livre]

Algumas regras básicas devem ser seguidas para que o dado à ser criptografado ou descriptografado seja feita com sucesso:

* Se você apertou a letra A e ela foi codificada para a letra G, por exemplo, não adianta alterar todas as letras A para G diretamente na sua palavra que isso não vai funcionar. Repare que se você pressionar a letra A para ser critografada várias vezes consecutivamente, cada vez ela será criptografada de uma forma.
* Você deve anotar a sequencia das três letras iniciais de configuração, elas são a chave da criptografia que você deve trocar com o seu leitor, ou então, configurar com essa sequencia para descriptografar uma determinada mensagem.

`EnigmaMachineTesteSerial.ino`

Trata-se de uma versão onde não existe a necessidad de acoplar nenhum periférico ao Arduino, pois a entrada de dados é feito através do setup() chamando uma determinada função e a saída é feita no LOG da Serial. Basta colar o conteúdo desse arquivo dentro de um novo projeto no seu Arduino e mandar executar. Verifique o Monitor Serial para identificar as saídas. Lembre-se de verificar os comentários dentro desse arquivo para fazer a correta configuração do mesmo na hora de criptografar ou descriptografar uma mensagem.


