#include <bits/stdc++.h>
using namespace std;
// super keys can be book_name and (book_id , bookname)
// book_name is the candidate key
// book_name is the primary key;
class Record{
    public:
    string bis,ai,bi,an,bn;
    Record(string a_id,string b_id,string a_name,string b_name) {
        ai = a_id;
        bi = b_id;
        an = a_name;
        bn = b_name;
    }
};

class bucket{
    public:
    int c,ld,bs;
    vector<Record*> v;
    bucket(int b_size){
        bs = b_size;
        ld = 1;
        c =0;
        v.resize(bs);
    }
};

class directory{
    public:
    int gd,bs,sz;
    vector<bucket*> dir;
    directory(int b_size){
        bs = b_size;
        gd = 1;
        sz = 2*gd;
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

        unordered_set<int> st;
        for (int i =0;i<ti.size();i++) {
            for (int j = 0;j<bkt->v.size();j++) {
                if (bkt->v[j] == NULL) {continue;}
                if (st.count(j) > 0) {continue;}
                string idx = bkt->v[j]->bis;
                string tidx = itb(ti[i]);
                if (idx.substr(0,hbkt[i]->ld) == tidx.substr(0,hbkt[i]->ld)) {
                    hbkt[i]->v[hbkt[i]->c++] = bkt->v[j]; 
                    // bkt->v[j] = NULL;
                    st.insert(j);
                    
                }
            }
        }     

        for (int i = 0;i<ti.size();i++) {
            dir[ti[i]] = hbkt[i];
        }   

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

    void insert(string a_id,string b_id,string a_name,string b_name) {
        // cout << "entering into insert:" << endl;
        // int num = hf(b_id+b_name);
        int num = hf(b_id);
        // cout << num << endl;
        int hv = num % sz;
        // cout << hv << endl;
        if (dir[hv] == NULL) {
            dir[hv] = new bucket(bs);
        }
        int cv = dir[hv]->c;
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
            insert(a_id,b_id,a_name,b_name);
        } 
        else if (dir[hv]->v[cv] == NULL) {
            dir[hv]->v[cv] = new Record(a_id,b_id,a_name,b_name);
            dir[hv]->c++;
            dir[hv]->v[cv]->bis = itb(num);
            cout << "record placed successfully at : " << hv<< endl;
        }

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
            for (int j= 0;j<ptr->c;j++) {
                // cout << "("<<ptr->v[j]->bis << "), ";
                cout << "("<<ptr->v[j]->ai << ", " << ptr->v[j]->bi<< ", " << ptr->v[j]->an << ", " << ptr->v[j]->bn << ", "<<ptr->v[j]->bis <<"), ";
            }

            cout << endl;
        }
    }

    void search(string b_id) {
        int num = hf(b_id);
        int hv = num % sz;

        int cr = (dir[hv] == NULL)?0:dir[hv]->c;
        int val = 0;
        for (int i =0;i<cr;i++) {

            if (dir[hv]->v[i]->bi == b_id ) {
                cout << "Details of the book is: "<<endl;
                cout << "("<<dir[hv]->v[i]->ai << " " << dir[hv]->v[i]->bi<< " " << dir[hv]->v[i]->an << " " << dir[hv]->v[i]->bn << "), " << endl;
                val = 1;
                // break;
            }
        } 
        if (val == 0) {
            cout << "no such book exists " << endl;
        }
    }
};


int main(int argc , char * argv[]) {
    int bk_size;
    cout << "enter bucket size : ";
    cin >> bk_size;
    directory * d = new directory(bk_size);
    
    d->insert("Da_001","Da001_Sel","Damasio", "Self Comes to Mind");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    d->insert("To_015","To015_Fel","Tolkien", "Fellowship of the Rings_Lord of the Rings");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    d->insert("Mi_009","Mi009_Emo","Minsky", "Emotion Machine");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    d->insert("Mi_009","Mi009_Soc","Minsky", "Society of Mind");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    d->insert("Ra_001","Ra001_Pha","Ramachandran", "Phantoms in the Brain");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    d->insert("Ro_015","Ro015_Fan","Rowling", "Fantastic Beasts and Where to Find Them");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    d->insert("Ro_015","Ro015_Gob","Rowling", "Goblet of Fire_Harry Potter");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    d->insert("Ro_015","Ro015_Pri","Rowling", "Prisoner of Azkaban_Harry Potter");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    d->insert("Sa_001","Sa001_Wha","Safina", "What Animals Think");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;
    d->insert("Wo_015","Wo015_Wod","Wodehouse", "Wodehouse at the Wicket");cout << "goning for next " << endl; d->description() ; cout << endl;d->print() ;cout << endl;

    while (1) {
        int n;
        string b_id;
        cout << "do you want to search(0) or insert(1) : ";
        cin >> n;
        char c = getchar();
        if (n == 0) {
            cout << "enter book_id to search: "; 
            cin >> b_id;

            d->search(b_id);    
        } else if (n == 1) {
            string ai,bi,an,bn;
            cout << "enter author id: " ;
            cin >> ai;
            cout << "enter book id: ";
            cin >> bi;
            cout << "enter author name: ";
            char c = getchar();
            getline(cin , an);
            cout << "enter book name: ";
            getline(cin , bn);
            d->insert(ai,bi,an,bn);
            cout << endl;
            d->description();
            cout << endl;
            d->print();
            cout << endl;
        }
        else {
            cout << "invalid request try again!!" << endl;
        }
    }
    return 0;
}