————————

# 📌 Biblioteca de Lectura Genérica para Principiantes en programación C

Esta pequeña biblioteca facilita la lectura de diferentes tipos de datos en C usando funciones simples y amigables. Es ideal para quienes comienzan a programar en C como primer lenguaje.
Abstrae del uso de sintaxis innecesaria para el comienzo. Como el uso de caracteres especiales o &.
Se recomienda utilizar la biblioteca de **sdtio.h** una vez se dominen los conceptos de punteros y referencias.
————————

## ✏ Características

⦁ Lectura de tipos básicos: int, float, double, long, char y string (cadenas de texto).
⦁ Manejo automático de memoria dinámica para los inputs.
⦁ Validación básica de errores de entrada.
⦁ Funciones específicas para cada tipo que retornan el valor directamente, sin que el usuario tenga que hacer cast.
⦁ Pensada para ayudar a estudiantes que están aprendiendo C y quieren un input más sencillo y seguro.

————————

## ✏ Uso básico

Existen varias funciones read segun el tipo de dato que vas a usar.
```C 
int readInt();
float readFloat();
double readDouble();
long readLong();
char readChar();
char* readString();
```

Aqui un ejemplo de su uso:

```C
#include "inputs.h"
#include <stdio.h>

int main() {
    int x = readInt();
    printf("Entero leído: %d\n", x);

    float f = readFloat();
    printf("Float leído: %f\n", f);

    char* str = readString();
    printf("Cadena leída: %s\n", str);
    free(str); // ¡no olvides liberar!

    return 0;
}
```

————————

## ✏ Recomendaciones y buenas prácticas

⦁ Siempre valida que las entradas sean correctas (la biblioteca maneja errores básicos y termina el programa en caso de fallo).
⦁ Para strings: recuerda liberar la memoria reservada con free() cuando ya no necesites la cadena.
⦁ Esta biblioteca usa memoria dinámica para adaptar el tamaño de la input y facilitar la lectura desde teclado.
⦁ Es una buena base para quienes inician y quieren evitar errores comunes con punteros y casting.

————————

## ✏ Sobre el curso en Hotmart

Esta biblioteca forma parte del curso "Programación en C para Principiantes" que ofrezco en Hotmart, donde aprenderás conceptos fundamentales, manejo básico de memoria, y cómo crear programas robustos y eficientes desde cero.

————————


————————

## ✏ Cómo funciona (recomendado entender punteros)

Para las mentes curiosas revisar este [enlace](pointer.md).
————————