#include<stdio.h>

int solve(int x,int y,int m, int n,char arr[])
{
    if(x<0 || y<0||x>=n||y>=m ||)
}

int main()
{
    int m,n;
    int x,y;
    scanf("%d %d",&m,&n);
    char maze[m*n];
    char *ptr = maze;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf(" %c",(ptr+(i*n)+j));
        }
    }
    scanf("%d %d",&x,&y);

    int a = solve(x,y,m,n,maze);
    printf("%d",a);
    


}