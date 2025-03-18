#include <iostream>

#include "sales_item.h"
int main() {
  SaleItem total, book;
  // std::cout<<"请输入相同的isbn"<<std::endl;
  if (std::cin >> total) {
    while (std::cin >> book) {
      if (compareIsbn(total, book)) {
        total += book;
      } else {
        std::cout << "isbn不同，请重新输入" << std::endl;
        return -1;
      }
    }
  } else {
    std::cout << "没有数据" << std::endl;
    return -1;
  }
  std::cout << "所有输入记录的和为：" << total << std::endl;
  return 0;
}