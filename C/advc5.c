#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(int argc,char **argv)
{
    int r,c;
    r=atoi(argv[1]);
    c=atoi(argv[2]);

    int *ptr = malloc(sizeof(int)*r*c);
    srand(time(NULL));
    for(int i=0;i<r*c;i++)
    {
        
        *(ptr+i) = rand()%100+1; 

        printf("%d ",*(ptr+i));
    }
    return 0;

}