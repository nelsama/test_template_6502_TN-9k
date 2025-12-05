/**
 * main.c - Template 6502 para Tang Nano 9K
 * 
 * Este es un proyecto base para desarrollo en 6502.
 * Compatible con librerías estándar de cc65 (stdlib, string, etc.)
 * 
 * Hardware:
 *   - CPU 6502 @ 3.375 MHz en FPGA Tang Nano 9K
 *   - 6 LEDs conectados a PORT_SALIDA_LED ($C001)
 *   - UART para debug
 * 
 * Compilar: make
 */

#include <stdint.h>
/* Puedes incluir librerías de cc65: */
/* #include <stdlib.h> */
/* #include <string.h> */

#include "../libs/uart/uart.h"

/* ============================================================================
 * REGISTROS DE HARDWARE
 * ============================================================================ */

#define PORT_SALIDA_LED      (*(volatile uint8_t*)0xC001)  /* Salida LEDs */
#define CONF_PORT_SALIDA_LED (*(volatile uint8_t*)0xC003)  /* Config: 0=out, 1=in */

/* ============================================================================
 * FUNCIONES
 * ============================================================================ */

/**
 * Delay simple por software
 */
void delay(uint16_t count) {
    volatile uint16_t i;
    for (i = 0; i < count; i++) {
        /* espera */
    }
}

/* ============================================================================
 * PROGRAMA PRINCIPAL
 * ============================================================================ */

int main(void) {
    
    /* Configurar LEDs como salidas */
    CONF_PORT_SALIDA_LED = 0xC0;  /* bits 5-0 = salida */
    PORT_SALIDA_LED = 0x00;       /* LEDs apagados */
    
    /* Inicializar UART */
    uart_init();
    uart_puts("6502 Template Ready!\r\n");

    /* Bucle principal */
    while (1) {
        uart_puts("LED ON\r\n");
        PORT_SALIDA_LED = 0x00;   /* Enciende (lógica inversa) */
        delay(10000);
        
        uart_puts("LED OFF\r\n");
        PORT_SALIDA_LED = 0xFF;   /* Apaga */
        delay(10000);
    }
    
    return 0;
}
