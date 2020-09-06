/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-08-20
 */

#include <iostream>
#include <vector>

void maxHeapify(std::vector<int>& nums, int i, int n) {
  int a1 = 2 * i + 1;
  int a2 = 2 * i + 2;
  while (a1 <= n) {
    int max = i;
    if (nums[a1] > nums[max]) max = a1;
    if (a2 <= n && nums[a2] > nums[max]) max = a2;
    if (max == i) {
      return;
    } else {
      std::swap(nums[i], nums[max]);
      i = max;
      a1 = 2 * i + 1;
      a2 = 2 * i + 2;
    }
  }
}

void heapSort(std::vector<int>& nums) {
  int N = nums.size();
  std::cout << N << std::endl;
  for (int i = N / 2 - 1; i >= 0; i--) {
    maxHeapify(nums, i, N - 1);
  }
  for (int i = N - 1; i > 0; i--) {
    std::swap(nums[0], nums[i]);
    maxHeapify(nums, 0, i - 1);
  }
}
int main() {
  std::vector<int> num = {1, 4, 7, 2, 3, 8, 1, 9, 20, 11, 24, 3, 5};
  heapSort(num);
  for (auto& n : num) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}
