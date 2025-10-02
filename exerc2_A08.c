#include <stdio.h>
#define tam 10

void preencherArray(int v[]){
    int i;
    for (i = 0; i < tam; i++){
        printf("Digite o %d número: ", i+1);
        scanf("%d", &v[i]);
    }
}

void exibirArray(const int v[]){
    int i;
    printf("[");
    for (i = 0; i < tam; i++){
        printf("%d", v[i]);
    if (i < tam-1) printf(", ");
    }
    printf("]\n");
}

int maiorValor(const int v[]) {
    int i;
    int maior = v[0];
    for (i = 1; i < tam; i++){
    if (v[i] > maior){
        maior = v[i];}
    }
    return maior;
}

// Menor valor
int menorValor(const int v[]) {
    int i;
    int menor = v[0];
    for (i = 1; i < tam; i++){
        if (v[i] < menor){
    menor = v[i];}
    }
    return menor;
}

float media(const int v[]) {
    int soma = 0;
    for (int i = 0; i < tam; i++){
        soma += v[i];
    }
    return (float)soma / tam;
}

void ordenar(int v[]) {
    int i, j;
    for (i = 0; i < tam-1; i++) {
        for (j = 0; j < tam-1-i; j++) {
            if (v[j] > v[j+1]) {
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}

int main() {
int numeros[tam];

    printf("Digite 10 números:\n");
    preencherArray(numeros);

    printf("Array original: ");
    exibirArray(numeros);

    printf("Maior valor: %d\n", maiorValor(numeros));
    printf("Menor valor: %d\n", menorValor(numeros));
    printf("Média: %.2f\n", media(numeros));

    ordenar(numeros);
    printf("Array ordenado: ");
    exibirArray(numeros);
    return 0;
}