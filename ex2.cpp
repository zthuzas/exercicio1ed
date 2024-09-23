#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10
#define TAMANHO_NOME 50
#define TAMANHO_CARGO 30

typedef struct {
    char nome[TAMANHO_NOME];
    char cargo[TAMANHO_CARGO];
    float salarioBase;
    float beneficios;
    float descontos;
} Funcionario;

typedef struct {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int totalFuncionarios;
} Loja;

float calcularSalarioLiquido(Funcionario func) {
    return func.salarioBase + func.beneficios - func.descontos;
}

void cadastrarFuncionarios(Loja *loja) {
    printf("Quantos funcion�rios deseja cadastrar (m�ximo %d)? ", MAX_FUNCIONARIOS);
    scanf("%d", &loja->totalFuncionarios);

    if (loja->totalFuncionarios > MAX_FUNCIONARIOS) {
        loja->totalFuncionarios = MAX_FUNCIONARIOS;
    }

    for (int i = 0; i < loja->totalFuncionarios; i++) {
        printf("\nCadastro do funcion�rio %d\n", i + 1);

        printf("Nome: ");
        getchar();
        fgets(loja->funcionarios[i].nome, TAMANHO_NOME, stdin);
        loja->funcionarios[i].nome[strcspn(loja->funcionarios[i].nome, "\n")] = '\0';

        printf("Cargo: ");
        fgets(loja->funcionarios[i].cargo, TAMANHO_CARGO, stdin);
        loja->funcionarios[i].cargo[strcspn(loja->funcionarios[i].cargo, "\n")] = '\0';

        printf("Sal�rio Base: ");
        scanf("%f", &loja->funcionarios[i].salarioBase);

        printf("Benef�cios: ");
        scanf("%f", &loja->funcionarios[i].beneficios);

        printf("Descontos: ");
        scanf("%f", &loja->funcionarios[i].descontos);
    }
}

void mostrarDadosFuncionarios(const Loja *loja) {
    printf("\nDados dos funcion�rios:\n");
    for (int i = 0; i < loja->totalFuncionarios; i++) {
        Funcionario f = loja->funcionarios[i];
        float salarioLiquido = calcularSalarioLiquido(f);

        printf("\nFuncion�rio %d\n", i + 1);
        printf("Nome: %s\n", f.nome);
        printf("Cargo: %s\n", f.cargo);
        printf("Sal�rio Base: %.2f\n", f.salarioBase);
        printf("Benef�cios: %.2f\n", f.beneficios);
        printf("Descontos: %.2f\n", f.descontos);
        printf("Sal�rio L�quido: %.2f\n", salarioLiquido);
    }
}

float calcularMediaSalarial(const Loja *loja) {
    float somaSalarios = 0.0;
    for (int i = 0; i < loja->totalFuncionarios; i++) {
        somaSalarios += calcularSalarioLiquido(loja->funcionarios[i]);
    }
    return loja->totalFuncionarios > 0 ? somaSalarios / loja->totalFuncionarios : 0.0;
}

Funcionario encontrarMaiorSalario(const Loja *loja) {
    Funcionario maiorSalario = loja->funcionarios[0];
    for (int i = 1; i < loja->totalFuncionarios; i++) {
        if (calcularSalarioLiquido(loja->funcionarios[i]) > calcularSalarioLiquido(maiorSalario)) {
            maiorSalario = loja->funcionarios[i];
        }
    }
    return maiorSalario;
}

int main() {
    Loja loja;
    loja.totalFuncionarios = 0;

    cadastrarFuncionarios(&loja);

    mostrarDadosFuncionarios(&loja);

    float mediaSalarial = calcularMediaSalarial(&loja);
    printf("\nM�dia Salarial: %.2f\n", mediaSalarial);

    Funcionario maiorSalario = encontrarMaiorSalario(&loja);
    printf("\nFuncion�rio com o maior sal�rio l�quido:\n");
    printf("Nome: %s\n", maiorSalario.nome);
    printf("Cargo: %s\n", maiorSalario.cargo);
    printf("Sal�rio L�quido: %.2f\n", calcularSalarioLiquido(maiorSalario));

    return 0;
}
