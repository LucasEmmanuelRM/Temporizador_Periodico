#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_R 13
#define LED_Y 12
#define LED_G 11

static int ledpin = 13;

void inicializar_pinos();
bool repeating_timer_callback(struct repeating_timer *t);

int main() {
    stdio_init_all();
    inicializar_pinos();

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        if (ledpin == LED_R)
            printf ("Sinal Vermelho - Pare!\n");
        if (ledpin == LED_Y)
            printf ("Sinal Amarelo - Atenção!\n");
        if (ledpin == LED_G)
            printf ("Sinal Verde - Siga!\n");
        sleep_ms(1000);
    }
}

bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(ledpin, 0);
    ledpin--;
    if (ledpin < 11)
        ledpin = 13;
    gpio_put(ledpin, 1);
    return true;
}

// Para executar este código na BitDogLab, comente a função acima e descomente a função abaixo!
// bool repeating_timer_callback(struct repeating_timer *t) {
//     ledpin--;
//     if (ledpin < 11)
//         ledpin = 13;
//     if (ledpin == 13){
//         gpio_put(LED_G, 0);
//         gpio_put(LED_R, 1);
//     }
//     if (ledpin == 12){
//         gpio_put(LED_G, 1);
//     }
//     if (ledpin == 11){
//         gpio_put(LED_G, 1);
//         gpio_put(LED_R, 0);
//     }
//     return true;
// }

void inicializar_pinos(){
    // Inicializa LEDs
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_put(LED_G, 0);

    gpio_init(LED_Y);
    gpio_set_dir(LED_Y, GPIO_OUT);
    gpio_put(LED_Y, 0);

    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_put(LED_R, 1);
}