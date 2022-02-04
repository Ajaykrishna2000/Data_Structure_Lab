#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int s[100];
int find(int);
int finds(int);
void main()
    {
    int n,a,b,i,p,q,key;
    printf("\nEnter the limit of the set:");
    scanf("%d",&n);
    //printf("\nEnter the root values to the set:");//
    for(i=1;i<=n;i++)
        {
        s[i]=0;
        }
    do{
    printf("\nEnter the First element to perform union operation:");
    scanf("%d",&a);
    printf("\nEnter the Second element to perform union operation:");
    scanf("%d",&b);
    p=find(a);
    q=finds(b);
    if(p!=q)
        {
        s[b]=a;
        printf("\nUnion operation of %d and %d is been performed",a,b);
        }
    else
        {
        printf("\nUnion operation cannot be performed");
        }
    printf("\n\nNow the array of sets is:");
    for(i=1;i<=n;i++)
        {
        printf("%d",s[i]);
        }
    printf("\n\nPress 0 to perform more....");
    scanf("%d",&key);
    }
    while(key==0);
    }
int find(a)
    {
    if(s[a]==0)
        {
        return a;
        }
    else
        {
        find(s[a]);
        return;
        }
    }
int finds(b)
    {
    if(s[b]==0)
        {
        return b;
        }
    else
        {
        find(s[b]);
        return;
        }
    }
