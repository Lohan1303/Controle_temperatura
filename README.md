# Projeto - Controle de temperatura

Neste projeto, simulando uma estufa de hortaliças, foi desenvolvido no simulador TinkerCad (https://www.tinkercad.com/) um circuito eletrônico envolvendo um sensor de temperatura, uma buzina, um LED e um motor, controlados por meio de um Arduino. O projeto tem a seguinte funcionalidade:

(a) Fazer a leitura da temperatura;

(b) Fazer o acionamento de um motor de ventilador caso a temperatura seja igual ou maior a 30 °C;

(c) Caso a temperatura ultrapasse os 50 °C, um LED vermelho e uma buzina devem acionar avisando uma situação de emergência.



## Circuito

![image-20231008175248075](C:\Users\Lohan\AppData\Roaming\Typora\typora-user-images\image-20231008175248075.png)

[Circuito - Controle de temperatura](https://www.tinkercad.com/things/indk6247VXq?sharecode=RavtWvPjDJpf9-8u52gLcthKCSRvj84CN2Go3aO9l2E)

## Código

```c++

int analogTemp;

void setup() {

 pinMode(7, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(8, OUTPUT);
  
 Serial.begin(9600);
}

void loop() {

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

```

