#include <bits/stdc++.h>

using namespace std;

class Tuple{
    public:
    string hashbinary;
    string book_id,author_id,book_name,author_name;
    Tuple(string bk_id,string auth_id,string bk_name,string auth_name,string hash) {
        book_id = bk_id;
        author_id = auth_id;
        book_name = bk_name;
        author_name = auth_name;
        hashbinary = hash;
    }    
};

class bucket{
    public:
    int counter,bucket_size,depth;
    string endingwith;    
    Tuple ** arr;
    bucket(int n) {
        bucket_size = n;
        counter = 0;
        depth = 1;
        arr = new Tuple*[n];
        for (int i =0;i<bucket_size;i++) {
            arr[i] = NULL;
        } 
    }
};

class directory{
    public:
    bucket ** arr;
    int sz_ofarr,bs;
    directory(int bkt_size) {
        sz_ofarr = 2;
        bs = bkt_size;
        arr = (bucket **) malloc(sizeof(bucket*) * sz_ofarr);
        for (int i =0;i<sz_ofarr;i++) {
            arr[i] = new bucket(bkt_size);
            arr[i]->endingwith = i+'0';
        }
    }

    int to_number(int a,int b,string bk_name) {
        int to_number;
        for (int i =0;i<bk_name.length();i++) {
            to_number += (a*(bk_name[i]-'a') + b) % sz_ofarr; 
        }
        to_number %= sz_ofarr;
        return to_number; 
    }

    int hash_string(string bk_name) {
        return to_number(2,3,bk_name);
    }
    void insert(string auth_id,string book_id,string auth_name,string bk_name) {
        int hashind = hash_string(bk_name);
        string bin = int_to_bin(hashind);
        Tuple * tpl = new Tuple(book_id,auth_id,bk_name,auth_name,bin);
        if (arr[hashind]->counter < bs) {
            arr[hashind]->arr[arr[hashind]->counter++] = tpl;
        } else {
            int prevd = arr[hashind]->depth++;
            sz_ofarr *= 2;
            arr = (bucket **) realloc((void *) arr,sizeof(bucket *)*sz_ofarr);
            for (int i =0;i<sz_ofarr/2;i++) {
                arr[i]->endingwith = '0' + arr[i]->endingwith;
            }
            for (int i = sz_ofarr/2;i<sz_ofarr;i++) {
                arr[i]->endingwith = '1' + arr[i]->endingwith;
            }

            arr[hashind]->depth++;

            for (int i =0;i<sz_ofarr;i++) {
                if (arr[i]->depth <= prevd) {
                    
                }
            }



        }


    }

    void search(string bk_name) {
        ;
    }
    string int_to_bin(int number) {
        int a = number;
        string s = "";
        while (a > 0) {
            s += a % 2 + '0'; 
            a = a / 2;
        }
        while (s.length() != 8) {
            s += '0';
        }
        return s;
    }

    int bin_to_int(string value) {
        int count =0;
        int ans = 0;
        for (int i =0;i<value.length();i++) {
            ans += (value.at(i) == '1')?pow(2,count):0;
            count++;
        }
        return ans; 
    }
};

int main(int argc , char * argv[]) {
    
    directory dir(4);

    string as = dir.int_to_bin(8);
    int d = dir.bin_to_int(as);

    cout << as << " " << d;
    
    return 0;
}