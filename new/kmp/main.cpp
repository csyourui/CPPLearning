/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-09-06
 */
#include <iostream>
#include <string>
#include <vector>

int bruteForce(const std::string &str, const std::string &pattern) {
  int i = 0, j = 0;
  int ilen = str.size(), jlen = pattern.size();
  while (i < ilen && j < jlen) {
    if (str[i] == pattern[j]) {
      i++;
      j++;
    } else {
      i = i - (j - 1);
      j = 0;
    }
  }
  if (j == jlen) {
    return i - j;
  } else {
    return -1;
  }
}

void getNext(const std::string &pattern, std::vector<int> &next) {
  next[0] = -1;
  int i = 0, j = -1;
  while (i < pattern.size()) {
    if (j == -1 || pattern[i] == pattern[j]) {
      i++;
      j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}
int kmp(const std::string &str, const std::string &pattern,
        const std::vector<int> &next) {
  int i = 0, j = 0;
  int ilen = str.size(), jlen = pattern.size();
  while (i < ilen && j < jlen) {
    if (j == -1 || str[i] == pattern[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (j == jlen) {
    return i - j;
  } else {
    return -1;
  }
}
int main() {
  std::string str = "BBC ABCDAB ABCDABCDABDE";
  std::string pattern = "ABDE";
  int pos = bruteForce(str, pattern);
  std::cout << str.substr(pos, pattern.size()) << std::endl;
  std::cout << pattern << std::endl;
  std::vector<int> next(str.size());
  getNext(pattern, next);
  int pos2 = kmp(str, pattern, next);
  std::cout << str.substr(pos2, pattern.size()) << std::endl;
  std::cout << pattern << std::endl;
}
