#include<iostream>
#include"Header.h"
#include<string.h>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;
void output(bigint a) {
    for (auto i : a.data) {
        cout << i;
    }
}
int main()
{
    bigint a1, b1,res,x1,test;
    string a = "8793278316383117319";
    string b = "0";
    string x = "1248163264128256512";
    //11111001111
    a1 = string2bigint(a);
    b1 = string2bigint(b);
    x1 = string2bigint(x);
    //res = add_dec(a1, b1);
    test = divide(x1,125);
    //output(test);
    //cout << getLength(a1);
    //cout << not_operator(x1);
    //cout << bin2dec(x1);
    //cout<<mod(a1, 10);
    //res = multiply(a1, b1);
    output(test);
    //cout << compare(a1, b1);
}

