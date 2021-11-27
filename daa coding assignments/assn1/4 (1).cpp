#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
using namespace std;

vector<vector<int>> graph;
vector<int> visit,color;

bool bfs(int src)
{
    if(visit[src]==1){return true;}
    int a=0,b=0;
    vector<int> temp={src};
    visit[src]=1;
    color[src]=0;
    while(a<=b)
    {
        int x=graph[temp[a]].size();
        for(int i=0;i<x;i++)
        {
            int tt=graph[temp[a]][i];
            if(visit[tt]!=1)
            {
                temp.push_back(tt);b++;
                visit[tt]=1;
                color[tt]=1-color[temp[a]];
            }
            else
            {if(color[temp[a]]==color[tt]){return false;}}
        }
        a++;
    }
    return true;
}

int main()
{
    int n,e,a,b;
    cin>>n>>e;
    graph.clear();
    graph.resize(n);
    visit.clear();
    visit.resize(n,0);
    color.clear();
    color.resize(n,-1);
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    bool ans=true;
    for(int i=0;i<n;i++)
    {
        ans=ans&bfs(i);
    }
    if(ans)
    {cout<<"YES\n";}
    else{cout<<"NO\n";}
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
