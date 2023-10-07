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
      if(n->sudo[j][i]){
        for(int k=i+1;k<9;k++){
          if(n->sudo[k][j]==n->sudo[i][j]){
            return 0;
          }
        }
      }
    }
  }



  
  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  if(n==NULL){
    return list;
  }

  for(int num=1; num<=9;num++){
    if(n->sudo[0][2]==0){
      Node* newNode=copy(n);
      newNode->sudo[0][2]=num;
      pushBack(list,newNode);
    }
  }
  return list;
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