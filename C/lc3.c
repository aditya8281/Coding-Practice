#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int e = len*(len+1)/2;
    char **l = malloc(e*sizeof(char*));
    int idx=0;
    for(int j =0;j<len;j++)
    {
        for(int k=1;k<=len-j;k++)
        {
            l[idx] = malloc((k+1)*sizeof(char));
            for(int m=0;m<k;m++)
            {
                l[idx][m]=s[j+m];
            }
            l[idx][k]='\0';
            idx++;
        }
    }

    int maxlen=0;

    for(int i=0;i<e;i++)
    {
        int temp=0;
        int slen = strlen(l[i]);
        for(int j=0;j<slen;j++)
        {
            for(int k=j+1;k<slen;k++)
            {
                if(l[i][j]==l[i][k])
                {
                    temp=1;
                    break;
                }
            }
            if(temp==1)
            {
                break;
            }
            
        }
        if(temp==0 && maxlen<=slen)
        {
            maxlen = slen;
        }
    }

    for(int i=0;i<e;i++)
    {
        free(l[i]);
    }

    return maxlen;
    
}

int main()
{
    char *s;
    
    int n = lengthOfLongestSubstring(s);
    printf("%d",n);
    scanf("%d",n);
    return 0;
}