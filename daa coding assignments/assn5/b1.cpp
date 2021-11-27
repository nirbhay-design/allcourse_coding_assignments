#include <bits/stdc++.h>

using namespace std;

bool checkwin(vector<int> v,int sum ,bool p1,int init) {
    if (v.size() ==0 && sum%3 !=0) {
        // return (p1)?!p1:!p1;
        return false;
    }
    if (sum % 3 == 0 && v.size() == 0) {
        return p1;
    }
    if (sum %3 == 0 && v.size() != 0 && init !=0) {
        return p1;
    }
    if (!init) {
        init=1;
    }
    
    bool ans = false;
    for (int i =0;i<v.size();i++) {
        vector<int> vmm(v.begin(),v.end());
        int vall = vmm[i];
        vmm.erase(vmm.begin()+i);
        // if ((sum + vall)%3 == 0 && (v.size()-1) > 0) {
        //     continue;
        // } 
        ans = ans || checkwin(vmm,sum+vall,!p1,init);
    }

    return ans;
}


int main(int argc, char * argv[]) {
    
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for (int i =0;i<n;i++) {
        cin >> v[i];
    }

    bool check_win = checkwin(v,0,true,0);
    string ans =(check_win)?"true":"false";
    cout << ans;
    
    return 0;


}