#include <stdio.h>

struct Livro {
    char titulo[100];
    char autor[100];
    int numeroPaginas;

    void ler() {
        printf("Qual o nome do livro?");
        scanf("%[^\n]%*c", titulo);
        printf("Qual o nome do autor do livro?");
        scanf("%[^\n]%*c", autor);
        printf("Qual oo número de páginas do livro");
        scanf("%d%*c", &numeroPaginas);
    }

    void imprimir () {
        printf("Titulo: %s", titulo);
        printf("Autor: %s", autor);
        printf("Numero Paginas %d", numeroPaginas);
    }
};

struct Biblioteca {

    Livro livros[10];
    int totalLivros = 0;

    void cadastrar() {
        if (totalLivros == 10) {
            printf("Máximo de 10 livros.");
        }

        livros[totalLivros].ler();
        totalLivros++;
    }

    void imprimirLivros() {
        for (int i = 0; i < 10; i++) {
            livros[i].imprimir();
        }
    }

    void imprimirMaiorLivro () {
        Livro maiorLivro = livros[0];

        for (int i = 1; i < totalLivros; i++) {
            if (livros[i].numeroPaginas > maiorLivro.numeroPaginas) {
                maiorLivro = livros[i];
            }
        }

        maiorLivro.imprimir();
    }
};


int main() {
    Biblioteca biblioteca;

    biblioteca.cadastrar();
    biblioteca.cadastrar();

    biblioteca.imprimirLivros();

    biblioteca.imprimirMaiorLivro();

return 0;
}
