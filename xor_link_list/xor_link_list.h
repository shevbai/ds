#ifndef XOR_LINK_LIST
#define XOR_LINK_LIST
#include <iostream>
using std::endl;
using std::cout;

template<class T>
struct XorNode {
 public:
  XorNode() : xor_(NULL) {};
  XorNode(const T& t) : val(t), xor_(NULL) {}
 public:
  XorNode<T>* xor_;
  T val;
};

template<class T>
class XorLinkList {
 public:
  XorLinkList() : head_(NULL), tail_(NULL), penult_(NULL), size_(0) {};
  size_t size() const { return size_; }
  size_t size() { return size_; }
  void append(const T& t) {
      XorNode<T>* node = new XorNode<T>();
      node->val = t;
      ++size_;
      if (head_ == NULL) {
          head_ = node;
          head_->xor_ = reinterpret_cast<XorNode<T>* >(long(0) ^ long(0));
          tail_ = head_;
          return;
      }
      tail_->xor_ = reinterpret_cast<XorNode<T>* >(
              (reinterpret_cast<long>(node)) ^ (reinterpret_cast<long>(penult_)));
      penult_ = tail_;
      tail_ = node;
      node->xor_ = reinterpret_cast<XorNode<T>* >(
              (reinterpret_cast<long>(penult_) ^ (long)(NULL)));
  }
  void traverse() {
      if (head_ == NULL) {
          return;
      }
      XorNode<T>* current = head_;
      XorNode<T>* last = NULL;
      cout << current->val << endl;
      XorNode<T>* next =reinterpret_cast<XorNode<T>* >(
              reinterpret_cast<long>(current->xor_) ^ reinterpret_cast<long>(last));
      while (next) {
         last = current;
         current = next;
         cout << current->val << endl;
         next =reinterpret_cast<XorNode<T>* >(
              reinterpret_cast<long>(current->xor_) ^ reinterpret_cast<long>(last));
      }
  }
 private:
  XorNode<T>* head_;
  XorNode<T>* penult_;
  XorNode<T>* tail_;
  size_t size_;
};
#endif  // XOR_LINK_LIST
