#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int *ese=NULL,*high=NULL;
    int eseC=0,highC=0;

    int temp=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if(temp <5000)
        {
            eseC++;
            ese = (int *)realloc(ese,eseC*sizeof(int));
            *(ese+eseC-1)=temp;

        }
        else
        {
            highC++;
            high = (int *)realloc(high,highC*sizeof(int));
            *(high+highC-1)=temp;
        }

    }

    int totese=0,tothigh=0;
    for(int i=0;i<eseC;i++)
    {
        totese += *(ese+i);

    }
    for(int i=0;i<highC;i++)
    {
        tothigh += *(high+i);

    }

    printf("%d %d\n",eseC,totese);
    printf("%d %d",highC,tothigh);
    free(ese);
    free(high);
    free(temp);

    return 0;

}