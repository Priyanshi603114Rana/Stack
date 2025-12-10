#include <stdio.h>
#include <conio.h>
#define SIZE 10
int top = -1 , stk[SIZE] , temp[SIZE];

void push();
void disp();
void pop();
void pick();
void update();
void peep();

//MAIN Function
int main(){
  clrscr();
  int ch;
  do{
    printf("\nPress 1 for Push : ");
    printf("\nPress 2 for Display : ");
    printf("\nPress 3 for Pop : ");
    printf("\nPress 4 for pick : ");
    printf("\nPress 5 for update : ");
    printf("\nPress 6 for peep : ");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch){
       case 1 : push();
		break;
       case 2 : disp();
		break;
       case 3 : pop();
		printf("\n--------After Popping values are-----------\n");
		disp();
		break;
       case 4 : pick();
		break;
       case 5 : update();
		break;
       case 6 : peep();
		break;
       default : ch = 0;
		 break;
    }
  }while(ch!=0);
  getch();
  return 0;
} //Main Function Closed

//PUSH Function
void push(){
  int data;
  if(top>=SIZE-1){
     printf("\nStack is not Empty!\n");
  }
  else{
    top++;
    printf("Enter value : ");
    scanf("%d",&data);
    stk[top]=data;
  }
}

//DISPLAY Function
void disp(){
  int i;
  if(top==-1) {
    printf("\nStack is Empty");
  }
  else{
    for(i=top; i>=0; i--){
      printf("%d\n",stk[i]);
    }
  }
}

//POP Function
void pop(){
  if(top==-1){
    printf("\nStack is Empty\n");
  }
  else{
    printf("\nPopped Element = %d\n",stk[top]);
    stk[top] = 0;
    top--;
  }
}

//PICK Function
void pick(){
  int n;
  printf("Enter your choice to pick data : ");
  scanf("%d",&n);
  if(top==-1){
     printf("\nStack is Empty!\n");
  }
  else if((top-n+1)<0 || (top-n+1)>top){
    printf("\nTry Again\n");
  }
  else{
    printf("\nData = %d\n",stk[top-n+1]);
  }
}

//UPDATE Function
void update(){
  int n,data;
   printf("Enter your choice to update data : ");
  scanf("%d",&n);
  if(top==-1){
     printf("\nStack is Empty!\n");
  }
  else if((top-n+1)<0 || (top-n+1)>top){
    printf("\nTry Again\n");
  }
  else{
    printf("\nEnter new data : \n");
    scanf("%d",&data);
    stk[top-n+1] = data;
  }
}

//PEEP Function
void peep(){
  int n , i , ct=0;
  printf("Enter your choice to peep data : ");
  scanf("%d",&n);
  if(top==-1){
     printf("\nStack is Empty!\n");
  }
  else if(n>=0 && n<=top+1){
     for(i=0; top>n-1; i++){
       temp[i] = stk[top];
       top--;
       ct++;
    }
    pop();
    for(i=ct; i>=0; i--){
       top++;
       stk[top] = temp[i];
    }
    disp();
  }
  else{
   printf("\nTry Again!");
  }
}
















