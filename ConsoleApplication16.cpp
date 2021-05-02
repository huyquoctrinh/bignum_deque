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
    string a = "123456789";
    string b = "12316767678678";
    string x = "00000101111";
    //11111001111
    a1 = string2bigint(a);
    b1 = string2bigint(b);
    x1 = string2bigint(x);
    //res = add_dec(a1, b1);
    test = not_operator(x1);
    //output(test);
    //cout << getLength(a1);
    //cout << not_operator(x1);
    //cout << bin2dec(x1);
    cout<<mod(b1, 10);
}

