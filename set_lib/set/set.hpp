#include <cassert>

template <typename T>
class Set {
    public:
        Set();
        ~Set();
    private:
        struct Node {
            T* left;
            T* right;
            T data;
        };
};