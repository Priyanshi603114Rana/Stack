#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct link{
  int info;
  struct link *next;
}*start;

void display(struct link *);
struct link *push(struct link *);
struct link *pop(struct link *);

void display(struct link *rec){
    while(rec != NULL){
       printf("%d\n",rec->info);
       rec = rec->next;
    }
}

struct link *push(struct link *ptr){
    struct link *new_rec;
    printf("\nInput the new value for next location of the stack : ");
    new_rec = (struct link *)malloc(sizeof(struct link));
    scanf("%d",&new_rec->info);
    new_rec->next = ptr;
    ptr = new_rec;
    return(ptr);
}

struct link *pop(struct link *rec){
      struct link *temp;
      if(rec==NULL){
	printf("\nStack is empty");
      }
      else{
	temp = rec->next;
	free(rec);
	rec = temp;
	printf("\nAfter POP operation the stack is as follows : \n");
	if(rec != NULL){
	  display(rec);
	}
      }
      return(rec);
}

int main(){
  clrscr();
  int choice;
  start = NULL;
  do{
     do{
	printf("\nPRess 1 for push : ");
	printf("\nPress 2 for POP : ");
	printf("\nPress 3 for Quit : ");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	if(choice<1 || choice>3){
	     printf("\nIncorrect Choice ---> Try Again !");
	}
     }while(choice<1 || choice>3);
     switch(choice){
	 case 1 : start = push(start);
		  printf("\nStack is as follows : \n");
		  display(start);
		  break;
	 case 2 : start = pop(start);
		  break;
	default : choice = 3;
		  printf("\nEnd of Session");
     }
  }while(choice!=3);
  getch();
}



















