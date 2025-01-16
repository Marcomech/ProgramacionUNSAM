/* >> Conversiones y Mascaras <<
  * Escribe un programa en C que
  * 1) Pida al usuario un numero entero decimal y lo convierta a: binario, hexadecimal y BCD
  * 2) Pida al usuario un numero binario y lo utilice para aplicar los operadores (OR, AND y XOR) sobre el nro del punto 1
  * 3) Bonus - Calcule la cantidad de 1s y 0s en el numero ingresado por el usuario 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_INT 32
#define BITS_SHORT 16



int main() {

    unsigned short numOriginal, aux, digitoHex;
    char numHex[BITS_SHORT/4];
    unsigned short numBCD[10];

    char mascara[BITS_SHORT];

    unsigned short contador1s = 0;

    while (1) {
        printf("\n\nNumero original: ");
        scanf("%hu", &numOriginal);
        while (getchar() != '\n');  /* Para limpiar el buffer */


        /* =================================== Pasaje a Binario =================================== */
        printf("\nNumero en binario:\t0b");
        for (int i = BITS_SHORT-1; i >= 0; i--) 
            printf("%hu", (numOriginal >> i) & 0b1); /* Aplico una mascara sobre el numero shifteado */
        


        /* =================================== Pasaje a Hexadecimal =================================== */
        printf("\nNumero en Hexa: \t0x");
        if (numOriginal == 0)
            printf("0");

        else{
            aux = numOriginal; /* Hago esto para no pisar el valor */
            int i = 0;
            while (aux > 0) {
                digitoHex  = aux % 16;  /* Me quedo con el resto de aux / 16*/
                if (digitoHex < 10){
                    numHex[i] = digitoHex + '0';
                    i+=1;
                }
                else
                    numHex[i++] = digitoHex - 10 + 'A';/* Ver Tabla ASCII en el campus */
                /* 
                 * Podemos ver mas arriba dos formas equivalentes de aumentar el valor de la variable i.
                 * Hay que tener en cuenta que en ambos casos primero se guarda la variable en la posicion i del vector
                 * y despues se incrementa la misma.
                */
                aux /= 16; /* Divido aux / 16 y me quedo con el cociente, porque estoy trabajando con ints */
                }
                for (i-=1; i>= 0 ; i--) /* debido al loop utilizado, el valor de i es igual al largo de la cadena numHex */
                    printf("%c", numHex[i]);
        }
        /* =================================== Pasaje a BCD =================================== */
        printf("\nNumero en BCD:\t\t");
        if ( numOriginal == 0)
            printf("0");
        else {
            aux = numOriginal;
            int j = 0;
            while (aux > 0) {
                numBCD[j++] = aux % 10;
                aux /= 10;
            }
            for (j-=1; j >= 0; j--){
                for (int i = 3; i >= 0; i--)
                    printf("%hu", (numBCD[j] >> i) & 0b1);
                printf("  ");
            }
        }

        /* =================================== Aplicando Mascaras =================================== */
        printf("\n\nIngrese su Mascara: 0b");
        scanf("%15s", &mascara);
        while (getchar() != '\n');  /* Para limpiar el buffer */

        unsigned short valorMascara;
        valorMascara = (unsigned short) strtol(mascara, NULL, 2);
        

        printf("\n%hu AND 0b%s  =\t %hu  =\t 0b", numOriginal, mascara, numOriginal & valorMascara);
        for (int i = BITS_SHORT-1; i >= 0; i--) {printf("%hu", ((numOriginal & valorMascara) >> i) & 0b1);}

        printf("\n%hu OR  0b%s  =\t %hu  =\t 0b", numOriginal, mascara, numOriginal | valorMascara);
        for (int i = BITS_SHORT-1; i >= 0; i--) {printf("%hu", ((numOriginal | valorMascara) >> i)  & 0b1);}

        printf("\n%hu XOR 0b%s  =\t %hu  =\t 0b", numOriginal, mascara, numOriginal ^ valorMascara);
        for (int i = BITS_SHORT-1; i >= 0; i--) {printf("%hu", ((numOriginal ^ valorMascara) >> i) & 0b1);}

        /* =================================== Calculando cantidad de 1s =================================== */

        for (int i = BITS_SHORT-1; i >= 0; i--) 
            contador1s += (numOriginal >> i) & 0b1;
        printf("\n\nHay %hu unos en el numero %hu", contador1s, numOriginal);
        

    }
    return 0;
}