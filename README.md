# Controle de Servomotor e LED com PWM no RP2040

Este projeto demonstra como controlar um servomotor e um LED usando o módulo PWM (Pulse Width Modulation) no microcontrolador RP2040. O código foi desenvolvido utilizando o Pico SDK e pode ser facilmente adaptado para outras aplicações de controle de dispositivos com PWM.

## Requisitos

- **Hardware**:
  - Raspberry Pi Pico (com RP2040)
  - Servomotor (compatível com sinais PWM de 50 Hz)
  - LED Vermelho (para teste de PWM)
  - Fios de conexão
  - Fonte de alimentação adequada para o servomotor (se necessário)

- **Software**:
  - Pico SDK instalado e configurado
  - Compilador GCC para ARM
  - CMake (para gerenciamento de build)

## Configuração do Ambiente

1. **Instale o Pico SDK**:
   - Siga as instruções oficiais para instalar o Pico SDK: [Getting Started with Raspberry Pi Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).

2. **Clone este repositório**:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   cd seu-repositorio
   ```

3. **Configure o projeto**:

   Crie um diretório build e configure o projeto com CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

4. **Compile o código**:

   Use make para compilar o projeto:
   ```bash
   make
   ```

## Conexões

### Servomotor:

- Conecte o fio de sinal do servomotor à GPIO 22.
- Conecte o fio de alimentação do servomotor a uma fonte de 5V (ou conforme especificado pelo fabricante).
- Conecte o fio de terra do servomotor ao GND do Raspberry Pi Pico.

### LED (testes):

- Conecte o ânodo do LED à GPIO 13.
- Conecte o cátodo do LED a um resistor de 330Ω e depois ao GND.

## Executando o Projeto

1. **Carregue o código no Raspberry Pi Pico**:

   Conecte o Raspberry Pi Pico ao computador via USB.

   Carregue o arquivo .uf2 gerado na pasta build para o Pico.

2. **Observe o comportamento**:

   - O servomotor deve se mover para as posições de 0°, 90° e 180°, com pausas de 5 segundos em cada posição.
   - Após isso, o servomotor deve oscilar suavemente entre 0° e 180°.
   - Se estiver usando o LED, ele deve variar de intensidade conforme o ciclo de trabalho do PWM.

## Código

O código principal está no arquivo `servomotor.c`. Ele configura o PWM para controlar o servomotor e realiza a movimentação conforme especificado. O código de teste para o LED está no arquivo `led_red.c`, que possui a mesma estrutura do `servomotor.c`, mas com o pino de saída alterado para o controle do LED.

### Estrutura do Código

- **Configuração do PWM**:
  - Define a frequência do PWM para 50 Hz.
  - Configura o ciclo de trabalho para diferentes posições do servomotor.

- **Movimentação do Servomotor**:
  - Move o servomotor para as posições de 0°, 90° e 180°, com pausas de 5 segundos em cada posição.
  - Realiza uma movimentação suave entre 0° e 180°.

- **Controle do LED (testes)**:
  - Varia a intensidade do LED conforme o ciclo de trabalho do PWM.
  - Utiliza a GPIO 13 para o controle do LED.
