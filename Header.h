#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include<deque>
#include <iterator>
using namespace std;
struct bigint {
	bool dau;
	deque<int> data;
};
int getLength(bigint a);
void Set(bigint& a);
bigint string2bigint(string s);
string bigint2string(bigint a);
bigint add_bin(bigint a, bigint b);
bigint add_dec(bigint a, bigint b);
int bin2dec(bigint n);
int bitshift_right(bigint a, int unit);
int bitshift_left(bigint a, int unit);
bigint not_operator(bigint a);
int mod(bigint a, int n);
bigint multiply(bigint a, bigint b);
int compare(bigint a, bigint b);
bigint divide(bigint number, int divisor);
bigint dec2bin(bigint n);
void output(bigint a);
bigint int2bigint(int n);
bigint subtract_step(bigint a, bigint b);
bigint substract(bigint a, bigint b);
bigint abs_big(bigint a);
#pragma once
