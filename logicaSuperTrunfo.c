#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

// Função para cadastrar uma carta
struct Carta cadastrarCarta() {
    struct Carta c;

    printf("\nCadastro de Carta:\n");

    printf("Estado: ");
    scanf(" %[^\n]", c.estado);

    printf("Código da Carta: ");
    scanf(" %[^\n]", c.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c.nome);

    printf("População: ");
    scanf("%d", &c.populacao);

    printf("Área (em km²): ");
    scanf("%f", &c.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &c.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c.pontos_turisticos);

    if (c.area != 0)
        c.densidade = c.populacao / c.area;
    else
        c.densidade = 0;

    return c;
}

// Função para exibir uma carta
void exibirCarta(struct Carta c) {
    printf("\n🗺️  Cidade: %s (%s) - Código: %s\n", c.nome, c.estado, c.codigo);
    printf("👥 População: %d hab\n", c.populacao);
    printf("📐 Área: %.2f km²\n", c.area);
    printf("💰 PIB: R$ %.2f bilhões\n", c.pib);
    printf("🎯 Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("📊 Densidade populacional: %.2f hab/km²\n", c.densidade);
}

// Função para comparar dois atributos
void compararCartas(struct Carta c1, struct Carta c2, char atributo[]) {
    printf("\n🔍 Comparando pelo atributo: %s\n", atributo);
    
    if (strcmp(atributo, "populacao") == 0) {
        if (c1.populacao > c2.populacao)
            exibirCarta(c1);
        else if (c2.populacao > c1.populacao)
            exibirCarta(c2);
        else
            printf("\n⚖️ Empate na populacao!\n");
    } else if (strcmp(atributo, "area") == 0) {
        if (c1.area > c2.area)
            exibirCarta(c1);
        else if (c2.area > c1.area)
            exibirCarta(c2);
        else
            printf("\n⚖️ Empate na area!\n");
    } else if (strcmp(atributo, "pib") == 0) {
        if (c1.pib > c2.pib)
            exibirCarta(c1);
        else if (c2.pib > c1.pib)
            exibirCarta(c2);
        else
            printf("\n⚖️ Empate no PIB!\n");
    } else if (strcmp(atributo, "pontos_turisticos") == 0) {
        if (c1.pontos_turisticos > c2.pontos_turisticos)
            exibirCarta(c1);
        else if (c2.pontos_turisticos > c1.pontos_turisticos)
            exibirCarta(c2);
        else
            printf("\n⚖️ Empate nos pontos turísticos!\n");
    } else if (strcmp(atributo, "densidade") == 0) {
        if (c1.densidade < c2.densidade)
            exibirCarta(c1);
        else if (c2.densidade < c1.densidade)
            exibirCarta(c2);
        else
            printf("\n⚖️ Empate na densidade!\n");
    } else {
        printf("\n❌ Atributo inválido.\n");
    }
}

int main() {
    struct Carta carta1, carta2;
    char atributo[30];

    printf("🎮 SUPER TRUNFO - CIDADES\n");

    // Cadastro das cartas
    printf("\n--- Carta 1 ---");
    carta1 = cadastrarCarta();

    printf("\n--- Carta 2 ---");
    carta2 = cadastrarCarta();

    // Exibir cartas
    printf("\n--- Exibindo Cartas ---");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Comparação
    printf("\nAtributos disponíveis para comparação: populacao, area, pib, pontos_turisticos, densidade\n");
    printf("Digite o atributo que deseja comparar: ");
    scanf(" %[^\n]", atributo);

    compararCartas(carta1, carta2, atributo);

    return 0;
}
