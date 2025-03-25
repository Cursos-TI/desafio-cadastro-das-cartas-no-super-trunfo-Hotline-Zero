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
    int populacao;              // População da cidade
    float area;                 // Área da cidade em km²
    float pib;                  // PIB da cidade em bilhões de reais
    int pontosTuristicos;       // Número de pontos turísticos na cidade
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
    scanf("%d", &carta->populacao);  // Lê a população

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);  // Lê a área

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);  // Lê o PIB

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);  // Lê o número de pontos turísticos
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);  // Exibe o número da carta
    printf("Estado: %c\n", carta.estado);  // Exibe o estado
    printf("Código: %s\n", carta.codigo);  // Exibe o código
    printf("Nome da Cidade: %s\n", carta.nomeCidade);  // Exibe o nome da cidade
    printf("População: %d\n", carta.populacao);  // Exibe a população
    printf("Área: %.2f km²\n", carta.area);  // Exibe a área
    printf("PIB: %.2f bilhões de reais\n", carta.pib);  // Exibe o PIB
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);  // Exibe o número de pontos turísticos
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

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}

