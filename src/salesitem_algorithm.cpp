#include <algorithm>
#include <cctype>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

#include "sales_item.h"

using std::accumulate;
using std::back_inserter;
using std::cin;
using std::count;
using std::cout;
using std::deque;
using std::endl;
using std::fill_n;
using std::find_if;
using std::for_each;
using std::forward_list;
using std::ifstream;
using std::invalid_argument;
using std::list;
using std::partition;
using std::sort;
using std::stable_sort;
using std::stack;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;
using std::bind;
using std::inserter;

int main() {
    vector<SaleItem> total;
    std::istream_iterator<SaleItem> in_iter(cin), eof;
    std::ostream_iterator<SaleItem> out_iter(cout, "\n");
    while (in_iter != eof) {
        total.push_back(*in_iter++);
    }
    if (total.empty()) {
        std::cerr << "没有输入" << endl;
        return -1;
    }
    sort(total.begin(), total.end(), compareIsbn);
    //for(auto elem = total){
    //    *out_iter++ = elem;
    //}
    auto beg_iter = total.begin();
    while (beg_iter != total.end()) {
        auto item = *beg_iter;
        auto first_different_book_iter =
            find_if(beg_iter+1, total.end(),
                    [item](const SaleItem &item1) { return item1.isbn() != item.isbn(); });
        cout << accumulate(beg_iter + 1, first_different_book_iter, item) << endl;
        beg_iter = first_different_book_iter;
    }
    return 0;
}
    /*
  SaleItem total, book;
  // std::cout<<"请输入相同的isbn"<<std::endl;
  if (std::cin >> total) {
    while (std::cin >> book) {
      if (compareIsbn(total, book)) {
        total += book;
      } else {
        std::cout << total << std::endl;
        total = book;
      }
    }
    std::cout << total << std::endl;
  } else {
    std::cout << "没有数据" << std::endl;
    return -1;
  }
  std::cout << "所有输入记录的和为：" << total << std::endl;
    return 0;
}
  */