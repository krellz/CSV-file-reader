/*
Nome: Miguel Medeiros Duarte
Descrição: CSV file reader
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "menu.h"

//Estou a assumir que os ficheiros têm cabeçalhos, por isso ignoro a primeira linha.

/*O programa tem um problema...
Quando copia do ficheiro para o array coloca o nome seguinte juntamente com o telefone do contato anterior.
Tem a ver com erro no delimitador de linha, porque no fim do telefone não tem ';'
Ele vai até ao próximo ';' do ficheiro que está após o nome da linha seguinte. Não consegui resolver.
Tentei fgets, mas depois não conseguir separar o nome, da morada e do telefone. */

int main()
{
  setlocale(LC_ALL,"Portuguese");
  menu();
}
