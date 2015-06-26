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

    //   INITALIZATIONS OF FUNCTIONS
void readDataFile (struct boggleDataNode **boggleDataHead);
void addDataNode (char tempdata[], struct boggleDataNode **boggleDataHead);
void displayData(struct boggleDataNode** boggleDataHead);
void addDataSide (struct boggleDataNode** boggleDataHead,struct boggleDieSideNode** boggleDieSideHead, int counter);
void displayDie(struct boggleDieSideNode** boggleDieSideHead);
void clearDie (struct boggleDieSideNode** boggleDieSideHead);
void clearData(struct boggleDataNode** boggleDataHead);


 int main (int argc, char* argv[]){
    int counter =0;
    struct boggleDataNode *boggleDataHead = NULL;
    readDataFile (&boggleDataHead);  //Reading DataFile
    displayData (&boggleDataHead);  // Displaying Said Data File.
    system("pause");

    for (counter=0; counter < 96; counter+=6){ // Loop to cycle through each dieSide
    struct boggleDieSideNode *boggleDieSideHead = NULL;
    int i=0;
    printf("\n------NextDie-------\n");
    for (i=0;i<6;i++){ // Loop to cycle through each die
        addDataSide(&boggleDataHead,&boggleDieSideHead, counter+i);
    }//for
    displayDie(&boggleDieSideHead);  //Displays the Dice
    clearDie(&boggleDieSideHead);   // Clears the dice for next insertion.
    }//for
    clearData(&boggleDataHead);    // Clears ALL Data.
    return 0;
}//main

void readDataFile (struct boggleDataNode **boggleDataHead) //Reads data file from BoggleData.txt
{
    FILE *fp;
    char data[3];
    fp = fopen("BoggleData.txt","r");  //Opens File
    int i;
    for (i=0; i < 96; i++) {
        fscanf(fp,"%s", data);
        addDataNode(data,boggleDataHead);  //Scans each letter.
  }//for
}//ReadDataFile

void addDataNode (char tempdata[], struct boggleDataNode **boggleDataHead) { // Writes Data to DataNode
    struct boggleDataNode* end = *boggleDataHead;
    if(end) {
        while(end->nextData != NULL) {
        end = end->nextData;
        }
    }
    struct boggleDataNode* node = malloc(sizeof (struct boggleDataNode));  //; Adds each Letter, passed from readdata. To here, where each node is a letter.
    strcpy(node->data,tempdata);
    node->nextData = NULL;
    if(end) {
    end->nextData = node;
    } else {
    *boggleDataHead = node;
    }
}//addDataNode

void displayData(struct boggleDataNode **boggleDataHead) // Displays Data from DataNode
{
    struct boggleDataNode *t = *boggleDataHead;
    int i = 0;
    for (i=0; i<96; i++){
        printf("\nData Value %i : %s",i,t->data);
        t = t->nextData;
    }//for
}//DisplayData function

void addDataSide (struct boggleDataNode** boggleDataHead, struct boggleDieSideNode** boggleDieSideHead,int counter) //Adds Data from boggleDataNode Struct to each side.
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
struct boggleDieSideNode* node = malloc(sizeof(struct boggleDieSideNode)); //
strcpy(node->dieSideData,d->data);
node->nextSide = NULL;
if (t) {
    t->nextSide = node;
} else {
*boggleDieSideHead = node;}//else

}//addDataSide

void displayDie(struct boggleDieSideNode** boggleDieSideHead){ //Displays the contents of each die.
    struct boggleDieSideNode* t = *boggleDieSideHead;
    if (!t) {
        printf("Nothing Here\n");
        return;}//printf
    int i = 1;
    while(t){
        printf("DIE SIDE %d: %s\n",i++,t->dieSideData);
        t = t->nextSide;
    }//while
}//displayDie

void clearDie (struct boggleDieSideNode** boggleDieSideHead){ //Clears the Die, preparation for next 6 values.
struct boggleDieSideNode* t = *boggleDieSideHead;
if (!t) {
    printf("Nothing In Hur");
    return;}
while(t) {
    struct boggleDieSideNode* d = t;
    t=t->nextSide;
    free(d);
    d=NULL;
}//while loop
}//clearDie

void clearData(struct boggleDataNode** boggleDataHead){ // Clears the boggleDataNode Struct and free's up the memory.
    struct boggleDataNode* t = *boggleDataHead;
    if(!t) {printf("List Empty Bruh");
    return;}//if
    while(t) {
        struct boggleDataNode* d = t;
        t=t->nextData;
        free(d);
        d = NULL;
    }
}//clearRootfunction
