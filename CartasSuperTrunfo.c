#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Definição da estrutura que representa uma carta do jogo
// Contém informações como estado, cidade, população, área, PIB e atributos calculados
typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float denscidadepopul;
    float pibpercapita;
} Carta;

// Função para ler os dados de uma carta pela entrada do usuário
void lerCarta(Carta *carta) {
    printf("Digite o estado (ex: SP): ");
    scanf("%s", carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^"]", carta->nomeCidade);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculo dos atributos derivados
    carta->denscidadepopul = (carta->area != 0) ? carta->populacao / carta->area : 0;
    carta->pibpercapita = (carta->populacao != 0) ? (carta->pib * 1e9) / carta->populacao : 0;
}

// Função que exibe os dados de uma carta formatadamente
void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f\n", carta.denscidadepopul);
    printf("PIB per capita: %.2f\n", carta.pibpercapita);
}

// Função que retorna o nome do atributo com base no seu número identificador
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        default: return "Desconhecido";
    }
}

// Função que retorna o valor do atributo correspondente da carta
// Para densidade populacional, aplica-se a inversão (menor valor vence)
float obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return (carta.denscidadepopul != 0) ? (1.0f / carta.denscidadepopul) : 0;
        default: return 0;
    }
}

int main() {
    Carta carta1, carta2;
    int atributo1 = 0, atributo2 = 0;
    float soma1 = 0, soma2 = 0;

    printf("=== Bem-vindo ao Super Trunfo ===\n");

    // Entrada de dados das duas cartas
    printf("\nInsira os dados da primeira carta:\n");
    lerCarta(&carta1);

    printf("\nInsira os dados da segunda carta:\n");
    lerCarta(&carta2);

    // Menu para seleção do primeiro atributo
    do {
        printf("\nEscolha o PRIMEIRO atributo para comparação:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
        printf("Digite sua escolha: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5)
            printf("Opção inválida! Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 5);

    // Menu para seleção do segundo atributo (sem repetir o primeiro)
    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro - %s):\n", nomeAtributo(atributo1));
        for (int i = 1; i <= 5; i++) {
            if (i != atributo1) {
                printf("%d - %s\n", i, nomeAtributo(i));
            }
        }
        printf("Digite sua escolha: ");
        scanf("%d", &atributo2);
        if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5)
            printf("Opção inválida! Tente novamente.\n");
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5);

    // Comparando o primeiro atributo escolhido
    printf("\nComparando o atributo: %s\n", nomeAtributo(atributo1));
    float valor1a = obterValorAtributo(carta1, atributo1);
    float valor2a = obterValorAtributo(carta2, atributo1);
    soma1 += valor1a;
    soma2 += valor2a;
    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor1a, carta2.nomeCidade, valor2a);

    // Comparando o segundo atributo escolhido
    printf("\nComparando o atributo: %s\n", nomeAtributo(atributo2));
    float valor1b = obterValorAtributo(carta1, atributo2);
    float valor2b = obterValorAtributo(carta2, atributo2);
    soma1 += valor1b;
    soma2 += valor2b;
    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor1b, carta2.nomeCidade, valor2b);

    // Exibindo o resultado final da comparação
    printf("\nSoma dos atributos:\n");
    printf("Carta 1 (%s): %.2f\n", carta1.nomeCidade, soma1);
    printf("Carta 2 (%s): %.2f\n", carta2.nomeCidade, soma2);

    if (soma1 > soma2)
        printf("\nResultado Final: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    else if (soma2 > soma1)
        printf("\nResultado Final: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    else
        printf("\nResultado Final: Empate!\n");

    return 0;
}
