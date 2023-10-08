
int analogTemp;

void setup() {

 pinMode(7, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(8, OUTPUT);
  
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int analogTemp = analogRead(A0);
  
  if(analogTemp >= 166 && analogTemp < 205)
  {    
    digitalWrite(7,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(8,HIGH);
  }
  
  
  if(analogTemp >= 205)
  {
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
  }
  
  if(analogTemp < 166)
  {
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(4,LOW);
  }
  

  Serial.println(analogTemp);

    
  delay(1000);

}


/*

Esse sensor trabalha no intervalo de 0 a 1,75V com uma faixa de temperatura de -50°C a 125°C (uma variação de 175°C),
de modo que cada 1,75V/175°C = 0,01V corresponde a 1°C, ou seja, 10mV = 1°C ou 1mV = 0,1°C. Como não estamos medindo
a temperatura de 0°C até 175°C, precisamos alterar o valor de saída para que a leitura mínima de -50°C corresponda a 
leitura de tensão de 0V (zero volts). Fazemos isso subtraindo -50x0,01 = -0,5V da tensão de saída (-0,5V=-500mV).
Assim o novo intervalo de tensão passa a ser: -0,5V à 1,25V.
*/
