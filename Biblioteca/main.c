#include <stdio.h>
#include "biblioteca.h"
#include <locale.h>

int main() {
    int opcao, executar;
    int quant[3] = {100, 100, 100};

    printf("BEM-VINDO AO SISTEMA DE GERENCIAMENTO DE BIBLIOTECA\n\n");

    do {
        menu();
        printf("Escolha uma das opções acima: ");
        scanf("%d", &opcao);

        while (opcao < 1 || opcao > 4) {
            printf("Opção inválida! Digite novamente: ");
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

        printf("Pretende executar outra ação? (1-Sim ou 2-Não): ");
        scanf("%d", &executar);

    } while (executar == 1);

    return 0;
}

