#include<iostream>
#include"Header.h"
#include<string.h>
#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "math_header.h"
bigint max(bigint* a, int n) {
    bigint max;
    for (int i = 0; i < n; i++) {
        if (compare(a[i + 1], a[i]) == 1) {
            equal(max, a[i + 1]);
        }
    }
    return max;
}
bigint min(bigint* a, int n) {
    bigint min;
    for (int i = 0; i < n; i++) {
        if (compare(a[i + 1], a[i]) != 1) {
            equal(min, a[i + 1]);
        }
    }
    return min;
}
bigint abs_big(bigint a) {
    if (a.dau == 0) {
        a.dau = 1;
        return a;
    }
    else {
        return a;
    }
}