/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-08-22
 */

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief 01背包问题，每个物品要么选要么不选
 * @param int V 最大费用开销
 * @param int N 个数
 * @param vector<int> C 费用
 * @param vector<int> W 价值
 * @return int 最大价值
 */
int zeroOnePack(const int &V, const int &N, const std::vector<int> &C,
                const std::vector<int> &W) {
  /*
    F[i,v] 表示前i件物品恰好放入一个容量为v的背包可以获得的最大价值
    则状态转移方程为: F[i, v] = max{F[i-1, v], F[i-1][v-Ci] + Wi};
    转化为不选择或者选择当前第i件物品
  */
  // 空间复杂度 O(VN)
  std::vector<std::vector<int>> F(N + 1, std::vector<int>(V + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int v = 0; v <= V; v++) {
      F[i][v] = F[i - 1][v];
      if (v >= C[i - 1]) {
        F[i][v] = std::max(F[i][v], F[i - 1][v - C[i - 1]] + W[i - 1]);
      }
    }
  }
  // 空间复杂度O(V);
  std::vector<int> F2(V + 1, 0);
  for (int i = 1; i <= N; i++) {
    for (int v = V; v >= C[i - 1]; v--) {
      F2[v] = std::max(F2[v], F2[v - C[i - 1]] + W[i - 1]);
    }
  }
  return F2[V];
}

/**
 * @brief 完全背包问题，每个物品可以选任意个数
 * @param int V 最大费用开销
 * @param int N 个数
 * @param vector<int> C 费用
 * @param vector<int> W 价值
 * @return int 最大价值
 */
int completePack(const int &V, const int &N, const std::vector<int> &C,
                 const std::vector<int> &W) {
  std::vector<int> F(V + 1, 0);
  for (int i = 1; i <= N; i++) {
    for (int v = C[i - 1]; v <= V; v++) {
      F[v] = std::max(F[v], F[v - C[i - 1]] + W[i - 1]);
    }
  }
  return F[V];
}

/**
 * @brief 多重背包问题，每个物品可以选任意个数
 * @param int V 最大费用开销
 * @param int N 个数
 * @param vector<int> C 费用
 * @param vector<int> W 价值
 * @param vector<int> M 每个物品的个数
 * @return int 最大价值
 */
int multiplePack(const int &V, const int &N, const std::vector<int> &C,
                 const std::vector<int> &W, std::vector<int> &M) {
  std::vector<int> F(V + 1, 0);
  for (int i = 1; i <= N; i++) {
    if (C[i - 1] * M[i - 1] >= V) {
      // 完全背包
      for (int v = C[i - 1]; v <= V; v++) {
        F[v] = std::max(F[v], F[v - C[i - 1]] + W[i - 1]);
      }
      continue;
    }

    int k = 1;
    while (k < M[i - 1]) {
      // 01背包
      for (int v = V; v >= k * C[i - 1]; v--) {
        F[v] = std::max(F[v], F[v - k * C[i - 1]] + k * W[i - 1]);
      }
      M[i - 1] -= k;
      k *= 2;
    }
    for (int v = V; v >= M[i - 1] * C[i - 1]; v--) {
      F[v] = std::max(F[v], F[v - M[i - 1] * C[i - 1]] + M[i - 1] * W[i - 1]);
    }
  }
  return F[V];
}

int main() {
  int N, V;
  std::cin >> N >> V;
  std::vector<int> C(N, 0);
  std::vector<int> W(N, 0);
  std::vector<int> M(N, 0);

  for (int i = 0; i < N; i++) {
    std::cin >> C[i] >> W[i] >> M[i];
  }
  std::cout << multiplePack(V, N, C, W, M) << std::endl;
}
