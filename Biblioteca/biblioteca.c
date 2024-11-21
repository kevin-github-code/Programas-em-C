#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void menu() {
    system("cls"); // Pode ser substituído por uma função para limpar a tela de forma portátil
    printf("================================================MENU========================================================\n");
    printf(" 1 - Requisitar um livro \n");
    printf(" 2 - Devolver um livro \n");
    printf(" 3 - Ver livros disponíveis \n");
    printf(" 4 - Sair do sistema \n");
    printf("=============================================================================================================\n");
}

void livrosmenu() {
    printf("==========================================LIVROS DISPONÍVEIS===============================================\n");
    printf("1 - Linguagem C por Prof. Carmem Hara e Prof. Wagner Zola\n");
    printf("2 - C# e Orientação a Objetos autor Caelum\n");
    printf("3 - Apostila de PHP autor Bruno Rodrigues Siqueira\n");
    printf("============================================================================================================\n");
}

void requisitar(int lista[3]) {
    int option;
    system("cls");
    printf("=======================================REQUISITANDO UM LIVRO================================================\n");
    livrosmenu();
    printf("Qual dos livros pretende requisitar (1-3): ");
    scanf("%d", &option);

    if (option < 1 || option > 3) {
        printf("Opção inválida!\n");
        return;
    }

    if (lista[option - 1] > 0) {
        lista[option - 1]--;
        printf("Livro requisitado com sucesso! Obrigado por usar o nosso sistema!\n");
    } else {
        printf("Este livro não está disponível no momento.\n");
    }
}

void devolver(int lista[3]) {
    int option;
    system("cls");
    printf("=========================================DEVOLVER UM LIVRO=================================================\n");
    livrosmenu();
    printf("Qual dos livros pretende devolver (1-3): ");
    scanf("%d", &option);

    if (option < 1 || option > 3) {
        printf("Opção inválida!\n");
        return;
    }

    lista[option - 1]++;
    printf("Livro devolvido com sucesso! Obrigado por usar o nosso sistema!\n");
}

void ver(int lista[3]) {
    system("cls");
    printf("========================================LIVROS DISPONÍVEIS================================================\n");
    printf("1 - Linguagem C: %d unidades disponíveis\n", lista[0]);
    printf("2 - C#: %d unidades disponíveis\n", lista[1]);
    printf("3 - PHP: %d unidades disponíveis\n", lista[2]);
    printf("============================================================================================================\n");
}

void sair() {
    system("cls");
    printf("Saindo do sistema... Até a próxima!\n");
}

