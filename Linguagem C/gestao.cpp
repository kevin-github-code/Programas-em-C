#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Necessário para usar strcpy

#define MAX_ALUNOS 50
#define MAX_DISCIPLINAS 10
#define MAX_NOME 100

// Função para calcular a média das notas do aluno
float calcularMedia(float notas[], int numDisciplinas) {
    float soma = 0.0;
    for (int i = 0; i < numDisciplinas; i++) {
        soma += notas[i];
    }
    return soma / numDisciplinas;
}

// Função para determinar o status do aluno baseado na média
void determinarStatus(float media, char status[]) {
    if (media >= 10.0) {
        strcpy(status, "Aprovado");  // Copia "Aprovado" para o status
    } else {
        strcpy(status, "Reprovado");  // Copia "Reprovado" para o status
    }
}

// Função para cadastrar um aluno
void cadastrarAluno(char alunos[][MAX_NOME], float notas[MAX_ALUNOS][MAX_DISCIPLINAS], int *numAlunos, char status[MAX_ALUNOS][10], int *numDisciplinasPorAluno) {
    if (*numAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido.\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    getchar();  // Limpar o buffer do teclado
    fgets(alunos[*numAlunos], MAX_NOME, stdin);
    alunos[*numAlunos][strcspn(alunos[*numAlunos], "\n")] = 0;  // Remove o '\n' do nome

    printf("Quantas disciplinas o aluno tem? ");
    scanf("%d", &numDisciplinasPorAluno[*numAlunos]);

    if (numDisciplinasPorAluno[*numAlunos] > MAX_DISCIPLINAS) {
        numDisciplinasPorAluno[*numAlunos] = MAX_DISCIPLINAS;
        printf("Número de disciplinas ajustado para %d.\n", MAX_DISCIPLINAS);
    }

    // Entrada das notas
    for (int i = 0; i < numDisciplinasPorAluno[*numAlunos]; i++) {
        printf("Digite a nota da disciplina %d: ", i + 1);
        scanf("%f", &notas[*numAlunos][i]);
    }

    // Calculando média e status
    float media = calcularMedia(notas[*numAlunos], numDisciplinasPorAluno[*numAlunos]);
    determinarStatus(media, status[*numAlunos]);

    (*numAlunos)++;
}

// Função para exibir os alunos cadastrados
void exibirAlunos(char alunos[][MAX_NOME], float notas[MAX_ALUNOS][MAX_DISCIPLINAS], int numAlunos, char status[MAX_ALUNOS][10], int numDisciplinasPorAluno[MAX_ALUNOS]) {
    if (numAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    for (int i = 0; i < numAlunos; i++) {
        printf("\nNome do aluno: %s\n", alunos[i]);
        printf("Notas: ");
        for (int j = 0; j < numDisciplinasPorAluno[i]; j++) {
            printf("%.2f ", notas[i][j]);
        }
        printf("\nMédia final: %.2f\n", calcularMedia(notas[i], numDisciplinasPorAluno[i]));
        printf("Status: %s\n", status[i]);
    }
}

int main() {
    char alunos[MAX_ALUNOS][MAX_NOME]; // Array para armazenar os nomes dos alunos
    float notas[MAX_ALUNOS][MAX_DISCIPLINAS]; // Array para armazenar as notas dos alunos
    char status[MAX_ALUNOS][10]; // Array para armazenar o status dos alunos ("Aprovado" ou "Reprovado")
    int numAlunos = 0;
    int numDisciplinasPorAluno[MAX_ALUNOS]; // Array para armazenar o número de disciplinas de cada aluno
    int opcao;

    printf("Sistema de Gestão de Notas\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Exibir alunos cadastrados\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno(alunos, notas, &numAlunos, status, numDisciplinasPorAluno);
                system("cls");
                break;
            case 2:
                exibirAlunos(alunos, notas, numAlunos, status, numDisciplinasPorAluno);
                system("pause");
				system("cls");
                break;
            case 3:
                printf("Saindo do sistema...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

