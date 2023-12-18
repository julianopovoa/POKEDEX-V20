#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 30
// Pokédex 1ª geração conta com 151 Pokémons
#define QTD_POKEDEX 151

// Estrututa para cadastrar Pokémon
struct pokemon {
  char nome[MAX], tipo[MAX];
};

void Linha() { printf("_____________________________________\n"); }

// Função para padronizar a primeira letra como maiúscula
void PadronizarPokemon(char pokemon[]) {
  int i;

  if (strlen(pokemon) > 0) {  
    pokemon[0] = toupper((unsigned char)pokemon[0]);
  }
  for (i = 1; pokemon[i] != '\0'; i++) {
      pokemon[i] = tolower((unsigned char)pokemon[i]);
  }
}

int main() {
  // Variável para verificar Pokémon cadastrado
  char novo_nome[QTD_POKEDEX][MAX];
  // Variáveis auxiliares
  int i, opcao, qtd_pokemon, qtd_tipo, tipo_existente, nome_existente;

  // Pokémons pré-cadastrados
  struct pokemon pk[QTD_POKEDEX] = {
    {"Bulbasaur", "Grama"},
    {"Charmander", "Fogo"},
    {"Squirtle", "Água"},        
    {"Pikachu", "Elétrico"},
    {"Jigglypuff", "Fada"}, 
    {"Mewtwo", "Psíquico"},
    {"Caterpie", "Inseto"}, 
    {"Snorlax", "Normal"}
  };

  // Variáveis para armazenar os tipos dos Pokémons
  int normal = 1, fogo = 1, grama = 1, agua = 1, voador = 0, lutador = 0, veneno = 0, eletrico = 1, terra = 0, pedra = 0, psiquico = 1, gelo = 0, inseto = 1, fantasma = 0, aco = 0, dragao = 0, sombrio = 0, fada = 1;

  // Definição da quantidade de Pokémons e tipos cadastrados
  qtd_pokemon = 8;
  qtd_tipo = 8;   

  tipo_existente = 0;
  nome_existente = 0;

  // Entrada do nome do usuário
  char treinador[50], *ponteiro;

  printf("Olá treinador(a), para iniciar a Pokedéx, digite seu nome: ");
  gets(treinador);

    if (strlen(treinador) > 0) {
    for (int i = 0; treinador[i] != '\0'; i++) {
        treinador[i] = toupper((unsigned char)treinador[i]);
    }
  }
  ponteiro = treinador;
  printf("\nOlá ");

  while (*ponteiro != '\0') {
    printf("%c", *ponteiro);
    ponteiro++;
  }
  printf("! Que bom tê-lo conosco! Esperamos que você se divirta!\n");

  // Introdução da Pokédex
  printf("\n««« BEM-VINDO A POKÉDEX »»» \n");
  Linha();
  printf("\nA Pokédex, também conhecida como Poké-Agenda, é uma mini enciclopédia eletrônica de Pokémons. Ela contém informações de todos os Pokémons existentes registrados em seu banco de dados, nela você pode cadastrar e/ou consultar Pokémons. Criada por Ana Clara Matias, Juliano Póvoa e Luiz Fernando Zamboti.\n");

  // Menu com opções da Pokédex
  do {

    Linha();

    printf("\n1. Cadastrar Pokémon \n2. Pokémons Cadastrados \n3. Informações da Pokédex \n4. Sair \n\nDigite a Opção Desejada: ");
    scanf("%d", &opcao);  
    fgetc(stdin);

    Linha();

    switch (opcao) {
      // Cadastro de Pokémons
      case 1:
        // Verificando se quantidade de Pokémons já atingiu o limite
        if (qtd_pokemon < QTD_POKEDEX) {
          printf("\nDigite o nome do Pokémon: ");
          gets(novo_nome[qtd_pokemon]);
          PadronizarPokemon(novo_nome[qtd_pokemon]);
          for (i = 0; i < qtd_pokemon; i++) {
            nome_existente = 0;
              if (strcmp(novo_nome[qtd_pokemon], pk[i].nome) == 0) {
                nome_existente = 1;
                break;
              }
          }
          if (nome_existente) {
            // Se um Pokémon com esse nome já foi cadastrado, o programa emite mensagem de erro
            printf("\n⚠️\tPokémon já cadastrado!\n");
          } else {
            strcpy(pk[qtd_pokemon].nome, novo_nome[qtd_pokemon]);
            // Se não estiver cadastrado, é pedido o tipo do Pokémon
            printf("\nDigite o tipo de Pokémon: ");
            gets(pk[qtd_pokemon].tipo);
            PadronizarPokemon(pk[qtd_pokemon].tipo);
            // Padronização de palavras acentuadas
            if (strcmp(pk[qtd_pokemon].tipo, "Agua") == 0 || (strcmp(pk[qtd_pokemon].tipo, "água") == 0)) {
              strcpy(pk[qtd_pokemon].tipo, "Água");
            }
            if (strcmp(pk[qtd_pokemon].tipo, "Eletrico") == 0) {
              strcpy(pk[qtd_pokemon].tipo, "Elétrico");
            }
            if (strcmp(pk[qtd_pokemon].tipo, "Psiquico") == 0) {
              strcpy(pk[qtd_pokemon].tipo, "Psíquico");
            }
            if (strcmp(pk[qtd_pokemon].tipo, "Dragao") == 0) {
              strcpy(pk[qtd_pokemon].tipo, "Dragão");
            }
            // Verificando se o tipo digitado é válido
              if (strcmp(pk[i].tipo, "Normal") == 0 || strcmp(pk[i].tipo, "Fogo") == 0 || strcmp(pk[i].tipo, "Água") == 0 || strcmp(pk[i].tipo, "Grama") == 0 || strcmp(pk[i].tipo, "Voador") == 0 || strcmp(pk[i].tipo, "Lutador") == 0 || strcmp(pk[i].tipo, "Veneno") == 0 || strcmp(pk[i].tipo, "Elétrico") == 0 || strcmp(pk[i].tipo, "Terra") == 0 || strcmp(pk[i].tipo, "Pedra") == 0 || strcmp(pk[i].tipo, "Psíquico") == 0 || strcmp(pk[i].tipo, "Gelo") == 0 || strcmp(pk[i].tipo, "Inseto") == 0 || strcmp(pk[i].tipo, "Fantasma") == 0 || strcmp(pk[i].tipo, "Aço") == 0 || strcmp(pk[i].tipo, "Dragão") == 0 || strcmp(pk[i].tipo, "Sombrio") == 0 || strcmp(pk[i].tipo, "Fada") == 0) {
              if (strcmp(pk[i].tipo, "Normal") == 0) {
                normal++;
              }
              if (strcmp(pk[i].tipo, "Fogo") == 0) {
                fogo++;
              } 
              if (strcmp(pk[i].tipo, "Água") == 0) {
                agua++;
              } 
              if (strcmp(pk[i].tipo, "Grama") == 0) {
                grama++;
              } 
              if (strcmp(pk[i].tipo, "Voador") == 0) {
                voador++;
              }
              if (strcmp(pk[i].tipo, "Lutador") == 0) {
                lutador++;
              }
              if (strcmp(pk[i].tipo, "Veneno") == 0) {
                veneno++;
              }
              if (strcmp(pk[i].tipo, "Elétrico") == 0) {
                eletrico++;
              }
              if (strcmp(pk[i].tipo, "Terra") == 0) {
                terra++;
              }
              if (strcmp(pk[i].tipo, "Pedra") == 0) {
                pedra++;
              }
              if (strcmp(pk[i].tipo, "Psíquico") == 0) {
                psiquico++;
              }
              if (strcmp(pk[i].tipo, "Gelo") == 0) {
                gelo++;
              }
              if (strcmp(pk[i].tipo, "Inseto") == 0) {
                inseto++;
              }
              if (strcmp(pk[i].tipo, "Fantasma") == 0) {
                fantasma++;
              }
              if (strcmp(pk[i].tipo, "Aço") == 0) {
                aco++;
              }
              if (strcmp(pk[i].tipo, "Dragão") == 0) {
                dragao++;
              }
              if (strcmp(pk[i].tipo, "Sombrio") == 0) {
                sombrio++;
              }
              if (strcmp(pk[i].tipo, "Fada") == 0) {
                fada++;
              }
            qtd_pokemon++;
            printf("\n✅\tPokémon cadastrado com sucesso!\n\n");
            } else {
              printf("\n⚠️\tTipo digitado inválido!\n");
            }
          }
        } else {
          // Se atingir o limite da Pokédex, o programa emite mensagem de erro
          printf("\nA Pokédex está cheia! Não é possível cadastrar mais Pokémons.\n");
        }
        break;
      // Visualização de Pokémons cadastrados
      case 2:
        printf("\nPokémons Cadastrados:\n\n");
        for (i = 0; i < qtd_pokemon; i++) {
          printf("%d. Nome: %s\t\t Tipo: %s\n", i, pk[i].nome, pk[i].tipo);
        }
        printf("\n");
        break;
      // Informações sobre a Pokédex
      case 3: 
        printf("\nA Pokédex possui %d Pokémons cadastrados. Faltam %d Pokémons para completá-la.\n", qtd_pokemon, QTD_POKEDEX - qtd_pokemon);
        // Visualização da quantidade de cada tipo de Pokémon cadastrado
        printf("\nTipos de Pokémons Cadastrados:\n\n");
        if (normal > 0) {
          printf("🕸️\tNormal [%d]\n", normal);
        }
        if (fogo > 0) {
          printf("🔥\tFogo [%d]\n", fogo);
        }
        if (agua > 0) {
          printf("💧\tÁgua [%d]\n", agua);
        }
        if (grama > 0) {
          printf("🍃\tGrama [%d]\n", grama);
        }
        if (voador > 0) {
          printf("🌫️\tVoador [%d]\n", voador);
        }
        if (lutador > 0) {
          printf("🥊\tLutador [%d]\n", lutador);
        }
        if (veneno > 0) {
          printf("☠️\tVeneno [%d]\n", veneno);
        }
        if (eletrico > 0) {
          printf("⚡\tElétrico [%d]\n", eletrico);
        }
        if (terra > 0) {
          printf("🌍\tTerra [%d]\n", terra);
        }
        if (pedra > 0) {
          printf("🌑\tPedra [%d]\n", pedra);
        }
        if (psiquico > 0) {
          printf("🌌\tPsíquico [%d]\n", psiquico);
        }
        if (gelo > 0) {
          printf("❄️\tGelo [%d]\n", gelo);
        }
        if (inseto > 0) {
          printf("🐛\tInseto [%d]\n", inseto);
        }
        if (fantasma > 0) {
          printf("👻\tFantasma [%d]\n", fantasma);
        }
        if (aco > 0) {
          printf("⚙️\tAço [%d]\n", aco);
        }
        if (dragao > 0) {
          printf("🐉\tDragão [%d]\n", dragao);
        }
        if (sombrio > 0) {
          printf("🦇\tSombrio [%d]\n", sombrio);
        }
        if (fada > 0) {
          printf("🧚‍♀️\tFada [%d]\n", fada);
        }
        break;
      // Sair do programa
      case 4:
        printf("\n ««« POKÉDEX ENCERRADA, ATÉ A PRÓXIMA %s! »»»", treinador);
        break;
      default:
        printf("\n Opção inválida, tente novamente.\n\n");
    }
  } while (opcao != 4);
  return 0;
}


