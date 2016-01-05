#ifndef int_hpp
#define int_hpp

#include "common.hpp"
#include "int.hpp"
#include "adder.hpp"


namespace OA {
    template <int width>
    class Int {

    public:
        BS<width> upper;
        BS<width> lower;

        // constructor
        template <class Type> inline Int(Type val);
        inline Int(BS<width> upper, BS<width> lower) :
        upper(upper), lower(lower) {}

        // operators
        inline Int<width> operator+(const Int<width>& other) const;
        inline Int<width> operator*(const Int<width>& other) const;
        inline Int<width> operator-() const;
        inline Int<width> operator-(const Int<width>& other) const;
        inline operator int() const {
            return (int)upper.to_ulong() - (int)lower.to_ulong();
        };
    };

#pragma mark Implementation

    template <int width>
    template <class Type>
    inline OA::Int<width>::Int(Type val) {
        if (val >= 0) {
            upper = val;
            lower = 0;
        } else {
            upper = 0;
            lower = -val;
        }
    }

    template <int width>
    inline Int<width> OA::Int<width>::operator+(const Int<width>& other) const {
        FullAdderArray<width> full_adder_array1(upper, ~lower, other.upper);
        auto intermediate_carry_array = full_adder_array1.carry_array;
        auto intermediate_sum_array = full_adder_array1.sum_array;

        bool upper_carry_out = intermediate_carry_array[0];
        intermediate_carry_array >>= 1;

        FullAdderArray<width> full_adder_array2(
                intermediate_sum_array, ~other.lower, intermediate_carry_array);
        auto not_carry_array = ~full_adder_array2.carry_array;
        bool lower_carry_out = not_carry_array[0];
        auto new_lower = not_carry_array >> 1;
        auto new_upper = full_adder_array2.sum_array;

        if (lower_carry_out || upper_carry_out) {
            std::cout << "Overflow " << lower_carry_out
                      << upper_carry_out << std::endl;
        }

        return Int<width>(new_upper, new_lower);
    }

    template <int width>
    inline Int<width> OA::Int<width>::operator*(const Int<width>& other) const {
        // not implemented
    }

    template <int width>
    inline Int<width> OA::Int<width>::operator-() const {
        return Int<width>(lower, upper);
    }

    template <int width>
    inline Int<width> OA::Int<width>::operator-(const Int<width>& other) const {
        return *this + (-other);
    }
}

#endif /* int_hpp */
