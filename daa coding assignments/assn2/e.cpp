#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<char,pair<int,int>> &p1,pair<char,pair<int,int>> & p2) {
    if (p1.second.second >= p2.second.second) {
        return false;
    }
    return true;
}

int main(){
    int n ; cin >> n;
    string s;
    cin.ignore();
    getline(cin,s);

    s = s.substr(1,s.length()-2);

    int i =0;
    // vector<string> inp;
    vector<pair<char,pair<int,int>>> v;
    int t = s.length();
    pair<char,pair<int,int>> per;
    int counter=0;
    while (i<t) {
        
        int ascii = s[i] -'A';
        if (s[i] == '}') {
            v.push_back(per);
            i++;
        }else if (s[i] == '{' || s[i] == '}' || s[i] ==',' || s[i] == ' ') {
            i++;
        } else if (ascii >= 0 && ascii <= 25) {
            // string seer="";
            // seer += s[i];
            // inp.push_back(seer);
            per.first = s[i++];
        } else if (ascii < 0) {
            string temp = "";
            temp += s[i++];
            while (s[i] != ',' && s[i] != '}') {
                temp += s[i++];
            }
            // cout << temp << endl;
            // inp.push_back(temp);
            if (!counter) {
                per.second.first = stoi(temp);
                counter =1;
            } else {
                per.second.second = stoi(temp);
                counter=0;
            }
        }
    }
    
    // for (int i =0;i<inp.size();i++) {
    //     cout << inp[i] << " ";
    // }

    // cout << endl; 
    // return 0;

    // while (n--) {
    //     char c;
    //     int a,b;
    //     cin >> c >> a >> b;
    //     v.push_back(make_pair(c,make_pair(a,b)));
    // }

    // for (int i =0;i<v.size();i++) {
    //     cout << v[i].first <<" "<< to_string(v[i].second.first) <<" " << to_string(v[i].second.second) << " " << endl;
    // }
    sort(v.begin(),v.end(),comparator);

    vector<char> ans;

    while (v.size()>0){
        int val = v.size();
        pair<char,pair<int,int>> comp = v[0];
        ans.push_back(comp.first);
        int i =0;
        while (i<val){
            if ( (v[i].second.first < comp.second.second) && (comp.second.first < v[i].second.second) ) {
                v.erase(v.begin()+i);
                val--;
            } else {
                i++;
            }
        }
    }

    for (int i =0;i<ans.size();i++) {
        if (i == ans.size()-1) {
            cout << ans[i];break;
        }
        cout << ans[i] << " ";
    }
    // cout<< endl;
    return 0;
}