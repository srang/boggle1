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
void addDataSide (struct boggleDataNode **boggleDataHead,struct boggleDieSideNode **boggleDieSideHead, int counter);
void displayDie(struct boggleDieSideNode** boggleDieSideHead);


 int main (int argc, char* argv[]){
    int counter =0;
    struct boggleDataNode *boggleDataHead = NULL;
    readDataFile (&boggleDataHead);
    displayData (&boggleDataHead);
    system("pause");

    for (counter=0; counter < 96; counter+=6){
    struct boggleDieSideNode *boggleDieSideHead = NULL;
    int i=0;
    printf("\n------NextDie-------\n");
    for (i=0;i<6;i++){
        addDataSide(&boggleDataHead,&boggleDieSideHead, counter);
    }//for
    displayDie(&boggleDieSideHead);
// clearDie(&boggleDieSideHead);
    }//for
    //clearData(&boggleDataHead);
    return 0;
}//main

void readDataFile (struct boggleDataNode **boggleDataHead)
{
    FILE *fp;
    char data[3];
    fp = fopen("BoggleData.txt","r");
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
        printf("\nData Value %i : %s",i,t->data);
        t = t->nextData;
    }//for
}//DisplayData function

void addDataSide (struct boggleDataNode **boggleDataHead, struct boggleDieSideNode **boggleDieSideHead,int counter)
{
    struct boggleDieSideNode* t = *boggleDieSideHead;
    if(t) {
        while(t->nextSide != NULL) {
            t= t->nextSide;
        }//while
    }//if
    struct boggleDataNode* d = *boggleDataHead;
    int i=0;
    for (i=0; i < counter; i++){
        if(d) {
            d = d->nextData;
        } else {
            printf("I don't Duggie like that\n");
            exit(1);
        }//else
    }//for
struct boggleDieSideNode* insert = malloc(sizeof(struct boggleDieSideNode));
strcpy(insert->dieSideData,d->data);
insert->nextSide = NULL;
if (t) {
    t->nextSide = insert;
} else {
*boggleDieSideHead = insert;}//else

}//addDataSide

void displayDie(struct boggleDieSideNode** boggleDieSideHead){
    struct boggleDieSideNode* t = *boggleDieSideHead;
    if (!t) {
        printf("Nothing Here\n");
    }//printf
    int i = 1;
    while(t){
        printf("DIE SIDE %d: %s\n",i++,t->dieSideData);
        t = t->nextSide;
    }//while
}//displayDie
