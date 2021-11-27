#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    vector<pair<int,bool>> pref;
    int mp;
    bool ismp;
    node(){
        mp=-1;
        ismp =false;
    }
};


vector<node> extractdata(string s,int n) {
    vector<int> vs;
    vector<node> vss;
    int i =0;
    int t = s.length();
    while (i<t) {
        
        int ascii = s[i] -'0';
        if (s[i] == '[' || s[i] ==']' || s[i] ==',' || s[i] ==' ') {
            i++;
        } else if (ascii >=0 && ascii <= 9) {
            string value= "";
            value += s[i++];
            while (s[i] !=',' && s[i] !=']') {
                value += s[i++];
            }
            vs.push_back(stoi(value));
        }        
    }

    int sz = vs.size();
    i =0;
    int ss = n;
    while (i<sz) {
        node pr;
        while (i<ss) {
            pr.pref.push_back(make_pair(vs[i++],false));
        }
        // cout << ss << endl;
        ss = ss+n;

        vss.push_back(pr);
    }
    return vss;
}

void print(vector<node> vs,int vss) {
    int n = vs.size();
    if (vss) {
        cout << "[[";
        for (int i =0;i<n;i++) {
            if (i == n-1) {
                cout << i+n << "," << vs[i].mp << "]]";
                continue;    
            }
            cout << i+n << "," << vs[i].mp << "], [";
        }
        cout << endl;

    } else {
        cout << "[[";
        for (int i =0;i<n;i++) {
            if (i == n-1) {
                cout << i << "," << vs[i].mp << "]]";
                continue;    
            }
            cout << i << "," << vs[i].mp << "], [";
        }
        cout << endl;
    }
}

int main(){
    int n;cin>>n;
    cin.ignore();
    string s;
    getline(cin ,s);
    cin.ignore();
    string t;
    getline(cin,t);

    // cout << s << t;
    vector<node> vs;
    vector<node> vt;
    vs = extractdata(s,n);
    vt = extractdata(t,n);

    
    // print(vt);

    unordered_set<int> st;
    for (int i=0;i<n;i++) {
        st.insert(i+n);
    }

    int i =0;
    while (st.size() > 0) {
        node *p = &vs[i];
        if (p->ismp == true){i=(i+1)%n ; continue;}
        int index,flag=0,index1;
        for (int j = 0;j<n;j++) {
            if (p->pref[j].second == false) {
                flag = 1;
                index1 = j;
                index = p->pref[j].first;
                p->pref[j].second=true;break;
            }
        }
        if (flag ==0) { i=(i+1)%n  ;continue;}
        node *q = &vt[index];
        if (q->ismp == false) {
            p->pref[index1].second =true;
            p->mp = index;p->ismp = true;
            q->ismp = true;q->mp = i+n;
            st.erase(i+n);
            i = (i+1)%n;
        } else {
            // i+n -> node
            // index -> cur node
            // pref of index node
            int prf1,prf2;//index
            for (int j=0;j<n;j++) {
                if (q->pref[j].first == q->mp) {
                    prf1 = j;
                } if (q->pref[j].first == (i+n)) {
                    prf2 = j;
                }
            }
            if (prf1 > prf2) {
                // more pref to i+n
                // (i+n) erase from set 
                // q.mp put into the set;
                // changes the maps
                st.insert(q->mp);
                st.erase(i+n);
                p->mp = index;p->ismp = true;
                q->mp = (i+n);q->ismp = true;
                node* r = &vs[q->pref[prf1].first - n];
                r->mp = -1;r->ismp = false;
                i = (i+1)%n;
            } else if (prf2 > prf1) {
                // more pref to q.mp
                p->pref[index1].second = true;
                i = (i+1)%n;
            }
        }


    }
    print(vs,1);
    for (int m=0;m<n;m++) {
        for (int tt=0;tt<n;tt++) {
            vs[m].pref[tt].second = false;
            vt[m].pref[tt].second=false;
        }
        vs[m].ismp=false;vs[m].mp=-1;
        vt[m].ismp=false;vt[m].mp=-1;
    }

    // print(vs);
    // print(vt);
    st.clear();
    for (int i=0;i<n;i++) {
        st.insert(i);
    }

    i =0;
    while (st.size() > 0) {
        node *p = &vt[i];
        if (p->ismp == true){i=(i+1)%n ; continue;}
        int index,flag=0,index1;
        for (int j = 0;j<n;j++) {
            if (p->pref[j].second == false) {
                flag = 1;
                index1 = j;
                index = p->pref[j].first-n;
                p->pref[j].second=true;break;
            }
        }
        if (flag ==0) { i=(i+1)%n  ;continue;}
        node *q = &vs[index];
        if (q->ismp == false) {
            p->pref[index1].second =true;
            p->mp = index+n;p->ismp = true;
            q->ismp = true;q->mp = i;
            st.erase(i);
            i = (i+1)%n;
        } else {
            // i+n -> node
            // index -> cur node
            // pref of index node
            int prf1,prf2;//index
            for (int j=0;j<n;j++) {
                if (q->pref[j].first == q->mp) {
                    prf1 = j;
                } if (q->pref[j].first == i) {
                    prf2 = j;
                }
            }
            if (prf1 > prf2) {
                // more pref to i+n
                // (i+n) erase from set 
                // q.mp put into the set;
                // changes the maps
                st.insert(q->mp);
                st.erase(i);
                p->mp = index+n;p->ismp = true;
                q->mp = i;q->ismp = true;
                node * r = &vt[q->pref[prf1].first];
                r->mp = -1;r->ismp = false;
                i = (i+1)%n;
            } else if (prf2 > prf1) {
                // more pref to q.mp
                p->pref[index1].second = true;
                i = (i+1)%n;
            }
        }


    }

    
    print(vt,0);
    return 0;
}
/*
4
[[1,3,2,0],[3,1,0,2],[0,2,1,3],[2,0,3,1]]
[[4,6,5,7],[6,7,5,4],[5,4,7,6],[4,7,6,5]]

5
[[1,4,2,3,0], [0,3,2,1,4], [4,2,1,3,0], [0,1,3,2,4], [2,1,4,3,0]]
[[7,6,8,9,5], [5,8,9,7,6], [8,9,6,5,7], [6,9,5,7,8], [9,5,7,8,6]]
*/
