#include <stdio.h>

// Função para exibir as cartas e seus valores
void exibirCarta(char *cidade, char estado, unsigned long int populacao, float area, float pib, int pontosTuristicos, float densidade, float pibPerCapita) {
    printf("%s (%c)\n", cidade, estado);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Pontos Turísticos: %d\n", pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade);
    printf("PIB per Capita: %.2f reais\n\n", pibPerCapita);
}

// Função para calcular a soma dos atributos de uma carta
float calcularSoma(float atributo1, float atributo2, float densidade1, float densidade2, int atributoTipo) {
    if (atributoTipo == 5) {
        return (densidade1 < densidade2) ? (atributo1 + atributo2) : (atributo1 + atributo2);
    } else {
        return atributo1 + atributo2;
    }
}

int main() {
    // Definição de variáveis para as duas cartas
    char estado1 = 'A', estado2 = 'B';
    char cidade1[] = "São Paulo", cidade2[] = "Rio de Janeiro";
    unsigned long int populacao1 = 12325000, populacao2 = 6748000;
    float area1 = 1521.11, area2 = 1200.25;
    float pib1 = 699.28, pib2 = 300.50;
    int pontosTuristicos1 = 50, pontosTuristicos2 = 30;

    // Cálculos de densidade e PIB per capita
    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;
    float pibPerCapita1 = pib1 * 1000000000 / populacao1;
    float pibPerCapita2 = pib2 * 1000000000 / populacao2;

    // Menu para escolher o primeiro atributo
    int atributo1, atributo2;

    // Exibindo o menu e as opções para o jogador
    printf("Escolha o primeiro atributo para comparar (1-6):\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Impedir que o jogador escolha o mesmo atributo duas vezes
    do {
        printf("Escolha o segundo atributo para comparar (1-6):\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Populacional\n");
        printf("6. PIB per Capita\n");
        printf("Opção: ");
        scanf("%d", &atributo2);
    } while (atributo1 == atributo2);

    // Exibindo as cartas
    printf("\nCarta 1 - %s\n", cidade1);
    exibirCarta(cidade1, estado1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1);
    
    printf("Carta 2 - %s\n", cidade2);
    exibirCarta(cidade2, estado2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2);

    // Comparando os dois atributos
    float valorCarta1 = 0, valorCarta2 = 0;
    
    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1: // População
            valorCarta1 = populacao1;
            valorCarta2 = populacao2;
            break;
        case 2: // Área
            valorCarta1 = area1;
            valorCarta2 = area2;
            break;
        case 3: // PIB
            valorCarta1 = pib1;
            valorCarta2 = pib2;
            break;
        case 4: // Pontos Turísticos
            valorCarta1 = pontosTuristicos1;
            valorCarta2 = pontosTuristicos2;
            break;
        case 5: // Densidade Populacional
            valorCarta1 = densidade1;
            valorCarta2 = densidade2;
            break;
        case 6: // PIB per Capita
            valorCarta1 = pibPerCapita1;
            valorCarta2 = pibPerCapita2;
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Comparação do segundo atributo
    float valorCarta1_2 = 0, valorCarta2_2 = 0;
    switch (atributo2) {
        case 1: // População
            valorCarta1_2 = populacao1;
            valorCarta2_2 = populacao2;
            break;
        case 2: // Área
            valorCarta1_2 = area1;
            valorCarta2_2 = area2;
            break;
        case 3: // PIB
            valorCarta1_2 = pib1;
            valorCarta2_2 = pib2;
            break;
        case 4: // Pontos Turísticos
            valorCarta1_2 = pontosTuristicos1;
            valorCarta2_2 = pontosTuristicos2;
            break;
        case 5: // Densidade Populacional
            valorCarta1_2 = densidade1;
            valorCarta2_2 = densidade2;
            break;
        case 6: // PIB per Capita
            valorCarta1_2 = pibPerCapita1;
            valorCarta2_2 = pibPerCapita2;
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Soma dos atributos
    float somaCarta1 = valorCarta1 + valorCarta1_2;
    float somaCarta2 = valorCarta2 + valorCarta2_2;

    // Determinar o vencedor
    printf("\nResultado da comparação:\n");
    if (somaCarta1 > somaCarta2) {
        printf("Carta 1 (");
        exibirCarta(cidade1, estado1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1);
        printf("Venceu!\n");
    } else if (somaCarta1 < somaCarta2) {
        printf("Carta 2 (");
        exibirCarta(cidade2, estado2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2);
        printf("Venceu!\n");
    } else {
        printf("Empate! Ambas as cartas têm a mesma soma de atributos.\n");
    }

    return 0;
}
