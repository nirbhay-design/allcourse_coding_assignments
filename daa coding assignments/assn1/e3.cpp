/*

#include<bits/stdc++.h>

using namespace std;

void print(vector<int> v){
    for(int i =0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void print2d(vector<vector<int>> v){
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v[i].size();j++){
            cout << v[i][j] << " " ;
        }
        cout << endl ;
    }
}

void showinput(vector<vector<int>> g){
    for(int i =0;i<g.size();i++){
        cout << i+1 << "=> ";
        for(int j = 0;j<g[i].size();j++){
            if(g[i][j] == 1){
                cout << j+1 << " ";
            }
        }
        cout << endl;
    }
}
void dfsT(int node , int parent , vector<int> &dfs,vector<int> &visited,vector<vector<int>> g,int n){
    visited[node] = 1;
    dfs.push_back(node+1);
    for(int i =0;i<n;i++){
        if(g[node][i] == 1 && visited[i] == 0){
            dfsT(i,node,dfs,visited,g,n);
        }else if (g[node][i] == 1 && visited[i] == 1 && (parent != i) && (parent != -1)){
            cout <<"node: " <<node + 1 << " parent: " << parent + 1 << " refering: " << i + 1;
            cout << " => cycle detected" << endl;
        }
    }
}   

int main(){

    int n,e;cin>>n>>e;

    vector<vector<int>> G(n,vector<int>(n,0));

    for(int i =0;i<e;i++){
        int u,v;cin>>u>>v;
        G[u-1][v-1] = 1;
        G[v-1][u-1] = 1;
    }

    vector<int> dfs;
    vector<int> visited(n,0);
    // vector<int> parent(n,-1);
    int curpar = -1;
    stack<int> stk;
    stk.push(0);
    visited[0] = 1;
    dfs.push_back(1);
    unordered_set<int> instack;
    instack.insert(0);
    vector<vector<int>> cycles;
    while(!stk.empty()){
        int currentNode = stk.top();

        bool hascon = false;
        for(int i =0 ;i<n;i++){
            if(G[currentNode][i]==1  && visited[i] == 0){
                curpar = currentNode;
                dfs.push_back(i+1);
                hascon=true;
                stk.push(i);
                instack.insert(i);
                visited[i] = 1;
                break;
            }else if(G[currentNode][i] == 1 && visited[i] == 1 && (i != curpar) && (curpar != -1)){
                if(instack.find(i) != instack.end()){
                    stack<int> stk1;
                    vector<int> cyclesnode;
                    while(stk.top() != i){
                        int toper = stk.top();
                        stk1.push(toper);
                        cyclesnode.push_back(toper+1);
                        stk.pop();
                    }

                    int tuper = stk.top();
                    stk1.push(tuper);
                    cyclesnode.push_back(tuper+1);
                    stk.pop();

                    if(cyclesnode.size() > 2){
                        cycles.push_back(cyclesnode);                        
                    }

                    while(!stk1.empty()){
                        stk.push(stk1.top());
                        stk1.pop();
                    }

                }
            }
        }

        if(!hascon){
            int val = stk.top();
            stk.pop();
            if(instack.count(val) > 0){
                instack.erase(instack.find(val));
            }

        }


    }

    // print(dfs);

    print2d(cycles);
    if(cycles.size()==0){
        cout << "SAFE" << endl;
    }
    else{
        pair<pair<int,int>,pair<int,set<int>>> maxlen;
        maxlen.second.first=0;
        for(int i = 0;i<cycles.size();i++){
            for(int j=i+1;j<cycles.size();j++){
                if(cycles[i] == cycles[j]){
                    set<int> s;
                    for(int k=i;k<=j;k++){
                        for(int val:cycles[k]){
                            s.insert(val);
                        }
                    }
                    
                    if(maxlen.second.first < s.size()){
                        maxlen.first.first= i;
                        maxlen.first.second=j;
                        maxlen.second.first=s.size();
                        maxlen.second.second=s;
                    }
                    
                }
            }
        }

        int maximum = maxlen.second.first;
        int maxid = -1;
        for(int i =maxlen.first.second+1;i<cycles.size();i++){
            if(maximum < cycles[i].size()){
                maximum = cycles[i].size();
                maxid = i;
            }
        }
        
        if(maxid != -1){
            // cout << "----------------------" << endl;
            // print2d(cycles);
            // cout << "----------------------" << endl;
            int index = 0;
            int maxlen = cycles[0].size();
            for(int i =1;i<cycles.size();i++){
                if(cycles[i].size() > maxlen){
                    maxlen = cycles[i].size();
                    index = i;
                }
            }

            sort(cycles[index].begin(),cycles[index].end());

            print(cycles[index]);
        }else{
            for(auto it=maxlen.second.second.begin();it!=maxlen.second.second.end();it++){
                cout << *it << " ";
            }
            cout << endl;
        }
        
        
    }
    // cout << "input -------------------" << endl;
    // showinput(G);
    return 0;
}


*/
/*
6
6
1 2
2 6
3 4
5 6
1 5
6 3


6
5
1 2
1 3
2 5
6 4
2 4


7
8
1 2
2 6
3 4
5 6
1 5
6 3
4 7
7 3

6
8
1 2
2 3
2 5
3 4
5 4
4 6
5 6
3 1

6
7
1 2
2 3
2 5
3 4
5 4
4 6
5 6

8
10
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

8
11
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
3 1

15
24
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
6 11
6 12
5 11
4 12
11 13
12 14
11 12
13 14
13 15
14 15



*/



#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
using namespace std;

vector<vector<int>> graph,alpa;
vector<int> visit,path;
int tt;

void dfs(int a,int n)
{
    if(visit[a]==2){return ;}
    if(visit[a]==1)
    {
        if(a==tt)
        {alpa.push_back(path);return ;}
        else
        {return ;}
    }
    visit[a]=1;
    for(int i=0;i<n;i++)
    {
        if(graph[a][i]==1 && visit[i]!=2)
        {
            path.push_back(i);
            dfs(i,n);
            path.pop_back();
            visit[i]=2;
        }
    }
    return ;
}

int main()
{
    int n,e,a,b,aa=0;
    cin>>n>>e;
    visit.resize(n,0);
    graph.resize(n,vector<int> (n,0));
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a-1][b-1]=1;
        graph[b-1][a-1]=1;
    }
    a=0;
    for(int i=0;i<n;i++)
    {
        tt=i;
        visit.clear();
        visit.resize(n,0);
        dfs(i,n);
    }
    for(auto x:alpa)
    {if(x.size()>a){a=x.size();}}
    if(a==2){cout<<"SAFE\n";return 0;}
    for(auto x:alpa)
    {
        if(x.size()==a)
        {
            sort(x.begin(),x.end());
            for(auto y:x)
            {cout<<y+1<<" ";}
            break;
        }
    }
}