#include <bits/stdc++.h>
using namespace std;
// super keys can be book_name and (book_id , bookname)
// book_name is the candidate key
// book_name is the primary key;
class Record{
    public:
    string ai,bi,an,bn;
    Record(string a_id,string b_id,string a_name,string b_name) {
        ai = a_id;
        bi = b_id;
        an = a_name;
        bn = b_name;
    }
    Record() {
        ;
    }
};

class bucket{
    public:
    int bs,c;
    vector<Record*> v;
    bucket(int bk_size) { 
        bs = bk_size;
        c = 0;
        v.resize(bk_size);
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
            bucket * ptr = dir[i];
            for (int j= 0;j<ptr->c;j++) {
                string a_id = ptr->v[j]->ai;
                string b_id = ptr->v[j]->bi;
                string a_name = ptr->v[j]->an;
                string b_name = ptr->v[j]->bn;
                int hv = hf(b_id);
                if (rh[hv] == NULL) {
                    rh[hv] = new bucket(bs);
                } 
                int cv = rh[hv]->c;
                // cout << cv << endl;
                if (cv == bs) {
                    cout << "not enough space" << endl;
                } 
                else if (rh[hv]->v[cv] == NULL) {
                    rh[hv]->v[cv] = new Record(a_id,b_id,a_name,b_name);
                    rh[hv]->c++;
                }
            }
        }
        dir.resize(sz);
        dir = rh; 
    }

    void insert(string a_id,string b_id,string a_name,string b_name) {
        int hv = hf(b_id);
        if (dir[hv] == NULL) {
            dir[hv] = new bucket(bs);
        } 
        int cv = dir[hv]->c;
        if (cv == bs) {
            cout << "overflow occures at " << hv << " going for rehashing" << endl;
            rehash();
            insert(a_id,b_id,a_name,b_name);
        } 
        else if (dir[hv]->v[cv] == NULL) {
            dir[hv]->v[cv] = new Record(a_id,b_id,a_name,b_name);
            dir[hv]->c++;
            cout << "record placed successfully" << endl;
        }
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
            for (int j= 0;j<ptr->c;j++) {
                cout << "("<<ptr->v[j]->ai << " " << ptr->v[j]->bi<< " " << ptr->v[j]->an << " " << ptr->v[j]->bn << "), ";
            }

            cout << endl;
        }
    }
    void search(string b_id) {
        int hv = hf(b_id);
        int val = 0;
        for (int i = 0;i<dir[hv]->c;i++) {
            if (dir[hv]->v[i]->bi == b_id) {
                cout << "Details of the book is: "<<endl;
                cout << "("<<dir[hv]->v[i]->ai << " " << dir[hv]->v[i]->bi<< " " << dir[hv]->v[i]->an << " " << dir[hv]->v[i]->bn << "), " << endl;
                val = 1;
                // break;
            }
        }
        if (val == 0) {
            cout << "no such book exists" << endl;
        }
    }
};


int main(int argc, char * argv[]) {
    int bksz;
    cin >> bksz;
    directory * d = new directory(bksz);
    
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