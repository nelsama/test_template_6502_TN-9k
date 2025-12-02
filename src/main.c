/**
 * main.c - Juego de luces LED para 6502
 * 
 * Hardware:
 *   - 6502 CPU @ 3.375 MHz en FPGA Tang Nano
 *   - 6 LEDs conectados a los bits 0-5 de PORT_SALIDA_LED ($C001)
 *   - Configuración del puerto en CONF_PORT_SALIDA_LED ($C003)
 * 
 * Compilar: make
 */

#include <stdint.h>
#include "../libs/uart/uart.h"

/* Registro de salida de LEDs (6 bits inferiores) */
#define PORT_SALIDA_LED      (*(volatile uint8_t*)0xC001)

/* Registro de configuración: 0=salida, 1=entrada */
#define CONF_PORT_SALIDA_LED (*(volatile uint8_t*)0xC003)

/* ============================================================================
 * FUNCIONES DE UTILIDAD
 * ============================================================================ */

/**
 * Delay simple
 */
void delay(uint16_t count) {
    volatile uint16_t i;
    for (i = 0; i < count; i++) {
        /* espera */
    }
}


/**
 * LEDS Encendidos
 */
void encendido(uint16_t velocidad) {
    uart_puts("Encendiendo..\r\n");
    PORT_SALIDA_LED = 0x00;
    delay(velocidad);
}

/**
 * LEDS Apagados
 */
void apagado(uint16_t velocidad) {
    uart_puts("Apagando..\r\n");
    PORT_SALIDA_LED = 0xFF;
    delay(velocidad);
}

/* ============================================================================
 * PROGRAMA PRINCIPAL
 * ============================================================================ */

int main(void) {
    
    /* Configurar los 6 bits inferiores como salidas (0 = salida) */
    CONF_PORT_SALIDA_LED = 0xC0;  /* bits 7,6 = entrada, bits 5-0 = salida */
    
    /* Apagar todos los LEDs inicialmente */
    PORT_SALIDA_LED = 0x00;
    
    uart_init();
    uart_puts("##### UART ENCENDIDO #####\r\n");

    /* Bucle principal con secuencia de efectos */
    while (1) {
        encendido(10000);
        apagado(10000);
    }
    
    return 0;
}
