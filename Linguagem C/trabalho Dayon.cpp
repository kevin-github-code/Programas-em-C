#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define 
// Estrutura para armazenar os dados de um usuário
typedef struct {
    char username[50];
    char password[20];
    float balance;
} User;

// Lista de usuários cadastrados
User users[] = {
	{"alice", "1234", 1000.0},
    {"alice", "4321", 2000.0},
    {"bob", "5678", 1500.0},
    {"charlie", "abcd", 2000.0}
};

const int NUM_USERS = sizeof(users) / sizeof(users[0]);

// Função para autenticar o usuário
int authenticate(char *username, char *password) {
	int i;
    for (i = 0; i < NUM_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Retorna o índice do usuário autenticado
        }
    }
    return -1; // Retorna -1 se a autenticação falhar
}

// Função para exibir o menu de operações
void display_menu() {
    printf("\n=== Caixa Eletrônico ===\n");
    printf("1. Consultar Saldo\n");
    printf("2. Depositar\n");
    printf("3. Sacar\n");
    printf("4. Transferir\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

// Função principal
int main() {
    char username[50], password[20];
    int choice, user_index;
    float amount;

    printf("=== Bem-vindo ao Caixa Eletrônico ===\n");
    printf("Digite seu nome de usuário: ");
    scanf("%s", username);
    printf("Digite sua senha: ");
    scanf("%s", password);

    // Autenticação
    user_index = authenticate(username, password);
    if (user_index == -1) {
        printf("Autenticação falhou! Encerrando o programa.\n");
        return 1;
    }

    printf("Bem-vindo(a), %s!\n", users[user_index].username);

    // Loop para o menu de operações
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Seu saldo é: Mzn%.2f\n", users[user_index].balance);
                break;
            case 2:
                printf("Digite o valor para depositar: Mzn");
                scanf("%f", &amount);
                if (amount > 0) {
                    users[user_index].balance += amount;
                    printf("Depósito realizado com sucesso! Saldo atual: R$%.2f\n", users[user_index].balance);
                } else {
                    printf("Valor inválido para depósito.\n");
                }
                break;
            case 3:
                printf("Digite o valor para sacar: Mzn");
                scanf("%f", &amount);
                if (amount > 0 && amount <= users[user_index].balance) {
                    users[user_index].balance -= amount;
                    printf("Saque realizado com sucesso! Saldo atual: Mzn%.2f\n", users[user_index].balance);
                } else {
                    printf("Saldo insuficiente ou valor inválido.\n");
                }
                break;
            case 4: {
                char target_username[50];
                printf("Digite o nome do usuário para transferir: ");
                scanf("%s", target_username);
                printf("Digite o valor para transferir: Mzn");
                scanf("%f", &amount);

                if (amount > 0 && amount <= users[user_index].balance) {
                    int target_index = -1;
                    int i;
                    for (i = 0; i < NUM_USERS; i++) {
                        if (strcmp(users[i].username, target_username) == 0) {
                            target_index = i;
                            break;
                        }
                    }

                    if (target_index != -1) {
                        users[user_index].balance -= amount;
                        users[target_index].balance += amount;
                        printf("Transferência de Mzn%.2f para %s realizada com sucesso!\n", amount, target_username);
                        printf("Seu saldo atual: Mzn%.2f\n", users[user_index].balance);
                    } else {
                        printf("Usuário de destino não encontrado.\n");
                    }
                } else {
                    printf("Saldo insuficiente ou valor inválido.\n");
                }
                break;
            }
            case 5:
                printf("Saindo... Obrigado por usar o caixa eletrônico!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 5);

    return 0;
}
