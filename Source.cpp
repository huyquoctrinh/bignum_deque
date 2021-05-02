#include<iostream>
#include"Header.h"
#include<string.h>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;
string ReverseString(string s)
{
    string sTemp = s;
    reverse(sTemp.begin(), sTemp.end());
    return sTemp;
}
int getLength(bigint a) {
	return a.data.size();
}

void Set(bigint& a) {
	while (a.data.size() > 1 && a.data.back() == 0) a.data.pop_back();
}

bigint string2bigint(string s) {
    bigint res;
    int l = s.length();
    for (int i = 0; i < l; i++) {
        res.data.push_back(int(s[i]-48));
    }
    return res;
}

string bigint2string(bigint a) {
    string res;
    int l = getLength(a);
    if (!a.data.empty())
    {
        for (int i = 0; i < l; i++) {
            res = res + to_string(a.data[i]-48);
        }
    }
    return res;
}

int getDigit(bigint a,int pos) {
    return a.data[pos];
}
void make_equal(bigint& a, bigint& b) {
    int n = getLength(b);
    int na = getLength(a);
    while (na < n) {
        a.data.push_front(0);
        na++;
    }
}
int makeEqualLength(bigint& a, bigint& b) {
    int n1 = getLength(a);
    int n2 = getLength(b);
    if (n1 < n2) {
        make_equal(a, b);
        return n2;
    }
    else if (n1 > n2) {
        make_equal(b, a);
        return n1;
    }
    else if (n1 == n2) {
        return n1;
    }
}
bigint add_bin(bigint a, bigint b) {
    bigint res;
    int buffer = 0;
    int l = makeEqualLength(a, b);
    for (int i = l-1; i >= 0; i--) {
        int fbit = getDigit(a, i);
        int sbit = getDigit(b, i);
        int sum = fbit ^ sbit ^ buffer;
        res.data.push_front(sum);
        if ((fbit == 1) && (sbit == 1)) {
            buffer = 1;
        }
        else {
            buffer = 0;
        }
    }
    if (buffer == 1) {
        res.data.push_front(1);
    }
    return res;
}
bigint add_dec(bigint a, bigint b) {
    bigint res;
    int la = getLength(a);
    int lb = getLength(b);
    int l = makeEqualLength(a, b);
    int buffer = 0;
    for (int i = l - 1; i >= 0; i--) {
        int fnum = getDigit(a, i);
        int snum = getDigit(b, i);
        int sum = fnum + snum + buffer;
        res.data.push_front(sum % 10);
        if (sum > 10) {
            buffer = 1;
        }
        else {
            buffer = 0;
        }
    }
    return res;
}
int bin2dec(bigint n) {
    int dec_value = 0;
    int base = 1;

    int len = getLength(n);
    for (int i = len - 1; i >= 0; i--) {
        if (n.data[i] == 1)
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
int bitshift_right(bigint a, int unit) {
    int l = getLength(a);
    for (int i = 0; i < unit; i++) {
        a.data.pop_back();
    }
    int kq = bin2dec(a);
    return kq;
}
int bitshift_left(bigint a, int unit) {
    int l = getLength(a);
    for (int i = 0; i < unit; i++) {
        a.data.pop_front();
        a.data.push_back(0);
    }
    int kq = bin2dec(a);
    return kq;
}
bigint not_operator(bigint a) {
    int l = getLength(a);
    for (int i = 0; i < l; i++) {
        if (a.data[i] == 0) {
            a.data[i] = 1;
        }
        else if (a.data[i] == 1) {
            a.data[i] = 0;
        }
    }
    bigint b,res;
    b.data = {1};
    res =add_bin(a, b);
    int kq = bin2dec(res);
    return res;
}
int mod(bigint a, int n)
{
    int res = 0;
    int l = getLength(a);
    for (int i = 0; i < l; i++)
        res = (res * 10 + a.data[i]) % n;

    return res;
}