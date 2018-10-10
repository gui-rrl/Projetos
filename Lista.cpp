#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Struct Cliente
typedef struct 
{
   char nome[30];
   int idade;
}CLIENTE;

// Struct Lista 
typedef struct
{
   CLIENTE vetor[MAX];
   int nElem;
}LISTA;

// Função para criar a Lista
void criarLista (LISTA * lista)
{
     lista->nElem = 0;
}

// Função para inserir no final da lista 
 void inserirFinal (LISTA *lista, CLIENTE cli)
 {
     lista->vetor[lista->nElem]=cli;
     lista->nElem = lista->nElem +1;  // Posição final da lista + 1
 } 
  
  void inserirPosicao (LISTA *lista, int pos, CLIENTE cli)
  {
     int i;
     
     if (pos >= lista->nElem)
        inserirFinal (lista, cli);
     else 
     {
          for (i = lista->nElem; i>pos; i--)
          {
              lista->vetor[i] = lista->vetor[i-1];
          }
          
          lista->vetor[pos] = cli;
          lista->nElem = lista->nElem + 1;
     }
   }
    
     void inserirInicio (LISTA *lista, CLIENTE cli)
     {
         inserirPosicao (lista, 0, cli);
     }
    
     CLIENTE * acessarAPartirInicio (LISTA *lista, int pos)
     {
       if (pos < lista->nElem)
          return &lista->vetor[lista->nElem - pos -1];
       else
          return NULL; //Se não encontrar retornar nulo
     }
     
     CLIENTE * acessarAPartirFim (LISTA *lista, int pos)
     {
       if (pos < lista->nElem)
          return &lista->vetor[lista->nElem - pos -1];
       else
          return NULL; //Se não encontrar retornar nulo
     }
      
      
    void listarInicioAoFim (LISTA *lista)
    {
      int i;
      CLIENTE cli;
      for (i=0; i < lista->nElem; i++)
      {
          cli = lista->vetor[i];
          printf ("Nome: %s\n", cli.nome);
          printf ("Idade: %d\n", cli.idade);
      }
    }
    
int main ()
{
    int posicao, op = 0;
    LISTA lista;
    CLIENTE cli;
    CLIENTE *cp;
    criarLista (&lista);
    
    do
    {
       printf("1 - Criar Lista \n");
       printf("2 - Inserir Inicio \n");
       printf("3 - Inserir Final \n");
       printf("4 - Inserir Posicao \n");
       printf("5 - Acessar a Partir Inicio \n");
       printf("6 - Acessar a Partir Fim \n");
       printf("7 - Listar do Inicio ao fim \n");
       printf("8 - Listar do Fim ao Inicio \n");
       printf("Opcao! ");
       scanf ("%d", &op);
       
       switch (op){
       
       case 1: criarLista (&lista);
               break;
       case 2: printf("Nome: ");
               scanf ("%s", &cli.nome);
               printf("Idade: ");
               scanf ("%d", &cli.idade);
               inserirInicio (&lista, cli);
               break;
       case 3: printf("Nome: ");
               scanf ("%s", &cli.nome);
               printf("Idade: ");
               scanf ("%d", &cli.idade);
               inserirFinal (&lista, cli);
               break;
       case 4: printf("Nome: ");
               scanf ("%s", &cli.nome);
               printf("Idade: ");
               scanf ("%d", &cli.idade);
               printf("Posicao: ");
               scanf ("%d", &posicao);
               inserirPosicao (&lista, posicao, cli);
               break;
       case 5: printf("Posicao: ");
               scanf ("%d", posicao);
               cp = acessarAPartirInicio (&lista, posicao);
               
               if (cp != NULL)
               {
                  printf("nome: %s", cp->nome);
                  printf("idade: %d", cp->idade);
               }
               else 
                  printf("posicao nao existe \n");
                  break;
       case 6: printf("posicao: ");
               scanf ("%d", &posicao);
               cp =  acessarAPartirFim (&lista, posicao);
               
               if (cp !=NULL)
               {
                  printf("Nome: %s", cp->nome);
                  printf("Idade: %d", cp->idade);
               }
               else 
                  printf("posicao nao existe \n");
                  break;
       case 7: 
               listarInicioAoFim(&lista);
               break;
       case 8: 
               break;  
       }
       }
       while (op != 14);
       return 0;
       
}
