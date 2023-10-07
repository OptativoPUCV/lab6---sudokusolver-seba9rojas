#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  //Columnas
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(n->sudo[i][j]){
        for(int k=j+1;k<9;k++){
          if(n->sudo[i][j]==n->sudo[i][k]){
            return 0;
          }
        }
      }
    }
  }

  //Se repite el proceso pero ahora para Filas
  for(int j=0;j<9;j++){
    for(int i=0;i<9;i++){
      if(n->sudo[i][j]){
        for(int k=i+1;k<9;k++){
          if(n->sudo[k][j]==n->sudo[i][j]){
            return 0;
          }
        }
      }
    }
  }

  //Ahora para subcuadrícula
  for(int i=0;i<9;i++){
    int valores[10]={0};
    for(int j=0;j<9;j++){
      int subFila= 3*(i/3) + (j/3);
      int subCol= 3*(i%3) + (j%3);
      if(valores[n->sudo[subFila][subCol]]!=0){
        return 0;
      }
      if(valores[n->sudo[subFila][subCol]]==0 && n->sudo[subFila][subCol]!=0){
        valores[n->sudo[subFila][subCol]]=1;
      }
    }
  }
  return 1;
}


List* get_adj_nodes(Node* n){
  List* lista=createList();
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        for(int k=1;k<10;k++){
          Node *aux=copy(n);
          aux->sudo[i][j]=k;
          if(is_valid(aux)){
            pushBack(lista,aux);
          }
        }
        return lista;
      }
    }
  }
  return lista;
}

int is_final(Node* n){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        return 0;
      }
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  Stack *pila=createStack();
  push(pila,initial);

  (*cont)=0;
  
  while(is_empty(pila)==0){
    Node *primerNodo=top(pila);
    pop(pila);
    if(is_final(primerNodo)){
      return primerNodo;
    }
    List* lista=get_adj_nodes(primerNodo);
    Node* currentNode=first(lista);

    while(currentNode!=NULL){
      push(pila,currentNode);
      currentNode=next(lista);
    }
    cont++;
  }


  
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/