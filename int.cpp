// #include <ap_int.h>
#include <iostream>
#include <bitset>

namespace OA {

template <int width>
class Int {

private:
    std::bitset<width> _upper;
    std::bitset<width> _lower;

public:
    // constructor
    template <typename Type>
    inline Int<width>(Type val) {
        if (val >= 0) {
            _upper = val;
            _lower = 0;
        } else {
            _upper = 0;
            _lower = -val;
        }
    };
    inline Int<width>(std::bitset<width> upper, std::bitset<width> lower) :
        _upper(upper), _lower(lower) {}

    // getter
    inline std::bitset<width> upper() const { return _upper; }
    inline std::bitset<width> lower() const { return _lower; }

    // operators
    // a + b
    inline Int<width> operator+(const Int<width>& other) const {
        // override this
        return Int<width>(
            _upper.to_ulong() + other.upper().to_ulong() -
            _lower.to_ulong() - other.lower().to_ulong());
    }
    // a * b
    inline Int<width> operator+(const Int<width>& other) const {
    }
    // -a
    inline Int<width> operator-() const {
        return Int<width>(_lower, _upper);
    }
    // a - b
    inline Int<width> operator-(const Int<width>& other) const {
        return *this + (-other);
    }
};

}


int main(int argc, char *argv[])
{
    OA::Int<32> a = 1;
    a = a - a;
    std::cout << a.upper() << ", " << a.lower() << std::endl;
    return 0;
}
