# 6502 LED Light Show

Juego de luces LED para CPU 6502 en FPGA Tang Nano.

## Características

- ✅ CPU 6502 @ 3.375 MHz en FPGA Tang Nano
- ✅ 6 LEDs con efectos de iluminación
- ✅ 4 efectos visuales diferentes
- ✅ Compilación con cc65

## Hardware

| Componente | Dirección | Descripción |
|------------|-----------|-------------|
| PORT_SALIDA_LED | $C001 | Puerto de salida para 6 LEDs (bits 0-5) |
| CONF_PORT_SALIDA_LED | $C003 | Configuración: 0=salida, 1=entrada |

## Estructura

```
micro6502/
├── src/
│   ├── main.c              # Programa principal con efectos LED
│   └── simple_vectors.s    # Vectores de interrupción 6502
├── config/
│   └── fpga.cfg            # Configuración del linker cc65
├── scripts/
│   └── bin2rom3.py         # Conversor BIN → VHDL
├── build/                  # Archivos compilados
├── output/                 # ROM generada (.vhd, .bin, .hex)
└── makefile                # Compilación con cc65
```

## Compilación

### Requisitos previos
- [cc65](https://cc65.github.io/) instalado en `D:\cc65`
- Python 3 para el script de conversión

### Compilar
```bash
make
```

### Limpiar
```bash
make clean
```

### Cargar en FPGA
Copiar `output/rom.vhd` al proyecto FPGA y sintetizar.

## Efectos de Luces

El programa ejecuta 4 efectos en bucle infinito:

| Efecto | Descripción |
|--------|-------------|
| Knight Rider | LED que recorre de izquierda a derecha y regresa |
| Llenado | LEDs se llenan desde los extremos hacia el centro |
| Alternado | Parpadeo alternado (010101 ↔ 101010) |
| Contador | Contador binario de 0 a 63 |

## Mapa de Memoria

| Región | Dirección | Tamaño | Descripción |
|--------|-----------|--------|-------------|
| Zero Page | $0002-$00FF | 254 bytes | Variables rápidas |
| RAM | $0100-$3DFF | ~15 KB | RAM principal |
| Stack | $3E00-$3FFF | 512 bytes | Pila del sistema |
| ROM | $8000-$9FF9 | 8 KB | Código del programa |
| Vectores | $9FFA-$9FFF | 6 bytes | NMI, RESET, IRQ |
| I/O | $C000-$C003 | 4 bytes | Puertos de E/S |

## Requisitos

- [cc65](https://cc65.github.io/) - Compilador C para 6502 (instalado en `D:\cc65`)
- Python 3 - Para el script bin2rom3.py
- FPGA Tang Nano 9K (o compatible)
- 6 LEDs conectados a los bits 0-5 del puerto $C001

## Licencia

MIT
