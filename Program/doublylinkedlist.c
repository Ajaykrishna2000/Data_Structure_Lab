#include<stdio.h>
#include<stdlib.h>
void insertAtBegining(int);
void insertAtEnd(int);
void insertAtPos(int,int,int);
void deleteAtBegining();
void deleteAtEnd();
void deleteAtPos(int);
struct Node
    {
    int data;
    struct Node *next;
    struct Node *prev;
    }*head=NULL;
void main()
    {
    int key,value,choice,a,b;
    do{
    printf("\nDOUBLY LINKED LIST MENUS:");
    printf("\n1.Insert at beginning \n2.Insert at end \n3.Insert in between two nodes \n4.Delete from beginning \n5.Delete from end \n6.Delete an element \n7.Traversal \n8.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&key);
    switch(key)
     {
      case 1:
          printf("\nINSERTION FROM BEGINNING\n");
          do{
            printf("\nEnter the item which is to be inserted:");
            scanf("%d",&value);
            insertAtBegining(value);
            printf("\nPress 0 to insert more..");
            scanf("%d",&choice);
            }
          while(choice==0);
      break;
      case 2:
          printf("\nINSERTION FROM END\n");
          do{
            printf("\nEnter the item which is to be inserted:");
            scanf("%d",&value);
            insertAtEnd(value);
            printf("\nPress 0 to insert more..");
            scanf("%d",&choice);
            }
          while(choice==0);
      break;
      case 3:
          printf("\nINSERTION INBETWEEN TWO NODES\n");
          do{
            printf("\nEnter the nodes in between the item to be inserted:");
            scanf("%d%d",&a,&b);
            printf("\nEnter the item which is to be inserted:");
            scanf("%d",&value);
            insertAtPos(a,b,value);
            printf("\nPress 0 to insert more..");
            scanf("%d",&choice);
            }
          while(choice==0);
      break;
      case 4:
          printf("\nDELETION FROM BEGINNING\n");
          do{
            deleteAtBegining();
            printf("\nPress 0 to delete more..");
            scanf("%d",&choice);
            }
          while(choice==0);
      break;
      case 5:
          printf("\nDELETION FROM END\n");
          do{
            deleteAtEnd();
            printf("\nPress 0 to delete more..");
            scanf("%d",&choice);
            }
          while(choice==0);
      break;
      case 6:
          printf("\nDELETION OF SPECIFIC ELEMENT\n");
          do{
            printf("\nEnter the element to delete:");
            scanf("%d",&a);
            deleteAtPos(a);
            printf("\nPress 0 to delete more..");
            scanf("%d",&choice);
            }
          while(choice==0);
      break;
      case 7:
          printf("\nTRAVERSAL\n");
          if(head==NULL)
            {
            printf("\nList is Empty\n");
            }
          else
            {
            struct Node *temp=head;
            printf("\nList elements are:");
            printf("NULL--->");
            while(temp->next!=NULL)
             {
             printf("%d --->",temp->data);
             temp=temp->next;
             }
            printf("%d--->NULL\n",temp->data);
            }
      break;
      case 8:
          printf("\nExiting...");
          printf("\nPress Enter to continue");
          exit(0);
     }
    }
    while(key<=8);
    }
void insertAtBegining(int value)
    {
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
     {
     head=newNode;
     newNode->next=NULL;
     newNode->prev=NULL;
     }
    else
     {
     newNode->next=head;
     newNode->prev=NULL;
     head=newNode;
     }
    printf("\nOne Node Inserted at beginning!!");
    }
void insertAtEnd(int value)
    {
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
     {
     head=newNode;
     newNode->next=NULL;
     newNode->prev=NULL;
     }
    else
     {
      struct Node *temp=head;
      while(temp->next!=NULL)
      {
       temp=temp->next;
      }
     temp->next=newNode;
     newNode->next=NULL;
     newNode->prev=temp;
     }
    printf("\nOne Node Inserted at end!!");
    }
void insertAtPos(int a,int b,int value)
    {
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
     {
     newNode->next=NULL;
     newNode->prev=NULL;
     head=newNode;
     }
    else
     {
      struct Node *temp=head;
      while(temp->data!=a && temp->data!=b && temp->next!=NULL)
       {
        if(temp->next==NULL){
           printf("\nGiven node not found\n");
           }
        else{
          temp=temp->next;
          }
       }
     if(temp->data!=a && temp->data!=b)
        {
        printf("\nGiven node not found\n");
        }
    else{
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next=newNode;
        temp=temp->next;
        printf("\nOne Node Inserted between elements %d and %d !!",a,b);
        }
     }
    }
void deleteAtBegining()
    {
    struct Node *temp;
    if(head==NULL)
     {
     printf("\nList is empty\n");
     exit(0);
     }
    else
     {
     temp=head;
     if(temp->prev==temp->next)
        {
        head=NULL;
        free(temp);
        }
    else{
        head=temp->next;
        temp->prev=NULL;
        free(temp);
        }
     printf("\nOne Node Deleted from beginning!!");
     }
    }
void deleteAtEnd()
    {
    struct Node *temp;
    struct Node *temp2;
    temp=head;
    temp2=head;
    if(head==NULL)
     {
     printf("\nList is empty\n");
     }
    else
     {
     if(temp->prev==NULL && temp->next==NULL)
        {
        head=NULL;
        free(temp);
        }
     else
      {
      while(temp->next!=NULL)
       {
       temp2=temp;
       temp=temp->next;
       }
      temp2->next=NULL;
      free(temp);
      }
     printf("\nOne node deleted from the last!!");
     }
    }
void deleteAtPos(int a)
    {
    struct Node *temp;
    struct Node *temp2;
    temp=head;
    temp2=head;
    if(head==NULL)
     {
     printf("\nList is empty\n");
     }
    else
     {
     if(head->data==a)
        {
        head=head->next;
        free(temp);
        printf("\n%d deleted from list!!",a);
        }
     else
      {
      while(temp->next!=NULL && temp->data!=a)
       {
        temp2=temp;
        temp=temp->next;
       }
        if(temp->data!=a && temp->next==NULL)
         {
         printf("\nElement not found in list");
         }
        else if(temp->data==a && temp->next==NULL)
         {
         temp2->next=NULL;
         free(temp);
         printf("\n%d deleted from list!!",a);
         }
      else
        {
         temp2->next=temp->next;
         temp->next->prev=temp2;
         free(temp);
         printf("\n%d deleted from list!!",a);
        }
       }
     }
    }

