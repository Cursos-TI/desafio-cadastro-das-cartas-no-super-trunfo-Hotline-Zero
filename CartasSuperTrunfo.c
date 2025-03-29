#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Definição da estrutura 'Carta' que representa uma carta com várias informações
typedef struct {
    char estado;                // Estado representado pela carta (A-H)
    char codigo[4];             // Código da carta (ex: A01)
    char nomeCidade[50];        // Nome da cidade
    unsigned long int populacao;   // População da cidade aterada para unsigned long int
    float area;                 // Área da cidade em km²
    float pib;                  // PIB da cidade em bilhões de reais
    int pontosTuristicos;       // Número de pontos turísticos na cidade
    float denscidadepopul;       // Densidade da população (população dividida pela área)
    float pibpercapita;         // PIB per capita (PIB dividido pela população)
    float superpoder;           // Superpoder da carta 
} Carta;

// Função para ler os dados de uma carta do usuário
void lerCarta(Carta *carta) {
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);  // Lê o estado

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);    // Lê o código da carta

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", carta->nomeCidade);  // Lê o nome da cidade

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);  // Lê a população modificado para unsigned long int

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);  // Lê a área

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);  // Lê o PIB

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);  // Lê o número de pontos turísticos
    
    // Calcula a densidade populacional e o PIB per capita
    carta->denscidadepopul = (carta->area != 0) ? carta->populacao / carta->area : 0;
    carta->pibpercapita = (carta->populacao != 0) ? carta->pib / carta->populacao : 0;

        //Calcula o superpoder
    float inversoDensidade = (carta->area != 0) ? carta->populacao / carta->area : 0;
    carta->superpoder = carta->populacao + carta->area + carta->pib +
                        carta->pontosTuristicos + carta->pibpercapita + inversoDensidade;
}


// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);  // Exibe o número da carta
    printf("Estado: %c\n", carta.estado);  // Exibe o estado
    printf("Código: %s\n", carta.codigo);  // Exibe o código
    printf("Nome da Cidade: %s\n", carta.nomeCidade);  // Exibe o nome da cidade
    printf("População: %lu\n", carta.populacao);  // Exibe a população usando %lu para unsigned long int
    printf("Área: %.2f km²\n", carta.area);  // Exibe a área
    printf("PIB: %.2f bilhões de reais\n", carta.pib);  // Exibe o PIB
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);  // Exibe o número de pontos turísticos
    printf("Densidade da População: %.2f\n", carta.denscidadepopul);  // Exibe a densidade da população
    printf("PIB per Capita: %.2f\n", carta.pibpercapita);  // Exibe o PIB per capita
    printf("Superpoder: %.2f\n", carta.superpoder); // Exibe o superpoder
}
// Função para comparar atributos entre duas cartas e exibir resultados
void compararCartas(Carta carta1, Carta carta2) {
    printf("\nComparação de Cartas:\n");

    #define COMPARAR(nome, regra) \
        do { \
            if (regra) { \
                printf("%s: Carta 1 venceu\n", nome); \
            } else { \
                printf("%s: Carta 2 venceu\n", nome); \
            } \
        } while (0)
    COMPARAR("População", carta1.populacao > carta2.populacao);
    COMPARAR("População", carta1.populacao > carta2.populacao);
    COMPARAR("Área", carta1.area > carta2.area);
    COMPARAR("PIB", carta1.pib > carta2.pib);
    COMPARAR("Pontos Turísticos", carta1.pontosTuristicos > carta2.pontosTuristicos);
    COMPARAR("Densidade Populacional", carta1.denscidadepopul < carta2.denscidadepopul);
    COMPARAR("PIB per Capita", carta1.pibpercapita > carta2.pibpercapita);
        COMPARAR("Super Poder", carta1.superpoder > carta2.superpoder);
    }
// Função principal do programa
int main() {
    Carta carta1, carta2;  // Declara duas variáveis do tipo 'Carta'

    // Lê e exibe os dados da primeira carta
    printf("Insira os dados da primeira carta:\n");
    lerCarta(&carta1);

    // Lê e exibe os dados da segunda carta
    printf("\nInsira os dados da segunda carta:\n");
    lerCarta(&carta2);

    // Exibe os dados das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

        // Adiciona a chamada para comparar as cartas
        compararCartas(carta1, carta2);


    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}

