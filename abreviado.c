#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100

void recebe_nome(char nome[MAX]){
printf("digite seu nome completo: ");
fgets(nome,MAX,stdin);
printf("\nnome original: %s", nome);
}

void tudo_maiusculo(char nome[MAX]){
int i;
for (i=0;nome[i]!='\0';i++){
nome[i]=toupper(nome[i]);
}


}

void conta_palavras(char nome[MAX], int *cont){
int i;
for(i=0;nome[i]!='\0';i++){
    if (nome[i]==' ' || nome[i]=='\n'){
        if(nome[i+1]!=' '&& nome[i+1]!='\n'){
(*cont)++;
              }
         }
     }
     if (*cont>=4){
      (*cont)=4;
     }
}

void nome_final(char nome[MAX],char final[MAX]){
int i = strlen(nome)-1;
int j = 0;
while((i>0)&&(nome[i]!=' ')){
  final[j]=nome[i];
    i--;
      j++;
 }
  final[j] = '\0';
}

void nome_inicio(char nome[MAX], char inicio[MAX]){
int i=0,j=0;
int cont= 0;
    while((cont==0)){
        if (nome[i]==' '){  
            i++;
    }else
        cont++;
}
cont=0;
j=0;
while((cont==0)){
    if ((nome[i]!=' ')){
     inicio[j]= nome[i];
        j++;
             i++;
    }else
    cont++;    
}
inicio[j]='\0';
}

void inverte_nome(char final[MAX]){
int i, j;
int tamanho = strlen(final);
char temp;
    for (i = 0, j = tamanho - 1; i < j; i++, j--) {
        temp = final[i];
        final[i] = final[j];
        final[j] = temp;
    }
}

void letras_sobrenome(char nome[MAX], char *letra1, char *letra2) {
    int i = 0;
    int cont = 0;
    while (cont == 0) {
        if (nome[i] == ' ') {
            i++;
        } else {
            cont++;
        }
    }
    cont = 0;
    while(cont==0) {
        if (nome[i] != ' ' && nome[i] != '\0') {
            i++;
        } else {
            cont++;
        }
    }
      cont = 0;
     while (cont == 0) {
        if (nome[i] == ' ') {
            i++;
        } else {
            (*letra1) = nome[i];
            cont++;
        }
    }
        cont = 0;
        while(cont == 0) {
            if ((nome[i] != ' ')){
              i++;
            } else {
               cont++;
            }
        }
     cont = 0;
 while (cont == 0) {
        if (nome[i] == ' ') {
            i++;
        } else {
      (*letra2) = nome[i];
            cont++;
             }
        }
    }

void cria_login(char inicio[MAX], char fim[MAX], int op, char l1, char l2){
switch(op){
case 1: 
printf("abreviado nao da, fica original");
break;
  case 2:
    printf("Abreviado: %s %c.", inicio,l1);
  break;
case 3: 
printf("Abreviado: %s %c. %s",inicio, l1,fim);
break;
case 4:
printf("abreviado: %s %c. %c. %s",inicio, l1,l2,fim);
break;
}
}

int main(){
char nome[MAX];
char inicio[MAX];
char final[MAX];
char l1= ' ';
char l2= ' ';
int cont=0;

recebe_nome(nome);
conta_palavras(nome,&cont);
tudo_maiusculo(nome);
nome_final(nome, final);
nome_inicio(nome, inicio);
inverte_nome(final);
letras_sobrenome(nome, &l1, &l2);
cria_login(inicio, final, cont, l1, l2);

return 0;
}
