/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-09-02
 *
 * 5 6
 1 2 5
 1 3 8
 2 3 1
 2 4 3
 4 5 7
 2 5 2
 *
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define Max_N 1000
#define INF 0x3f3f3f3f

struct edge {
  int to;
  int cost;
};
struct node {
  int cost;
  int index;
  node(int cost, int index) : cost(cost), index(index) {}
};

template <class T>
struct cmp1 {
  bool operator()(const T &x, const T &y) { return x.cost > y.cost; }
};
int V, E;
std::vector<edge> G[Max_N];
int d[Max_N];
int pre[Max_N];

void dijkstra(int s) {
  std::priority_queue<node, std::vector<node>, cmp1<node>> Q;
  for (int i = 1; i <= V; i++) {
    d[i] = INF;
  }
  d[s] = 0;
  Q.push(node(0, s));
  while (!Q.empty()) {
    node top = Q.top();
    Q.pop();
    int v = top.index;
    if (d[v] < top.cost) continue;  // 更小则不更新
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pre[e.to] = v;
        Q.push(node(d[e.to], e.to));
      }
    }
  }
}
int main() {
  std::cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int s, t, co;
    std::cin >> s >> t >> co;
    G[s].push_back({t, co});
  }
  // printMap(map);
  dijkstra(1);
  for (int i = 1; i <= V; i++) {
    std::cout << "S到序号" << i << "顶点的最短距离:" << d[i] << std::endl;
  }
  for (int i = 1; i <= V; i++) {
    std::cout << pre[i] << std::endl;
  }
}
