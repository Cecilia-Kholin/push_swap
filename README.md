*This project has been created as part of the 42 curriculum by maricamp.*

# Push_swap

## Description
**push_swap** es un proyecto de algoritmos de ordenación de alta eficiencia desarrollado íntegramente en **lenguaje C**. El objetivo es ordenar una pila de datos (stack A) utilizando un conjunto limitado de instrucciones y una pila auxiliar (stack B), buscando siempre el **mínimo número de movimientos posible**.

Este proyecto permite profundizar en conceptos fundamentales de la programación de bajo nivel, tales como:
* La manipulación de estructuras de datos (listas enlazadas).
* La implementación y optimización de algoritmos de ordenación.
* La gestión rigurosa de la memoria dinámica y la prevención de fugas (*memory leaks*).

---

## Instructions

### Compilation
El proyecto cuenta con un `Makefile` que gestiona la compilación. Para generar el ejecutable, ejecuta en la terminal:

```bash
make
```
## Execution
El programa recibe como argumento una lista de números enteros. Los números no deben estar duplicados y deben estar dentro del rango de un int.
```bash
./push_swap 2 1 3 6 5 8
```
los argumentos son válidos, el programa imprimirá la secuencia de instrucciones (ej. sa, pb, ra, etc.) necesaria para ordenar la lista de menor a mayor.

## Checker
Para verificar que la secuencia de movimientos es correcta, puedes utilizar el checker (proporcionado por la escuela o la comunidad):
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Resources
Documentation & References
* VisuAlgo: Herramienta visual para comprender la lógica de los algoritmos de ordenación.

* K-sort Algorithm: Documentación sobre la segmentación por rangos (chunks) para optimizar el movimiento de nodos.

* Norminette: Estándar de código de la escuela 42 para garantizar la legibilidad y calidad.

## Use of AI
En este proyecto, la Inteligencia Artificial se utilizó de forma estratégica para las siguientes tareas:

* Optimización de lógica: Comparativa de eficiencia entre algoritmos (Radix vs. K-sort) para decidir la mejor estrategia en C.

* Generación de casos de prueba: Creación de scripts en Python para generar listas de números aleatorios y verificar el manejo de errores (overflows, duplicados).

* Depuración: Análisis de errores de segmentación y fugas de memoria detectados mediante Valgrind.

## Technical Choices
Algorithm: K-sort
Para la resolución de este reto, decidí implementar el algoritmo K-sort. Esta elección se basó en dos motivos principales:

* Facilidad de implementación: K-sort ofrece una lógica basada en rangos que resulta muy intuitiva de trasladar a lenguaje C, facilitando el control sobre el flujo de datos entre los stacks.

* Recomendación de pares: Tras intercambiar ideas con compañeros del campus, se determinó que es uno de los algoritmos más equilibrados para cumplir con los límites de instrucciones (especialmente en pruebas de 100 y 500 números) manteniendo un código limpio.

Data Structure
Se utilizaron listas enlazadas para representar los stacks, permitiendo una manipulación dinámica de los elementos y una ejecución eficiente de las operaciones de rotación y empuje.

:test_tube: Evaluation Checklist
1. Error Management

Every command in this section must print Error to the standard error (stderr), except for the empty argument which should return the prompt.
Bash

# Non-numeric arguments
./push_swap 1 2 three 4

# Duplicate arguments
./push_swap 1 2 3 1

# Out of integer range (INT_MAX / INT_MIN)
./push_swap 2147483648

./push_swap -2147483649

# Empty string (Should NOT display anything)
./push_swap ""

2. Memory Leaks (Valgrind)

Run these commands to ensure there are no memory leaks in any scenario.
Bash

# Normal execution leak check
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); valgrind --leak-check=full ./push_swap $ARG

# Error handling leak check
valgrind --leak-check=full ./push_swap 1 2 3 1

3. Benchmarks & Correctness

The score depends on the number of instructions. Use these commands to check the count and verify sorting.
:1234: Small Sets (Score based on logic)
Bash

# 3 numbers (Should be < 3 instructions)
ARG="1 3 2"; ./push_swap $ARG | wc -l

./push_swap $ARG | ./checker_linux $ARG

# 5 numbers (Should be < 12 instructions)
ARG="5 2 4 1 3"; ./push_swap $ARG | wc -l

./push_swap $ARG | ./checker_linux $ARG

:1234: Large Sets (Score based on efficiency)
Bash

# 100 numbers (Max score < 700)
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

./push_swap $ARG | ./checker_linux $ARG

# 500 numbers (Max score < 5500)
ARG=$(shuf -i 0-5000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l

./push_swap $ARG | ./checker_linux $ARG

4. Already Sorted / Identity

If the stack is already sorted, the program should display nothing.
Bash

./push_swap 1 2 3

./push_swap 0 1 2 3 4 5