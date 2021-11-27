#include <bits/stdc++.h>

using namespace std;

class solution{
    public:
    string n;
    int k;
    solution() {
        cin >> n;
        cin >> k;
    }
    void solve() {
        deque<int> dq;
        for (int i =0;i<n.length();i++) {
            int val = n[i] - '0';
            if (dq.empty() || k == 0) {
                // cout << "b\n";
                
                dq.push_back(val);
            } else {
                int top = dq.back();
                if (val >= top) {
                    
                    dq.push_back(val);
                } else {
                    bool brk = false;
                    while (dq.back() > val) {
                        // cout << "c\n";
                        // cout << "popping\n";
                        dq.pop_back();
                        k--;
                        if (k ==0 || dq.empty()) {
                            
                            brk = true;
                            dq.push_back(val);
                            break;
                        }
                    }
                    if(val != 0 && !brk) {
                        
                        dq.push_back(val);

                    }
                }
            }
        }
        while (dq.front() == 0) {
            dq.pop_front();
        }
        string ans = "";
        while (!dq.empty()) {
            ans += dq.front()+'0';
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