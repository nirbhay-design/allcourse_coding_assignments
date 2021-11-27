#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int n;
    int ** mat1;
    int ** mat2;
    int ** res;
    Solution() {
        cin >> n;
        mat1 = new int*[n];
        mat2 = new int*[n];
        for (int i =0;i<n;i++) {
            mat1[i] = new int[n];
            mat2[i] = new int[n];
        }
        for (int i =0;i<n;i++) {
            for (int j =0;j<n;j++) {
                cin >> mat1[i][j];
            }
        }
        for (int i =0;i<n;i++) {
            for (int j =0;j<n;j++) {
                cin >> mat2[i][j];
            }
        }
        res = new int*[n];
        for (int i =0;i<n;i++) {
            res[i] = new int[n];
            for (int j = 0;j<n;j++) {
                res[i][j] = 0;
            }
        }                
    }

    void pe(vector<vector<int>> & l,int rl,int cl,int ** mat) {
        
    }

    void mult(int i1,int mid1,int i2,int j1,int mid2,int j2) {
        int ra=mid1-i1+1,ca=mid2-j1+1;
        int rb=ra,cb=j2-mid2;
        int rc=i2-mid1,cc=ca;
        int rd=rc,cd=cb;
        int re=ra,ce=ca;
        int rf=rb,cf=cb;
        int rg=rc,cg=cc;
        int rh=rd,ch=cd;

        vector<vector<int>> a(ra,vector<int>(ca,0));
        vector<vector<int>> b(rb,vector<int>(cb,0));
        vector<vector<int>> c(rc,vector<int>(cc,0));
        vector<vector<int>> d(rd,vector<int>(cd,0));
        vector<vector<int>> e(ra,vector<int>(ca,0));
        vector<vector<int>> f(rb,vector<int>(cb,0));
        vector<vector<int>> g(rc,vector<int>(cc,0));
        vector<vector<int>> h(rd,vector<int>(cd,0));


    }
    void mat_mul(int i1,int i2,int j1,int j2){
        if (i1 < i2 && j1 < j2) {
            int mid1 = (i1 + i2)/2;
            int mid2 = (j1 + j2)/2; 
            mat_mul(i1,mid1,j1,mid2);//a
            mat_mul(i1,mid1,mid2+1,j2);//b
            mat_mul(mid1+1,i2,j1,mid2);//c
            mat_mul(mid1+1,i2,mid2,j2);//d
            mult(i1,mid1,i2,j1,mid2+1,j2);
        }
    }

    void solve() {
        mat_mul(0,n-1,0,n-1);
        for (int i =0;i<n;i++) {
            for (int j = 0;j<n;j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main(int argc , char * argv[]) {
    Solution * sol = new Solution();
    sol->solve();
}

/*
{101, 645, 304, 456, 925, 849},{ 466, 846, 48, 648, 830, 547},{ 384, 628, 649, 283, 846, 925},{ 482, 638, 429, 485, 928, 384},{ 292, 846, 939, 649, 992, 729},{ 935, 946, 294, 946, 452, 739 }
{639, 739, 739, 657, 796, 689},{ 884, 859, 357, 479, 547, 987},{ 787, 578, 668, 568, 576, 568},{ 577, 786, 656, 764, 85,768},{	764,857,856,668,868,574},{	768,876,657,987,574,876 }

*/