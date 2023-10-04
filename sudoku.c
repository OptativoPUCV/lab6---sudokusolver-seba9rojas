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

    return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();

  for(int fila=0;fila<9;fila++){
    for(int columna=0;columna<9;columna++){
      int valor=n->sudo[fila][columna];

      //FILAS
      for(int i=0;i<9;i++){
        if(i!=columna && n->sudo[fila][i] !=valor){  
          int* valorPtr=(int*)malloc(sizeof(int));
          *valorPtr=n->sudo[i][columna];
          pushBack(list,valorPtr);
        } 
      }

      //COLUMNAS
      for(int i=0;i<9;i++){
        if(i!=fila && n->sudo[i][columna] !=valor){
          int* valorPtr=(int*)malloc(sizeof(int));
          *valorPtr=n->sudo[i][columna];
          pushBack(list,valorPtr);
        }  
      }

      //ESQUINA SUPERIOR IZQ
      int filaInicioSub = (fila/3) *3;
      int colInicioSub = (columna/3) *3;

      for(int i=filaInicioSub; i<filaInicioSub+3 ; i++ ){
        for(int j=colInicioSub; j<colInicioSub+3 ; j++){
          if(i!=fila && j!=columna && n->sudo[i][j] !=valor){
            int* valorPtr=(int*)malloc(sizeof(int));
            *valorPtr=n->sudo[i][j];
            pushBack(list,valorPtr);
          }
        }  
      }
    }
  }
  return list;
}



int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
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