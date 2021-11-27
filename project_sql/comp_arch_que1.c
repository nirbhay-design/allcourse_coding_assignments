#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <math.h>
// last three digits is 114

#define Rand_max 255 
#define LAST 114

char * binary(float n) {
    char * myvalue = (char *)malloc(sizeof(char) * 24);
    int value_index = 0;
    int int_part= (int)n;
    float float_part = n - int_part;
    int arr[50];int index =0;
    int part = int_part;
    float part2 = float_part;
    while (part > 0) {
        arr[index++] = part%2;
        part = part/2;
    }
    for (int i = index-1;i>=0;i--) {
        myvalue[value_index++] = arr[i]+'0';
    }
    myvalue[value_index++] = '.';
    if ((n - int_part) == 0) {
        myvalue[value_index++] = '0';
        myvalue[value_index] = '\0';
        return myvalue;
    }
    index = 0;
    while (index < 6) {
        int id = (int) (part2 * 2);
        float goahead = part2 * 2 - id;
        arr[index++] = id;
        part2 = goahead;
    }
    for (int i =0;i<index;i++) {
        myvalue[value_index++] = arr[i]+'0';
    }
    myvalue[value_index] = '\0';
    return  myvalue;
}

char * int_binary(int n) {
    char * myvalue = (char *)malloc(sizeof(char) * 24);
    int arr[25],index=0;
    int part = n;
    while (part > 0) {
        arr[index++] = part%2;
        part = part/2;
    }
    int value_index = 0;
    if (index < 7) {
        int tval = 7 - index;
        while (value_index < tval) {
            myvalue[value_index++] = '0';
        }
    }
    for (int i = index-1;i>=0;i--) {
        myvalue[value_index++] = arr[i]+'0';
    }
    return myvalue;
}
char * getmantissa(float n, char * binary_rep){
    char * mant = (char *)malloc(sizeof(char) * 23);
    int ind = 0;
    if (n < 1) {
        int index = 0;
        while(binary_rep[index] != '1') {
            index++;
        }
        index++;
        while(binary_rep[index] !='\0') {
            mant[ind++] = binary_rep[index++];
        }
        while (ind < 16) {
            mant[ind++] = '0';
        }
        mant[ind] = '\0';
        return mant;
    } 
    int index=1;
    while(binary_rep[index] != '\0') {
        if (binary_rep[index] == '.') {
            index++;continue;
        }
        mant[ind++] = binary_rep[index++];
    }
    while (ind < 16) {
        mant[ind++] = '0';
    }
    mant[ind] = '\0';
    return mant;


}

int getexpo(float n ,char * binary_rep) {
    int index=0;
    if (n < 1) {
        while(binary_rep[index] != '.') {
            index++;
        }
        index++;
        int ans=0;
        while(binary_rep[index] != '1') {
            index++;
            ans++;
        }
        return -(ans + 1);

    }
    while (binary_rep[index] != '.') {
        index++;
    }

    return index-1;
}

float convert(char * binary_rep) {
    int index = 0;
    int left,right;
    while (binary_rep[index] != '.' && binary_rep[index] != '\0') {
        index++;
    }
    left = index;
    while(binary_rep[index] != '\0') {
        index++;
    }

    right = index - left-1;
    float ans = 0;
    // printf("%d %d",left,right);
    int myindex = 0;
    while (binary_rep[myindex] != '.'  && binary_rep[myindex] != '\0') {
        ans += (binary_rep[myindex] == '1')?(pow((double)2,(double)left-1)):0.0;
        left--;
        myindex++;
    }
    myindex++;
    int tvalue = right + 1;
    while (binary_rep[myindex] != '\0') {
        ans += (binary_rep[myindex] == '1')?pow((double)2,(double)(right - tvalue)):0.0;
        myindex++;
        right--;
    }

    return ans;
}

