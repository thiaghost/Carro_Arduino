# Projeto: Carro Controlado por Sensor Ultrassônico

Este projeto utiliza um sensor ultrassônico para medir a distância de obstáculos à frente e controlar um motor DC de acordo com a proximidade do obstáculo. O carro avança se não houver nenhum objeto próximo e freia quando um obstáculo é detectado dentro de um determinado raio de distância.

## Componentes Utilizados

- **Arduino UNO (ou similar)**
- **Sensor Ultrassônico (HC-SR04 ou similar)**
- **Driver de Motor**
- **Motor DC**
- **LED (indicador de proximidade)**

## Biblioteca Requerida

A biblioteca **Ultrasonic** é necessária para o funcionamento do sensor ultrassônico. Certifique-se de instalá-la antes de rodar o código:

```cpp
#include <Ultrasonic.h>
```

## Pinos Utilizados

### Sensor Ultrassônico:

- **Trigger**: Pino 10
- **Echo**: Pino 11

### Motor DC:

- **IN3**: Pino 7 (sentido de rotação)
- **IN4**: Pino 6 (sentido de rotação)
- **velocidadeB**: Pino 5 (controle de velocidade via PWM)

### LED:

- O pino do LED não foi definido no código fornecido, adicione um pino para conectar o LED.

## Funcionalidade

O código utiliza um sensor ultrassônico para medir a distância de obstáculos à frente. Dependendo da distância medida, o carro realiza uma das seguintes ações:

1. **Avançar**: Se a distância do obstáculo for superior a 30 cm, o motor é acionado para mover o carro para a frente.
2. **Frear**: Se a distância for inferior ou igual a 30 cm, o carro freia e o LED acende, indicando a proximidade de um objeto.

## Funções

- **sentidoFrente()**: Define a rotação do motor para mover o carro para frente.
- **sentidoTras()**: Define a rotação do motor para mover o carro para trás (não utilizado no loop principal, mas pode ser implementado).
- **acelerar()**: Define o motor para rodar a 135 unidades de PWM, movendo o carro para frente.
- **freio()**: Para o motor.

## Como Usar

1. Conecte o sensor ultrassônico e o motor aos pinos do Arduino conforme especificado.
2. Substitua o valor do pino do LED na função `loop()` (adicionar `int led = X;` no código).
3. Carregue o código no Arduino.
4. Monitore a distância detectada pelo sensor e o comportamento do carro: se houver um obstáculo a menos de 30 cm, o carro freia e o LED acende.

---

### Melhorias Sugeridas

- Adicionar o controle para mover o carro para trás ao detectar um obstáculo muito próximo.
- Definir o pino do LED no código.
- Permitir ajustes dinâmicos na velocidade do motor dependendo da proximidade do obstáculo.

