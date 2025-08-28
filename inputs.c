#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void* read(char* type)
{
    void* aux = NULL;
    int memory=0;
    bool supported = true;
    char initial = type[0];
    char* scanfType = "";
    switch(initial)
    {
        case 'i':
            memory = sizeof(int);
            scanfType="%d";
            break;
        case 'f':
            memory = sizeof(float);
            scanfType="%f";
            break;
        case 'd':
            memory = sizeof(double);
            scanfType="%lf";
            break;
        case 'l':
            memory = sizeof(long);
            scanfType="%ld";
            break;
        case 's':
            memory = 100;
            scanfType="%s";
            break;
        default:
            printf("Unsuported type: %s",type);
            supported = false;
            return NULL;
    }
    aux = malloc(memory);
    if(scanf(scanfType,aux)!=1)
    {
        free(aux);
        return NULL;
    }
    return aux;
}


int readInt()
{
    int* pointer = (int*)read("int");
    if(pointer == NULL)
    {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    int number = *pointer;
    free(pointer);
    return number;
}

float readFloat()
{
    float* pointer = (float*)read("float");
    if(pointer == NULL)
    {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    float number = *pointer;
    free(pointer);
    return number;
}

double readDouble()
{
    double* pointer = (double*)read("double");
    if(pointer == NULL)
    {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    double number = *pointer;
    free(pointer);
    return number;
}

long readLong()
{
    long* pointer = (long*)read("long");
    if(pointer == NULL)
    {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    long number = *pointer;
    free(pointer);
    return number;
}

char readChar()
{
    char* str = readString();
    char character = str[0];
    free(str);
    return character;
}

char* readString()
{
    char* str = (char*)read("string");
    if(str == NULL)
    {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    return str;
}

void testInputs()
{
    printf("Prueba de lectura de int. Introduce: 123\n");
    int i = readInt();
    printf("Valor leído: %d\n", i);
    if(i == 123) printf("OK: readInt\n");
    else printf("FALLO: readInt\n");

    printf("\nPrueba de lectura de float. Introduce: 4.56\n");
    float f = readFloat();
    printf("Valor leído: %f\n", f);
    if(f > 4.55f && f < 4.57f) printf("OK: readFloat\n");
    else printf("FALLO: readFloat\n");

    printf("\nPrueba de lectura de double. Introduce: 7.89\n");
    double d = readDouble();
    printf("Valor leído: %lf\n", d);
    if(d > 7.88 && d < 7.90) printf("OK: readDouble\n");
    else printf("FALLO: readDouble\n");

    printf("\nPrueba de lectura de char. Introduce: x\n");
    char c = readChar();
    printf("Valor leído: %c\n", c);
    if(c == 'x') printf("OK: readChar\n");
    else printf("FALLO: readChar\n");

    printf("\nPrueba de lectura de string. Introduce: hola\n");
    char* s = readString();
    printf("Valor leído: %s\n", s);
    if(strcmp(s, "hola") == 0) printf("OK: readString\n");
    else printf("FALLO: readString\n");
    free(s);
}
