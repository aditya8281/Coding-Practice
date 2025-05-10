#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int storeID[n];
    float earnings[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&storeID[i]);
        scanf("%f",&earnings[i]);
    }

    for(int j=0;j<n;j++)
    {
        for(int i=1;i<n;i++)
        {
            if((earnings[i-1]<earnings[i])||(earnings[i-1]==earnings[i]&&storeID[i-1]>storeID[i]))
            {
                float t1 = earnings[i];
                earnings[i] = earnings[i-1];
                earnings[i-1]= t1;

                int t2 =storeID[i];
                storeID[i] =storeID[i-1];
                storeID[i-1]= t2;

            }
        }
    }
    printf("\n");

    for(int i=0;i<n;i++)
    {
        printf("%d %.1f\n",storeID[i],earnings[i]);
    }

}