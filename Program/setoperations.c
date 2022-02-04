#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
    {
    int n,m,a[20],b[20],c[50],i,key,temp;
    printf("\nEnter the limit of first set:");
    scanf("%d",&n);
    printf("\nEnter the First set of binary digits:");
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    printf("\nEnter the limit of Second set:");
    scanf("%d",&m);
    printf("\nEnter the Second set of binary digits:");
    for(i=0;i<m;i++)
        {
        scanf("%d",&b[i]);
        }
    do{
    printf("\nBIT VECTOR SET OPERATIONS:");
    printf("\n1.Union \n2.Intersection \n3.Difference \n4.Equality \n5.Traversal \n6.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&key);
    switch(key)
     {
      case 1:
            printf("\nUNION OPERATION\n");
            if(n==m)
            {
            for(i=0;i<n;i++)
                {
                c[i]=a[i]||b[i];
                }
            printf("\nThe set after union is:");
            printf("{");
            for(i=0;i<n;i++)
                {
                printf("%d ,\t",c[i]);
                }
            printf("}");
            }
            else
                {
                printf("\nSet operations not possible");
                }
            break;
      case 2:
            printf("\nINTERSECTION OPERATION\n");
            if(n==m)
            {
            for(i=0;i<n;i++)
                {
                c[i]=a[i]&&b[i];
                }
            printf("\nThe set after intersection is:");
            printf("{");
            for(i=0;i<n;i++)
                {
                printf("%d ,\t",c[i]);
                }
            printf("}");
            }
            else
                {
                printf("\nSet operations not possible");
                }
            break;
      case 3:
            printf("\nDIFFRENCE OPERATION\n");
            if(n==m)
            {
            for(i=0;i<n;i++)
                {
                if(a[i]!=b[i])
                    {
                    for(i=0;i<n;i++)
                        {
                        c[i]=a[i];
                        }
                    }
                }
            printf("\nThe set after difference is:");
            printf("{");
            for(i=0;i<n;i++)
                {
                printf("%d ,\t",c[i]);
                }
            printf("}\n");
            }
            else
                {
                printf("\nSet operations not possible");
                }
            break;
      case 4:
            printf("\nEQUALITY OPERATION\n");
            if(n==m)
             {
             for(i=0;i<n;i++)
                {
                if(a[i]==b[i])
                    {
                    temp=1;
                    }
                }
             if(temp!=1)
                {
                printf("\nThe two sets are not equal");
                }
             else
                {
                printf("\nThe two sets are equal");
                }
             }
            else
                {
                printf("\nSet operations not possible");
                }
            break;
      case 5:
            printf("\nTRAVERSAL\n");
            printf("\nThe First set of binary digits is:");
            printf("{");
            for(i=0;i<n;i++)
                {
                printf("%d ,\t",a[i]);
                }
            printf("}\n");
            printf("\nThe Second set of binary digits is:");
            printf("{");
            for(i=0;i<n;i++)
                {
                printf("%d ,\t",b[i]);
                }
            printf("}\n");
        break;
        case 6:
          printf("\nExiting...");
          printf("\nPress Enter to continue");
          exit(0);
     }
    }
    while(key<=6);
    }
