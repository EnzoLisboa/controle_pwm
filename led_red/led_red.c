#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 13 // GPIO 13 para a led vermelha

// Função para definir o ciclo ativo em microssegundos
void set_position(uint slice, uint channel, uint pulse_width_us) {
    // Convertendo microssegundos para nível PWM
    uint16_t level = (pulse_width_us * 20000) / 20000; // 20000 é o valor de wrap, 20000 é o período em microssegundos
    pwm_set_chan_level(slice, channel, level);
}

int main() {
    stdio_init_all(); // Inicializa o sistema padrão de I/O

    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM); // Habilita o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_PIN); // Obtém o canal PWM da GPIO
    uint channel = pwm_gpio_to_channel(PWM_PIN); // Obtém o canal PWM

    pwm_set_clkdiv(slice, 125.0); // Define o divisor de clock para 125 (125MHz / 125 = 1MHz)
    pwm_set_wrap(slice, 20000); // Define o valor de wrap para 20000 (1MHz / 20000 = 50Hz)
    pwm_set_enabled(slice, true); // Habilita o PWM no slice correspondente

    // Posição inicial: 180 graus
    set_position(slice, channel, 2400);
    sleep_ms(5000);

    // Posição intermediária: 90 graus
    set_position(slice, channel, 1470);
    sleep_ms(5000);

    // Posição final: 0 graus
    set_position(slice, channel, 500);
    sleep_ms(5000);

    // Movimentação periódica entre 0 e 180 graus
    while (true) {
        // Incrementa o pulso de 500us (0 graus) até 2400us (180 graus) em passos de 5us
        for (uint pulse_width = 500; pulse_width <= 2400; pulse_width += 5) {
            set_position(slice, channel, pulse_width);
            sleep_ms(10); // Espera 10ms entre cada incremento
        }
        // Decrementa o pulso de 2400us (180 graus) até 500us (0 graus) em passos de 5us
        for (uint pulse_width = 2400; pulse_width >= 500; pulse_width -= 5) {
            set_position(slice, channel, pulse_width);
            sleep_ms(10); // Espera 10ms entre cada decremento
        }
    }
}