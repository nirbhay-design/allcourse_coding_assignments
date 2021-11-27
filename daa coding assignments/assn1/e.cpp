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

    // print2d(cycles);
    if(cycles.size()==0){
        cout << "SAFE" << endl;
    }
    else{

        cout << "----------------------" << endl;
        print2d(cycles);
        cout << "----------------------" << endl;
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
    }
    // cout << "input -------------------" << endl;
    // showinput(G);
    return 0;
}

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
7
1 2
2 3
2 5
3 6
5 4
4 6
5 6
*/