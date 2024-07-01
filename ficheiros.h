#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM_MAX 100

FILE *ficheiro;
char nomeFicheiro[TAM_MAX];


//Função para procurar o ficheiro
void encontrarFicheiro()
{
  limpar();
  linhabranco(2);
  printf("\t\tProcurar Ficheiro\n");
  linhachar(1,50,'«');
  linhabranco(2);
  printf("Nome do ficheiro que deseja utilizar: ");
  scanf("%s", nomeFicheiro);
}


//Função para criar o ficheiro
void criarFicheiro()
{
  ficheiro=fopen(nomeFicheiro, "a");
}

//Função para abrir o ficheiro
void abrirFicheiro()
{
  ficheiro=fopen(nomeFicheiro, "r+");
}

//Função para verificar a existência do ficheiro
void verificarFicheiro()
{
  if (ficheiro==NULL)
  {
  printf("\nFicheiro não encontrado\n");
  return;
  }
}

//Função para fechar o ficheiro
void fecharFicheiro()
{
  fclose(ficheiro);
}


//Função para limpar o ecrã
void limpar()
{
  system("CLS");
}

//Função para pausar
void pausa()
{
  printf("\n Pressione uma tecla para avançar \n");
  getche();
  system("PAUSE");
}

//Imprime n linhas, com nc caracteres iguais ao cararacter
void linhachar(int nr_linhasl , int nr_caracteres, char caracter) //Usar no programa linhachar(nr_linhas, quantidade caracteres, tipo de caracter);
{
  int i, j;
  for(i=0;i<nr_linhasl;i++)
    {
    for(j=0;j<nr_caracteres;j++)
    printf("%c",caracter);
    }
}

//Escrever linhas em branco
void linhabranco(int nr_linhas)
{
  int i;
  for(i=0;i<nr_linhas; i++)
  printf("\n");
}
