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
    if (a.dau == 0) {
        cout << "-";
    }
    for (auto i : a.data) {
        cout << i;
    }

}
bool check_dau(bigint a,bigint b) {
    if ((a.dau == 0) && (b.dau == 0)) {
        return true;
    }
    else if ((a.dau == 0) && (b.dau == 1)) {
        return false;
    }
    else if ((a.dau == 1) && (b.dau == 0)) {
        return false;
    }
    else if ((a.dau == 1) && (b.dau == 1)) {
        return true;
    }
    return true;
}
string ReverseString(string s)
{
    string sTemp = s;
    reverse(sTemp.begin(), sTemp.end());
    return sTemp;
}
int getLength(bigint a) {
	return a.data.size();
}
bigint int2bigint(int n) {
    bigint res;
    res.data.push_back(n);
    return res;
}
void Set(bigint& a) {
	while (a.data.size() > 1 && a.data.back() == 0) a.data.pop_back();
}

bigint string2bigint(string s) {
    bigint res;
    int l = s.length();

    if (s[0] == '-') {
        res.dau = 0;
        for (int i = 1; i < l; i++) {
            res.data.push_back(int(s[i] - 48));
        }
    }
    else if ((s[0] != '-') || (s[0] == '+')) {
        res.dau = 1;
        for (int i = 0; i < l; i++) {
            res.data.push_back(int(s[i] - 48));
        }
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
    if (a.dau == 0) {
        res = "-" + res;
    }
    return res;
}

int getDigit(bigint a,int pos) {
    int n = getLength(a);
    if (pos >= n) {
        return -1;
    }       
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
bigint add_dec_step(bigint a, bigint b) {
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
bigint add_dec(bigint a, bigint b) {
    if ((a.dau==1) &&(b.dau==1)) {
        return add_dec_step(a, b);
    }
    else if ((a.dau==1)&&(b.dau==0)) {
        return substract(a, b);
    }
    else if ((a.dau == 0) && (b.dau == 1)) {
        return substract(b, a);
    }
    else if ((a.dau == 0) && (b.dau == 0)) {
        bigint res;        
        res = add_dec_step(a, b);
        res.dau = 0;
        return res;
    }
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
        res = (res * 10 + getDigit(a,i)) % n;

    return res;
}
bigint multiply(bigint a, bigint b)
{
    int l1 = getLength(a);
    int l2 = getLength(b);
    bigint res;
    if ((a.dau == 0) && (b.dau == 0)) {
        res.dau = 1;
    }
    else if ((a.dau == 0) && (b.dau ==1)) {
        res.dau = 0;
    }
    else if ((a.dau ==1) && (b.dau == 0)) {
        res.dau = 0;
    }
    else if ((a.dau ==1) && (b.dau ==1)) {
        res.dau = 1;
    }
    deque<int> result(l1 + l2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i = l1 - 1; i >= 0; i--)
    {
        int buffer = 0;
        int n1 = getDigit(a, i);
        i_n2 = 0;          
        for (int j = l2 - 1; j >= 0; j--)
        {
            int n2 = getDigit(b,j);
            int sum = n1 * n2 + result[i_n1 + i_n2] + buffer;
            buffer = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (buffer > 0)
            result[i_n1 + i_n2] += buffer;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    if (i == -1) {
        bigint r;
        r.data = { 0 };
        return r;
    }

    
    res.data = result;
    res.data.pop_back();
    reverse(res.data.begin(), res.data.end());
    return res;
}
bigint divide_step(bigint number, int divisor)
{
    bigint res;
    int idx = 0;
    int temp = getDigit(number, idx);
    while (temp < divisor) {
        ++idx;
        if (getDigit(number, idx) == -1) {
            res.data = { temp/divisor };
            return res;
        }
        temp = temp * 10 + getDigit(number, idx);

    }
    while (getLength(number) > idx) {
        res.data.push_back(temp / divisor);
        ++idx;
        if (getDigit(number, idx) == -1) {
            return res;
        }
        temp = temp % divisor * 10 + getDigit(number, idx);
        
    }
    if (getLength(res) == 0) {
        res.data = { 0 };
        return res;
    }
}
bigint divide(bigint a, int divisor) {
    bigint res;
    res = divide_step(a, divisor);
    if ((a.dau == 0) && (divisor < 0)) {
        res.dau = 1;
    }
    else if ((a.dau == 0) && (divisor > 0)) {
        res.dau = 0;
    }
    else if ((a.dau == 1) && (divisor < 0)) {
        res.dau = 0;
    }
    else if ((a.dau == 1) && (divisor > 0)) {
        res.dau = 1;
    }
    return res;
}
int compare(bigint a, bigint b) {
    int l1 = getLength(a);
    int l2 = getLength(b);
    if (l1 > l2) {
        return 1;
    }
    else if (l1 < l2) {
        return -1;
    }
    else if (l1 == l2) {
        for (int i = 0; i < l1; i++) {
            if (a.data[i] > b.data[i]) {
                return 1;
            }
            else if (a.data[i] < b.data[i]) {
                return -1;
            }
        }
        return 0;
    }
    
}

bigint dec2bin(bigint n){
    bigint res, tmp;
    tmp.data = { 0 };
    while (compare(n, tmp) == 1) {
        res.data.push_front(mod(n, 2));
        n = divide(n, 2);
    }
    return res;
}
bigint subtract_step(bigint a, bigint b) {
    bigint res;
    int la = getLength(a);
    int lb = getLength(b);
    int buffer = 0;
    int l = makeEqualLength(a, b);
    for (int i = l-1; i >=0; i--) {
        int fbit = getDigit(a, i);
        int sbit = getDigit(b, i);
        sbit = sbit + buffer;
        if (fbit < sbit) {
            fbit +=10;
            buffer = 1;
        }
        else {
            buffer = 0;
        }
        int sum = fbit - sbit;
        res.data.push_front(sum);
    }
    return res;
}
bigint substract(bigint a, bigint b) {
    bigint res;
    int check = compare(a, b);
    if (check == 1) {
        res = subtract_step(a, b);
    }
    else if (check == 0) {
        return subtract_step(a, b);
    }
    else if (check == -1) {
        res = subtract_step(a, b);
        res.dau = 0;
    }
    return subtract_step(a, b);

}
void equal(bigint& a, bigint& b) {
    b.data = a.data;
    b.dau = a.dau;
}
int compare_full(bigint a,bigint b) {
    if (check_dau(a, b)) {
        if (compare(a, b) == 1) {
            return 1;
        }
        else if (compare(a, b) == -1) {
            return -1;
        }
        else if (compare(a, b) == 0) {
            return 0;
        }
    }
    else if (!check_dau(a,b)) {
        if ((a.dau == 1) && (b.dau == 0)) {
            return 1;
        }
        else if ((a.dau == 0) && (b.dau == 1)) {
            return -1;
        }
    }
}
