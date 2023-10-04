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
  int valor=n->sudo[9][9];

  //FILAS
  for(int i=0;i<9;i++){
    if(i!=columna && n->sudo[9][i] != valor){
      pushBack(list,&(n->sudo[9][i]));
    } 
  }

  //COLUMNAS
  for(int i=0; i<9 ; i++){
    if(i!=fila && n->sudo[i][9] !=valor){
      pushBack(list,&(n->sudo[i][9]));
    }
  }

  //ESQUINA SUPERIOR IZQ
  int filaInicioSub = (9/3) *3;
  int colInicioSub = (9/3) *3;

  //SUBCUADRÍCULA
  for(int i=filaInicioSub; i<filaInicioSub+3 ; i++ ){
    for(int j=colInicioSub; j<colInicioSub+3 ; j++){
      if(i!=9 && j!=9 && n->sudo[i][j] !=valor){
        pushBack(list, n->sudo[i][j]);
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