char * to_register(float n) {
    char * myregister = (char *)malloc(sizeof(char)*30);
    int regindex=0;
    myregister[regindex++] = (n<0) + '0';
    n = (n<0)?-n:n;
    char * binary_rep = binary(n);
    int expo = getexpo(n,binary_rep);
    char * expon = int_binary(expo+114);//114 is bias
    char * mant = getmantissa(n,binary_rep);
    // printf("%s %s %d %s\n",binary_rep,expon,expo,mant);
    myregister[regindex++] = '-';
    int expo_ind=0,mant_ind=0;

    while (expon[expo_ind] != '\0') {
        myregister[regindex++] = expon[expo_ind++];
    }
    myregister[regindex++] = '-';
    while (mant[mant_ind] != '\0') {
        myregister[regindex++] = mant[mant_ind++];
    }
    myregister[regindex] = '\0';
    return myregister;
}

float register_to_int(char * myregister) {
    int sign = (myregister[0] == '0')?1:-1;
    char * expon = (char *)malloc(sizeof(char) * 8);
    int expon_index=0;
    int ind = 2;
    while (myregister[ind] != '-') {
        expon[expon_index++] = myregister[ind++];
    }
    expon[expon_index] = '\0';
    ind++;

    char * mantissa = (char *)malloc(sizeof(char) * 17);
    int mant_index = 0;
    while (myregister[ind] != '\0') {
        mantissa[mant_index++] = myregister[ind++];
    }
    mantissa[mant_index] = '\0';
    float expo = convert(expon);
    expo = expo - 114;

    float mant_value = 0;
    int value = -1;
    int mantind=0;
    while (mantissa[mantind] !='\0') {
        mant_value += (mantissa[mantind] == '1')?pow((double)2,(double)value):0.0;
        value--; 
        mantind++;
    }
    return (float)sign * pow((double)2,(double)expo) * (1+mant_value);

}
int main(int argc , char * argv[]) {
    srand(time(NULL));
    
    float m = LAST * 2.2;
    // printf("%f",m);    
    float n = (float)rand() / (float)(Rand_max-LAST+1) + (float)LAST;//+ (float)LAST;
    int sign = rand()%2;// 1 for the -ve and 0 for positive;
    // printf("%f %d\n",n,sign);
    int bias = LAST;
    // first is for sign;
    // 7 bits for the exponent;
    // 16 bits for the mantissa;
    printf("n = %f, random sign of n: %s, m = %f\n",n,(sign)?"- (negative)":"+ (positive)",m);

    printf("Register total size is 24 bit \n 1) first bit is for sign \n 2) next 7 bits are for exponent \n 3) next 16 bits are for mantissa \n 4) bias is 114 \n");
    // char * binary_rep_m = binary(m);
    // char * binary_rep_n = binary(n);
    
    // printf("%s %s \n",binary_rep_n,binary_rep_m);

    // printf("%d %d\n",getexpo(n,binary_rep_n),getexpo(m,binary_rep_m));

    // printf("%s %s \n",getmantissa(n,binary_rep_n),getmantissa(m,binary_rep_m));
    // printf("%f %f\n",convert(binary_rep_n),convert(binary_rep_m));

    n = (sign)?-n:n;
    char * reg_n = to_register(n);
    char * reg_m = to_register(m);
    printf("Register of n : %s \nRegister of m : %s\n",reg_n,reg_m);
    
    float m_ = register_to_int(reg_m);
    float n_ = register_to_int(reg_n);
    printf("n from register : %f, m from register : %f\n",n_,m_);
    printf("m+n: %f, n-m: %f, m-n: %f\n",m_+n_,n_- m_,m_- n_);

    char * sum = to_register(n_+m_);
    char * diff_m_n = to_register(m_-n_);
    char * diff_n_m = to_register(n_-m_);

    float sumf=register_to_int(sum), diff_m_nf=register_to_int(diff_m_n),diff_n_mf=register_to_int(diff_n_m);    
    printf("Register of m+n : %s \nRegister of n-m : %s\nRegister of m-n : %s\n",sum,diff_n_m,diff_m_n);
    

    
    printf("m+n from register : %f \nn-m from register : %f\nm-n from register : %f\n",sumf,diff_n_mf,diff_m_nf);
    
    // char * m_n = binary(m+n);
    // char * m__n = binary(m-n);

    // printf("%s %s \n",m_n,m__n);
    // printf("%d %d\n",getexpo(n+m,m_n),getexpo(m-n,m__n));
    // printf("%s %s \n",getmantissa(n+m,m_n),getmantissa(m-n,m__n));
    // printf("%f", convert(".1000"));
    // printf("%s",int_binary(8));
    return 0;
}