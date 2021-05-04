#include<iostream>
#include"Header.h"
#include<string.h>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "math_header.h"
using namespace std;

int main()
{
    bigint a1, b1,res,x1,test;
    string a = "0";
    string b = "1231231231231231231231434832483249832489324893274893247329847329847329843294732948327498324793284793284793284123456789";
    string x = "123456";
    //11111001111
    a1 = string2bigint(a);
    b1 = string2bigint(b);
    x1 = string2bigint(x);
    //res = add_dec(a1, b1);
    //test = mod(x1,2);
    test = divide(b1,123456789);
    //test = divide(b1,123456789);
    //output(test);
    //cout << getLength(a1);
    //cout << not_operator(x1);
    //cout << bin2dec(x1);
    //cout<<mod(x1, 2);
    //output(test);
    //cout << compare(a1, b1);
    //cout << b1.dau << " " << x1.dau<<" "<<test.dau<<" \n";
    output(test);
    //cout << test;
}

