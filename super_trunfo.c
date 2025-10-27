#include <stdio.h>

int main() {
    // Declaração das variáveis para duas cartas
    char estado1 = 'R', estado2 = 'S';
    char codigo1[3] = "01", codigo2[3] = "02";
    char cidade1[50] = "CidadeA", cidade2[50] = "CidadeB";
    unsigned long int populacao1 = 1000000, populacao2 = 800000;
    float area1 = 500.0, area2 = 400.0;
    float pib1 = 2000000, pib2 = 1800000;
    int pontos_turisticos1 = 10, pontos_turisticos2 = 8;
    float densidade1, densidade2, percapita1, percapita2;

    // Calculando atributos derivados
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    percapita1 = pib1 / populacao1;
    percapita2 = pib2 / populacao2;

    // Menu para escolher os dois atributos
    int attr1 = 0, attr2 = 0;
    printf("Escolha dois atributos para comparar entre as cartas:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");

    // Escolha do primeiro atributo
    do {
        printf("Digite o número do primeiro atributo: ");
        scanf("%d", &attr1);
        if(attr1 < 1 || attr1 > 6) printf("Opção inválida! Tente novamente.\n");
    } while(attr1 < 1 || attr1 > 6);

    // Escolha do segundo atributo (diferente do primeiro)
    do {
        printf("Digite o número do segundo atributo (diferente do primeiro): ");
        scanf("%d", &attr2);
        if(attr2 < 1 || attr2 > 6 || attr2 == attr1) printf("Opção inválida! Tente novamente.\n");
    } while(attr2 < 1 || attr2 > 6 || attr2 == attr1);

    // Função para comparar atributos (retorna 1 se Carta1 vence, 0 se Carta2 vence)
    int compara(int atributo) {
        switch(atributo) {
            case 1: return (populacao1 > populacao2 ? 1 : 0);
            case 2: return (area1 > area2 ? 1 : 0);
            case 3: return (pib1 > pib2 ? 1 : 0);
            case 4: return (pontos_turisticos1 > pontos_turisticos2 ? 1 : 0);
            case 5: return (densidade1 < densidade2 ? 1 : 0); // menor vence
            case 6: return (percapita1 > percapita2 ? 1 : 0);
            default: return -1;
        }
    }

    // Função para obter o valor do atributo (para soma)
    float valor(int atributo) {
        switch(atributo) {
            case 1: return populacao1; // Carta1, para soma usamos carta1 e carta2 separadamente
            case 2: return area1;
            case 3: return pib1;
            case 4: return pontos_turisticos1;
            case 5: return 1.0 / densidade1; // inverso da densidade para poder
            case 6: return percapita1;
            default: return 0;
        }
    }

    // Comparando os atributos
    int resultado1 = compara(attr1);
    int resultado2 = compara(attr2);

    // Soma dos valores dos atributos selecionados para cada carta
    float soma1, soma2;
    float val1_attr1, val1_attr2, val2_attr1, val2_attr2;

    // Valores do primeiro atributo
    switch(attr1){
        case 1: val1_attr1 = populacao1; val2_attr1 = populacao2; break;
        case 2: val1_attr1 = area1; val2_attr1 = area2; break;
        case 3: val1_attr1 = pib1; val2_attr1 = pib2; break;
        case 4: val1_attr1 = pontos_turisticos1; val2_attr1 = pontos_turisticos2; break;
        case 5: val1_attr1 = 1.0 / densidade1; val2_attr1 = 1.0 / densidade2; break;
        case 6: val1_attr1 = percapita1; val2_attr1 = percapita2; break;
    }

    // Valores do segundo atributo
    switch(attr2){
        case 1: val1_attr2 = populacao1; val2_attr2 = populacao2; break;
        case 2: val1_attr2 = area1; val2_attr2 = area2; break;
        case 3: val1_attr2 = pib1; val2_attr2 = pib2; break;
        case 4: val1_attr2 = pontos_turisticos1; val2_attr2 = pontos_turisticos2; break;
        case 5: val1_attr2 = 1.0 / densidade1; val2_attr2 = 1.0 / densidade2; break;
        case 6: val1_attr2 = percapita1; val2_attr2 = percapita2; break;
    }

    soma1 = val1_attr1 + val1_attr2;
    soma2 = val2_attr1 + val2_attr2;

    // Exibindo resultados
    printf("\nComparação das cartas selecionadas:\n");
    printf("Atributo 1: %d - Carta %d venceu (%d)\n", attr1, resultado1 ? 1 : 2, resultado1);
    printf("Atributo 2: %d - Carta %d venceu (%d)\n", attr2, resultado2 ? 1 : 2, resultado2);
    printf("Soma dos atributos:\nCarta 1: %.2f\nCarta 2: %.2f\n", soma1, soma2);
    if(soma1 > soma2) printf("Vencedor da rodada: Carta 1\n");
    else if(soma2 > soma1) printf("Vencedor da rodada: Carta 2\n");
    else printf("Empate!\n");

    return 0;
}
