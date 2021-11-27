#include<bits/stdc++.h>

using namespace std;

void print(vector<int> v){
    for(int i =0;i<v.size();i++){
        cout << v[i] <<" ";
    }
    cout << endl;
}

int main(){

    int n; cin >> n;

    unordered_map<string,int> mp;

    for(int i = 0;i<n;i++){
        string s ; cin>> s;
        mp.insert(pair<string,int>(s,i));
    }

    string src,dest;
    cin >> src >> dest;

    int sv=mp[src];
    int dv = mp[dest];

    int e; cin >> e;

    vector<vector<int>> G(n,vector<int>(n,0));

    for(int i =0;i<e;i++){
        string s1,s2;cin >> s1>> s2;

        G[mp[s1]][mp[s2]] =1;
        G[mp[s2]][mp[s1]]=1;
    }

    // for(int i =0;i<n;i++){
    //     for(int j =0;j<n;j++){
    //         cout << G[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> v;
    set<vector<int>> paths;
    queue<int> q;
    q.push(sv);
    vector<int> visited(n,0);
    while(!q.empty()){

        int node = q.front();
        q.pop();

        if(v.size()==0){
            v.push_back({node});
        }

        else{
            int sz = v.size();
            for(int lis=0;lis<sz;lis++){

                if(G[v[lis][v[lis].size()-1]][node] == 1){
                    vector<int> veer(v[lis].begin(),v[lis].end());

                    veer.push_back(node);
                    v.push_back(veer);
                    if(node == dv){
                        paths.insert(veer);
                    }
                }
            }
        }

        visited[node] = 1;

        for(int i =0;i<n;i++){
            if(G[node][i] == 1 && visited[i] == 0){
                q.push(i);
            }
        }


    }

    // cout << paths.size();
    unordered_map<int,string> maper;
    for(pair<string,int> pr:mp){
        maper.insert(pair<int,string>(pr.second,pr.first));
    }


    // for(auto vec:paths){
    //     for(int j =0;j<vec.size();j++){
    //         cout << maper[vec[j]] << " ";
    //     }
    //     cout << endl;
    // }
    
    int min=INT_MAX;
    vector<int> ver;
    for(auto it = paths.begin();it!=paths.end();it++){
        if(min > (*it).size()){
            ver = *it;
            min = (*it).size();
        }

    }

    for(int i =0;i<ver.size();i++){
        cout << maper[ver[i]] << " "; 
    }

    cout << endl;
    

    return 0;
}

/*
5
3
1 2
3 2
4 5

*/