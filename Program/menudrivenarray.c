#include<stdio.h>
void main(){
int a[20],i,j,n,m,k,pos,item,search,index,del,temp,flag;
printf("Enter the limit of array:");
scanf("%d",&n);
printf("\nEnter the elements:");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
menu:
printf("\nMenus:\n");
printf("\n1.Traversal \n2.Insertion \n3.Deletion \n4.Searching \n5.Sorting \n6.Exit \n");
printf("Enter your choice:");
scanf("%d",&k);
switch(k)
    {
    case 1:
    printf("The array is:");
     for(i=0;i<n;i++){
        printf("%d",a[i]);
        }
    break;
    case 2:
    printf("\nEnter the position to insert element:");
    scanf("%d",&pos);
    printf("\nEnter the element:");
    scanf("%d",&item);
     for(i=n;i>=pos;i--){
        a[i]=a[i-1];
        }
    a[pos-1]=item;
    n++;
    printf("\nNow the array is:");
     for(i=0;i<n;i++){
        printf("\t%d",a[i]);
        }
    break;
    case 3:
    printf("\nEnter the element to delete:");
    scanf("%d",&del);
    for(int k=0;k<n;k++){
     for(i=0;i<n;i++){
        if(a[i]==del){
            for(j=i;j<n;j++){
                a[j]=a[j+1];
                }
            n--;
            }
        }
     }
    printf("\nNow the array is:");
     for(i=0;i<n;i++){
        printf("\t%d",a[i]);
        }
    break;
    case 4:
    printf("\nEnter the element to search:");
    scanf("%d",&search);
     for(i=0;i<n;i++){
        if(a[i]==search){
            flag=1;
            index=i+1;
            }
        }
    if(flag==1){
    printf("\nElement %d found at position %d",search,index);
    }
    else{
    printf("\nElement not found");
    }
    break;
    case 5:
     for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                }
            }
        }
    printf("\nThe array after sorting is:");
        for(i=0;i<n;i++){
        printf("\t%d",a[i]);
        }
    break;
    case 6:
    printf("\nExitting...");
    printf("\nPress Enter to exit");
    exit(0);
    }
    goto menu;
}
