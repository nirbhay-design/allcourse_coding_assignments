#include <bits/stdc++.h>

using namespace std;


class node{
    public:
    int first,second,index;
    node(int fst,int snd,int idx) {
        first = fst; second = snd;
        index=idx;
    }
};

bool comparator(node* a,node * b) {
    if (a->second >= b->second) {
        return false;
    }
    return true;
}
class Solution{
    public:
    int n;
    node ** arr;
    Solution() {
        cin >> n;
        arr = new node*[n];

        for (int i =0;i<n;i++) {
            int a;cin >> a;
            arr[i] = new node(a,-1,i);
        }
        for (int i =0;i<n;i++) {
            int a;cin >> a;
            arr[i]->second = a;
        }
    }
    void solve() {
        sort(arr,arr+n,comparator);
        int current_lateness = (arr[0]->first-arr[0]->second <=0)?0:arr[0]->first-arr[0]->second;
        int cumulative = arr[0]->first;
        int maxmum = current_lateness;
        for (int i =1;i<n;i++) {
            int value = cumulative + arr[i]->first - arr[i]->second;
            if (value > maxmum) {
                maxmum = value;
            }
            current_lateness = (value <= 0)?0:value;
            cumulative += arr[i]->first;
        }

        cout << maxmum << endl;
        for (int i =0;i<n;i++) {
            cout << arr[i]->index << " ";
        }
    }
};


int main(int argc , char * argv[]) {
    Solution * sol = new Solution();
    sol->solve();
}

/*


5
2 3 4 2 5
3 4 1 5 6

*/