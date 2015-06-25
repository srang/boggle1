#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct boggleDataNode {
  char data[3];
  struct boggleDataNode* nextData;
};//struct 1

struct boggleDieSideNode {
  char dieSideData[3];
  struct boggleDieSideNode* nextSide;
};//struct 2


void readDataFile (struct boggleDataNode *boggleDataHead);
void addDataNode (char tempdata[], struct boggleDataNode *boggleDataHead);
void displayNodes(struct boggleDataNode *boggleDataHead);


int main (int argc, char* argv[]){
  struct boggleDataNode *boggleDataHead = NULL;
  //struct boggleDieSideNode *boggleDieSideHead = NULL;
  readDataFile (boggleDataHead);
  displayNodes (boggleDataHead);
  return 0;
}//main

void readDataFile (struct boggleDataNode *boggleDataHead)
{
  FILE *fp;
  char data[3];
  fp = fopen("boggle.txt","r");
  int i;
  for (i=0; i < 96; i++) {
    fscanf(fp,"%s", data);
    addDataNode(data,boggleDataHead);
  }//for
}//ReadDataFile

void addDataNode (char tempdata[], struct boggleDataNode *boggleDataHead) {
  struct boggleDataNode *node = malloc(sizeof (struct boggleDataNode));
  if (boggleDataHead == NULL) {
    printf("1\n");
    boggleDataHead = &node;
    strcpy(node->data,tempdata);
    boggleDataHead->nextData = NULL;
  } else {
    printf("2\n");
    strcpy(node->data,tempdata);
    node->nextData = NULL;
    printf("%s\n",node->data);
  }//else
}//addDataNode

void displayNodes(struct boggleDataNode *boggleDataHead){
  struct boggleDataNode *t = boggleDataHead;

  int counter = 0;

  while (counter!=16) {
    printf("\n\nDice Number %d\n",counter);
    int i = 0;

    for (i=0;i<6;i++) {
      printf("%s\n", t->data);
      t=t->nextData;
    }//if
    counter++;
  }//while
}//display function
