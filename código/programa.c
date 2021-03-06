#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char crip[128];

void maiusculas(char *texto){
    int i;

    for(i=0;i<strlen(texto);i++) // Pega todos os caracteres do vetor string(texto ou chave)
	{
        texto[i] = toupper(texto[i]); // Transforma todas as letras minusculas em maiusculas
    }
}

void somente_letras(char *texto){ // Remove numeros e caracteres especiais
    int i,j=0;
    char texto_novo[128];

    for(i=0;i<strlen(texto);i++){ // Pega todos os caracteres do vetor string(texto ou chave)
        if(texto[i]>='A' && texto[i]<='Z'){ // Se o caractere atual não estiver intervalo A-Z
            texto_novo[j] = texto[i]; // Adiciona a letra maiuscula a um novo vetor
            j++;
        }
    }

    for(i=0;i<j;i++){ // Substitue o texto antigo pelo novo(que contem somente letras)
        texto[i] = texto_novo[i];
    }

    texto[i] = '\0'; // Adiciona um valor nulo ao final do texto
}

void cifrar(char *texto, char *chave, int op_cifra){
    int i;

    maiusculas(texto);
    maiusculas(chave);
    somente_letras(texto);
    somente_letras(chave);

    for(i=0;i<strlen(texto);i++){ // Pega todos os caracteres do vetor string(texto ou chave)
        if(op_cifra == 1){
            crip[i] = ((texto[i] - 'A') + (chave[i % strlen(chave)] - 'A')) % 26 + 'A'; // Criptografa o caractere
        }
        else{
            crip[i] = (texto[i] - chave[i % strlen(chave)] + 26) % 26 + 'A'; // Descriptografa o caractere
        }
    }
}

int main(int argc, char *argv[])
{
    char texto[128],chave[128],m1[128],m2[128];
    int op,e,op_cifra;

    printf("PROGRAMA DE CRIPTOGRAFIA QUE UTILIZA A CIFRA DE VIGENERE \n");

    printf("\n\nObservacoes, tanto para o texto quanto para a cifra:");
    printf("\n1 - no maximo 128 caracteres;");
    printf("\n2 - somente e permitida a utilizacao de letras;");
    printf("\n3 - os acentos e a letra 'c cedilha' nao sao aceitos;");

    printf("\n\n\nOpcoes: ");
    printf("\n1 - Criptografar");
    printf("\n2 - Descriptografar");
    printf("\n0 - Sair do programa");

    do{
        printf("\n\nDigite o numero da opcao escolhida: ");
        scanf("%d",&op);

        fflush(stdin);
        //__fpurge(stdin); //somente no linux

        e = 1;

        if(op!=1 && op!=2 && op!=0){
            printf("\nOpcao invalida!\n");
            e = 0;
        }
    }
    while(e == 0); // Verifica se foi digitado algum texto

    switch(op){
        case 0:
            return 0;
        case 1:
            printf("\n\nOPCAO ESCOLHIDA: CRIPTOGRAFAR\n\n");

            op_cifra = 1;

            strcpy(m1, "Texto original");
            strcpy(m2, "Texto criptografado");

            break;

        case 2:
            printf("\n\nOPCAO ESCOLHIDA: DESCRIPTOGRAFAR\n\n");

            op_cifra = 2;

            strcpy(m1, "Texto criptografado");
            strcpy(m2, "Texto original");

            break;
    }

    do{
        printf("\nDigite o texto: ");
        fgets(texto,128,stdin);

        fflush(stdin);
        //__fpurge(stdin); //somente no linux

        if(texto[strlen(texto)-1]=='\n'){
            texto[strlen(texto)-1]='\0';
        }

        e = 1;

        if(!strlen(texto)){
            printf("\nNao foi digitado nenhum texto!\n");
            e = 0;
        }
        else if(strlen(texto) < 4){
            printf("\nO texto deve ter no minimo 4 caracteres!\n");
            e = 0;
        }
    }
    while(e == 0);

    do{
        printf("\nDigite a chave: ");
        fgets(chave,128,stdin);

        fflush(stdin);
        //__fpurge(stdin);  //somente no linux

        if(chave[strlen(chave)-1]=='\n'){
            chave[strlen(chave)-1]='\0';
        }

        e = 1;

        if(!strlen(chave)){
            printf("\nNao foi digitada nenhuma chave!\n");
            e = 0;
        }
        else if(strlen(chave) < 4){
            printf("\nA chave deve ter no minimo 4 caracteres!\n");
            e = 0;
        }
    }
    while(e == 0);

    cifrar(texto,chave,op_cifra);

    printf("\n\n\n%s: \t%s \n",m1,texto);
    printf("\nChave: \t\t\t%s \n",chave);
    printf("\n%s: \t%s \n",m2,crip);

    printf("\n\n\n");

    getchar();
    getchar();
    return 0;
}
