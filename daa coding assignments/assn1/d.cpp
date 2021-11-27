#include<bits/stdc++.h>

using namespace std;

void print(vector<int> v){
    for(int i =0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    int n,e;cin>>n>>e;

    vector<vector<int>> G(n,vector<int>(n,0));

    for(int i =0;i<e;i++){
        int u,v;cin>>u>>v;
        G[u-1][v-1] = 1;
    }

    vector<int> nodes(n,0);
    vector<int> safe;

    for(int i =0;i<n;i++){
        nodes[i] = i;
    }
    bool exist = true;
    while(nodes.size()>0){
        vector<int> torem;
        int sz = nodes.size();
        for(int i =0;i<sz;i++){
            bool hasin = false;
            for(int j =0;j<n;j++){
                if(G[j][nodes[i]] == 1){
                    hasin = true;
                }
            }
            if(!hasin){
                torem.push_back(nodes[i]);
                safe.push_back(nodes[i]+1);
                for(int j=0;j<n;j++){
                    G[nodes[i]][j] = 0;
                }
                break;
            }
        }

        if(torem.size()==0){
            exist = false;
            break;
        }

        for(int k = 0;k<torem.size();k++){
            nodes.erase(find(nodes.begin(),nodes.end(),torem[k]));
        }

    }

   
    if(exist){
        for(int i =0;i<safe.size();i++){
            cout<< safe[i] << " ";
        }
        cout << endl;
    }else{
        cout << "NOTIFY" << endl;
    }

    return 0;
}

/*
5
3
1 2
3 2
4 5

*/