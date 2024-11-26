#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_LIVROS 100

// Estrutura para representar um livro
typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int disponivel;  // 1 para disponível, 0 para emprestado
} Livro;

// Funções básicas
void menu();
void livrosmenu();
void sair();

// Funções de gerenciamento de livros
void adicionarLivro(Livro livros[], int *totalLivros);
void removerLivro(Livro livros[], int *totalLivros);
void buscarLivro(Livro livros[], int totalLivros);
void registrarEmprestimo(Livro livros[], int totalLivros);
void registrarDevolucao(Livro livros[], int totalLivros);
void listarLivros(Livro livros[], int totalLivros);

// Funções de persistência
void salvarBiblioteca(Livro livros[], int totalLivros);
void carregarBiblioteca(Livro livros[], int *totalLivros);

#endif

