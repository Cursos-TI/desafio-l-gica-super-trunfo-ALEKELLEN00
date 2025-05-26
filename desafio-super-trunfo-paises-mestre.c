#include <stdio.h>
#include <string.h>

// Função para exibir o menu dinâmico
void exibir_menu_atributos() {
    printf("\nEscolha um atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - PIB per capita\n");
    printf("6 - Densidade populacional (menor vence)\n");
    printf("7 - Super Poder\n");
}

int main() {
    // Cartas
    char estado1[50], nome1[50], estado2[50], nome2[50];
    int codigo1, codigo2;
    unsigned long populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;

    // Cálculos derivados
    float densidade1, densidade2;
    float percapita1, percapita2;
    float super1, super2;

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO - NÍVEL MESTRE ===\n");

    // Entrada carta 1
    printf("\nCadastro da carta 1:\n");
    printf("Estado: ");
    scanf(" %[^\n]", estado1);
    printf("Cidade: ");
    scanf(" %[^\n]", nome1);
    printf("Código: ");
    scanf("%d", &codigo1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos1);

    // Entrada carta 2
    printf("\nCadastro da carta 2:\n");
    printf("Estado: ");
    scanf(" %[^\n]", estado2);
    printf("Cidade: ");
    scanf(" %[^\n]", nome2);
    printf("Código: ");
    scanf("%d", &codigo2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos2);

    // Cálculos derivados
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    percapita1 = pib1 / populacao1;
    percapita2 = pib2 / populacao2;
    super1 = 1 / densidade1 + (populacao1 + area1 + pib1 + pontos1 + percapita1);
    super2 = 1 / densidade2 + (populacao2 + area2 + pib2 + pontos2 + percapita2);

    // Menu dinâmico
    exibir_menu_atributos();
    printf("Escolha o primeiro atributo para comparar: ");
    scanf("%d", &atributo1);

    exibir_menu_atributos();
    printf("Escolha o segundo atributo para desempate: ");
    scanf("%d", &atributo2);

    // Função para retornar o valor de um atributo
    float obter_valor(int atributo, int carta) {
        switch (atributo) {
            case 1: return carta == 1 ? populacao1 : populacao2;
            case 2: return carta == 1 ? area1 : area2;
            case 3: return carta == 1 ? pib1 : pib2;
            case 4: return carta == 1 ? pontos1 : pontos2;
            case 5: return carta == 1 ? percapita1 : percapita2;
            case 6: return carta == 1 ? -densidade1 : -densidade2; // menor vence
            case 7: return carta == 1 ? super1 : super2;
            default: return 0;
        }
    }

    // Comparação principal
    float valor1_c1 = obter_valor(atributo1, 1);
    float valor1_c2 = obter_valor(atributo1, 2);

    const char* vencedora = (valor1_c1 > valor1_c2) ? nome1 :
                            (valor1_c2 > valor1_c1) ? nome2 :
                            (obter_valor(atributo2, 1) > obter_valor(atributo2, 2)) ? nome1 :
                            (obter_valor(atributo2, 2) > obter_valor(atributo2, 1)) ? nome2 :
                            NULL;

    // Resultado
    printf("\nResultado da comparação:\n");
    if (vencedora != NULL) {
        printf("Cidade vencedora: %s\n", vencedora);
        printf("Critério principal: atributo %d\n", atributo1);
        printf("Critério de desempate: atributo %d\n", atributo2);
    } else {
        printf("Empate total entre as duas cidades nos dois critérios.\n");
    }

    return 0;
}