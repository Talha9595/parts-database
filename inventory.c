/*Making parts database.*/
#include<stdio.h>
#include<string.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part{
    int number,
    char name[NAME_LEN + 1];
    int on_hand;
} invetory[MAX_PARTS];

int num_parts = 0; /*Number of parts currently stored.*/

/*Function prototypes.*/
int find_part(int number);  //** */
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void){
    char code;
    for(;;){
        printf("Enter operation code: ");
        scanf("%c",&code);
        while(getchar() != '\n') //Skips to end of line.
            ;
        switch(code){
            case 'i': insert();
                    break;
            case 's': search();
                    break;
            case 'u': update();
                    break;
            case 'p': print();
                    break;
            case 'q': return 0;
            default: printf("Character entered N=not allowed.\n");  
        }
    }
}