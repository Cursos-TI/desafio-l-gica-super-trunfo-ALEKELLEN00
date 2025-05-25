#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis cidade 1
    char estado1[50], nome1[50];
    int codigo1;
    unsigned long int populacao1;
    float area1, pib1;
    int pontos1;

    // Variáveis cidade 2
    char estado2[50], nome2[50];
    int codigo2;
    unsigned long int populacao2;
    float area2, pib2;
    int pontos2;

    // Outras variáveis calculadas
    float densidade1, densidade2;
    float percapita1, percapita2;
    float super1, super2;

    int opcao;

    printf("=== SUPER TRUNFO - NÍVEL AVENTUREIRO ===\n\n");

    // --- Cadastro cidade 1 ---
    printf("Cadastro da carta da cidade 1:\n");
    printf("Estado: ");
    scanf(" %[^\n]", estado1);
    printf("Cidade: ");
    scanf(" %[^\n]", nome1);
    printf("Código da carta: ");
    scanf("%d", &codigo1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos1);

    // --- Cadastro cidade 2 ---
    printf("\nCadastro da carta da cidade 2:\n");
    printf("Estado: ");
    scanf(" %[^\n]", estado2);
    printf("Cidade: ");
    scanf(" %[^\n]", nome2);
    printf("Código da carta: ");
    scanf("%d", &codigo2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos2);

    // --- Cálculos ---
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    percapita1 = pib1 / populacao1;
    percapita2 = pib2 / populacao2;
    super1 = 1 / densidade1 + (populacao1 + area1 + pib1 + pontos1 + percapita1);
    super2 = 1 / densidade2 + (populacao2 + area2 + pib2 + pontos2 + percapita2);

    // --- Menu Interativo ---
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - PIB per capita\n");
    printf("6 - Densidade populacional (MENOR VENCE)\n");
    printf("7 - Super Poder\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    // --- Comparação ---
    printf("\nResultado da comparação:\n");

    switch(opcao) {
        case 1:
            if (populacao1 > populacao2) {
                printf("%s venceu com maior população.\n", nome1);
            } else if (populacao2 > populacao1) {
                printf("%s venceu com maior população.\n", nome2);
            } else {
                printf("Empate na população! Comparando pelo PIB...\n");
                if (pib1 > pib2) printf("%s venceu no desempate com maior PIB.\n", nome1);
                else if (pib2 > pib1) printf("%s venceu no desempate com maior PIB.\n", nome2);
                else printf("Empate total!\n");
            }
            break;

        case 2:
            if (area1 > area2) {
                printf("%s venceu com maior área.\n", nome1);
            } else if (area2 > area1) {
                printf("%s venceu com maior área.\n", nome2);
            } else {
                printf("Empate na área! Comparando por população...\n");
                if (populacao1 > populacao2) printf("%s venceu no desempate com maior população.\n", nome1);
                else if (populacao2 > populacao1) printf("%s venceu no desempate com maior população.\n", nome2);
                else printf("Empate total!\n");
            }
            break;

        case 3:
            if (pib1 > pib2) {
                printf("%s venceu com maior PIB.\n", nome1);
            } else if (pib2 > pib1) {
                printf("%s venceu com maior PIB.\n", nome2);
            } else {
                printf("Empate no PIB! Comparando por PIB per capita...\n");
                if (percapita1 > percapita2) printf("%s venceu no desempate com maior PIB per capita.\n", nome1);
                else if (percapita2 > percapita1) printf("%s venceu no desempate com maior PIB per capita.\n", nome2);
                else printf("Empate total!\n");
            }
            break;

        case 4:
            if (pontos1 > pontos2) {
                printf("%s venceu com mais pontos turísticos.\n", nome1);
            } else if (pontos2 > pontos1) {
                printf("%s venceu com mais pontos turísticos.\n", nome2);
            } else {
                printf("Empate nos pontos turísticos! Comparando por PIB...\n");
                if (pib1 > pib2) printf("%s venceu no desempate com maior PIB.\n", nome1);
                else if (pib2 > pib1) printf("%s venceu no desempate com maior PIB.\n", nome2);
                else printf("Empate total!\n");
            }
            break;

        case 5:
            if (percapita1 > percapita2) {
                printf("%s venceu com maior PIB per capita.\n", nome1);
            } else if (percapita2 > percapita1) {
                printf("%s venceu com maior PIB per capita.\n", nome2);
            } else {
                printf("Empate no PIB per capita! Comparando por população...\n");
                if (populacao1 > populacao2) printf("%s venceu no desempate com maior população.\n", nome1);
                else if (populacao2 > populacao1) printf("%s venceu no desempate com maior população.\n", nome2);
                else printf("Empate total!\n");
            }
            break;

        case 6:
            if (densidade1 < densidade2) {
                printf("%s venceu com menor densidade populacional.\n", nome1);
            } else if (densidade2 < densidade1) {
                printf("%s venceu com menor densidade populacional.\n", nome2);
            } else {
                printf("Empate na densidade! Comparando por área...\n");
                if (area1 > area2) printf("%s venceu no desempate com maior área.\n", nome1);
                else if (area2 > area1) printf("%s venceu no desempate com maior área.\n", nome2);
                else printf("Empate total!\n");
            }
            break;

        case 7:
            if (super1 > super2) {
                printf("%s venceu com maior Super Poder.\n", nome1);
            } else if (super2 > super1) {
                printf("%s venceu com maior Super Poder.\n", nome2);
            } else {
                printf("Empate no Super Poder! Comparando por PIB...\n");
                if (pib1 > pib2) printf("%s venceu no desempate com maior PIB.\n", nome1);
                else if (pib2 > pib1) printf("%s venceu no desempate com maior PIB.\n", nome2);
                else printf("Empate total!\n");
            }
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }

    return 0;
}