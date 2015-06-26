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


void readDataFile (struct boggleDataNode **boggleDataHead);
void addDataNode (char tempdata[], struct boggleDataNode **boggleDataHead);
void displayData(struct boggleDataNode **boggleDataHead);


int main (int argc, char* argv[]){
  struct boggleDataNode *boggleDataHead = NULL;
  //struct boggleDieSideNode *boggleDieSideHead = NULL;
  readDataFile (&boggleDataHead);
  displayData (&boggleDataHead);
  return 0;
}//main

void readDataFile (struct boggleDataNode **boggleDataHead)
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

void addDataNode (char tempdata[], struct boggleDataNode **boggleDataHead) {
  struct boggleDataNode* end = *boggleDataHead;
  if(end) {
    while(end->nextData != NULL) {
      end = end->nextData;
    }
  }
  struct boggleDataNode *node = malloc(sizeof (struct boggleDataNode));
  strcpy(node->data,tempdata);
  node->nextData = NULL;
  if(end) {
    end->nextData = node;
  } else {
    *boggleDataHead = node;
  }
}//addDataNode

void displayData(struct boggleDataNode **boggleDataHead)
{
    struct boggleDataNode *t = *boggleDataHead;
    int i = 0;
    for (i=0; i<96; i++){
        printf("\n%s",t->data);// I NEED TO KNOW WHAT GOES HERE
        t = t->nextData;   // THIS LINE OF CODE MESSES WITH EVERYTHING
    }//for
}//DisplayData function
