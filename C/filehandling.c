#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fptr;
    char ch;

    fptr = fopen("Heyy.txt","a+");
    fputs("\nI am in ICS Course",fptr);
    if(fptr == NULL)
    {
        printf("ERROR");
        return 1;
    }

    // while((ch=fgetc(fptr))!=EOF)
    // {
    //     putchar(ch);
    // }
    if(fclose(fptr)==0)
    {
        printf("Closed");
    }
    else{
        printf("ERROR");
    }
    return 0;

}