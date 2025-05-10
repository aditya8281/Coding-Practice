#include<stdio.h>

int main()
{
    int c;
    FILE *fp = fopen(__FILE__,"r");
    
    if(fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while((c=fgetc(fp))!= EOF)
    {
        putchar(c);
    }

    fclose(fp);
    return 0;
}