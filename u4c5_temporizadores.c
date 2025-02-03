#include <stdio.h> // inclui a biblioteca padrão do c para entradas/sa´ídas
#include "pico/stdlib.h" // inclui a biblioteca padrão do pico sdk para entradas/sa´ídas (gpios)
#include "hardware/timer.h" // inclui a biblioteca para gerenciar temporizadores de hardware 

// define os pinos associados aos leds
#define RED_LED 13
#define GREEN_LED 11
#define YELLOW_LED 12

// definição e inicialização das variáveis que armazenam o estado de cada led (ligado/desligado)
static volatile bool red_led_state = true;
static volatile bool green_led_state = false;
static volatile bool yellow_led_state = false;

// inicialização das gpios associadas aos leds 
void setup() {
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);

    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    
    gpio_init(YELLOW_LED);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
}

// definição da função de callback que é chamada pelo temporizador a cada 3 segundos
// a função retorna um valor booleano que indica se o temporizador deve continuar ou parar 
bool repeating_timer_callback(struct repeating_timer *t) {
    printf("Passou 3 segundos\n");

    if (red_led_state) {
        red_led_state = !red_led_state;
        gpio_put(RED_LED, red_led_state);

        yellow_led_state = !yellow_led_state;
        gpio_put(YELLOW_LED, yellow_led_state);

        return true;
    }

    if (yellow_led_state) {
        yellow_led_state = !yellow_led_state;
        gpio_put(YELLOW_LED, yellow_led_state);

        green_led_state = !green_led_state;
        gpio_put(GREEN_LED, green_led_state);

        return true;
    }

    if (green_led_state) {
        green_led_state = !green_led_state;
        gpio_put(GREEN_LED, green_led_state);

        red_led_state = !red_led_state;
        gpio_put(RED_LED, red_led_state);

        return true;
    }
}

int main() {
    stdio_init_all();
    setup();

    struct repeating_timer timer;

    gpio_put(RED_LED, red_led_state);
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        // pausa de 9 segundos para reduzir o consumo da CPU
        sleep_ms(1000);
        printf("PASSOU 1 SEGUNDO!\n");
    }

    return 0;
}
