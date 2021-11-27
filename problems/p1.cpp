#include<bits/stdc++.h>

using namespace std;


bool comparator(pair<string,string> &a,pair<string,string> & b){
    if(a.second > b.second) return false;
    else if ( a. second == b.second){
        if(a.first > b.first){
            return false;
        }
    }
    return true;
}

void solve(vector<string> &a,vector<string> &b){
    vector<pair<string,string>> v;

    for(int i = 0;i<a.size();i++){
        v.push_back(pair<string,string>(a[i],b[i]));
    }

    sort(v.begin(),v.end(),comparator);

    for(int i = 0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << endl;
    }    
    
}


int main(){
    vector<string> a = {"jFK","JFK","SFO","ATL"};
    vector<string> b = {"SFO","ATL","ATL","JFK"};
    solve(a,b);
    return 0;
}

