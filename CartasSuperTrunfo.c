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
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
