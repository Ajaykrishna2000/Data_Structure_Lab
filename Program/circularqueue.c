#include<stdio.h>
#include<stdlib.h>
void main()
    {
    int key,value,choice,size,rear=-1,front=-1,queue[25],i;
    printf("\nEnter the size of queue:");
    scanf("%d",&size);
    do{
    printf("\n\n-------CIRCULAR QUEUE OPERATIONS-------");
    printf("\nMENUS:");
    printf("\n1.Enqueue \n2.Dequeue \n3.Traversal \n4.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&key);
    switch(key)
     {
      case 1:
        printf("\nENQUEUE OPERATION\n");
        do{
          printf("Enter the value to insert:");
          scanf("%d",&value);
           if(front==-1 && rear==-1)
           {
           front=0;
           rear=0;
           queue[rear]=value;
           }
          else if((rear+1)%size==front)
           {
           printf("\nQueue is Full");
           }
          else
           {
            rear=rear+1;
            queue[rear]=value;
           }
		 printf("\nPress 0 to insert more..");
         scanf("%d",&choice);
        }
        while(choice==0);
      break;
      case 2:
        printf("\nDEQUEUE OPERATION\n");
         do{
           if(front==-1 && rear==-1)
            {
             printf("\nQueue is empty");
            }
           else if(front==rear)
            {
            printf("\nThe element deleted is:%d", queue[front]);
            front=-1;
            rear=-1;
            }
           else
            {
            printf("\nThe element deleted is:%d", queue[front]);
            front=front+1;
            }
		 printf("\nPress 0 to delete more..");
         scanf("%d",&choice);
         }
        while(choice==0);
      break;
      case 3:
          i=front;
          printf("\nTRAVERSAL\n");
          if(front==-1 && rear==-1)
          {
           printf("\nQueue is empty");
          }
          else
          {
           while(i<=rear)
            {
            printf("%d-->", queue[i]);
            i=i+1;
            }
            printf("%d", queue[front]);
          }
      break;
      case 4:
          printf("\nExiting...");
          printf("\nPress Enter to continue");
          exit(0);
      }
     }
    while(key<=4);
    }
