#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int le[17][N];
 
void pre(int n) {
    for (int i = 1; i <= 16; i++) {
        for (int j = 1; j <= n; j++) {
            le[i][j] = min(le[i - 1][j], le[i - 1][j + (1 << (i - 1))]);
        }
    }
}
 
int get_min(int l, int r) {
    int k = __lg(r - l + 1);
    return min(le[k][l], le[k][r - (1 << k) + 1]);
}
