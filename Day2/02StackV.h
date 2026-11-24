#include<vector>
template<typename T>


class Stack  {
    std::vector<T> arr;
    public:

    void push(T value) {
        arr.push_back(value);
    }

    void pop() {
        arr.pop_back();
    }

    T top() const {
        return arr.back();
    }

    bool empty() const {
        return arr.empty();
    }
};
