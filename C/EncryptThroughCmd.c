#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *change(int shift,char *in)
{
    int len = strlen(in);
    for(int i=0;i<len;i++)
    {
        char c = in[i];
        if(isalpha(c))
        {
            c = c+shift;
            if(isalpha(c)!=0)
            {
            }
            else{
                if(c-'z'<c-'Z')
                {
                    c = 'a'+c-'z'-1;
                }
                else{
                    c = 'A'+c-'Z'-1;
                }
            }
        }
        in[i] = c;
    }

    return in;

}
int main(int argc,char **argv)
{
    char *type = argv[1];
    int shift = (int)atof(argv[2]);
    printf("%d\n",shift);
    char *in = argv[3];

    if(strcmp(type,"decrypt")==0)
    {
        shift = -shift;

    }
    char *ans = change(shift,in);
    printf("%s",ans);

}