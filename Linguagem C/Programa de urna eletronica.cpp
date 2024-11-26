#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEITORES 100
#define MAX_CANDIDATOS 10

// Estrutura para armazenar informa��es dos candidatos
typedef struct {
    char nome[50];
    int votos;
} Candidato;

// Estrutura para armazenar eleitores que j� votaram
typedef struct {
    int codigo;
    int jaVotou;
} Eleitor;

//////////////////////////////////////////////////////////////////////////////////
// M�dulo 1: Fun��es Utilit�rias
//////////////////////////////////////////////////////////////////////////////////

// Fun��o para limpar a tela (independente do sistema operacional)
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fun��o para exibir a mensagem inicial com efeito visual de asteriscos
void mensagemInicial() {
    printf("***************Seja bem-vindo ao Sistema de Urna Eletronica!****************\n");
    printf("     ***************Para iniciar, pressione ENTER...********************\n");
    getchar(); // Espera pressionar ENTER
    limparTela(); // Limpa a tela ap�s pressionar ENTER
}

///////////////////////////////////////////////////////////////////////////////////////////////
// M�dulo 2: Inicializa��o dos Candidatos e Eleitores
/////////////////////////////////////////////////////////////////////////////////////////////

// Fun��o para inicializar os candidatos, recebendo seus nomes e atribuindo votos como 0
void inicializarCandidatos(Candidato candidatos[], int qtdCandidatos) {
    for (int i = 0; i < qtdCandidatos; i++) {
        printf("Digite o nome do candidato %d: ", i + 1);
        scanf(" %[^\n]", candidatos[i].nome); // Leitura do nome com espa�o
        candidatos[i].votos = 0; // Inicializa votos como 0
    }
}

// Fun��o para encontrar um eleitor pelo c�digo
// Retorna o �ndice do eleitor ou -1 se n�o encontrado
int encontrarEleitor(Eleitor eleitores[], int qtdEleitores, int codigo) {
    for (int i = 0; i < qtdEleitores; i++) {
        if (eleitores[i].codigo == codigo) {
            return i; // Eleitor encontrado
        }
    }
    return -1; // Eleitor n�o encontrado
}

//////////////////////////////////////////////////////////////////////////////////////////////
// M�dulo 3: Vota��o e Felicita��es
////////////////////////////////////////////////////////////////////////////////////////////

// Fun��o para felicitar o vencedor ou informar empate
// Realiza o c�lculo e exibe a mensagem apropriada
void felicitarAutomaticamente(Candidato candidatos[], int qtdCandidatos, int *felicitou) {
    if (*felicitou) {
        return; // Evita felicita��es m�ltiplas
    }

    int maxVotos = -1;
    char vencedor[50];
    int empate = 0;

    // Verifica o vencedor ou empate
    for (int i = 0; i < qtdCandidatos; i++) {
        if (candidatos[i].votos > maxVotos) {
            maxVotos = candidatos[i].votos;
            strcpy(vencedor, candidatos[i].nome);
            empate = 0; // N�o h� empate
        } else if (candidatos[i].votos == maxVotos) {
            empate = 1; // Houve empate
        }
    }

    if (empate) {
        printf("\nA votacao terminou empatada entre os seguintes candidatos com %d votos:\n", maxVotos);
        for (int i = 0; i < qtdCandidatos; i++) {
            if (candidatos[i].votos == maxVotos) {
                printf("- %s\n", candidatos[i].nome);
            }
        }
    } else {
        printf("\nParabens, o novo PR e sua excelencia: %s!\n", vencedor);
    }

    *felicitou = 1; // Marca que a felicita��o foi feita
    printf("\nPressione ENTER para REINICIAR...");
    getchar(); // Consumir o newline
    getchar(); // Esperar ENTER
    limparTela(); // Limpar tela antes do rein�cio
}

