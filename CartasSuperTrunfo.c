#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
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

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
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

    // Função para exibir os dados de uma carta

}
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
