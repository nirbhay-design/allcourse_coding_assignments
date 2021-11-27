#include <bits/stdc++.h>
using namespace std;
// super keys can be book_name and (book_id , bookname)
// book_name is the candidate key
// book_name is the primary key;
class Record{
    public:
    vector<string> v;
    string bis;
    Record(int n,vector<string> vv) {
        v.resize(n);
        for (int i = 0;i<n;i++) {
            v[i] = vv[i];
        }
    }
    void print() {
        for (int i =0;i<v.size();i++) {
            if (i == 0) {
                cout << "("<<v[i] << ", ";
            } else {
                cout << v[i] << ", ";
            }
        }
        cout<<bis<<") -> ";
    }
};

class node{
    public:
    Record*r;
    node * nxt;
    node(Record * rr) {
        r = rr;
        nxt=NULL;
    }
};

class LList{
    public:
    node * hd,*tl;
    int len;
    LList() {
        hd = NULL;
        tl = NULL;
        len = 0;
    }
    void insert(Record *r) {
        node * nd = new node (r);
        len++;
        if (hd == NULL) {
            hd = nd;
            tl = nd;
        } else {
            tl->nxt = nd;
            tl = tl->nxt;
        }
    }
};

class bucket{
    public:
    int c,ld,bs;
    LList* v;
    bucket(int b_size){
        bs = b_size;
        ld = 1;
        c =0;
        v = new LList();
    }
    void print(){
        node * tmp = v->hd;
        while (tmp != NULL) {
            tmp->r->print();
            tmp= tmp->nxt;
        }
        cout << endl;
    }
    void sbi(LList*tmp,string val,int ind,vector<int> ver,vector<vector<string>> & vvm) {
        node * ndd = tmp->hd;
        while (ndd != NULL) {
            vector<string> vvr = ndd->r->v;
            vector<string> vor;
            if (vvr[ind] == val) {
                for(int i =0;i<ver.size();i++) {
                    vor.push_back(vvr[ver[i]]);
                }
            }
            if (vor.size()>0) {
                vvm.push_back(vor);

            }
            ndd = ndd->nxt;
        }
    }
    void searchbyidx(string val,int ind,vector<int> ver,vector<vector<string>> &vvm) {
        return sbi(v,val,ind,ver,vvm);
    }
    void sbig(LList*tmp,int val,int ind,vector<int> ver,vector<vector<string>> &vvm) {
        node * ndd = tmp->hd;
        while (ndd != NULL) {
            vector<string> vvr = ndd->r->v;
            vector<string> vor;
            if (stoi(vvr[ind]) > val) {
                for(int i =0;i<ver.size();i++) {
                    vor.push_back(vvr[ver[i]]);
                }
            }
            if (vor.size()>0) {
                vvm.push_back(vor);

            }
            ndd = ndd->nxt;
        }
    }
    void searchgreater(int val,int ind,vector<int> ver,vector<vector<string>> &vvm) {
        sbig(v,val,ind,ver,vvm);
    }
};

class directory{
    public:
    int gd,bs,sz,rn;
    vector<bucket*> dir;
    directory(int b_size,int n){
        bs = b_size;
        gd = 1;
        sz = 2*gd;
        rn = n;
        dir.resize(sz);
    }

    int hf(string value) {
        int ans=0;
        for (int i =0;i<value.size();i++) {
            ans += (value[i]-'a');
        }
        return (ans>0)?ans:-ans;
    }

