#include <bits/stdc++.h>

using namespace std;
bool checkwin(vector<int> v, int sum, bool p1, int init) {
    bool left = false;
    for (int i =0;i<v.size();i++) {
        if (v[i] != 0) {
            left=true;
        }
    }
    if (left) {
        if (sum %3 ==0 && init) {
            return p1;
        }
        if (!init) {
            init = 1;
        }
        bool ans = false;
        for (int i =0;i<v.size();i++) {
            if (v[i] != 0) {
                if ((sum + i)%3!=0) {
                    v[i]--;
                    ans = ans || checkwin(v,(sum+i)%3,!p1,init);
                    v[i]++;
                } else {
                    int s = v[0] + v[1] + v[2];
                    if (s == v[i]){
                        return !p1;
                    }

                }
            }
        }
        return ans;
    }

    else {
        if (sum %3==0){
            return p1;         
        } else {
            return false;
        }
    }

   
}

int main(int argc, char * argv[]) {
    
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    vector<int> vv;
    vv.resize(3);
    for (int i =0;i<n;i++) {
        cin >> v[i];
        vv[v[i]%3] += 1;
    }
    vv[0] %= 2;
    // for (auto x:vv){
    //     cout << x << " ";
    // }
    // cout << endl;


    bool check_win = checkwin(vv,0,true,0);
    string ans =(check_win)?"true":"false";
    cout << ans;


    return 0;
}

/*
[77,74,12,63,95,23,19,91,48,87,26,22,21,30,41,10,22,80,14,36,62,29,13,3,15,47,71,1,95,21,43,84,62,70,10,86,70,9,38,30,51,32,75,87,73,8,54,64,35,22,68,75,4,59,69,82,27,9,20,32,64,59,58,48,32,21,15,20,75]


*/