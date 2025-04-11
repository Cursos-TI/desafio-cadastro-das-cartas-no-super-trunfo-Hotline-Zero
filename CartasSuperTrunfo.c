#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Definição da estrutura que representa uma carta do jogo
// Contém informações como estado, cidade, população, área, PIB e atributos calculados
#include <stdio.h>

// Estrutura de uma carta do Super Trunfo
typedef struct {
    char estado;                  // Letra de 'A' a 'H'
    char codigo[4];               // Código da carta (ex: A01)
    char nomeCidade[50];         // Nome da cidade
    unsigned long int populacao; // Número de habitantes
    float area;                  // Área em km²
    float pib;                   // PIB em bilhões de reais
    int pontosTuristicos;        // Número de pontos turísticos
    float densidadePopulacional; // Densidade populacional
    float pibPerCapita;          // PIB per capita
    float superPoder;            // Super Poder
} Carta;

int main() {
    Carta carta1, carta2;

    // Leitura da Carta 1
    printf("Carta 1:\n");
    printf("Estado: ");
    scanf(" %c", &carta1.estado);
    printf("Código: ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^"]", carta1.nomeCidade);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Leitura da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: ");
    scanf(" %c", &carta2.estado);
    printf("Código: ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^"]", carta2.nomeCidade);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculo dos atributos derivados
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1e9) / carta1.populacao;
    carta1.superPoder = carta1.populacao + carta1.area + carta1.pib + carta1.pontosTuristicos + carta1.pibPerCapita + (1.0f / carta1.densidadePopulacional);

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1e9) / carta2.populacao;
    carta2.superPoder = carta2.populacao + carta2.area + carta2.pib + carta2.pontosTuristicos + carta2.pibPerCapita + (1.0f / carta2.densidadePopulacional);

    // Exibição das cartas com todos os dados
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Número de Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Número de Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);

    // Comparação dos atributos
    printf("\nComparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1.pontosTuristicos > carta2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", carta1.densidadePopulacional < carta2.densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1.pibPerCapita > carta2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1.superPoder > carta2.superPoder);

    return 0;
}
