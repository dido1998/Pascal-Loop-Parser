#include <string.h>

#include<stdio.h>


typedef struct symTableEntry {
    int id;
    char varName[256];
    char varType[256];
    char varMemSize[256];
    char scope[256];
    int numArgs;
    int isfunction;
   char* args[256];
    char returnType[256];
    struct symTableEntry* next;
} symTableEntry;

//PROTOTYPES
int h(char *s);
int power(int base, int exp);
int search(symTableEntry* st[], char l[], char scope[]);
void insert(symTableEntry* st[], symTableEntry* newBoi, int* symCount);

//FUNCTIONS
int h(char *s) {
    /*
        input: string s
        output: index generated by open hashing function
        doc: Weight of a string is ascii sum of its characters. This weight is modded by 10 to get a hash index.
             The hash index generated by this method is fairly random, which is good as it leads to an equally distributed hash table.
    */

    int l = strlen(s);
    double weight = 0;
    for ( int i = 0; i < l; i++ ) {
        weight += (int)s[i];
    }
    return (int)weight % 10;
}

int power(int base, int exp) {
    for ( int i = 1; i < exp; i++ ) {
        base *= base;
    }
    return base;
}

int search(symTableEntry* st[], char l[], char scope[]) {
    symTableEntry* temp;
    int searchThisList = h(l);
    for(temp = st[searchThisList]; temp; temp = temp->next) { 
        if (strcmp(temp->varName, l) == 0 && (strcmp(scope, temp->scope)==0)) {
            return temp->id;
        }
    }
    return -1;
}

void insert(symTableEntry* st[], symTableEntry* newBoi, int* symCount) {
    (*symCount)++;
    int here = h(newBoi->varName);
    symTableEntry* temp, *last;
    if( st[here] == NULL ) {
        st[here] = newBoi;
        return;
    }   
    for(temp = st[here]; temp; temp = temp->next) {
        last = temp;
    }
    last->next = newBoi;
}


int hastype(symTableEntry* st[], char l[])
{
    symTableEntry* temp;
    int searchThisList = h(l);
    for(temp = st[searchThisList]; temp; temp = temp->next) { 
        if (strcmp(temp->varName, l) == 0 ) {
            if(temp->isfunction)
                return 0;
            else
                return 1;
        }
    }

}