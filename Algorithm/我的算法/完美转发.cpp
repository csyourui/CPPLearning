/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-08-31
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class CData {
 public:
  CData() = delete;

  explicit CData(const int& num) : num(num) {
    std::cout << "CData(const int & num)" << std::endl;
  }
  explicit CData(int&& num) : num(num) {
    std::cout << "CData(int&& num)" << std::endl;
  }
  ~CData() {}

 private:
  int num;
};
template <class T>
T&& myForward(std::remove_reference_t<T>& arg) {
  return (static_cast<T&&>(arg));
}
template <class T>
CData* Creator(T&& t) {
  /*
    1) 如果 CData* p = Creator(i);
    i 为 int 类型， T会被推导为 int & (T && -> int & && -> int &)
    forward中 std::remove_reference_t<int &> 为 int, static_cast<int& &&> 为
    int& 完美转发！

    2) 如果 CData* p = Creator(1 + 1);
    1 + 1 为 int&& 类型， T会被推导为 int (T && -> int &&)
    forward中 std::remove_reference_t<int> 为 int, static_cast<int &&> 为 int&&
    完美转发！ 等价于：
  */
  std::cout << t << "\t";

  return new CData(myForward<T>(t));
}

void Forward() {
  int tmp = 4, tmp2 = 5;

  int i = 1;
  std::cout << "int      \t";
  CData* p = Creator(i);
  delete p;

  int i_right = 1 + 1;
  std::cout << "int&&    \t";
  p = Creator(std::move(i_right));
  delete p;

  const int i_const = 3;
  std::cout << "const int\t";
  p = Creator(i_const);
  delete p;

  int& i_ref = tmp;
  std::cout << "int&       \t";
  p = Creator(i_ref);
  delete p;

  const int& i_cont_ref = tmp2;
  std::cout << "const int&\t";
  p = Creator(i_cont_ref);
  delete p;
}
int main() { Forward(); }
