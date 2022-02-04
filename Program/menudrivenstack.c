#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void traversal();
void search(int);
struct Node
    {
    int data;
    struct Node *next;
    }*top=NULL;
void main()
    {
    int key, value, choice, srch;
    do{
    printf("\nMENUS:");
    printf("\n1.PUSH \n2.POP \n3.TRAVERSAL \n4.SEARCH \n5.EXIT");
    printf("\nEnter your choice:");
    scanf("%d",&key);
    switch(key)
     {
      case 1:
          printf("\n*****PUSH OPERATION*****\n");
          do{
            printf("\nEnter the element to insert:");
            scanf("%d",&value);
            push(value);
            printf("\nPress 0 to Push more..");
            scanf("%d",&choice);
            }
          while(choice==0);
      break;
      case 2:
          printf("\n*****POP OPERATION*****\n");
          do{
            printf("\Popping the top item...");
            pop();
            printf("\nPress 0 to Pop more..");
            scanf("%d",&choice);
            }
          while(choice==0);
      break;
      case 3:
            printf("\n*****TRAVERSAL*****\n");
            traversal();
      break;
      case 4:
          printf("\n*****SEARCHING*****");
          printf("\nEnter the element to search:");
          scanf("%d",&srch);
          search(srch);
          printf("\nPress Enter to continue");
      break;
      case 5:
          printf("\nExiting...");
          printf("\nPress Enter to continue");
          exit(0);
     }
     }
    while(key<=5);
    }
void push(int value)
    {
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(top==NULL)
     {
     top=newNode;
     newNode->next=NULL;
     }
    else
     {
     newNode->next=top;
     top=newNode;
     }
    printf("\nOne Node Pushed to top!!");
    }
void pop()
    {
    struct Node *temp;
    if(top==NULL)
     {
     printf("\nNo value to pop");
     }
    else
     {
      temp=top;
      top=top->next;
      temp->next=NULL;
      free(temp);
     }

    printf("\nOne Node Popped from top!!");
    }
void traversal()
    {
    if(top==NULL)
        {
        printf("\n\nStack is Empty");
        }
    else
        {
        struct Node *temp=top;
        printf("\nThe Stack is:");
        while(temp->next!=NULL)
            {
            printf("%d --->",temp->data);
            temp=temp->next;
            }
        printf("%d--->NULL",temp->data);
        }
    }
void search(int srch)
    {
    struct Node *temp=top;
    if(top==NULL)
        {
        printf("\n\nStack is Empty");
        }
    else if(temp->data==srch)
        {
        printf("\nElement found");
        }
    else
        {
        printf("\nElement not found");
        }
    }
