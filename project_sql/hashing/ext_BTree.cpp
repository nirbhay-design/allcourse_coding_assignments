#include <bits/stdc++.h>

using namespace std;



class record{
    public:
    int i;
    vector<vector<string>> v;
    record(int j,vector<string> vv){
        i = j;
        v.push_back(vv);
    }
};

class node{
    public:
    vector<record *> r;
    vector<node*> v;
    int c;
    bool l;
    node (int m) {
        l = true;
        c = 0;
        v.resize(m+1);
        r.resize(m);
    }
};

bool comparator(record * &a,record * &b) {
    if (a->i >= b->i) {
        return false;
    }
    return true;
}

class Bt{
    public:
    node * rt;
    int deg;
    Bt(int d){
        rt = new node(d);
        deg = d;
    }
    node * find(int e) {
        node * tp = rt;

        while (tp != NULL) {
            int c = tp->c;
            int j = 0;
            while (j < c) {
                if (e == tp->r[j]->i) {
                    return tp->v[j];
                } else if (e > tp->r[j]->i) {
                    j++;
                } else {
                    break;
                }
            }
            tp = tp->v[j];
            
        }
        return NULL;
    }
    void findbyidx(node * tmp,string val,int ind,vector<int> vret,vector<vector<string>> &ver) {
        if (tmp == NULL) return;
        for (int i =0;i<tmp->c;i++) {
            if (tmp->r[i] == NULL) continue;
            vector<vector<string>> vvr = tmp->r[i]->v;
            vector<string> vvm;
            for (int j =0;j<vvr.size();j++){
                if (vvr[j][ind] == val) {
                    for (int k = 0;k<vret.size();k++) {
                        vvm.push_back(vvr[j][vret[k]]);
                    }
                }
            }
            if (vvm.size()>0){
                ver.push_back(vvm);

            }
        }
        for (int i = 0;i<tmp->c+1;i++) {
            if (tmp->v[i] == NULL) continue;
            findbyidx(tmp->v[i],val,ind,vret,ver);
        }
    }
    void findbyindex(string val,int ind,vector<int> vret,vector<vector<string>> &ver) {
        findbyidx(rt,val,ind,vret,ver);

    }
    void findidxgreater(node * tmp,int val,int ind,vector<int> vret,vector<vector<string>> &ver){
        if (tmp == NULL) return;
        for (int i =0;i<tmp->c;i++) {
            if (tmp->r[i] == NULL) continue;
            vector<vector<string>> vvr = tmp->r[i]->v;
            vector<string> vvm;
            for (int j =0;j<vvr.size();j++){
                if (stoi(vvr[j][ind]) > val) {
                    for (int k = 0;k<vret.size();k++) {
                        vvm.push_back(vvr[j][vret[k]]);
                    }
                }
            }
            if (vvm.size()>0){
                ver.push_back(vvm);

            }
        }
        for (int i = 0;i<tmp->c+1;i++) {
            if (tmp->v[i] == NULL) continue;
            findidxgreater(tmp->v[i],val,ind,vret,ver);
        }
    }
    void searchgreater(int val,int ind,vector<int> vret,vector<vector<string>> &ver) {
        findidxgreater(rt,val,ind,vret,ver);
    }
    void takecare(node * &t,record * &r) {
        t->r[t->c++] = r;
        sort(t->r.begin(),t->r.begin()+t->c,comparator);
    }
    pair<pair<node *,node *>,int> findip(record * &r) {
        node * p = NULL;
        node * tmp = rt;
        if (tmp->l) {
            takecare(tmp , r);
            return make_pair(make_pair(p,tmp),-1);//-1 means parent null;
        }
        while (tmp != NULL) {
            int c = tmp->c;
            int j = 0;
            while (j < c) {
                if (r->i > tmp->r[j]->i) {
                    j++;
                } else {
                    break;
                }
            }
            p = tmp;
            tmp = tmp->v[j];

            if (tmp->l) {
                takecare(tmp,r);
                return make_pair(make_pair(p,tmp),j);
            }
        }

        return make_pair(make_pair(p,tmp),-1);
    }

