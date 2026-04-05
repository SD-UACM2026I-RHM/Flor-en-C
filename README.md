# Flor-en-C
Este es un repositorio que contiene un ejercicio en el cual practicamos el uso de fork(), wait(), exit(), etc.

# Árbol de procesos en forma de flor (tallo + pétalos) - Práctica de Sistemas Operativos

## Descripción
Este programa en C crea una estructura jerárquica de procesos utilizando `fork()`. La estructura se asemeja a una **flor**:
- Un **tallo** formado por 8 procesos en línea.
- Desde tres procesos específicos del tallo (los que corresponden a `i=5`, `i=6` e `i=7`) se despliega un **abanico de pétalos**: cada uno de esos procesos crea 5 procesos hijos simulando ser los pétalos de una flor.

Cada proceso termina con `exit(1)` (excepto la raíz que no hace `exit` hasta el final), y el proceso raíz suma todos los valores devueltos por sus descendientes, más 1 por sí mismo, para obtener el número total de procesos creados.

## Estructura del árbol
- **Tallo**: 8 procesos en línea.
- **Flores**: Desde los procesos con `i=5`, `i=6` e `i=7` (que son los últimos tres procesos del tallo).
- **Pétalos**:  A partir de esa flor, se crea un abanico de 5 procesos.
  
## Número total de procesos
- Tallo: 8 procesos.
- Flores: 3 procesos del tallo (i=5,6,7) 
- Pétalos: 5 hijos en cada flor = 15 procesos.
- Total: 8 + 15 = 26 procesos.

El programa calcula este número mediante la propagación de `exit(1)` y la suma en la raíz.

## Requisitos
- Sistema operativo Linux/Unix (con `fork()`, `wait()`, `pstree`).
- Compilador GCC.

## Compilación y ejecución

gcc -o flor flor.c
./flor
