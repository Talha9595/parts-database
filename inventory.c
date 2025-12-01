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
        scanf(" %c",&code);
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

int find_part(int number){
    for(int i=0; i < num_parts; i++){
        if(invetory[i].number == number)
            return i;
        return -1;
    }
}

void insert(void){
    int part_number;
    if( num_parts == MAX_PARTS){
        printf("Database already full. Don't add any other part.\n");
        return;
    }
    printf("Enter part number.\n");
    scanf("%d", &part_number);
    if(find_part(part_number) >= 0){
        printf("Part already exists.");
        return;
    }
    invetory[num_parts].number = part_number;
    printf("Enter part name:");
    read_line(invetory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand:");
    scanf("%d",&invetory[num_parts].on_hand);
    num_parts++;
}

void search(void){
    int part_number;
    printf("Enter the part number: ");
    scanf("%d",&part_number);
    for(int i = 0; i < num_parts; i++){
        if(invetory[i].number == part_number){
           printf("Part name: %s\n", invetory[i].name);
           printf("Quantity on hand: %d\n", invetory[i].on_hand);
           return; 
        }
    }
    printf("Error: Part does not exist.\n");
    
}

void update(void){
    int i, number, change;
    printf("Enter part number to update:");
    scanf("%d", &number);
    i = find_part(number);
    if(i >= 0){
        printf("Enter quantity on hand: ");
        scanf("%d", &change);
        invetory[i].on_hand += change;
    }else
        printf("Part not found!.\n");
}

void print(void){
    printf("Part number         Name            Quantity on hand\n");
    for(int i=0; i < num_parts; i++){
        printf("%7d         %-25s%11d\n", invetory[i].number,invetory[i].name,invetory[i].on_hand);
    }

}