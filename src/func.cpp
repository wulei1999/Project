#include "func.h"

#define NDEBUG

int compareInt(int a, int *p) {
    if (a > *p) {
        return a;
    } else {
        return *p;
    }
}
/*值传递指针，不交换指针，但是交换指针指向的内容*/
void changePointer1(int *p1, int *p2) {
    int *p_temp = nullptr;
    p_temp = p1;
    p1 = p2;
    p2 = p_temp;
    return;
}

/*值传递指针，既不交换指针也不交换指针指向的内容*/
void changePointer2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}

/*传递指针的引用，交换指针不交换指针指向的内容*/
void changePointer3(int *&p1, int *&p2) {
    int *p_temp = p1;
    p1 = p2;
    p2 = p_temp;
    return;
}

void changeArrayElement(int (&arr)[], const unsigned int index) {
    cin >> arr[index];
}

int calculateInilsit(initializer_list<int> ini_int) {
    int sum = 0;
    for (auto beg = ini_int.begin(); beg != ini_int.end(); ++beg) {
        sum += *beg;
    }
    return sum;
}

int printVectorVal(const vector<int> v_int, vector<int>::size_type index) {
    if (index < v_int.size()) {
#ifndef NDEBUG
        cout << "vector size is " << v_int.size() << endl;
#endif
        cout << v_int[index++] << " ";
        return printVectorVal(v_int, index);
    } else {
        cout << endl;
        return 0;
    }
}

int (&returnArrayInt(int (&arr)[10]))[10] {
    return arr;
}

string(&returnString(string &str)) {
    str = " ";
    return str;
}
vector<string>(&returnVectorString(vector<string> &v_str)) {
    for (auto elem : v_str) {
        /* code */
        elem = " ";
    }
    return v_str;
}

// 定义变量
vector<int (*)(int, int)> v_func;

// 定义函数
int funcIntAdd(int a, int b) {
    return a + b;
}
int funcIntSubtract(int a, int b) {
    return a - b;
}
int funcIntMultiply(int a, int b) {
    return a * b;
}
int funcIntDivision(int a, int b) {
    return b != 0 ? a / b : 0;
}

// 顺序容器
void flistSearchString(forward_list<string> &flist_string, const string &str1, string &str2) {
    auto prev = flist_string.before_begin();
    auto iter = flist_string.begin();
    for (; iter != flist_string.end();) {
        if (*iter == str1) {
            flist_string.insert_after(iter, str2);
            return;
        } else {
            prev = iter;
            ++iter;
        }
    }
    if (iter == flist_string.end()) {
        flist_string.insert_after(prev, str2);
        return;
    }
}
#if 0
void repalceSimpleform(string &s, string &old_val, string &new_val) {
    auto beg_s = s.begin();
    auto beg_oldval = old_val.begin();
    decltype(s.size()) s_remain_num = s.size();
    size_t old_val_size = old_val.size();
    size_t new_val_size = new_val.size();
    unsigned int count_substr = 0;
    while (s_remain_num >= old_val_size) {
        if (beg_oldval != old_val.end()) {
            if (*beg_s == *beg_oldval) {
                ++beg_s;
                ++beg_oldval;
            } else {
                ++beg_s;
                --s_remain_num;
                if (beg_oldval != old_val.begin()) {
                    s_remain_num -= beg_oldval - old_val.begin();
                    beg_oldval = old_val.begin();
                }
            }
        } else {
            beg_s = s.erase(beg_s - old_val_size, beg_s);
            beg_s = s.insert(beg_s, new_val.begin(), new_val.end());
            beg_s += new_val_size;
            beg_oldval = old_val.begin();
            ++count_substr;
        }
    }
    if(!count_substr)
        cout << "old_val is not substr of s" << endl;
    else{
        cout << "there are " << count_substr << "times old_val of s" << endl;
    }
    return;
}
#endif
#if 1
void repalceSimpleform(string &s, string &old_val, string &new_val) {
    // auto beg_s = s.begin();
    // auto beg_oldval = old_val.begin();
    decltype(s.size()) s_remain_num = s.size();
    size_t old_val_size = old_val.size();
    size_t new_val_size = new_val.size();
    unsigned int count_substr = 0;
    unsigned int index_s, index_oldval;
    index_s = index_oldval = 0;
    while (s_remain_num >= old_val_size) {
        if (index_oldval < old_val_size) {
            if (s[index_s] == old_val[index_oldval]) {
                ++index_s;
                ++index_oldval;
                //--s_remain_num;
            } else {
                ++index_s;
                --s_remain_num;
                if (index_oldval != 0) {
                    s_remain_num -= index_oldval;
                    index_oldval = 0;
                }
            }
        } else {
            s = s.replace(index_s - old_val_size, old_val_size, new_val, 0, new_val_size);
            // index_s += (new_val_size - old_val_size);
            index_s -= old_val_size;
            index_s += new_val_size;
            s_remain_num -= old_val_size;
            index_oldval = 0;
            ++count_substr;
        }
    }
    if (!count_substr)
        cout << "old_val is not substr of s" << endl;
    else {
        cout << "there are " << count_substr << "times old_val of s" << endl;
    }
    return;
}
#endif

void addNameFrontAndSuffix(string &str_name, const string &name_front, const string &name_suffix) {
    // string 前插
    // str_name.insert(0, name_front);
    str_name.insert(0, name_front, 0, name_front.size());
    str_name.insert(str_name.size(), name_suffix, 0, name_suffix.size());
    // auto beg_strname = str_name.begin();
    // auto b_namefront = name_front.begin();
    // auto e_namefront = name_front.end();
    // str_name.insert(beg_strname, b_namefront, e_namefront);

    // string 追加
    // str_name.append(name_suffix);
    // str_name.append(name_suffix, 0, name_suffix.size());
    // auto b_namesuffix = name_suffix.begin();
    // auto e_namesuffix = name_suffix.end();
    // str_name.append(b_namesuffix, e_namesuffix);
}

void findNumberInstr(string &str) {
    string namebers("0123456789");
    string::size_type pos = 0;
    /*
    while ((pos = (str.find_first_of(namebers, pos))) && (pos != string::npos)) {
        cout << "found number at index: " << pos << "elem is " << str[pos] << endl;
        ++pos;
    }
    pos = 0;
    */
    ;
    while ((pos = str.find_first_not_of(namebers, pos)) != string::npos) {
        cout << "found alphabet at index: " << pos << "elem is " << str[pos] << endl;
        ++pos;
    }
    return;
}

void findLongestSubstr(ifstream &in) {
    string str, longest_word;
    unsigned int max_length = 0;
    while (in >> str) {
        if (str.find_first_of("bdfghjklpqty") != string::npos) {
            continue;
        }
        cout << str << endl;
        if(max_length < str.size()){
            max_length = str.size();
            longest_word = str;
        }
    }
    cout << "longest word is: " << longest_word << endl;
    return;
}

