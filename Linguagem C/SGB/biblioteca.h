#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_LIVROS 100

// Estrutura para representar um livro
typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int disponivel;  // 1 para dispon�vel, 0 para emprestado
} Livro;

// Fun��es b�sicas
void menu();
void livrosmenu();
void sair();

// Fun��es de gerenciamento de livros
void adicionarLivro(Livro livros[], int *totalLivros);
void removerLivro(Livro livros[], int *totalLivros);
void buscarLivro(Livro livros[], int totalLivros);
void registrarEmprestimo(Livro livros[], int totalLivros);
void registrarDevolucao(Livro livros[], int totalLivros);
void listarLivros(Livro livros[], int totalLivros);

// Fun��es de persist�ncia
void salvarBiblioteca(Livro livros[], int totalLivros);
void carregarBiblioteca(Livro livros[], int *totalLivros);

#endif

