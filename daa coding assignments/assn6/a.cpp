#include <bits/stdc++.h>

using namespace std;

class solution{
    public:
    string s;
    solution(){
        getline(cin,s);
    }
    bool valid(string ss){
        int nhyphen=0,nexcl=0,ndot=0,ncomma=0,ndigit=0;
        for (int i =0;i<ss.length();i++){
            if (ss[i] == '!'){
                nexcl++;
            }else if(ss[i] == '.'){
                ndot++;
            }else if(ss[i] == ','){
                ncomma++;
            }else if(ss[i] == '-'){
                nhyphen++;
            }else if(ss[i]>='0' && ss[i]<='9'){
                ndigit++;
            }
        }
        if(ndigit){
            return false;
        }
        // cout << "d\n";
        if(nhyphen){
            if (nhyphen >1) return false;
            if(ss[0] == '-' || ss[ss.length()-1]=='-'){
                return false;
            }
        }
        // cout << "h\n";
        if(ncomma+ndot+nexcl > 1){
            return false;
        } else{
            if (ncomma +ndot +nexcl == 0){
                return true; 
            }
            if (ss[ss.length()-1] != '!' && ss[ss.length()-1] != '.' && ss[ss.length()-1] != ','){
                return false;
            } 
        }
        // cout << "i\n";
        return true;
    }
    int solve(){
        int n = s.length();
        string temp = "";
        int i = 0;
        int ans = 0;
        vector<string> v;
        while (i <n){
            if (s[i] == ' '){
                // process;
                if (temp == ""){
                    i++;continue;
                }
                if (valid(temp)){
                    v.push_back(temp);
                    ans++;
                }
                temp = "";

            }else {
                temp += s[i];
            }
            i++;
        }
        if (temp != ""){
            v.push_back(temp);
            if (valid(temp)){
                ans++;
                temp = "";
            }
        }
        // for (int i =0;i<v.size();i++){
        //     cout << v[i] << " ";
        // }
        // cout << endl;
        return ans;
    }

};


int main(int argc, char * argv[]){
    solution * sol = new solution();
    int ans = sol->solve();
    cout << ans;
    return 0;
}