    void split(int hv) {
        string b = itb(hv);
        dir[hv]->ld++;
        bucket * bkt = dir[hv];
        vector<int> ti;
        for (int i =0;i<sz;i++) {
            if (dir[i] == NULL) {continue;}
            if (dir[i] == bkt) {ti.push_back(i);}
        }

        vector<bucket*> hbkt;
        hbkt.resize(ti.size());
        for (int i =0;i<ti.size();i++) {
            hbkt[i] = new bucket(bs);
            hbkt[i]->ld = dir[hv]->ld;
        }
        // for (int i =0;i<ti.size();i++) {
        //     cout << ti[i] << " ";
        // }
        // cout << endl;

        // for (int i =0;i<ti.size();i++) {
        //     cout << hbkt[i]->c << " ";
        // }
        // cout << endl;
        unordered_set<int> st;
        for (int i =0;i<ti.size();i++) {
            node * nd = bkt->v->hd;
            int j =0;
            while (nd!=NULL) {
                if (nd->r == NULL) {nd=nd->nxt;j++;continue;}
                if (st.count(j) > 0) {nd=nd->nxt;j++;continue;}
                string idx = nd->r->bis;
                string tidx = itb(ti[i]);
                if (idx.substr(0,hbkt[i]->ld) == tidx.substr(0,hbkt[i]->ld)) {
                    hbkt[i]->v->insert(nd->r);
                    hbkt[i]->c++; 
                    // bkt->v[j] = NULL;
                    st.insert(j);
                    
                }
                nd=nd->nxt;
                j++;
            }
        }     

        for (int i = 0;i<ti.size();i++) {
            dir[ti[i]] = hbkt[i];
        }
        // print();


        // for (int i =0;i<ti.size();i++) {
        //     int i1 = dir[ti[i]]->ld;
        //     string binary = itb(ti[i]);
        //     string binary1 = mt->bis;
        //     if (binary.substr(0,i1) == binary1.substr(0,i1)) {
        //         dir[ti[i]]->v[dir[ti[i]]->c++] = mt;
        //     }
        // }

    }
    void expand(int hv) {
        string b = itb(hv);
        // dir[hv]->ld++;
        gd++;
        int ps = sz;
        sz *= 2;
        dir.resize(sz);

        // first handle where pointer manipulation is required
        for (int i =0;i<sz;i++) {
            // if (i == hv) {continue;}
            if (dir[i] == NULL) {continue;}
            int t = i;
            string tt = itb(t);
            // cout << "b" << endl;
            int tld = dir[t]->ld;
            for (int j = t+1;j<sz;j++) {
                // cout<< "c" << endl;
                string ttt = itb(j);
                if (tt.substr(0,tld) == ttt.substr(0,tld)) {
                    // cout << "d" << endl;
                    dir[j] = dir[t];
                }
            }
        }

        // handle collision
        // cout << "a" << endl;
        split(hv);
        // bucket* b1= new bucket(bs);
        // bucket *b2 = new bucket(bs);

        // bucket * tmp = dir[hv];
        // for (int i = 0;i<) {

        // }




    }

    void insert(vector<string> vv) {
        // cout << "entering into insert:" << endl;
        // int num = hf(b_id+b_name);
        int num = hf(vv[0]);//vv[0] will always be the index key
        // cout << num << endl;
        int hv = num % sz;
        // cout << hv << endl;
        if (dir[hv] == NULL) {
            dir[hv] = new bucket(bs);
        }
        int cv = dir[hv]->c;
        if (cv > 0) {
            node * nd = dir[hv]->v->hd;
            while (nd!=NULL) {
                if (nd->r->v[0] == vv[0]) {
                    cout << "key should be unique."<< endl;
                    return;
                }
                nd = nd->nxt;
            }
        }
        if (cv == bs) {
            cout << "overflow occures at " << hv << endl;
            // rehash();
            // Record * tp = new Record(a_id,b_id,a_name,b_name);
            // tp->bis = itb(num);
            if (dir[hv]->ld < gd) {
                cout << "splitting " << endl;
                split(hv);
            }
            else {
                cout << "expanding" << endl;
                expand(hv);
            }
            insert(vv);
            return;
        } 
        
        Record * myrec = new Record(vv.size(),vv);
        dir[hv]->v->insert(myrec);
        dir[hv]->c++;
        dir[hv]->v->tl->r->bis = itb(num);
        cout << "record placed successfully at : " << hv<< endl;
    }
    string itb(int n) {
        int a = n;
        string s = "";
        while (a > 0) {
            s += a % 2 + '0'; 
            a = a / 2;
        }
        // cout << s.length() << endl;
        while (s.length() != 16) {
            s += '0';
        }
        return s;
    }

    int bti(string value) {
        int count =0;
        int ans = 0;
        for (int i =0;i<value.length();i++) {
            ans += (value.at(i) == '1')?pow(2,count):0;
            count++;
        }
        return ans; 
    }

