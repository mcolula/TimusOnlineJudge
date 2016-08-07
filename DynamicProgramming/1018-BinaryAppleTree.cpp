#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector< vi> vv;

const int M = 100000000;
const int A =       105;

int memo[A][A];
int W[A][A];
int size[A];
int cost[A];
vv  graph;
int L[A];
int R[A];

int addEdge(int u, int v) {
  if (L[u] < 0)
    return L[u] = v;
  if (R[u] < 0)
    return R[u] = v;
}

int count(int s, int p = 0) {
  if (size[s] >= 0)
    return size[s];
  int ans = 1;
  for (auto u: graph[s]) if (u != p)
    addEdge(s, u), ans += count(u, s);
  return size[s] = ans;
}

int waste(int s, int p = 0) {
  if (cost[s] >= 0)
    return  cost[s];
  int ans = W[s][p];
  for (auto u: graph[s]) if (u != p)
    ans += waste(u, s);
  return cost[s] = ans;
}

int mincst(int idx, int k) {
  if (k <= 0)
    return 0;
  if (k == count(idx))
    return waste(idx);
  if (k >= count(idx))
    return M;
  if (memo[idx][k] >= 0)
    return memo[idx][k];
  int ans = M;
  for (int i = 0; i <= k; i++)
    ans = min(ans, mincst(L[idx], i) + mincst(R[idx], k - i));
  return memo[idx][k] = ans;
}

int main() {
  ios::sync_with_stdio( 0); cin.tie(0);
  for (int i = 0; i < A; i++)
    fill(memo[i], memo[i] + A, -1);
  fill(size, size + A, -1);
  fill(cost, cost + A, -1);
  fill(L, L + A, -1);
  fill(R, R + A, -1);
  int w, u, v, n, k;
  cin >>  n  >>   k;
  graph = vv(n + 1, vi());
  for (int i = 1; i < n; i++) {
    cin >> u  >>  v  >> w;
    graph[u].push_back(v);
    graph[v].push_back(u);
    W[u][v] = W[v][u] = w;
  }
  cout << waste(1) - mincst(1, n - k - 1) << '\n';
  return 0;
}
