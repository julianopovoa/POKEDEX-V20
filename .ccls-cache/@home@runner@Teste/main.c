/*7) Escreva um programa que leia dois vetores de inteiros de mesmo tamanho e chame uma
função que receba dois vetores e o tamanho dos vetores como parâmetros. A função deverá
retornar o produto interno dos dois vetores. Ex: V={1, 2, 3} e W={4, 5, 6}, o produto interno
será: 1*4+2*5+3*6=32. Imprima o valor de retorno na main().*/

#include <stdio.h>
#include <string.h>

int verificar_maiusculo(char string[100]) {
  int i, cont_maiusculo;

  cont_maiusculo = 0;

  for (i = 0; i < strlen(string); i++) {
    if (string[i] >= 'A' && string[i] <= 'Z') {
      cont_maiusculo++;
    }
  }

  return cont_maiusculo;
}

int main() {
  char string[100];

  printf("Digite uma string: ");
  gets(string);

  printf("A string possui %d caracteres maiúsculas.\n", verificar_maiusculo(string));  

  return 0;
}
