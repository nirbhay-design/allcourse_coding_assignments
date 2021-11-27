#include <bits/stdc++.h>
using namespace std;
// super keys can be book_name and (book_id , bookname)
// book_name is the candidate key
// book_name is the primary key;
class Record{
    public:
    vector<string> v;
    Record(vector<string> vv) {
        v.resize(vv.size());
        for (int i =0;i<vv.size();i++){
            v[i] = vv[i];
        }
    }
    Record() {
        ;
    }
    void print() {
        for (int i =0;i<v.size();i++) {
            if (i == 0) {
                cout << "("<<v[i] << ", ";
            } else if (i == v.size()-1){
                cout << v[i] << ") ->";
            } else {
                cout << v[i] << ", ";
            }
        }
        // cout<<endl;
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
    int c,bs;
    LList* v;
    bucket(int b_size){
        bs = b_size;
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
    int l,sz,bs;
    vector<bucket*> dir;
    directory(int bkt_s){
        l = 0;
        sz = 1;
        bs = bkt_s;
        dir.resize(1);
    }

    int hf(string value) {
        int ans=0;
        for (int i =0;i<value.size();i++) {
            ans += (value[i]-'a') % sz;
        }
        ans %= sz;
        return (ans>0)?ans:-ans;
    }

    void rehash() {
        // cout << "a" << endl;
        l++;
        int ts = sz;
        sz *= 2;
        vector<bucket*> rh;
        rh.resize(sz);
        for (int i =0;i<ts;i++) {
            if (dir[i] == NULL) {continue;}
            node * ptr = dir[i]->v->hd;
            while (ptr != NULL) {
                vector<string> ve = ptr->r->v;
                int hv = hf(ve[0]);
                if (rh[hv] == NULL) {
                    rh[hv] = new bucket(bs);
                } 
                int cv = rh[hv]->c;
                // cout << cv << endl;
                if (cv == bs) {
                    cout << "not enough space" << endl;
                    return;
                } 
                Record * rr = new Record(ve);
                rh[hv]->v->insert(rr);
                rh[hv]->c++;
                ptr = ptr->nxt;
            }
        }
        dir.resize(sz);
        dir = rh; 
    }

    void insert(vector<string> v) {
        int hv = hf(v[0]);
        if (dir[hv] == NULL) {
            dir[hv] = new bucket(bs);
        } 
        int cv = dir[hv]->c;
        if (cv > 0) {
            node * nd = dir[hv]->v->hd;
            while (nd!=NULL) {
                if (nd->r->v[0] == v[0]) {
                    cout << "key should be unique."<< endl;
                    return;
                }
                nd = nd->nxt;
            }
        }
        if (cv == bs) {
            cout << "overflow occures at " << hv << " going for rehashing" << endl;
            rehash();
            insert(v);
            return;
        } 
        
        Record * nrd = new Record(v);
        dir[hv]->v->insert(nrd);
        dir[hv]->c++;
        cout << "record placed successfully" << endl;
    
    }

    void description() {
        cout << "bucket size : " << bs << endl;
        cout << "directory size : " << sz << endl;
        cout << "level : " << l << endl;
    }
    void print() {
        for (int i =0;i<sz;i++) {
            if (dir[i] == NULL) {cout << "NULL" << endl ;continue;}
            bucket * ptr = dir[i];
            cout << "index : " << i << " -> ";
            ptr->print();

            // cout << endl;
        }
    }
    void search(string b_id) {
        int hv = hf(b_id);

        int cr = dir[hv]->c;
        int val = 0;
        node * tmp = dir[hv]->v->hd;
        while (tmp != NULL){
            if (tmp->r->v[0] == b_id) {
                cout << "Details of the book is: "<<endl;
                tmp->r->print();
                cout << endl;
                val = 1;
                break;
            }
            tmp = tmp->nxt;
        } 
        if (val == 0) {
            cout << "no such book exists " << endl;
        }
    }
    void searchbyidx(string val,int ind,vector<int> vv, vector<vector<string>> &vvm) {
        for (int i =0;i<sz;i++) {
            if (dir[i] == NULL) continue;
            dir[i]->searchbyidx(val,ind,vv,vvm);
        }
    }
    void searchgreater(int val,int ind,vector<int> vv,vector<vector<string>> &vm) {
        for (int i =0;i<sz;i++) {
            if (dir[i] == NULL) continue;
            dir[i]->searchgreater(val,ind,vv,vm);
        }
    }
};


int main(int argc, char * argv[]) {

    directory * a = new directory(4);
    // directory * b = new directory(4);
    directory * cc = new directory(4);
    directory * d = new directory(4);

    
    // d->insert("Da_001","Da001_Sel","Damasio", "Self Comes to Mind");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    // d->insert("To_015","To015_Fel","Tolkien", "Fellowship of the Rings_Lord of the Rings");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    // d->insert("Mi_009","Mi009_Emo","Minsky", "Emotion Machine");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    // d->insert("Mi_009","Mi009_Soc","Minsky", "Society of Mind");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    // d->insert("Ra_001","Ra001_Pha","Ramachandran", "Phantoms in the Brain");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    // d->insert("Ro_015","Ro015_Fan","Rowling", "Fantastic Beasts and Where to Find Them");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    // d->insert("Ro_015","Ro015_Gob","Rowling", "Goblet of Fire_Harry Potter");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    // d->insert("Ro_015","Ro015_Pri","Rowling", "Prisoner of Azkaban_Harry Potter");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    // d->insert("Sa_001","Sa001_Wha","Safina", "What Animals Think");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    // d->insert("Wo_015","Wo015_Wod","Wodehouse", "Wodehouse at the Wicket");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
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