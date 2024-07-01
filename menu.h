/*
Nome: Miguel Duarte
Biblioteca Pessoal
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "ficheiros.h"


//Função para o menu principal
void menu()
{
  int opcao=0;
  setlocale(LC_ALL, "Portuguese");
  encontrarFicheiro();
  limpar();

    do
    {
    limpar();
    linhabranco(2);
    printf("\t\t\tMenu\n");
    linhachar(1,60,'«');
    linhabranco(2);
    printf("\t[1] - Ler ficheiro e mostrar no ecrã\n");
    printf("\t[2] - Contar o nº de campos do ficheiro\n");
    printf("\t[3] - Contar o nº de palavras do ficheiro\n");
    printf("\t[4] - Contar as linhas do ficheiro\n");
    printf("\t[5] - Copiar dados para array\n");
    printf("\t[6] - Ordenar o ficheiro\n");
    printf("\t[7] - About\n");
    printf("\t[0] - Sair\n");
    linhabranco(1);
    linhachar(1,60,'»');
    printf("\n\n Escolha uma opção: ");
    scanf("%i", &opcao);

    switch (opcao)
    {
    case 1:
      limpar();
      printf("\t\tAnalisar o Ficheiro\n");
      linhachar(1,50,'«');
      linhabranco(2);
      analisarFicheiro(); //Chama a função ler o ficheiro e mostrar no ecrã
      fecharFicheiro();
      pausa();
      break;

    case 2:
      limpar();
      printf("\tContagem de campos do ficheiro\n");
      linhachar(1,50,'«');
      linhabranco(1);
      contagemCampos(); //Chama a função para contar os campos do ficheiro. Apenas lê a primeira linha.
      fecharFicheiro();
      pausa();
      break;

    case 3:
      limpar();
      printf("\tContagem de palavras do ficheiro\n");
      linhachar(1,50,'«');
      linhabranco(1);
      contagemPalavras(); //Chama a função para contar o nº de palavras do ficheiro. Não lê espaços.
      fecharFicheiro();
      pausa();
      break;

    case 4:
      limpar();
      printf("\tContagem de linhas do Ficheiro\n");
      linhachar(1,50,'«');
      linhabranco(1);
      contagemLinhas(); //Chama a função para contar o nº de linhas do ficheiro.
      fecharFicheiro();
      pausa();
      break;

    case 5:
      limpar();
      printf("\tCopiar Ficheiro para um Array\n");
      linhachar(1,50,'«');
      linhabranco(1);
      copiarArray();
      fecharFicheiro();
      pausa();
      break;

    case 6:
      limpar();
      printf("\tOrdenar Ficheiro\n");
      linhachar(1,50,'«');
      linhabranco(1);
      menu_ordenacao(); //Chama a função que apresentar um novo menu ao utilizador onde tem de escolher o campo pelo qual quer ordenar o ficheiro.
      fecharFicheiro();
      pausa();
      break;

    case 7:
      limpar();
      printf("\t\tAbout\n");
      linhachar(1,35,'«');
      linhabranco(1);
      printf("\n Nome: Miguel Medeiros Duarte");
      linhabranco(1);
      printf("\n Número de aluno: 22306551");
      linhabranco(1);
      printf("\n UC: Programação Imperativa");
      linhabranco(1);
      printf("\n Desafio 4");
      linhabranco(2);
      linhachar(1,35,'»');
      pausa();
      break;

    case 0:
      limpar();
      linhachar(1,40,'«');
      linhabranco(1);
      printf("\n\tEscolheu sair do programa!");
      linhabranco(1);
      printf("\n\tObrigado e volte sempre!");
      linhabranco(2);
      linhachar(1,40,'»');
      break;
    }
} while (opcao!=0);

fecharFicheiro();

}

//Função para ler o ficheiro CSV e mostrar ao utilizador
void analisarFicheiro()
{
  char caractere;
  int linha1=1;

  abrirFicheiro();
  verificarFicheiro();

  caractere=fgetc(ficheiro);

  while(caractere!=EOF)
  {
  if(linha1==1) //Para ignorar o que está na primeira linha(cabeçalho de cada coluna)
  {
    if(caractere=='\n')
    {
    linha1=0;
    }
    else
    {
    caractere=fgetc(ficheiro);
    }
  }
  else
    {
    printf("%c", caractere);
    caractere=fgetc(ficheiro);
    }
  }
  linhabranco(1);
  fecharFicheiro();
}


//Função para contar o nº de campos do ficheiro (nº de colunas apresentadas no excel)
void contagemCampos()
{
 int campos=1;
 char caractere;

 abrirFicheiro();
 verificarFicheiro();

 caractere=fgetc(ficheiro);

 while(caractere!='\n')
 {
  if(caractere==';' || caractere==',')
  {
  campos++;
  }
  caractere=fgetc(ficheiro);
 }
  fecharFicheiro();
  printf("\n O ficheiro tem %i campos.", campos);
  linhabranco(1);
}

//Função para contar o nº de palavras do ficheiro (não conta espaços)
void contagemPalavras()
{
 int palavras=0, linha1=1;
 char caractere;

 abrirFicheiro();
 verificarFicheiro();

 caractere=fgetc(ficheiro);

 while(caractere!=EOF)
 {
  if(linha1==1) //Para ignorar o que está na primeira linha(cabeçalho de cada coluna)
  {
    if(caractere=='\n')
    {
    linha1=0;
    }
  }
  else
  {
    if(caractere==';' || caractere==',' || caractere=='\n' || caractere==' ')
    {
    palavras++;
   }
  }
  caractere=fgetc(ficheiro);
 }
  fecharFicheiro();
  printf("\n O ficheiro tem %i palavras.", palavras);
  linhabranco(1);
}

//Função para contar o nº de linhas do ficheiro
void contagemLinhas()
{
 int linhas=0;
 char caractere;

 abrirFicheiro();
 verificarFicheiro();

 for(caractere=getc(ficheiro); caractere!=EOF; caractere=getc(ficheiro))
 {
  if(caractere=='\n')
  {
   linhas++;
  }
 }
  linhas--;
  fecharFicheiro();
  printf("\n O ficheiro tem %i linhas.", linhas);
  linhabranco(1);
}

//definir a struct
typedef struct
  {
  char nome[50];
  char morada[100];
  char telefone[8];
  } dados;

  dados moradas[100];
  int num_moradas=0;

//Função para copiar os dados do ficheiro csv para uma struct(array).
void copiarArray()
{
  char ignorar_linha1[300];
  char caractere;
  int i=0;
  abrirFicheiro();
  verificarFicheiro();

  fscanf(ficheiro, "%[^\n]\n", ignorar_linha1);

  while(fscanf(ficheiro, "%[^;];%[^;];%[^\n]\n", moradas[num_moradas].nome, moradas[num_moradas].morada, moradas[num_moradas].telefone)!=EOF)
    {
    num_moradas++;
    }
    fclose(ficheiro);

    for(i=0; i<num_moradas; i++)
    {
    printf("\nNome: %s", moradas[i].nome);
    printf("\nMorada: %s", moradas[i].morada);
    printf("\nTelefone: %s", moradas[i].telefone);
    linhabranco(1);
    }
}

//Função para comparar o nome.
int compararNome(const void *a, const void *b)
{
  return strcasecmp(((dados*)a)->nome, ((dados*)b)->nome); //strcasecmp ignora se são minúsculas ou maiúsculas
}

//Função para comparar a morada.
int compararMorada(const void *a, const void *b)
{
  return strcasecmp(((dados*)a)->morada, ((dados*)b)->morada);
}

//Função para comparar o telefone.
int compararTelefone(const void *a, const void *b)
{
  return strcmp(((dados*)a)->telefone, ((dados*)b)->telefone);
}

//Função para ordenar o nome alfabeticamente
void ordenar_Nome()
{
  qsort(moradas, num_moradas, sizeof(dados), compararNome);
}

//Função para ordenar a morada alfabeticamente
void ordenar_Morada()
{
  qsort(moradas, num_moradas, sizeof(dados), compararMorada);
}

//Função para ordenar o telefone por ordem crescente
void ordenar_Telefone()
{
  qsort(moradas, num_moradas, sizeof(dados), compararTelefone);
}

//Função para criar um novo ficheiro com os dados ordenados.
void escrever_Ordenado(char* campo)
{
  int i=0;
  FILE* ficheiro_ordenado;
  ficheiro_ordenado=fopen("moradas_ordenadas.csv", "w+");

  if(ficheiro_ordenado==NULL)
  {
  printf("Erro ao abrir o ficheiro.\n");
  return 0;
  }

  for(i=0; i<num_moradas; i++)
  {
  fprintf(ficheiro_ordenado, "%s;%s;%s\n", moradas[i].nome, moradas[i].morada, moradas[i].telefone);
  }
  fclose(ficheiro_ordenado);
}

//Função para abrir o ficheiro ordenado como um apontador para o próprio ficheiro. (FOI A ÚNICA SOLUÇÃO QUE ENCONTREI ONLINE, COM VOID NÃO FUNCIONAVA).
FILE* abrir_Ficheiro_Ordenado() //para devolver dar return ao ficheiro ordenado
{
  FILE* ficheiro_ordenado;
  ficheiro_ordenado=fopen("moradas_ordenadas.csv", "r");

  if(ficheiro_ordenado==NULL)
  {
  printf("Erro ao abrir o ficheiro.\n");
  return;
  }
  return ficheiro_ordenado;
}

//Função para fechar o ficheiro ordenado.
void fechar_Ficheiro_Ordenado(FILE* ficheiro_ordenado)
{
  if(ficheiro_ordenado!=NULL)
  {
  fclose(ficheiro_ordenado);
  }
}

//Função para mostrar o ficheiro ordenado.
void mostrar_Ficheiro_Ordenado()
{
  char caractere;

  FILE* ficheiro_ordenado;
  ficheiro_ordenado=abrir_Ficheiro_Ordenado();

  if(ficheiro_ordenado==NULL)
  {
  return;
  }

  while(caractere!=EOF)
  {
    caractere=fgetc(ficheiro_ordenado);
    printf("%c", caractere);
  }

  linhabranco(1);
  fechar_Ficheiro_Ordenado(ficheiro_ordenado);
}

//Função para mostrar o menu de ordenação, caso o utilizador queira ordenar o ficheiro.
void menu_ordenacao()
{
  int opcao=0, i=0;
  setlocale(LC_ALL, "Portuguese");
  fecharFicheiro();

    do
    {
    limpar();
    linhabranco(2);
    printf("\tMenu de Ordenação\n");
    linhachar(1,40,'«');
    linhabranco(2);
    printf("  [1] - Nome\n");
    printf("  [2] - Morada\n");
    printf("  [3] - Telefone\n");
    printf("  [0] - Voltar ao menu principal\n");
    linhabranco(1);
    printf("Nota: Escolha a opção 5 antes de efetuar a ordenação!");
    printf("\nCaso já o tenho feito pode prosseguir.\n");
    linhabranco(1);
    linhachar(1,40,'»');
    printf("\n\nEscolha como deseja ordenar o ficheiro: ");
    scanf("%i", &opcao);

    switch (opcao)
    {
    case 1:
      limpar();
      printf("\t\tFicheiro ordenado pelo Nome\n");
      linhachar(1,50,'«');
      linhabranco(2);
      ordenar_Nome();
      escrever_Ordenado("Nome");
      mostrar_Ficheiro_Ordenado();
      pausa();
      break;

    case 2:
      limpar();
      printf("\t\tFicheiro ordenado pela Morada\n");
      linhachar(1,50,'«');
      linhabranco(2);
      ordenar_Morada();
      escrever_Ordenado("Morada");
      mostrar_Ficheiro_Ordenado();
      pausa();
      break;

    case 3:
      limpar();
      printf("\t\tFicheiro ordenado pelo Telefone\n");
      linhachar(1,50,'«');
      linhabranco(2);
      ordenar_Telefone();
      escrever_Ordenado("Telefone");
      mostrar_Ficheiro_Ordenado();
      pausa();
      break;

    case 0:
      limpar();
      fechar_Ficheiro_Ordenado(ficheiro);
      linhachar(1,45,'«');
      linhabranco(1);
      printf("\n    Escolheu voltar ao menu principal");
      linhabranco(2);
      linhachar(1,45,'»');
      break;
    }
} while (opcao!=0);

}
