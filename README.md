# Resolução da Atividade 2 (Parte 1) - Aula Síncrona 29/01 - Temporizador Periódico

Este código é a solução para a atividade 2, parte 1, referente a aula síncrona do dia 29/01 do Embarcatech que envolve o acionamento de LEDs em uma sequência específica utilizando temporizador de hardware periódico. Este projeto utiliza a Raspberry Pi Pico para controlar LEDs vermelhos, verdes e amarelos com base em um temporizador de 3 segundos. A cada 3 segundos, o estado dos LEDs alterna em uma sequência, gerenciando a troca entre eles. Além disso, a cada segundo, o programa imprime uma mensagem no console.

## Descrição

O código foi desenvolvido para a Raspberry Pi Pico usando o SDK C da plataforma. Ele configura três LEDs conectados aos pinos GPIO 13 (vermelho), 11 (verde) e 12 (amarelo) para alternar entre estados de ligado e desligado, com um intervalo de 3 segundos. O temporizador é configurado para chamar uma função de callback, que alterna os LEDs na seguinte sequência:

1. LED vermelho acende, LED amarelo apaga.
2. LED amarelo acende, LED verde acende.
3. LED verde acende, LED vermelho apaga.

Além disso, a cada segundo, uma mensagem "PASSOU 1 SEGUNDO!" é exibida no terminal.

### Compilação e Upload
1. Clone o repositório utilizando o comando abaixo.
```
git clone https://github.com/GabrielShiva/u4c5-temporizadores.git
```
2. No VsCode, clique na extensão `Raspberry Pi Pico W`, depois em *Importar Projeto*, selecione a pasta do projeto, escolha a versão do SDK (2.1.0) e, por fim, em *Importar*.