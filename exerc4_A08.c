#include <stdio.h>
#define alunos 5
#define disciplinas 4

// Função para exibir menu e obter a opção
int exibirMenu() {
    int opcao;
    printf("\n=== SISTEMA DE GESTÃO DE NOTAS ===\n");
    printf("1. Inserir notas\n");
    printf("2. Exibir notas\n");
    printf("3. Calcular médias por aluno\n");
    printf("4. Calcular médias por disciplina\n");
    printf("5. Exibir aprovados/reprovados\n");
    printf("0. Sair\nOpção: ");
    scanf("%d", &opcao);
    return opcao;
}


// Inserir notas (referência)
void inserirNotas(float notas[][disciplinas]) {
    int i, j;
    for (i = 0; i < alunos; i++) {
        printf("\nAluno %d:\n", i+1);
        for (j = 0; j < disciplinas; j++) {
            printf("  Nota disciplina %d: ", j+1);
            scanf("%f", &notas[i][j]);
        }
    }
}

// Exibir notas (valor)
void exibirNotas(const float notas[][disciplinas]) {
    int i, j;
    printf("\n=== NOTAS ===\n");
    for (i = 0; i < alunos; i++) {
        printf("Aluno %d: ", i+1);
        for (j = 0; j < disciplinas; j++) {
            printf(" %.1f ", notas[i][j]);
        }
        printf("\n");
    }
}

// Média por aluno
float calcularMediaAluno(const float notas[][disciplinas], int aluno) {
    int j;
    float soma = 0;
    for (j = 0; j < disciplinas; j++) soma += notas[aluno][j];
    return soma / disciplinas;
}

// Média por disciplina
float calcularMediaDisciplina(const float notas[][disciplinas], int disciplina) {
    int i;
    float soma = 0;
    for (i = 0; i < alunos; i++) soma += notas[i][disciplina];
    return soma / alunos;
}

// Relatório final
void exibirrelfinal(const float notas[][disciplinas]) {
    int i;
    printf("\n=== RELATÓRIO FINAL ===\n");
    for (i = 0; i < alunos; i++) {
        float media = calcularMediaAluno(notas, i);
        printf("Aluno %d - Média: %.2f - %s\n", i+1, media, media >= 6.0 ? "Aprovado" : "Reprovado");
    }
}

int main() {
    float notas[alunos][disciplinas];
    int opcao;

    do {
        opcao = exibirMenu();

        switch(opcao) {
            case 1: inserirNotas(notas); break;
            case 2: exibirNotas(notas); break;
            case 3:
                for (int i = 0; i < alunos; i++)
                    printf("Aluno %d média: %.2f\n", i+1, calcularMediaAluno(notas, i));
                break;
            case 4:
                for (int j = 0; j < disciplinas; j++)
                    printf("Disciplina %d média: %.2f\n", j+1, calcularMediaDisciplina(notas, j));
                break;
            case 5: exibirrelfinal(notas); break;

            case 0:
            printf("saindo..");
            break;
        }
    } while (opcao != 0);

    return 0;
}