    pair<pair<node *,node *>,int> findpos(record * &r) {
        node * p = NULL;
        node * tmp = rt;
        if (tmp->l) {
            return make_pair(make_pair(p,tmp),-1);//-1 means parent null;
        }
        int globj = 0;
        while (tmp != NULL) {
            int c = tmp->c;
            int j = 0;
            while (j < c) {
                if (r->i > tmp->r[j]->i) {
                    j++;
                } else if(r->i < tmp->r[j]->i) {
                    p = tmp;
                    tmp = tmp->v[j];
                    globj = j;
                    break;
                } else {
                    return make_pair(make_pair(p,tmp),(tmp == rt)?-1:globj);
                }
            }
            if (j == c) {
                p = tmp;
                tmp = tmp->v[j];
                globj=j;
            }

            if (tmp->l) {
                return make_pair(make_pair(p,tmp),j);
            }
        }

        return make_pair(make_pair(p,p),-1);
    }
    pair<node*, int> getPar(node * &nd) {
        pair<pair<node *,node *>,int> p = findpos(nd->r[0]);
        pair<node * , int> ter;
        ter.first = p.first.first;
        ter.second =p.second;
        return ter;
    }

    void printNode(node * a) {
        for (int i = 0;i<a->c;i++) {
            if (a->r[i] != NULL) {
                cout << a->r[i]->i << " ";

            } else {
                cout << "NULL" << endl;
            }
        }
        cout << endl;
    }
    void split(node * &ch,node * &pr,int ind) {
        if (pr == NULL) {
            // 3 nodes; overflow at root
            node * nrt = new node(deg);
            node * a = new node(deg);
            node * b = new node(deg);
            nrt->l = false;
            if (!ch->l) {
                a->l = false;
                b->l = false;
            }
            int sz2 = deg/2;
            record * elem = ch->r[sz2];
            
            while (a->c <= sz2-1) {
                a->r[a->c] = ch->r[a->c];
                a->c++;
            }
            
            while (b->c < (deg-sz2-1)) {
                b->r[b->c] = ch->r[sz2+1+b->c];
                b->c++;
            }
            // int t = 0;
            for (int d = 0;d<= sz2;d++) {
                a->v[d] = ch->v[d];
            }

            for (int d = sz2+1;d<=deg ;d++) {
                b->v[d-sz2-1] = ch->v[d];
            }
            
            rt = nrt;
            rt->r[rt->c++] = elem;
            rt->v[0] = a;
            rt->v[1] = b;
            
        } else {
            // 2 nodes;
            node * a = new node(deg);
            node * b = new node(deg);
            if (!ch->l) {
                a->l = false;
                b->l = false;
            }
            
            // pr->v[ind] = NULL;

            int sz2 = deg/2;
            record * elem = ch->r[sz2];
            
            while (a->c <= sz2-1) {
                a->r[a->c] = ch->r[a->c];
                a->c++;
            }

            while (b->c < (deg-sz2-1)) {
                b->r[b->c] = ch->r[sz2+1+b->c];
                b->c++;
            }
            
            for (int d = 0;d<= sz2;d++) {
                a->v[d] = ch->v[d];
            }

            for (int d = sz2+1;d<=deg ;d++) {
                b->v[d-sz2-1] = ch->v[d];
            }
            // shift the pr->v from ind + 1
            if (ind < deg - 1) {
                node * mynd = pr->v[ind + 1];
                for (int d = ind+1;d<deg;d++) {
                    if (pr->v[d] == NULL) {
                        pr->v[d] = mynd;
                        break;
                    }
                    node * pnd = pr->v[d+1];
                    pr->v[d+1] = mynd; 
                    mynd = pnd;
                }
            }

            takecare(pr,elem);
            pr->v[ind] = a;
            pr->v[ind + 1] = b;


            // if overflow -> split 
            if (pr-> c == deg) {
                pair<node *,int> pp = getPar(pr);
                split(pr,pp.first,pp.second);
            }
        }
    }

