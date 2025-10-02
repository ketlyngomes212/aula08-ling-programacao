#include <stdio.h>

float somar(float a, float b){
    return a + b;
}

float subtrair(float a, float b){
    return a - b;
}

float multiplicar(float a, float b){
    return a * b;
}

float dividir(float a, float b){
    if(b != 0){
     return a / b; 
    }
    return 0;
}

void exibirMenu(){
    printf("\n=== CALCULADORA ===\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("0. Sair\n");
    printf("Opção: ");
}

int obterOpcao(){
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

void obterNumeros(float *x, float *y){
    printf("Digite o primeiro número: ");
    scanf("%f", x);
    printf("Digite o segundo número: ");
    scanf("%f", y);  
}

void exibirResultado(float resultado){
    printf("\nO resultado é: %.2f\n ", resultado);
}


int main() {
    int opcao;
    float a, b, resultado;

    do{
        exibirMenu();
        opcao = obterOpcao();

         if (opcao >= 1 && opcao <= 4) {
            obterNumeros(&a, &b);
         }
         
         switch (opcao)
         {
         case 1:
            resultado = somar(a,b);
            exibirResultado(resultado);
            break;

         case 2:
            resultado = subtrair(a,b);
            exibirResultado(resultado);
            break;

         case 3:
            resultado = multiplicar(a,b);
            exibirResultado(resultado);
            break;

         case 4:
            resultado = dividir(a,b);
            exibirResultado(resultado);
            break;          
         
         case 0:
         printf("saindo..");
         break;

         } 
       
    
    }while(opcao != 0 );

    return 0;
}
