#include <bits/stdc++.h>

using namespace std;

void calculate(vector<int> v, int sum , int ind,vector<int> ver){
    
    if (ind >= v.size()) {

        printf("sum is : %d\n",sum);
        printf("array is: \n");
        for (int j:ver) {
            cout << j << " ";
        }
        cout << endl;
        return ;
    }

    vector<int> ver1(ver.begin(),ver.end()),ver2(ver.begin(),ver.end());
    ver1.push_back(v[ind]);
    calculate(v,sum+v[ind],ind+2,ver1);
    if (ind + 1 <= v.size()-1){
        ver2.push_back(v[ind+1]);
        calculate(v,sum+v[ind+1],ind+2,ver2);
    }

}

int main(int argc, char * argv[]) {
    
    vector<int> v = {1,2,3,4,5,6};

    calculate(v,0,0,{});
    
    
    return 0;


}