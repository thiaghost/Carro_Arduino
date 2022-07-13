//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Define os pinos para o trigger e echo
#define pino_trigger 10
#define pino_echo 11


//motor_A
int IN3 = 7 ;
int IN4 = 6 ;
int velocidadeB = 5;

//LED

//Variaveis
float cmMsec;

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void sentidoTras(){
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
}

void sentidoFrente(){
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void acelerar(){
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(velocidadeB,135);
}

void freio(){
  analogWrite(velocidadeB,0);
}

void setup()
{
  Serial.begin(9600);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(velocidadeB,OUTPUT);;
}

void loop()
{
  cmMsec = ultrasonic.distanceRead(CM);  
  if (cmMsec > 30){
    digitalWrite(led,LOW);
    acelerar();
  }
  else{
    digitalWrite(led,HIGH);
    freio();
  }

}
