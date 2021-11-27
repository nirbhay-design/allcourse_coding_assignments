#include <bits/stdc++.h>
using namespace std;
// super keys can be book_name and (book_id , bookname)
// book_name is the candidate key
// book_name is the primary key;
class Record{
    public:
    string author_id,book_id,author_name,book_name;
    Record * next;
    Record(string a_id,string b_id,string a_name,string b_name) {
        author_id = a_id;
        book_id = b_id;
        author_name = a_name;
        book_name = b_name;
        next = NULL;
    }
    void print() {
        cout << "author_id: " << author_id << " book_id: " << book_id << " author_name: " << author_name << " book_name: " << book_name << endl;
    }
};

// string findbook_id(string author_id , string s) {
//     string b_id = "";
//     int i =0;
//     while (author_id[i] != '_') {
//         b_id += author_id[i++];
//     }
//     i++;
//     while (i < author_id.length()) {
//         b_id += author_id[i++];
//     }
//     b_id += '_';
//     b_id += s;
//     return b_id;

// }

class RecordList{
    public:
    Record * front;
    Record * back;
    RecordList(){
        front = NULL;
        back = NULL;
    } 

    void insert(string auth_id,string bk_id,string auth_name, string bk_name) {
        Record * myrecord = new Record(auth_id,bk_id,auth_name,bk_name);
        if (front == NULL) {
            front = myrecord;
            back = myrecord;           
        } else {
            back->next = myrecord;
            back = back->next;
        }
    }

    void find(string b_id) {
        Record * temp = front;
        // string b_id = findbook_id(author_id,s);
        while (temp != NULL) {
            // cout << temp->book_id << " " << b_id << endl;
            if (temp->book_id == b_id) {
                cout << "("<<temp->book_id<<", "<<temp->author_name<<", "<<temp->book_name<<")" << endl;
            }
            temp = temp->next;
        }
    }
    void print() {
        Record * value = front;
        while (value != NULL) {
            cout << "("<<value->author_id<<", "<<value->book_id<<", "<<value->author_name<<", "<<value->book_name<<")---> ";
            value = value->next;
        }
        cout << endl;
        cout << endl;
    }
};


class Bucket{
    public:
    RecordList ** bucket;

    int sz;
    Bucket(int size){
        bucket = new RecordList*[size];
        for (int i =0;i<size;i++) {
            bucket[i] = new RecordList();
        }
        sz = size;

    }
    
    int hashFunction(int size,string s) { // string s should be a primary key
        int hashindex=0;
        for (int i =0;i<s.length();i++) {
            hashindex += (s[i]-'0') % size;
        }
        hashindex %= size;
        return (hashindex>0)?hashindex:-hashindex;
    }
    void insert_(string auth_id,string bk_id,string auth_name, string bk_name) {
        int myindex = hashFunction(sz,bk_id);
        bucket[myindex]->insert(auth_id,bk_id,auth_name,bk_name);
    }
    
    
    void show() {
        for (int i =0;i<sz;i++) {
            if (bucket[i]->front != NULL) {
                bucket[i]->print();
            }
        }
    }
    void search_(string b_id) {
        int index = hashFunction(sz,b_id);
        bucket[index]->find(b_id);
    }
    
};
int main(int argc , char * argv[]){
    cout << "choose the bucket size: ";    
    int n; cin>> n;
    
    Bucket * mybucket = new Bucket(n);
    
    mybucket->insert_("Da_001","Da001_Sel","Damasio", "Self Comes to Mind");
    mybucket->insert_("To_015","To015_Fel","Tolkien", "Fellowship of the Rings_Lord of the Rings");
    mybucket->insert_("Mi_009","Mi009_Emo","Minsky", "Emotion Machine");
    mybucket->insert_("Mi_009","Mi009_Soc","Minsky", "Society of Mind");
    mybucket->insert_("Ra_001","Ra001_Pha","Ramachandran", "Phantoms in the Brain");
    mybucket->insert_("Ro_015","Ro015_Fan","Rowling", "Fantastic Beasts and Where to Find Them");
    mybucket->insert_("Ro_015","Ro015_Gob","Rowling", "Goblet of Fire_Harry Potter");
    mybucket->insert_("Ro_015","Ro015_Pri","Rowling", "Prisoner of Azkaban_Harry Potter");
    mybucket->insert_("Sa_001","Sa001_Wha","Safina", "What Animals Think");
    mybucket->insert_("Wo_015","Wo015_Wod","Wodehouse", "Wodehouse at the Wicket");

    while (1) {
        string s1,s2;
        cout << "enter book id: " ;
        cin >> s1;
        mybucket->search_(s1);
    }
    return 0;
}