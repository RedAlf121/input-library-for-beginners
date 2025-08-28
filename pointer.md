# ✏ Cómo funciona (recomendado entender punteros)

La función principal **read(char* type)** hace la lectura genérica basándose en el tipo de dato indicado como string, reserva la memoria necesaria, lee usando scanf el valor y retorna un puntero a esa memoria.

Luego, funciones específicas como readInt(), readFloat(), etc., llaman a read(), validan la lectura y devuelven el valor esperado ya desreferenciado, liberando la memoria automáticamente (excepto para cadenas, que deben liberarse manualmente).

Esa función read es una funcion de tipo void*. ¿Qué sucede con un puntero de tipo void? Sucede que se define de forma manual la reserva en memoria. Un puntero de tipo float* va a reservar memoria para apuntar un float, pero el puntero void* no tiene definido eso por tanto puede apuntar a cualquier tipo de dato. Es como funciona por detrás el tipado dinámico de lenguajes como python o javascript. Lo engorroso de usar este tipo de datos es que aparte de manejar la reserva de memoria de forma manual hay que castear si quieres devolver el valor al que apunta. Un ejemplo de como está hecha la función readInt.
```C
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
```

Primero se hace un cast de void* a int* eso para sepa cuanto espacio en memoria ocupa el valor que está apuntando. Un int ocupa 4 bytes el puntero void va a ir al primer byte pero desconoce el resto con el cast puede tomar esos 3 que faltan.

————————