    void description() {
        cout << "bucket size : " << bs << endl;
        cout << "directory size : " << sz << endl;
        cout << "gd : " << gd << endl;
    }
    void print() {
        for (int i =0;i<sz;i++) {
            if (dir[i] == NULL) {cout << "NULL" << endl ;continue;}
            bucket * ptr = dir[i];
            cout << "index : " << i << "("<<ptr->ld<< ") -> ";
            ptr->print();

            // cout << endl;
        }
    }

    void search(string b_id) {
        int num = hf(b_id);
        int hv = num % sz;

        int cr = dir[hv]->c;
        int val = 0;
        node * tmp = dir[hv]->v->hd;
        while (tmp != NULL){
            if (tmp->r->v[0] == b_id) {
                cout << "Details of the book is: "<<endl;
                tmp->r->print();
                val = 1;
                break;
            }
            tmp = tmp->nxt;
        } 
        if (val == 0) {
            cout << "no such book exists " << endl;
        }

    }
    void searchbyidx(string val,int ind,vector<int> vv, vector<vector<string>> &vvm){
        // time_t start,end;
        // time(&start);
        for (int i =0;i<sz;i++) {
            if (dir[i] == NULL) continue;
            dir[i]->searchbyidx(val,ind,vv,vvm);
        }
        // time(&end);
        // double timeer = end - start;
        // cout << "time takein: "<< timeer << setprecision(12) << endl;
    }

    void searchgreater(int val,int ind,vector<int> vv,vector<vector<string>> &vm) {
        for (int i =0;i<sz;i++) {
            if (dir[i] == NULL) continue;
            dir[i]->searchgreater(val,ind,vv,vm);
        }
    }
};


int main(int argc , char * argv[]) {
    directory * a = new directory(4,3);
    // directory * b = new directory(4,3);
    directory * cc = new directory(4,2);
    directory * d = new directory(4,3);
    
    // d->insert({"abc_123", "abc"});
    // d->insert({"abc_321","abc_2"});
    // d->insert({"abc_213","abc_2"});
    // d->insert({"abc_132","abc_1"});
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
    // while (1) {
    //     int n;
    //     string b_id;
    //     cout << "do you want to search(0) or insert(1) : ";
    //     cin >> n;
    //     char c = getchar();
    //     if (n == 0) {
    //         cout << "enter book_id to search: "; 
    //         cin >> b_id;

    //         d->search(b_id);    
    //     } else if (n == 1) {
    //         vector<string> vv(2);
    //         // string ai,bi;
    //         cout << "enter book id: " ;
    //         cin >> vv[0];
    //         cout << "enter author id: ";
    //         cin >> vv[1];
    //         d->insert(vv);
    //         // cout << endl;
    //         d->description();
    //         // cout << endl;
    //         d->print();
    //         // cout << endl;
    //     }
    //     else {
    //         // cout << "invalid request try again!!" << endl;
    //         break;
    //     }
    // }
    // while (1) {
    //     int n;
    //     string b_id;
    //     cout << "do you want to search(0) or insert(1) : ";
    //     cin >> n;
    //     if (n == 0) {
    //         cout << "enter book_id to search: "; 
    //         cin >> b_id;
    //         vector<vector<string>> vor;
    //         cc->searchbyidx(b_id,1,{0,1},vor);    
    //         for (int i =0;i<vor.size();i++) {
    //             for (int j = 0;j<vor[i].size();j++) {
    //                 cout << vor[i][j] << " ";
    //             }
    //             cout << endl;
    //         }
    //     } else if (n == 1) {
    //         vector<string> vv;
    //         vv.resize(2);
    //         // cout << "enter book id: " ;
    //         cin >> vv[0];
    //         // cout << "enter author id: ";
    //         cin >> vv[1];
            
    //         cc->insert(vv);
    //         // cout << endl;
    //         // d->description();
    //         // cout << endl;
    //         // d->print();
    //         // cout << endl;
    //     }
    //     else {
    //         cout << "invalid request try again!!" << endl;
    //     }
    // }
    return 0;
}



