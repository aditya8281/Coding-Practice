#include<stdio.h>
#include<stdlib.h>

int main()
{
    char file1[100],file2[100],fileOut[100];
    scanf(" %s",file1);
    scanf(" %s",file2);
    scanf(" %s",fileOut);
    FILE *f1 = fopen(file1,"r");
    FILE *f2 = fopen((file2),"r");
    FILE *f3 = fopen((fileOut),"a+");

    // FILE *f1 = fopen(("file1.txt"),"r");
    // FILE *f2 = fopen(("file2.txt"),"r");    
    // FILE *f3 = fopen(("fileOut.txt"),"a+");

    char ch;
    while((ch=fgetc(f1))!=EOF)
    {
        fputc(("%c",ch),f3);
    }
    fputs("\n",f3);
    while((ch=fgetc(f2))!=EOF)
    {
        fputc(("%c",ch),f3);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;

}