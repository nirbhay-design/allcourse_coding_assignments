#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<string,string> &a,pair<string,string> &b){
    if(a.second > b.second) return false;
    else if (a.second == b.second){
        if(a.first > b.first){
            return false;
        }
    }
    return true;
}

int main(){

    vector<string> a = {"jFK","JFK","SFO","ATL"};
    vector<string> b = {"SFO","ATL","ATL","JFK"};
    vector<pair<string,string>> v;
    for(int i =0;i<a.size();i++){
        v.push_back(pair<string,string>(a[i],b[i]));
    }
    
    sort(v.begin(),v.end(),comparator);
    
    vector<int> visited(v.size(),0);
    vector<string> ans;
    int jfk;
    for(int i =0;i<v.size();i++){
        if(v[i].first == "JFK"){
            jfk = i;
            break;
        }
    }
    
    while(true){
        cout << "entering while loop" << endl;
        if(visited[jfk] == 0)
            ans.push_back(v[jfk].first);
            ans.push_back(v[jfk].second);
            visited[jfk] = 1;
            
        for(int i =0;i<v.size();i++){
            if(v[i].first == v[jfk].second && visited[jfk] ==0){
                jfk = i;
                break;
            }
        }
        
        bool visitall = true;
        for(int i =0;i<visited.size();i++){
            if(visited[i] == 0){
                visitall = false;
            }
        }
        
        if(visitall) break;
    }
    

    for(int i =0;i<a.size();i++){
        cout << a[i] << " ";
    }

    cout << endl;
    
    return 0;
    
}
