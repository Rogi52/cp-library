#include "../../src/cp-template.hpp"

template < class monoid >
struct swag_queue {
  public:
    using T = typename monoid::set;
    class node {
      public:
        T value, sum;
        node() : value(monoid::id()), sum(monoid::id()) {}
        node(const T& value, const T& sum) : value(value), sum(sum) {}
    };
    std::stack<node> front_stack, back_stack;

  public:
    swag_queue() { front_stack.push(node()), back_stack.push(node()); }
    int size() const {
        return (int(front_stack.size()) - 1) + (int(back_stack.size()) - 1);
    }
    bool empty() const {
        return size() == 0;
    }
    T fold() const {
        return monoid::op(front_stack.top().sum, back_stack.top().sum);
    }
    void push(const T& x) {
        back_stack.push(node(x, monoid::op(back_stack.top().sum, x)));
    }
    void pop() {
        assert(not empty());
        if(front_stack.size() == 1) {
            while(back_stack.size() > 1) {
                front_stack.push(node(back_stack.top().value, monoid::op(back_stack.top().value, front_stack.top().sum)));
                back_stack.pop();
            }
        }
        front_stack.pop();
    }
};

template < class monoid >
struct swag_deque {
  private:
    using T = typename monoid::set;
    class node {
      public:
        T value, sum;
        node() : value(monoid::id()), sum(monoid::id()) {}
        node(const T& value, const T& sum) : value(value), sum(sum) {}
    };
    std::stack<node> front_stack, back_stack;

  public:
    swag_deque() { front_stack.push(node()), back_stack.push(node()); }
    int size() const { return (int(front_stack.size()) - 1) + (int(back_stack.size()) - 1); }
    bool empty() const { return size() == 0; }

    T fold() const { return monoid::op(front_stack.top().sum, back_stack.top().sum); }
    void push_front(const T& x) { push(front_stack, x, 1); }
    void push_back (const T& x) { push( back_stack, x, 0); }
    void pop_front() { assert(not empty()); if(front_stack.size() == 1) amortize( back_stack, front_stack, 1); front_stack.pop(); }
    void pop_back () { assert(not empty()); if( back_stack.size() == 1) amortize(front_stack,  back_stack, 0);  back_stack.pop(); }

  private:
    void push(std::stack<node>& st, const T& x, int f) {
        st.push(node(x, f ? monoid::op(x, st.top().sum) : monoid::op(st.top().sum, x)));
    }
    void amortize(std::stack<node>& from, std::stack<node>& to, int f) {
        std::stack< T > st;
        while(st.size() < from.size() - 2) st.push(from.top().value), from.pop();
        while(from.size() > 1) push(to, from.top().value, f), from.pop();
        while(not st.empty()) push(from, st.top(), 1 - f), st.pop();
        printer::flush();
    }
};
