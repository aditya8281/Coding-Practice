#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    int n=strlen(argv[1]);
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        if(argv[1][i]==argv[1][n-1-i])
        {
            continue;

        }
        temp = 1;
        break;
    }
    if(temp == 0)
    {
        printf("P");
    }
    else{
        printf("N");
    }

    return 0;
}