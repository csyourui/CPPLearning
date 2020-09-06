/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-09-02
 */
#include <iostream>
#include <vector>

int upper_bound_(int n, int v, std::vector<int>& a) {
  // write code here
  int left = 0, right = n - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (a[mid] > v) {
      right = mid - 1;
    } else if (a[mid] < v) {
      left = mid + 1;
    } else if (a[mid] == v) {
      right = mid;
    }
  }
  return left;
}

int main() {
  int n = 5, v = 4;
  std::vector<int> a = {1, 2, 4, 4, 5};
  std::cout << upper_bound_(n, v, a) << std::endl;
}
