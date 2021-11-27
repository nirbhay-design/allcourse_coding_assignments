#include <bits/stdc++.h>

using namespace std;

vector<int> parse_string(string s){
    vector<int> vs;
    int i =0;
    int t = s.length();
    while (i<t) {
        
        // int ascii = s[i] -'0';
        if (s[i] == '[' || s[i] ==']' || s[i] ==',' || s[i] ==' ') {
            i++;
        } else if (s[i] >='0' && s[i] <= '9') {
            string value= "";
            value += s[i++];
            while (s[i] !=',' && s[i] !=']') {
                value += s[i++];
            }
            vs.push_back(stoi(value));
        }        
    }
    return vs;
}


class solution{
    public:
    string s1, s2;
    int v,E;
    vector<int> arr;
    vector<vector<int>> G;
    solution(){
        cin >> s1;
        v = s1.length();
        cin >> s2;
        arr = parse_string(s2);
        // cout << v << endl;
        G.resize(v);
        for (int i =0;i<v;i++){
            G[i].resize(v);
        }

        int o = 0;
        E = arr.size()/2;
        for (int i = 0;i<E ;i++){
            G[arr[o]][arr[o+1]] = 1;
            o += 2;
        }
    }
    void print_map(unordered_map<char,int> mp){
        for (auto x:mp){
            cout << x.first <<  " " << x.second << endl;
        }
    }
    void print_arr(vector<int> vect){
        for (int i = 0;i<v;i++){
            cout << vect[i] << " ";
        }
        cout << endl;
    }
    bool dfs(int i,vector<int> &vis){
        vis[i] = 1;
        for (int vertex = 0;vertex<v;vertex++){
            if (G[i][vertex] == 1 && !vis[vertex]){
                if(dfs(vertex,vis)){
                    return true;
                }
            } if (G[i][vertex]==1 && vis[vertex]==1){
                return true;
            }
        }
        vis[i] = 2;
        return false;

    }
    bool detect_cycle(){
        vector<int> visited(v,0);
        for (int i = 0;i<v;i++){
            if (dfs(i,visited)){
                return true;
            }
            for (int j = 0;j<v;j++){
                visited[j] = 0;
            }
            // break;
        }
        return false;
    }
    int start_dfs(int vertex,vector<int> &vis,unordered_map<char,int> mp){
        mp[s1[vertex]]++;
        vis[vertex] = 1;
        // cout << "entry on " << vertex << "\n";
        // print_map(mp);
        // print_arr(vis);
        int val =INT_MIN;
        bool left=false;
        for (int i = 0;i<v;i++){
            left = (G[vertex][i] && !vis[i])?true:false;
            if (G[vertex][i] == 1 && !vis[i]){
                val = max(start_dfs(i,vis,mp),val);
                // cout << val << "returned from " << vertex << " to " << i << "\n";
                vis[i] = 0;                
            }
        }
        // cout << "exit "<<vertex << "\n";
        // print_map(mp);
        // print_arr(vis);
        if (!left){
            int myval =INT_MIN;
            for (auto ter:mp){
                myval = max(myval,ter.second);
            }
            // cout << "returning myval for " << vertex<<", " << max(myval,val) << "\n";
            return max(myval,val);
        }
        // cout << "returning val for " << vertex << ", "<<val<<"\n";
        return val;
    }
    int solve(){
        if (detect_cycle()){
            return -1;
        }

        unordered_map<char,int> mp;
        for (int i =0;i<v;i++){
            if(mp.count(s1[i]) ==0){
                mp[s1[i]] = 0;
            }
        }
        int myans = INT_MIN;
        vector<int> vis(v,0);
        for (int i = 0;i<v;i++){
            int m=0;
            // cout <<"for " << i<<"\n";
            // print_arr(vis);
            int ans = max(start_dfs(i,vis,mp),myans);
            myans = ans;
            // cout << myans << "\n";
            for (int j = 0;j<v;j++){
                vis[j] = 0;
            }
        }
        return myans;
        // for (int i =0;i<2*E;i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        // for (int i =0;i<v;i++){
        //     for (int j = 0;j<v;j++){
        //         cout <<G[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return 0;
    }
};


int main(int argc, char * argv[]){
    solution * sol = new solution();
    int ans = sol->solve();
    cout << ans;
    return 0;
}