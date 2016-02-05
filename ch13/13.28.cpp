#include <string>

// Valuelike `TreeNode`. When we copy a `TreeNode`, we copy all the subtree
// from current node.
class TreeNode {
public:
  TreeNode() : value(), count(0), left(nullptr), right(nullptr) {}
  TreeNode(const std::string &s, int c)
      : value(s), count(c), left(nullptr), right(nullptr) {}
  TreeNode(const TreeNode &);

  ~TreeNode();

  TreeNode &operator=(const TreeNode &);

  // insert
  // remove
  // tranverse

private:
  std::string value;
  int count;
  TreeNode *left;
  TreeNode *right;
  // Note that the valid state for the `left` and `right` pointer is either
  // `nullptr` or a subtree node. So that we must check these pointers every
  // time before dereferencing them.

/* First version: helper funtion for copy constructor and destructor *
  static void copyTree(TreeNode *, const TreeNode *);
  static void destroyTree(TreeNode *);
/**/
};

/* First version: copy constructor and destructor *
void TreeNode::copyTree(TreeNode *lhs, const TreeNode *rhs) {
  // Both lhs and rhs must NOT be nullptr
  lhs->value = rhs->value;
  lhs->count = rhs->count;
  if (rhs->left) {
    lhs->left = new TreeNode;  // call default constructor of `TreeNode`
    copyTree(lhs->left, rhs->left);
  } else
    lhs->left = nullptr;
  if (rhs->right) {
    lhs->right = new TreeNode;  // call default constructor of `TreeNode`
    copyTree(lhs->right, rhs->right);
  } else
    lhs->right = nullptr;
}

void TreeNode::destroyTree(TreeNode *n) {
  // n can be a nullptr
  if (!n) return;
  destroyTree(n->left);
  n->left = nullptr;
  destroyTree(n->right);
  n->right = nullptr;
  delete n;  // This statement will cause delete subtree multiple times if we
             // forget to assign n->left and n->right to nullptr.
}

TreeNode::TreeNode(const TreeNode &n) {
  copyTree(this, &n);
}

TreeNode::~TreeNode() {
  destroyTree(left);
  destroyTree(right);
}
/**/

/* Second version: without helper function */
TreeNode::TreeNode(const TreeNode &n)
    : value(n.value), count(n.count), left(nullptr), right(nullptr) {
  if (n.left)
    left = new TreeNode(*n.left);  // recursively call copy constructor
  if (n.right)
    right = new TreeNode(*n.right);  // recursively call copy constructor
}

TreeNode::~TreeNode() {
  delete left;  // recursively call destructor on left subtree node
  delete right;  // recursively call destructor on right subtree node
  // Note that when left or right is nullptr, delete will do nothing, so that
  // the recursion will be stopped.
}

TreeNode &TreeNode::operator=(const TreeNode &n) {
  value = n.value;
  count = n.count;

  TreeNode *tmp = nullptr;
  if (n.left)
    tmp = new TreeNode(*n.left);  // recursively call copy constructor
  delete left;  // recursively call destructor
  left = tmp;

  tmp = nullptr;
  if (n.right)
    tmp = new TreeNode(*n.right);  // recursively call copy constructor
  delete right;  // recursively call destructor
  right = tmp;

  return *this;
}
/**/

// Two versions of `BinStrTree` are defined here. The first version is
// valuelike version, while the second verison is pointerlike version. The
// class declarations of these two versions are the same except the pointerlike
// version adds a data member for reference count, while the defitions of
// copy-control members are different.

/* First Version: Valuelike `BinStrTree` *
// When we copy a `BinStrTree`, we copy all the subtree from `root` node.
class BinStrTree {
public:
  BinStrTree(const TreeNode &r = TreeNode()) : root(new TreeNode(r)) {}
  BinStrTree(const BinStrTree &);

  ~BinStrTree();

  BinStrTree &operator=(const BinStrTree &);

private:
  TreeNode *root;
  // Note that the valid state for the `root` pointer is always a pointer to an
  // existing tree node, and `nullptr` is not a valid state. So that we can
  // dereference this pointer without checking if it's a null pointer in copy
  // constructor and copy-assignment operator. (Class Invariant)
};

BinStrTree::BinStrTree(const BinStrTree &rhs)
    : root(new TreeNode(*rhs.root)) {}  // recursively call copy constructor

BinStrTree::~BinStrTree() {
  delete root;  // recursively call destructor of `TreeNode`
}

BinStrTree &BinStrTree::operator=(const BinStrTree &t) {
  TreeNode *tmp = new TreeNode(*t.root);
  delete root;
  root = tmp;

  return *this;
}
/**/

/* Second version: Pointerlike `BinStrTree` */
// When we copy a `BinStrTree`, the copyed object point to the same tree as the
// original object.
class BinStrTree {
public:
  BinStrTree(const TreeNode &r = TreeNode())
      : root(new TreeNode(r)), use(new std::size_t(1)) {}
  BinStrTree(const BinStrTree &);

  ~BinStrTree();

  BinStrTree &operator=(const BinStrTree &);

private:
  TreeNode *root;
  // Note that the valid state for the `root` pointer is always a pointer to an
  // existing tree node, and `nullptr` is not a valid state. So that we can
  // dereference this pointer without checking if it's a null pointer in copy
  // constructor and copy-assignment operator. (Class Invariant)
  std::size_t *use;
};

BinStrTree::BinStrTree(const BinStrTree &rhs)
    : root(new TreeNode(*rhs.root)), use(rhs.use) { ++*use; }
      // recursively call copy constructor

BinStrTree::~BinStrTree() {
  if (--*use == 0) {
    delete root;  // recursively call destructor of `TreeNode`
    delete use;
  }
}

BinStrTree &BinStrTree::operator=(const BinStrTree &t) {
  ++*t.use;
  if (--*use == 0) {
    delete root;
    delete use;
  }
  root = t.root;
  use = t.use;

  return *this;
}
/**/

int main() {
  // TODO test class `TreeNode`
  TreeNode node;

  // TODO test class `BinStrTree`
  BinStrTree bst;

  return 0;
}
