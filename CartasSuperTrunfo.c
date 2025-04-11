#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Definição da estrutura de uma carta
typedef struct {
    char estado[3];               // Ex: "SP"
    char codigo[4];               // Código da carta, ex: "A01"
    char nomeCidade[50];         // Nome da cidade
    unsigned long int populacao; // População da cidade
    float area;                   // Área da cidade em km²
    float pib;                    // PIB da cidade em bilhões
    int pontosTuristicos;        // Pontos turísticos da cidade
    float denscidadepopul;       // Densidade populacional (calculada)
    float pibpercapita;          // PIB per capita (calculado)
} Carta;

// Função para ler os dados de uma carta fornecidos pelo usuário
void lerCarta(Carta *carta) {
    printf("Digite o estado (ex: SP): ");
    scanf("%s", carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); // Lê string com espaço

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcula os atributos derivados
    carta->denscidadepopul = (carta->area != 0) ? carta->populacao / carta->area : 0;
    carta->pibpercapita = (carta->populacao != 0) ? (carta->pib * 1e9) / carta->populacao : 0;
}

// Exibe todas as informações de uma carta
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

// Retorna o nome do atributo baseado no número escolhido
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

// Retorna o valor de um atributo específico de uma carta
float obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return carta.denscidadepopul;
        default: return 0;
    }
}

// Função principal
int main() {
    // Declaração das cartas e variáveis auxiliares
    Carta carta1, carta2;
    int atributo1 = 0, atributo2 = 0; // atributos escolhidos
    int vencedor1, vencedor2;         // não usados diretamente aqui
    float soma1 = 0, soma2 = 0;       // somas dos atributos das cartas

    printf("=== Bem-vindo ao Super Trunfo ===\n");

    // Leitura dos dados da primeira e segunda carta
    printf("\nInsira os dados da primeira carta:\n");
    lerCarta(&carta1);

    printf("\nInsira os dados da segunda carta:\n");
    lerCarta(&carta2);

    // Primeiro menu: escolha do primeiro atributo
    do {
        printf("\nEscolha o PRIMEIRO atributo para comparação:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
        printf("Digite sua escolha: ");
        scanf("%d", &atributo1);

        // Validação
        if (atributo1 < 1 || atributo1 > 5)
            printf("Opção inválida! Tente novamente.\n");

    } while (atributo1 < 1 || atributo1 > 5);

    // Segundo menu: escolha do segundo atributo, evitando repetição
    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro - %s):\n", nomeAtributo(atributo1));
        for (int i = 1; i <= 5; i++) {
            if (i != atributo1) {
                printf("%d - %s\n", i, nomeAtributo(i));
            }
        }
        printf("Digite sua escolha: ");
        scanf("%d", &atributo2);

        // Validação
        if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) {
            printf("Opção inválida! Tente novamente.\n");
        }

    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5);

    // Comparação do primeiro atributo
    printf("\nComparando o atributo: %s\n", nomeAtributo(atributo1));
    float valor1a = obterValorAtributo(carta1, atributo1);
    float valor2a = obterValorAtributo(carta2, atributo1);
    soma1 += valor1a;
    soma2 += valor2a;

    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor1a, carta2.nomeCidade, valor2a);

    // Comparação do segundo atributo
    printf("\nComparando o atributo: %s\n", nomeAtributo(atributo2));
    float valor1b = obterValorAtributo(carta1, atributo2);
    float valor2b = obterValorAtributo(carta2, atributo2);
    soma1 += valor1b;
    soma2 += valor2b;

    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor1b, carta2.nomeCidade, valor2b);

    // Exibição da soma total dos dois atributos
    printf("\nSoma dos atributos:\n");
    printf("Carta 1 (%s): %.2f\n", carta1.nomeCidade, soma1);
    printf("Carta 2 (%s): %.2f\n", carta2.nomeCidade, soma2);

    // Verificação do vencedor ou empate
    if (soma1 > soma2)
        printf("\nResultado Final: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    else if (soma2 > soma1)
        printf("\nResultado Final: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    else
        printf("\nResultado Final: Empate!\n");

    return 0;
}