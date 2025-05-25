#include <stdio.h>

int main (){

    printf("Desafio Supertrunfo - Países!\n\n");

    // Cadastro das cartas: Estado, código, nome, população, área, PIB, pontos turísticos

    // Adicionadas variáveis extras para cidade 1
    char estado[50], nome[50];
    int codigo;

    // Adicionadas variáveis extras para cidade 2
    char estado2[50], nome2[50];
    int codigo2;

    // Variáveis cidade 1
    unsigned long int populacao;
    float area, pib;
    int numero_pontos_turisticos;
    float densidade_populacional, pib_percapita, super_poder;

    // Variáveis cidade 2
    unsigned long int populacao2;
    float area2, pib2;
    int numero_pontos_turisticos2;
    float densidade_populacional2, pib_percapita2, super_poder2;

    // Leitura cidade 1
    printf("Digite o estado da cidade 1: ");
    scanf(" %[^\n]", estado);

    printf("Digite o nome da cidade 1: ");
    scanf(" %[^\n]", nome);

    printf("Digite o código da carta da cidade 1: ");
    scanf("%d", &codigo);

    printf("Digite a população da cidade 1: ");
    scanf("%lu", &populacao);

    printf("Digite a área da cidade 1: ");
    scanf("%f", &area);

    printf("Digite o PIB da cidade 1: ");
    scanf("%f", &pib);

    printf("Digite o número de pontos turísticos da cidade 1: ");
    scanf("%d", &numero_pontos_turisticos);

    // Leitura cidade 2
    printf("\nDigite o estado da cidade 2: ");
    scanf(" %[^\n]", estado2);

    printf("Digite o nome da cidade 2: ");
    scanf(" %[^\n]", nome2);

    printf("Digite o código da carta da cidade 2: ");
    scanf("%d", &codigo2);

    printf("Digite a população da cidade 2: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade 2: ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade 2: ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos da cidade 2: ");
    scanf("%d", &numero_pontos_turisticos2);

    // Cálculos
    densidade_populacional = populacao / area;
    pib_percapita = pib / populacao;
    super_poder = 1 / densidade_populacional + (populacao + area + pib + numero_pontos_turisticos + pib_percapita);

    densidade_populacional2 = populacao2 / area2;
    pib_percapita2 = pib2 / populacao2;
    super_poder2 = 1 / densidade_populacional2 + (populacao2 + area2 + pib2 + numero_pontos_turisticos2 + pib_percapita2);

    // Exibição dos dados cidade 1
    printf("\n--- Carta Cidade 1 ---\n");
    printf("Estado: %s\n", estado);
    printf("Cidade: %s\n", nome);
    printf("Código: %d\n", codigo);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f\n", area);
    printf("PIB: %.2f\n", pib);
    printf("Pontos turísticos: %d\n", numero_pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", densidade_populacional);
    printf("PIB per capita: %.2f\n", pib_percapita);

    // Exibição dos dados cidade 2
    printf("\n--- Carta Cidade 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Cidade: %s\n", nome2);
    printf("Código: %d\n", codigo2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos turísticos: %d\n", numero_pontos_turisticos2);
    printf("Densidade Populacional: %.2f\n", densidade_populacional2);
    printf("PIB per capita: %.2f\n", pib_percapita2);

    // Comparação com base em um critério específico
    printf("\n🔍 Comparando cartas com base no PIB...\n");

    if (pib > pib2) {
        printf("A carta vencedora é: %s (%s), com maior PIB.\n", nome, estado);
    } else if (pib < pib2) {
        printf("A carta vencedora é: %s (%s), com maior PIB.\n", nome2, estado2);
    } else {
        printf("Ambas as cidades possuem o mesmo PIB.\n");
    }

    // Comparação especial: densidade populacional (menor vence)
    printf("\nComparando densidade populacional (menor vence)...\n");

    if (densidade_populacional < densidade_populacional2) {
        printf("A carta vencedora é: %s (%s), com menor densidade populacional.\n", nome, estado);
    } else if (densidade_populacional > densidade_populacional2) {
        printf("A carta vencedora é: %s (%s), com menor densidade populacional.\n", nome2, estado2);
    } else {
        printf("Ambas as cidades possuem a mesma densidade populacional.\n");
    }

    return 0;
}
