#include<stdio.h>

struct Data {
    int dia;
    int mes;
    int ano;

        void ler() {
        printf("Dia: ");
        scanf("%d", &dia);
        printf("Mês: ");
        scanf("%d", &mes);
        printf("Ano: ");
        scanf("%d", &ano);
    }

};


struct Cliente {
    char nome[100];
    Data dataNasc;
    int idade;
    char sexo;

    void ler (){
        printf("Nome: ");
        scanf("%s", nome);

        printf("Data de Nascimento: ");
        dataNasc.ler();

        printf("Sexo M/F: ");
        scanf("%c", &sexo);

        calcularIdade();
    }

    void calcularIdade() {
        idade = 2024 - dataNasc.ano;
    }


    void imprimir () {
        printf("Nome: %s\n", nome);
        printf("Idade: %d\n", idade);
        printf("Sexo: %c\n", sexo);
    }
};


struct Menu {
    Cliente clientes[50];
    int totalClientes = 0;

    void cadastrar() {
        int qtdClientes;

        printf("Quantidade de usuarios a cadastrarem: ");
        scanf("%d", &qtdClientes);

        for (int i = 0; i < qtdClientes; i++) {
            clientes[i].ler();
            totalClientes++;
        }
    }

    void imprimir() {
         for (int i = 0; i < totalClientes; i++) {
             clientes[i].imprimir();
         }
    }

};

int main () {

    Menu menu;
    menu.cadastrar();
    menu.imprimir();

    return 0;
}
