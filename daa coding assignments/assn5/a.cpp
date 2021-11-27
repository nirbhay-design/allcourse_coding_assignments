#include <bits/stdc++.h>

using namespace std;
class solution{
    public:
    int n;
    string s;
    solution(){
        cin >> s;
        n = s.length();
    }
    void solve(){
        unordered_map<char,int> required,total,used;
        for (int i =0;i<n;i++) {
            if (total.count(s[i]) > 0) {
                total[s[i]] += 1;
            } else {
                total[s[i]] = 1;
            }
        }
        for (auto val:total) {
            required[val.first] = val.second/2;
            used[val.first] = 0;
            // cout << val.first << " " << val.second << " " << val.second/2 << " "<< endl; 
        }
        deque<char> dq;
        for (int i =n-1;i>=0;i--) {
            if (dq.empty()) {
                dq.push_back(s[i]);
                // cout << "dq empty so pushing \n";
                total[s[i]]--;
                used[s[i]]++;
                continue;
            }
            int val = s[i] - 'a';
            if (used[s[i]] == required[s[i]]) {
                total[s[i]]--;
                // cout << "requireement satisfied \n";
                continue;
            }
            while ((dq.back()-'a') > val) {
                char var = dq.back();
                if (total[var] <= 0 || ((total[var] + used[var] -1) < required[var])) {
                    // cout << "total is not sufficient\n";
                    break;
                }
                dq.pop_back();
                used[var]--;
                if (dq.empty()) {
                    // cout << "dq empty breaking \n";
                    break;
                }
            }
            
            // cout << "pushing again \n";
            dq.push_back(s[i]);
            total[s[i]]--;
            used[s[i]]++;

        }
        string ans = "";
        while (!dq.empty()) {
            ans += dq.front();
            dq.pop_front();
        }

        cout << ans;



    }
};



int main(int argc, char * argv[]) {
    solution * sol = new solution();
    sol->solve();
    return 0;
}
