#include<bits/stdc++.h>

using namespace std;

void print(vector<int> v){
    for(int i =0;i<v.size();i++){
        cout << v[i] <<" ";
    }
    cout << endl;
}

void printG(vector<vector<int>> v,int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int main(){

    int n,e ; cin >> n >> e;
    vector<vector<int>> G(n,vector<int>(n,0));

    for(int i =0;i<e;i++){
        int u,v ; cin>> u >> v;

        G[u-1][v-1]=1;
        G[v-1][u-1]=1;
    }
    
    // printG(G,n);
    
    vector<int> color(n,-1);
    int c1 = 0,c2=1;
    queue<int> q;
    int startNode=0;
    color[startNode] = c1;

    q.push(startNode);
    
    bool bipar = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i =0;i<n;i++){
            if(G[node][i] == 1 && color[i] == -1){
                color[i] = (color[node] == c1)?c2:c1;
                q.push(i);
            }else if (G[node][i] == 1 && color[i] == color[node]){
                bipar=false;
            }

        }
        if(!bipar){
            break;
        }
    }

    string ans =(bipar)?"YES":"NO";
    cout << ans << endl;




    return 0;
}

/*
5
3
1 2
3 2
4 5

*/