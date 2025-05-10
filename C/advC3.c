#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
    float n = atof(argv[2]);
    char *c = argv[1];
    float ans = 0;

    if(argc<3)
    {
        printf("Sorry buddy");
        return 1;
        
    }

    if(strcmp(c,"c2f")==0)
    {
        ans = (9/5)*n+32;

    }
    
    else if(strcmp(c,"f2c")==0)
    {
        ans = (n-32)*(5/9);
    }
    else{
        printf("Wrong command");
        return 1;
    }
    printf("%d",ans);
}