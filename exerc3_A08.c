#include <stdio.h>
#include <string.h>
#include <ctype.h>

int exibirMenu() {
    int opcao;
    printf("\n=== MANIPULADOR DE STRINGS ===\n");
    printf("1. Contar caracteres\n");
    printf("2. Inverter string\n");
    printf("3. Converter maiúscula\n");
    printf("4. Converter minúscula\n");
    printf("5. Contar palavras\n");
    printf("0. Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    return opcao;
}


void lerString(char *str) {
    printf("Digite uma string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
}


int contarCaracteres(const char *str) {
    return strlen(str);
}

void inverter(char *str) {
   int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void maiusculas(char *str) {
    for (int i = 0; str[i]; i++){
        str[i] = toupper(str[i]);
    }
}

void minusculas(char *str) {
    for (int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

int contarPalavras(const char *str) {
    int cont = 0, dentro = 0;
    for (int i = 0; str[i]; i++) {
        if (!isspace(str[i]) && dentro == 0) {
            dentro = 1;
            cont++;
        } else if (isspace(str[i])) {
            dentro = 0;
        }
    }
    return cont;
}

int main() {
    char str[100];
    int opcao;

    lerString(str);

    do {
        opcao = exibirMenu();

        switch(opcao) {
            case 1:
            printf("\nA string possui %d caracteres.\n", contarCaracteres(str)); 
            break;
            
            case 2: 
            inverter(str); 
            printf("\nInvertida: %s\n", str); 
            break;
            
            case 3: 
            maiusculas(str); 
            printf("\nMaiúscula: %s\n", str); 
            break;
            
            case 4: 
            minusculas(str); 
            printf("\nMinúscula: %s\n", str); 
            break;
            
            case 5: 
            printf("\nNúmero de palavras: %d\n", contarPalavras(str)); 
            break;

            case 0:
            printf("saindo..");
            break;
        }
    } while (opcao != 0);

    return 0;
}
