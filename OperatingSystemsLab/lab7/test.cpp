#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> v; 
    v.resize(5);
    for (int i =0;i<5;i++) {
        v[i] = i+1;
    }
    cout << v.size() << endl;
    for (int i =0;i<5;i++) {
        cout << v[i] << endl;
    }


    v.clear();
    v.resize(5);
    cout << v.size() << endl;
    for (int i =0;i<5;i++) {
        cout << v[i] << endl;
    }
    return 0;
}