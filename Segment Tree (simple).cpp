/*
            DD/MM/YYYY
Date: 11:59 20/11/2023
      12:00 21/11/2023

Creator: Me
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 6;
int a[N], st[4 * N];
// int lazy[4 * N];
int n;

void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }

  int mid = (l + r) >> 1;
  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);

  st[id] = st[2 * id] + st[2 * id + 1];
}

void update(int id, int l, int r, int i, int val) {
  if (l > i || r < i)
    return;

  if (l == r) {
    st[id] = val;
    return;
  }

  int mid = (l + r) >> 1;
  update(2 * id, l, mid, i, val);
  update(2 * id + 1, mid + 1, r, i, val);

  st[id] = st[2 * id] + st[2 * id + 1];
}

int get(int id, int l, int r, int u, int v) {
  if (l > v || r < u)
    return 0;

  if (l >= u && r <= v)
    return st[id];

  int mid = (l + r) >> 1;
  int get1 = get(2 * id, l, mid, u, v);
  int get2 = get(2 * id + 1, mid + 1, r, u, v);

  return get1 + get2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  build(1, 1, n);
  update(1, 1, n, 3, 10);
  cout << get(1, 1, n, 2, 4);
}