    pair<node *,int> check_dup(int num){
        node * tmp = rt;
        while (tmp != NULL) {
            int c = tmp->c;
            int j = 0;
            while (j < c) {
                if (num > tmp->r[j]->i) {
                    j++;
                } else if (num < tmp->r[j]->i) {
                    tmp = tmp->v[j];
                    break;
                } else {
                    return make_pair(tmp,j);
                }
            }
            if(j == c) {
                tmp = tmp->v[j];
            }
        }
        return make_pair(tmp,-1);
    }
    void put(int n,vector<string> vv) {
        pair<node *,int> nnd = check_dup(n);
        if (nnd.first != NULL) {
            nnd.first->r[nnd.second]->v.push_back(vv);
            return;
        }
        record * r = new record(n,vv);
        pair<pair<node *,node *>,int> tmp;
        tmp = findip(r);
        node * p,* ch;
        p = tmp.first.first;
        ch = tmp.first.second;

        if (ch->l) {
            // cout << "leaf confirmed " << endl;
            int c=  ch->c;
            if (c == deg) {
                // cout << "overflow occures\n" ;
                split (ch,p,tmp.second);
            }
        }
    }

    void lvlorder() {
        node * myrt = rt;
        queue <node *> q;
        q.push(myrt);
        while (!q.empty()) {
            node * nd = q.front();q.pop();
            // cout << "popping : " << nd->r[0]->i << endl;
            for (int i =0;i<nd->c;i++) {
                if (nd->r[i] != NULL) {
                    cout << nd->r[i]->i << " ";

                }
            }
            // cout << endl;

            for (int j = 0;j<=deg;j++) {
                if (nd->v[j] != NULL) {
                    // cout << "pushing node :" << j << endl;
                    q.push(nd->v[j]);
                }
            }
        }

        cout << endl;
    }
};


class extHashing{
    public:
    int gd;
    vector<Bt*> v;
    int maxdeg;
    extHashing(int glob_dir,int deg) {
        gd = glob_dir;
        v.resize(gd);
        maxdeg = deg;
        for (int i =0;i<gd;i++) {
            v[i] = new Bt(maxdeg);
        }
    }
    int hf(string s) {
        int ans = 0;
        for (int i =0;i<s.length();i++) {
            ans += s[i] - 'a';
        }
        return (ans>0)?ans:-ans;
    }
    void insert(vector<string> vv) {
        int val = hf(vv[0]);
        int hv = val % gd;
        v[hv]->put(val,vv);
    }

    void search(string ss) {
        int val = hf(ss);
        int hv = val % gd;
        pair<node * ,int> ver = v[hv]->check_dup(val);
        vector<vector<string>> vvv = ver.first->r[ver.second]->v;
        for (int i =0;i<vvv.size();i++) {
            for (int j =0;j<vvv[i].size();j++) {
                cout << vvv[i][j] << " ";
            }
            cout << endl;
        }
    }

    void searchbyidx(string val,int ind,vector<int> vret,vector<vector<string>> &ver) {
        for (int i =0;i<gd;i++) {
            if (v[i] == NULL) continue;
            v[i]->findbyindex(val,ind,vret,ver);
        }
    }
    void searchgreater(int val,int ind,vector<int> vret,vector<vector<string>> &ver) {
        for (int i =0;i<gd;i++) {
            if (v[i] == NULL) continue;
            v[i]->searchgreater(val,ind,vret,ver);
        }
    }
};


