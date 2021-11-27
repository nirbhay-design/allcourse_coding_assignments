#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b) {
    if (a.second.first > b.second.first) {
        return false;
    } else if (a.second.first == b.second.first) {
        if (a.second.second <= b.second.second) {
            return false;
        }
    } 
    return true;
}

class Solution{
    public:
    int c,d,k;
    string s;
    vector<pair<int,pair<int,int>>> ino;
    vector<vector<int>> G;
    Solution(){
        cin >> c >> d >> s >> k;
        ino.resize(c+1);
        G.resize(c+1);
        for (int i =0;i<=c;i++) {
            G[i].resize(c+1,0);
            // for (int j =0;j<=c;j++) {
            //     G[i][j] = 0;
            // }
        }
        for (int i = 0;i<c+1;i++) {
            ino[i].first = i; // node value
            ino[i].second.first = 0;// indeg
            ino[i].second.second = 0;// outdeg
        }
        vector<int> vs;
        int i =0;
        int t = s.length();
        while (i<t) {
            
            int ascii = s[i] -'0';
            if (s[i] == '[' || s[i] ==']' || s[i] ==',' || s[i] ==' ') {
                i++;
            } else if (ascii >=0 && ascii <= 9) {
                string value= "";
                value += s[i++];
                while (s[i] !=',' && s[i] !=']') {
                    value += s[i++];
                }
                vs.push_back(stoi(value));
            }        
        }
        for (int i =0;i<vs.size();i+=2){
            G[vs[i]][vs[i+1]] = 1;
            ino[vs[i]].second.second +=1;
            ino[vs[i+1]].second.first += 1;
        }   
        
    }
    void printino() {
        for (int i =1;i<c+1;i++) {
            cout <<"(" <<ino[i].first << " " << ino[i].second.first << " " << ino[i].second.second <<") ";
        }
        cout << endl;
    }
    void solve(){
        sort(ino.begin()+1,ino.end(),comparator);
        // main  algorithm
        // printino();

        vector<int> visited(c+1,0);
        visited[0] = 1;
        int ans = 0;
        int var =0;
        int i =1;
        int prev = i;
        while (i < ino.size()) {
            bool flag = false;
            if (ino[i].second.first ==0) {
                // cout << "a";
                i++;var++;
                if (i == ino.size()) {
                    ans++;
                }
                if (var == k) {
                    flag = true;
                    ans++;
                    var=0;
                }
            } else {
                // cout <<"b";
                flag = true;
                var =0;
                ans++;
            }
            if (flag) {
                // cout << "c";
                for (int j = prev;j < i ;j++) {
                    ino[j].second.first = 0;
                    ino[j].second.second = 0;
                    int val = ino[j].first;
                    for (int ma = 1;ma<c+1;ma++) {
                        if (G[val][ma] !=0) {
                            int ker;
                            for (ker = i;ker < ino.size();ker++) {
                                if (ino[ker].first == ma){
                                    // ker = kere;
                                    break;
                                }
                            }
                            ino[ker].second.first--;
                            G[val][ma] = 0;
                        }
                    }
                }
                prev = i;
                sort(ino.begin()+i,ino.end(),comparator);
                // cout << "i: " <<i << endl;
                // printino();
            }
        }
        cout << ans;
    }
};

int main(int argc,char * argv[]) {
    Solution * sol = new Solution();
    sol->solve();
    return 0;
}