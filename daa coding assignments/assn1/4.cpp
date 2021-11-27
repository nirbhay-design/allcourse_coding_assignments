#include<stdio.h>
int arr[100];
int graph[100][100];

void dfs(int a,int n,int x)
{
  arr[a]=x;
  for(int i=0;i<n;i++)
  {
    if(graph[a][i]==1 && arr[i]==-1)
    {dfs(i,n,x);}
  }
}


int main()
{
    for(int i=0;i<100;i++)
    {arr[i]=-1;}
    for(int i=0;i<100;i++)
    {
        for(int x=0;x<100;x++)
        {
            graph[i][x]=0;
        }
    }
  int n,ans=0,a,b,e;
  scanf("%d",&n);
  scanf("%d",&e);
  for(int i=0;i<e;i++)
  {
    scanf("%d",&a);
    scanf("%d",&b);
    graph[a-1][b-1]=1;
    graph[b-1][a-1]=1;
  }
  for(int i=0;i<n;i++)
  {
    if(arr[i]==-1)
    {
      ans++;
      dfs(i,n,i);
    }
  }
  printf("%d\n",ans);
  for(int i=0;i<n;i++)
  {
      if(arr[i]==0)
        printf("%d ",i+1);
  }
}


/*
10
14
1 2
2 3
2 5
3 4
5 4
4 6
5 6
4 7
4 8
7 8
1 9
1 10
9 10
3 1

*/