int main(int argc, char * argv[]) {
    // int m;cout << "enter degree: ";cin >> m;
    extHashing * a = new extHashing(5,3);
    // extHashing * b = new extHashing(5,3);
    extHashing * cc = new extHashing(5,4);
    extHashing * d = new extHashing(5,3);

    // while (true) {
    //     int n;
    //     cout << "query_run(0) or Insert(1): ";cin >> n;
    //     if (n == 1){
    //         vector<string> v1(3);
    //         vector<string> v2(2);
    //         vector<string> v3(3);
    //         vector<string> v4(3);
    //         cout << "enter book_id: ";
    //         cin >> v1[0];
    //         v3[0] = v1[0]; 
    //         cout << "enter author_id: ";
    //         cin >> v1[1];
    //         v2[0] = v1[1];
    //         cout << "enter purchase date: ";
    //         cin >> v3[1];
    //         cout << "enter number of copies of book: ";
    //         cin >> v3[2];
    //         cout << "enter book_name: ";
    //         char c = getchar();
    //         getline(cin , v1[2]);
    //         cout << "enter author_name: ";
    //         getline(cin ,v2[1]);
    //         v4[0] = v1[1];
    //         v4[1] = v1[0];
    //         v4[2] = v1[2];
    //         a->insert(v1);
    //         b->insert(v4);
    //         cc->insert(v2);
    //         d->insert(v3);
    //     } else if (n == 0) {

    //     }
    // }
    while (true) {
        int n;
        cout << "query_run(0) or Insert(1): ";cin >> n;
        if (n == 1){
            vector<string> v1(3);
            vector<string> v2(2);
            vector<string> v3(3);
            // vector<string> v4(3);
            cout << "enter book_id: ";
            cin >> v1[0];
            v3[0] = v1[0]; 
            cout << "enter author_id: ";
            cin >> v1[1];
            v2[0] = v1[1];
            cout << "enter purchase date: ";
            cin >> v3[1];
            cout << "enter number of copies of book: ";
            cin >> v3[2];
            cout << "enter book_name: ";
            char c = getchar();
            getline(cin , v1[2]);
            cout << "enter author_name: ";
            getline(cin ,v2[1]);
            // v4[0] = v1[1];
            // v4[1] = v1[0];
            // v4[2] = v1[2];
            a->insert(v1);
            // b->insert(v4);
            cc->insert(v2);
            d->insert(v3);
        } else if (n == 0) {
            cout << "for query 1 enter author name: ";
            char cer= getchar();
            string l;
            getline(cin,l);
            vector<vector<string>> vv1,vv2;
            cc->searchbyidx(l,1,{0},vv1);
            for (int m = 0;m<vv1.size();m++) {
                a->searchbyidx(vv1[m][0],1,{2},vv2);
            }
            for (int m = 0;m<vv2.size();m++){
                cout << vv2[m][0] << endl;
            }

            vv1.clear();
            vv2.clear();
            cout << "for query 3 enter the number of copies: ";
            int val;
            cin >> val;
            d->searchgreater(val,2,{0},vv1);
            for (int m = 0;m<vv1.size();m++) {
                a->searchbyidx(vv1[m][0],0,{0,2},vv2);
            }
            for (int m = 0;m<vv2.size();m++){
                for (int t=0;t<vv2[m].size();t++){
                    cout << vv2[m][t] << " ";
                }
                cout << endl;
            }
            cout << "for query 4 enter date of purchase: ";

            string o;
            char corr = getchar();
            cin >> o;
            vv1.clear();
            vv2.clear();
            d->searchbyidx(o,1,{0},vv1);
            for (int m = 0;m<vv1.size();m++) {
                a->searchbyidx(vv1[m][0],0,{0,2},vv2);
            }
            for (int m = 0;m<vv2.size();m++){
                for (int t=0;t<vv2[m].size();t++){
                    cout << vv2[m][t] << " ";
                }
                cout << endl;
            }
        }
    }
    // while(true) {
    //     int n;
    //     cout << "search (0) or Insert(1): ";
    //     cin >>n;
    //     if (n == 0) {
    //         string id;
    //         cin >> id;
    //         vector<vector<string>> vvm;
    //         cc->searchbyidx(id,1,{0},vvm);
    //         for (int i =0;i<vvm.size();i++) {
    //             for (int j =0;j<vvm[i].size();j++) {
    //                 cout << vvm[i][j] << endl;
    //             }
    //         }
    //     } else {
    //         vector<string> s;
    //         s.resize(2);
    //         cin>>s[0] >> s[1];
    //         cc->insert(s);
    //     }
    // }
    // t->put(6);
    // t->put(3);
    // t->put(9);
    // t->put(10);
    // t->put(4);
    // t->put(5);
    // t->put(11);
    // t->put(12);
    // t->put(13);
    // t->put(14);

    // t->lvlorder();
    return 0;
}