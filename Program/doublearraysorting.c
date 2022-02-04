#include<stdio.h>
void main(){
int a[20],b[20],c[40],i,j,k,n,m,temp,p;
p=n+m;
printf("\nEnter the limit of first array:");
scanf("%d",&n);
printf("\nEnter the elements:");
for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
for(i=0;i<n;i++)
    {
    for(j=i+1;j<n;j++)
        {
        if(a[i]>a[j])
            {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            }
        }
    }
printf("\nThe first array after sorting is:");
for(i=0;i<n;i++)
    {
    printf("\t%d",a[i]);
    }
printf("\n\nEnter the limit of second array:");
scanf("%d",&m);
printf("\nEnter the elements:");
for(k=0;k<m;k++)
    {
    scanf("%d",&b[k]);
    }
for(k=0;k<m;k++)
    {
    for(j=k+1;j<m;j++)
        {
        if(b[k]>b[j])
            {
            temp=b[k];
            b[k]=b[j];
            b[j]=temp;
            }
        }
    }
printf("\nThe second array after sorting is:");
for(k=0;k<m;k++)
    {
    printf("\t%d",b[k]);
    }
for(i=0;i<n;i++)
    {
    c[i]=a[i];
    }
for(i=n;i<=m+n;i++)
    {
    for(k=0;k<m;k++)
        {
        c[i]=b[k];
        i++;
        }
    }
for(i=0;i<n+m;i++)
    {
    for(j=i+1;j<n+m;j++)
        {
        if(c[i]>c[j])
            {
            temp=c[i];
            c[i]=c[j];
            c[j]=temp;
            }
        }
    }
printf("\nAfter combining and sorting both arrays:");
for(i=0;i<n+m;i++)
    {
    printf("\t%d",c[i]);
    }
}
