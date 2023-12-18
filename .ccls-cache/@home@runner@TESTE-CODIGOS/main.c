#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 50
#define QTD_POKEDEX 151

void Linha() { printf("___________________________________\n"); }

int main() {

  // Criação de Variáveis e Vetores para serem utilizadas
  char nome[QTD_POKEDEX][MAX], tipo[QTD_POKEDEX][MAX],
      novo_nome[QTD_POKEDEX][MAX]; // Vetores da Pokédex: nome e tipo
  int i, j, opcao, qtd_pokemon, qtd_tipo, tipo_existente,
      nome_existente; // Variáveis auxiliares

  /* A Pokédex básica conta com 151 Pokémons, por isso definimos a quantidade a
   * priori, lá em cima */

  // Vou registrar de antemão alguns Pokémons em nossa Pokédex //

  strcpy(nome[0], "Bulbasaur");
  strcpy(tipo[0], "Planta/Veneno");
  strcpy(nome[1], "Charmander");
  strcpy(tipo[1], "Fogo");
  strcpy(nome[2], "Squirtle");
  strcpy(tipo[2], "Agua");
  strcpy(nome[3], "Caterpie");
  strcpy(tipo[3], "Inseto");
  strcpy(nome[4], "Pidgey");
  strcpy(tipo[4], "Normal/Voador");
  strcpy(nome[5], "Pikachu");
  strcpy(tipo[5], "Eletrico");

  qtd_pokemon = 6; // Já incorporando a quantidade colocada
  qtd_tipo = 6;    // Já incoporando a quantidade colocada
  tipo_existente = 0;
  nome_existente = 0;

  /* Printando a Introdução da Pokédex, com a descrição básica*/

  printf("\n ««« BEM-VINDO A POKEDÉX »»» \n");
  Linha();
  printf("\n A Pokédex, também conhecida como Poké-Agenda, é uma mini "
         "enciclopédia eletrônica de Pokémons. Ela contém informações de todos "
         "os Pokémons existentes registrados em seu banco de dados, nela você "
         "pode cadastrar e/ou consultar Pokémons. Criada por Ana Clara Matias "
         "e Juliano Póvoa.\n");

  /* Aqui estamos colocando as opçõe possíveis para o usuário na nossa Pokédex
   */

  do {

    Linha();

    printf("\n 1. Cadastrar Pokémon \n 2. Pokémons Cadastrados \n 3. "
           "Informações da Pokédex \n 4. Sair \n\n Digite a Opção Desejada: ");
    scanf("%d", &opcao);

    Linha();

    switch (opcao) {

    case 1:                            // Cadastramento de Pokémons
      if (qtd_pokemon < QTD_POKEDEX) { // Assim a quantidade não é maior do que
                                       // cabe na Pokédex básica //

        printf("\n Digite o nome do Pokémon: ");
        scanf("%s", novo_nome[qtd_pokemon]);

        for (i = 0; i < qtd_pokemon; i++) {
          nome_existente = 0;
          if (strcmp(novo_nome[qtd_pokemon], nome[i]) == 0) { // Comparativo
            nome_existente = 1;
            break;
          }
        }

        if (nome_existente) {
          printf("\n ⚠️ Um Pokémon com esse nome já foi cadastrado! \n");
          /* Se um Pokémon com esse nome já foi cadastrado, o programa indica e
           * não possibilita o cadastramento duplicado */
        } else {
          strcpy(nome[qtd_pokemon], novo_nome[qtd_pokemon]);
          printf("\n Digite o tipo de Pokémon: ");
          scanf("%s", tipo[qtd_pokemon]);
          qtd_pokemon++;
          printf("\n ✓ Pokémon cadastrado com sucesso! \n\n");
        } /* Se não for duplicado, pedimos o tipo do Pokémon e liberamos o
             cadastramento */

      } else {
        printf("\n A Pokédex está cheia! Não é possível cadastrar mais "
               "Pokémons.\n");
        /* Se a quantidade de Pokémon exceder 151, não podemos cadastrar novos
         * Pokémons */
      }
      break;

    case 2: // Visualização de Pokémons Cadastrados

      printf("\n Pokémons Cadastrados:\n\n");
      for (i = 0; i < qtd_pokemon; i++) {
        printf("%d. Nome: %s\t Tipo: %s\n", i, nome[i], tipo[i]);
      }
      printf("\n");
      break;

    case 3: // Informações da Pokédex

      printf("\n A Pokédex possui %d Pokémons cadastrados. Faltam %d Pokémons "
             "para completá-la.\n",
             qtd_pokemon, QTD_POKEDEX - qtd_pokemon);
      /* Aqui colocamos uma conta básica para saber quantos Pokémons faltam para
       * completar nossa Pokédex */
      printf("\n Tipos de Pokémons Cadastrados:\n\n");
      /* Para tipos, precisamos contar individualmente os tipos, para não somar
       * duas vezes Elétrico, por exemplo */

      for (i = 0; i < qtd_pokemon; i++) {
        tipo_existente = 0;
        for (j = 0; j < i; j++) {
          if (strcmp(tipo[i], tipo[j]) == 0) {
            tipo_existente = 1;
            break;
          }
        }

        if (!tipo_existente) {
          qtd_tipo++;
        }
      }

      for (i = 0; i < qtd_pokemon; i++) {
        tipo_existente = 0;
        for (j = 0; j < i; j++) {
          if (strcmp(tipo[i], tipo[j]) == 0) {
            tipo_existente = 1;
            break;
          }
        }

        if (!tipo_existente) {
          printf("► %s \n", tipo[i]);
        }
      }

      break;

    case 4: // Sair da Pokédex

      printf("\n ««« POKEDÉX ENCERRADA, ATÉ A PRÓXIMA! »»»");
      break;
    default:
      printf("\n Opção inválida, tente novamente.\n\n");
    }
  } while (opcao != 4);

  return 0;
}