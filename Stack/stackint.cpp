#include "stackint.h"

/**
 * Constructor
 */
  StackInt::StackInt() {

  }

/**
 * Destructor
 */
  StackInt::~StackInt() {

  }

/**
 * Returns true if the stack is empty, false otherwise
 */
  bool StackInt::empty() const {
  	return list_.size ()== 0;
  }

/**
 * Pushes a new value, val, onto the top of the stack
 */
  void StackInt::push(const int& val) {
  	list_.insert(list_.size(), val);
  }

/**
 * Returns the top value on the stack
 */
  int const &  StackInt::top() const {
  	return list_.get(list_.size()-1);
  }

/**
 * Removes the top element on the stack
 */
  void StackInt::pop() {
  	list_.remove(list_.size()-1);
  }