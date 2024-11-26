#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100
#define ARQUIVO_BIBLIOTECA "biblioteca.dat"

// Definição de estrutura para o livro
typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int disponivel;  // 1 para disponível, 0 para emprestado
} Livro;

// Funções auxiliares
void adicionarLivro(Livro livros[], int *totalLivros);
void removerLivro(Livro livros[], int *totalLivros);
void buscarLivro(Livro livros[], int totalLivros);
void registrarEmprestimo(Livro livros[], int totalLivros);
void registrarDevolucao(Livro livros[], int totalLivros);
void salvarBiblioteca(Livro livros[], int totalLivros);
void carregarBiblioteca(Livro livros[], int *totalLivros);
void listarLivros(Livro livros[], int totalLivros);

int main() {
    Livro livros[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // Carregar os livros do arquivo
    carregarBiblioteca(livros, &totalLivros);

    do {
        printf("\nSistema de Gerenciamento de Biblioteca\n");
        printf("1. Adicionar Livro\n");
        printf("2. Remover Livro\n");
        printf("3. Buscar Livro\n");
        printf("4. Registrar Emprestimo\n");
        printf("5. Registrar Devolucao\n");
        printf("6. Listar Livros\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(livros, &totalLivros);
                system("pause");
                system("cls");
                break;
            case 2:
                removerLivro(livros, &totalLivros);
                system("pause");
                system("cls");
                break;
            case 3:
                buscarLivro(livros, totalLivros);
                system("pause");
                system("cls");
                break;
            case 4:
                registrarEmprestimo(livros, totalLivros);
                system("pause");
                system("cls");
                break;
            case 5:
                registrarDevolucao(livros, totalLivros);
                system("pause");
                system("cls");
                break;
            case 6:
                listarLivros(livros, totalLivros);
                system("pause");
                system("cls");
                break;
            case 7:
                salvarBiblioteca(livros, totalLivros);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 7);

    return 0;
}

void adicionarLivro(Livro livros[], int *totalLivros) {
    if (*totalLivros >= MAX_LIVROS) {
        printf("Nao ha espaco para adicionar mais livros.\n");
        return;
    }

    Livro novoLivro;
    novoLivro.id = *totalLivros + 1;  // ID unico
    printf("Digite o titulo do livro: ");
    getchar(); // Limpar o buffer do teclado
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = '\0';  // Remover o \n

    printf("Digite o autor do livro: ");
    fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '\0';  // Remover o \n

    novoLivro.disponivel = 1; // Livro adicionado está disponível
    livros[*totalLivros] = novoLivro;
    (*totalLivros)++;

    printf("Livro adicionado com sucesso!\n");
}

void removerLivro(Livro livros[], int *totalLivros) {
    int id, i, encontrado = 0;
    printf("Digite o ID do livro a ser removido: ");
    scanf("%d", &id);

    for (i = 0; i < *totalLivros; i++) {
        if (livros[i].id == id) {
            encontrado = 1;
            int j;
            for (j = i; j < *totalLivros - 1; j++) {
                livros[j] = livros[j + 1];
            }
            (*totalLivros)--;
            printf("Livro removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Livro nao encontrado.\n");
    }
}

void buscarLivro(Livro livros[], int totalLivros) {
    char titulo[100];
    printf("Digite o titulo do livro a ser buscado: ");
    getchar();  // Limpar o buffer
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';  // Remover o \n

    int encontrado = 0;
    int i;
    for (i = 0; i < totalLivros; i++) {
        if (strstr(livros[i].titulo, titulo) != NULL) {
            printf("Livro encontrado: ID: %d, Titulo: %s, Autor: %s, %s\n",
                livros[i].id, livros[i].titulo, livros[i].autor,
                livros[i].disponivel ? "Disponível" : "Emprestado");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum livro encontrado com esse titulo.\n");
    }
}

void registrarEmprestimo(Livro livros[], int totalLivros) {
    int id, i;
    printf("Digite o ID do livro a ser emprestado: ");
    scanf("%d", &id);

    for (i = 0; i < totalLivros; i++) {
        if (livros[i].id == id) {
            if (livros[i].disponivel == 1) {
                livros[i].disponivel = 0;
                printf("Emprestimo realizado com sucesso!\n");
            } else {
                printf("Este livro ja esta emprestado.\n");
            }
            return;
        }
    }

    printf("Livro nao encontrado.\n");
}

void registrarDevolucao(Livro livros[], int totalLivros) {
    int id, i;
    printf("Digite o ID do livro a ser devolvido: ");
    scanf("%d", &id);

    for (i = 0; i < totalLivros; i++) {
        if (livros[i].id == id) {
            if (livros[i].disponivel == 0) {
                livros[i].disponivel = 1;
                printf("Devolucao realizada com sucesso!\n");
            } else {
                printf("Este livro nao foi emprestado.\n");
            }
            return;
        }
    }

    printf("Livro nao encontrado.\n");
}

void listarLivros(Livro livros[], int totalLivros) {
    if (totalLivros == 0) {
        printf("Nao ha livros cadastrados.\n");
    } else {
        printf("\nLista de Livros:\n");
        int i;
        for (i = 0; i < totalLivros; i++) {
            printf("ID: %d, Titulo: %s, Autor: %s, %s\n", livros[i].id, livros[i].titulo,
                   livros[i].autor, livros[i].disponivel ? "Disponível" : "Emprestado");
        }
    }
}

void salvarBiblioteca(Livro livros[], int totalLivros) {
    FILE *arquivo = fopen(ARQUIVO_BIBLIOTECA, "wb");
    if (arquivo == NULL) {
        printf("Erro ao salvar os dados.\n");
        return;
    }
    fwrite(livros, sizeof(Livro), totalLivros, arquivo);
    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

void carregarBiblioteca(Livro livros[], int *totalLivros) {
    FILE *arquivo = fopen(ARQUIVO_BIBLIOTECA, "rb");
    if (arquivo != NULL) {
        *totalLivros = fread(livros, sizeof(Livro), MAX_LIVROS, arquivo);
        fclose(arquivo);
    }
}
