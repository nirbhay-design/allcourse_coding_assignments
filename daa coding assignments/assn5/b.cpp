#include <bits/stdc++.h>


using namespace std;

class solution{
    public:
    int n;
    vector<int> v;
    solution(){
        cin >>n;
        v.resize(n);

        for (int i =0;i<n;i++) {
            cin >> v[i];
        }
    }
    bool check_win(unordered_map<int,int> mp,int limit,bool player1){
        if (limit == 0 ||mp[0] < 0 || mp[1] < 0 || mp[2] < 0) {
            return true;
        }
        if (mp[0] ==0 && mp[1]==0 || mp[2] == 0) {
            return !player1;
        }

        mp[0] -= 1;
        bool val = !check_win(mp,limit%3,!player1);
        mp[0] += 1;
        mp[1] -= 1;
        bool va = !check_win(mp,(limit+1)%3,!player1);
        mp[1] +=1;
        mp[2] -=1;
        bool ver = !check_win(mp,(limit+2)%3,!player1);
        mp[2] += 1;
        return val || va || ver;        
        
    }
    void solve(){
        unordered_map<int,int> mp;
        for (int i =0;i<v.size();i++) {
            if (mp.count(v[i]%3) >0) {
                mp[v[i]%3] += 1;
            } else {
                mp[v[i]%3] = 1;
            }
        }
        mp[0] %= 2;         
        bool ans = check_win(mp,3,true);
        string myans = (ans) ? "true" :"false";
        cout << myans;
        
    }
};


int main(int argc, char * argv[]) {
    solution * sol = new solution();
    sol->solve();
    return 0;
}




#include <bits/stdc++.h>

using namespace std;

bool checkwin(vector<int> v,int sum ,bool p1,int init) {
    if (v.size() ==0 && sum%3 !=0) {
        return (!p1)?p1:!p1;
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
    vector<int> vm(v.begin(),v.end());
    int val = vm[0];
    vm.erase(vm.begin()+0);
    bool ans = checkwin(vm,sum+val,!p1,init);
    for (int i =1;i<v.size();i++) {
        vector<int> vmm(v.begin(),v.end());
        int vall = vmm[i];
        vmm.erase(vmm.begin()+i);
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