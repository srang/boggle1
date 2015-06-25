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

struct boggledataNode* root = NULL;

struct boggleDataNode *boggleDataHead = NULL;
struct boggleDieSideNode *boggleDieSideHead = NULL;
//struct boggleDataNode *root = NULL;

readDataFile (&boggleDataHead);

displayNodes (&boggleDataHead);

system("pause");
return 0;
}//main



void readDataFile (struct boggleDataNode *boggleDataHead)
{
  FILE *fp;
  char data[3];
  fp = fopen("BoggleData.txt","r");
  int i;
  for (i=0; i < 96; i++)
  {

      fscanf(fp,"%s", data);

      addDataNode(data,boggleDataHead);
  }//for

}//ReadDataFile

void addDataNode (char tempdata[], struct boggleDataNode *boggleDataHead) {

   struct boggleDataNode *node = malloc(sizeof (struct boggleDataNode));
   strcpy(node->data, tempdata);

   if (boggleDataHead == NULL){
       boggleDataHead = node;
       boggleDataHead->nextData = NULL;
   }//if
  else {
      strcpy(node->data,tempdata);
       node->nextData = NULL;
       printf("%s ", tempdata);
    //   printf("%s\n",tempdata);
   }//else
}//addDataNode

void displayNodes(struct boggleDataNode *boggleDataHead){
   struct boggleDataNode *t = boggleDataHead;

   int counter = 0;
   int i = 0;

   while (counter!=16)
   {
   printf("\n\nDice Number %d\n",counter);

      for (i=0;i<6;i++){
           printf("%s\n", *t->data);
           t=t->data;
     //      printf("%i ",i);// Test Statement
      }//if
     counter++;
   }//while
}//display function
