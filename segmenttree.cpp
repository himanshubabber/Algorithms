#include <bits/stdc++.h>
using namespace std;

// segment tree array initialisation
int a[100000], seg[4 * 100000];
// use comment out part for max of range

void build(int i, int s, int e)
{
  if (s == e)
  {
    seg[i] = a[s];
    return;
  }
  int mid = s + (e - s) / 2;
  build(2 * i + 1, s, mid);
  build(2 * i + 2, mid + 1, e);

  // seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
  seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}
int query(int i, int s, int e, int st, int ed)
{
  if (st <= s && ed >= e)
  {
    return seg[i];
  }
  if (s > ed || e < st)
    return 0;
  int mid = s + (e - s) / 2;
  int left = query(2 * i + 1, s, mid, st, ed);
  int right = query(2 * i + 2, mid + 1, e, st, ed);
  // return max(left, right);
  return left + right;
}

int main()
{
  // ॐ
  int n;
  cout << "enter the value of n :" << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  build(0, 0, n - 1);
  int q;
  cout << "enter the value of q" << endl;
  cin >> q;
  while (q--)
  {
    int st, ed;
    cin >> st >> ed;
    cout << query(0, 0, n - 1, st, ed) << endl;
  }
  return 0;
}