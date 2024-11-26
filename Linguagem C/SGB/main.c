#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main() {
    Livro livros[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

//    carregarBiblioteca(livros, &totalLivros);

    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(livros, &totalLivros);
                break;
//            case 2:
//                removerLivro(livros, &totalLivros);
//                break;
//            case 3:
//                buscarLivro(livros, totalLivros);
//                break;
//            case 4:
//                registrarEmprestimo(livros, totalLivros);
//                break;
//            case 5:
//                registrarDevolucao(livros, totalLivros);
//                break;
//            case 6:
//                listarLivros(livros, totalLivros);
//                break;
//            case 7:
//                salvarBiblioteca(livros, totalLivros);
//                sair();
//                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    return 0;
}

