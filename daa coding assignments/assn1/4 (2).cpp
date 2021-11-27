#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
using namespace std;

vector<vector<int>> graph;
vector<int> visit;
map<int,int> curr;

void bfs(int n)
{
    while(curr.begin()!=curr.end())
    {
        auto it=curr.begin();
        int tt=it->first;
        visit[tt]=1;
        curr.erase(tt);
        cout<<tt+1<<" ";
        for(int i=0;i<n;i++)
        {
            if(graph[tt][i]==1 && visit[i]==0 && curr.find(i)==curr.end())
            {curr[i]=1;}
        }
    }
}

vector<int> visitt;
map<int,int> curre;
bool cycle(int a,int n)
{
    curre[a]=1;
    for(int i=0;i<n;i++)
    {
        if(graph[a][i]==1&& visitt[i]==0 && curre.find(i)==curre.end())
        {return cycle(i,n);}
        else if(graph[a][i]==1 && visitt[i]==0 && curre.find(i)!=curre.end())
        {return true;}
    }
    visitt[a]=1;
    curre.erase(a);
    return false;
}


int main()
{
    int n,e,a,b;
    vector<int> c;
    cin>>n>>e;
    graph.clear();
    curr.clear();
    visitt.clear();
    visitt.resize(n,0);
    graph.resize(n,vector<int> (n,0));
    visit.clear();
    visit.resize(n,0);
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a-1][b-1]=1;
    }
    b=-1;
    for(int i=0;i<n;i++)
    {
        a=0;
        for(int x=0;x<n;x++)
        {a+=graph[x][i];}
        if(a==0){b=0;curr[i]=1;}
    }
    bool ans=false;
    for(auto x:curr)
    {ans=ans|cycle(x.first,n);}
    if(ans){cout<<"NOTIFY\n";}
    else
    {bfs(n);}
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
