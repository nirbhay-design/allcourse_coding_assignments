#include <bits/stdc++.h>

using namespace std;



class solution{
    public:
    int n;
    vector<int> v;
    solution(){
        cin >> n;
        v.resize(n);
        for (int i =0;i<n;i++){
            cin>>v[i];
        }
    }
    int gcd(int a,int b){
        int mn = min(a,b);
        int ans = 1;
        for (int i =mn;i>=2;i--){
            if(a%i == 0 && b%i == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
    bool belongtosame(int * arr, int a ,int b){
        return (found(arr,a) == found(arr,b));
    }
    void unionalgo(int * arr,int a,int b){
        int find1 = found(arr,a);
        int find2 = found(arr,b);

        if (find1 != find2){
            arr[find1] = find2;
        }
    }
    int found(int * arr,int a){
        return (arr[a]==a)?a:found(arr,arr[a]);
    }
    bool cansort(){
        vector<int> p(v.begin(),v.end());
        sort(p.begin(),p.end());
        int maximum = p[n-1];
        int * arr = new int[maximum+1];
        for (int i = 0;i<maximum+1;i++){
            arr[i] = i;
        }
        for (int i = 0;i<n;i++){
            for (int j = i+1;j<n;j++){
                if(gcd(v[i],v[j])>1) unionalgo(arr,v[i],v[j]);
            }
        }

        for (int i = 0;i<n;i++){
            if(!belongtosame(arr,p[i],v[i])){
                return false;
            }
        }

        return true;
        

    }
    string solve(){
        bool val = cansort();
        string ans = (val)?"true":"false";
        return ans;
    }
};


int main(int argc, char * argv[]){
    solution * sol = new solution();
    string ans = sol->solve();
    cout << ans;
    // cout << endl;
    // cout << sol->gcd(2,6);
    return 0;
}