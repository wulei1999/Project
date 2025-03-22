#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::istream;
using std::make_shared;
using std::out_of_range;
using std::shared_ptr;
using std::string;
using std::vector;

// 二叉树行为实现类指针
class TreeNode {
private:
    /* data */
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode() : value(""), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const string &s = string(), TreeNode *lchild = nullptr, TreeNode *rchild = nullptr)
        : value(s), count(1), left(lchild), right(rchild) {}
    TreeNode(const TreeNode &);
    ~TreeNode();
    TreeNode &operator=(TreeNode &);
    void copy_tree(void);
    int release_tree(void);
};

TreeNode::~TreeNode() {
    if(count)
        release_tree();
}
TreeNode::TreeNode(const TreeNode &tn) : value(tn.value), count(1), left(tn.left), right(tn.right) {
    if (left)
        left->copy_tree();
    if (right)
        right->copy_tree();
}
void TreeNode::copy_tree(void) {
    if (left)
        left->copy_tree();
    if (right)
        right->copy_tree();
    count++;
}

int TreeNode::release_tree(void) {
    if (left) {
        if (!(left->release_tree()))
            delete left;
    }
    if (right) {
        if (!(right->release_tree()))
            delete right;
    }
    count--;
    return count;
}

class BinStrTree {
private:
    /* data */
    TreeNode *root;

public:
    BinStrTree() : root(nullptr) {}
    BinStrTree(TreeNode *t = nullptr) : root(t) {}
    BinStrTree(const BinStrTree &);
    ~BinStrTree();
    BinStrTree &operator=(const BinStrTree &);
};

BinStrTree::~BinStrTree() {
    if (!root->release_tree())
        delete root;
}

BinStrTree::BinStrTree(const BinStrTree &bst) : root(bst.root) {
    root->copy_tree();
}