// Fun��o para realizar a vota��o de um eleitor
// Registra o voto e atualiza o status do eleitor
void votar(Candidato candidatos[], int qtdCandidatos, Eleitor eleitores[], int *qtdEleitores, int *totalVotos, int maxVotos, int *felicitou) {
    if (*totalVotos >= maxVotos) {
        felicitarAutomaticamente(candidatos, qtdCandidatos, felicitou);
        return; // N�o permite mais votos
    }

    int codigoEleitor;
    printf("Digite o seu c�digo de eleitor: ");
    scanf("%d", &codigoEleitor);

    int indiceEleitor = encontrarEleitor(eleitores, *qtdEleitores, codigoEleitor);
    if (indiceEleitor == -1) {
        // Eleitor novo, registra no sistema
        eleitores[*qtdEleitores].codigo = codigoEleitor;
        eleitores[*qtdEleitores].jaVotou = 0;
        indiceEleitor = (*qtdEleitores)++;
    }

    // Verifica se o eleitor j� votou
    if (eleitores[indiceEleitor].jaVotou) {
        printf("Voce ja votou! Nao pode votar novamente.\n");
        return;
    }

    // Exibe os candidatos dispon�veis
    printf("Escolha um candidato para votar:\n");
    for (int i = 0; i < qtdCandidatos; i++) {
        printf("%d - %s\n", i + 1, candidatos[i].nome);
    }

    int opcao;
    printf("Digite o numero do candidato: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > qtdCandidatos) {
        printf("Opcao invalida!\n");
    } else {
        candidatos[opcao - 1].votos++; // Registra o voto no candidato escolhido
        eleitores[indiceEleitor].jaVotou = 1; // Marca que o eleitor votou
        (*totalVotos)++; // Incrementa o total de votos
        printf("Voto registrado com sucesso!\n");
    }

    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
    limparTela(); // Limpa a tela ap�s o voto
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// M�dulo 4: Rein�cio do Sistema
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Fun��o para reiniciar o sistema de vota��o
// Reconfigura os dados de eleitores, votos e candidatos
void reiniciarPrograma(int *qtdCandidatos, int *qtdEleitores, int *totalVotos, int *felicitou, Eleitor eleitores[], Candidato candidatos[]) {
    *qtdEleitores = 0;
    *totalVotos = 0;
    *felicitou = 0;

    printf("Digite o numero de candidatos: ");
    scanf("%d", qtdCandidatos);

    if (*qtdCandidatos > MAX_CANDIDATOS || *qtdCandidatos <= 0) {
        printf("Numero invalido de candidatos. O maximo e %d.\n", MAX_CANDIDATOS);
        exit(1); // Finaliza o programa caso o n�mero de candidatos seja inv�lido
    }

    inicializarCandidatos(candidatos, *qtdCandidatos);
    limparTela(); // Limpa a tela ap�s reiniciar
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// M�dulo 5: Fun��o Principal (Main)
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    int qtdCandidatos, maxVotos;
    Candidato candidatos[MAX_CANDIDATOS];
    Eleitor eleitores[MAX_ELEITORES];
    int qtdEleitores = 0, totalVotos = 0, felicitou = 0;

    // Exibe a mensagem inicial com efeito e aguarda pressionar ENTER
    mensagemInicial();

    // Inicializa o sistema de vota��o
    reiniciarPrograma(&qtdCandidatos, &qtdEleitores, &totalVotos, &felicitou, eleitores, candidatos);

    printf("Digite o numero de eleitores: ");
    scanf("%d", &maxVotos);

    if (maxVotos > MAX_ELEITORES || maxVotos <= 0) {
        printf("Numero invalido de eleitores. O maximo e %d.\n", MAX_ELEITORES);
        return 1;
    }

    limparTela();

    // Loop principal de intera��o com o usu�rio
    while (1) {
        printf("\nMenu:\n");
        printf("1 - Votar\n");
        printf("2 - Reiniciar\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                votar(candidatos, qtdCandidatos, eleitores, &qtdEleitores, &totalVotos, maxVotos, &felicitou);
                break;
            case 2:
                reiniciarPrograma(&qtdCandidatos, &qtdEleitores, &totalVotos, &felicitou, eleitores, candidatos);
                break;
            case 3:
                printf("Encerrando o sistema de votacao.\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}


