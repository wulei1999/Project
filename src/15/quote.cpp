#include "quote.h"

#include <algorithm>
#include <numeric>

using std::accumulate;
using std::make_shared;

ostream &operator<<(ostream &os, Quote &qt) {
    os << "Quote <<" << endl;
    return os;
}

ostream &operator<<(ostream &os, Bulk_quote &blq) {
    os << "Bulk_quote <<" << endl;
    return os;
}

double Basket::total_receipt(ostream &os) const {
    double sum = 0.0;
    for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)){
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return 0.0;
}
int main() {
    vector<shared_ptr<Quote>> v_qt;
    double sum = 0.0;
    Quote qt("001", 12);
    auto s_qt = make_shared<Quote>(qt);
    Bulk_quote b_qt("001", 5, 5, 0.8);
    auto s_bqt = make_shared<Bulk_quote>(b_qt);
    v_qt.push_back(s_qt);
    v_qt.push_back(s_bqt);
    sum = v_qt[0]->net_price(3) + v_qt[1]->net_price(6);
    cout << "计算结果: " << sum << endl;
    
    v_qt.push_back(make_shared<Quote>("001", 12));
    v_qt.push_back(make_shared<Bulk_quote>("001", 5, 5, 0.8));
    sum = v_qt[0]->net_price(3) + v_qt[1]->net_price(6);
    cout << "计算结果: " << sum << endl;

    // 验证对象类型和成员值
    if (auto bq = dynamic_cast<Bulk_quote *>(v_qt[1].get())) {
        cout << "实际min_qty值: " << bq->get_min_qty() << endl;
        cout << "实际discount值: " << bq->get_discount() << endl;
    } else {
        cout << "类型转换失败" << endl;
    }

    Basket bkt;
    bkt.add_item(qt);
    bkt.add_item(b_qt);
    bkt.total_receipt(cout);
    return 0;
}


