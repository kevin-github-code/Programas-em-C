#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao, executar;
    int quant[3] = {100, 100, 100};

    printf("BEM-VINDO AO SISTEMA DE GERENCIAMENTO DE BIBLIOTECA\n\n");

    do {
        menu();
        printf("Escolha uma das op��es acima: ");
        scanf("%d", &opcao);

        while (opcao < 1 || opcao > 4) {
            printf("Op��o inv�lida! Digite novamente: ");
            scanf("%d", &opcao);
        }

        switch (opcao) {
            case 1:
                requisitar(quant);
                break;
            case 2:
                devolver(quant);
                break;
            case 3:
                ver(quant);
                break;
            case 4:
                sair();
                return 0;
        }

        printf("Pretende executar outra a��o? (1-Sim ou 2-N�o): ");
        scanf("%d", &executar);

    } while (executar == 1);

    return 0;
}


void menu() {
	system("pause");
	system("cls");
    // Pode ser substitu�do por uma fun��o para limpar a tela de forma port�til
    printf("================================================MENU========================================================\n");
    printf(" 1 - Requisitar um livro \n");
    printf(" 2 - Devolver um livro \n");
    printf(" 3 - Ver livros dispon�veis \n");
    printf(" 4 - Sair do sistema \n");
    printf("=============================================================================================================\n");
}

void livrosmenu() {
    printf("==========================================LIVROS DISPON�VEIS===============================================\n");
    printf("1 - Linguagem C por Prof. Carmem Hara e Prof. Wagner Zola\n");
    printf("2 - C# e Orienta��o a Objetos autor Caelum\n");
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
        printf("Op��o inv�lida!\n");
        return;
    }

    if (lista[option - 1] > 0) {
        lista[option - 1]--;
        printf("Livro requisitado com sucesso! Obrigado por usar o nosso sistema!\n");
    } else {
        printf("Este livro n�o est� dispon�vel no momento.\n");
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
        printf("Op��o inv�lida!\n");
        return;
    }

    lista[option - 1]++;
    printf("Livro devolvido com sucesso! Obrigado por usar o nosso sistema!\n");
}

void ver(int lista[3]) {
    system("cls");
    printf("========================================LIVROS DISPON�VEIS================================================\n");
    printf("1 - Linguagem C: %d unidades dispon�veis\n", lista[0]);
    printf("2 - C#: %d unidades dispon�veis\n", lista[1]);
    printf("3 - PHP: %d unidades dispon�veis\n", lista[2]);
    printf("============================================================================================================\n");
}

void sair() {
    system("cls");
    printf("Saindo do sistema... At� a pr�xima!\n");
}

