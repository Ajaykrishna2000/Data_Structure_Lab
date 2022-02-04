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
    }*head=NULL;
void main()
    {
    int key,value,choice,a,b;
    do{
    printf("\nSINGLY LINKED LIST MENUS:");
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
          printf("\nDELETION OF CERTAIN ELEMENT\n");
          do{
            printf("\nEnter the element to delete:");
            scanf("%d",&a);
            deleteAtPos(a);
            printf("\nPress 0 to insert more..");
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
     }
    else
     {
     newNode->next=head;
     head=newNode;
     }
    printf("\nOne Node Inserted at beginning!!");
    }
void insertAtEnd(int value)
    {
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
     {
     head=newNode;
     }
    else
     {
      struct Node *temp=head;
      while(temp->next!=NULL)
      {
       temp=temp->next;
      }
     temp->next=newNode;
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
     head=newNode;
     }
    else
     {
      struct Node *temp=head;
      while(temp->data!=a && temp->data!=b && temp->next!=NULL)
       {
       temp=temp->next;
       }
     if(temp->data!=a && temp->data!=b)
        {
        printf("\nGiven node not found\n");
        }
    else{
        newNode->next=temp->next;
        temp->next=newNode;
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
     }
    else
     {
     temp=head;
     head=head->next;
     free(temp);
     printf("\nOne Node Deleted from beginning!!");
     }
    }
void deleteAtEnd()
    {
    struct Node *temp;
    struct Node *prev;
    temp=head;
    if(head==NULL)
     {
     printf("\nList is empty\n");
     }
    else
     {
     temp=head;
     while(temp->next!=NULL)
      {
      prev=temp;
      temp=temp->next;
      }
     prev->next=NULL;
     free(temp);
     printf("\nOne Node deleted from the last!!");
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
         free(temp);
         printf("\n%d deleted from list!!",a);
        }
       }
     }
    }
