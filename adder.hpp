//
//  adder.hpp
//  Online Arithmetic
//
//  Created by Xitong Gao on 04/01/2016.
//  Copyright © 2016 Xitong Gao. All rights reserved.
//

#ifndef adder_hpp
#define adder_hpp

#include "common.hpp"


namespace OA {

    template <int width>
    class FullAdderArray {

    public:
        BS<width> sum_array;
        BS<width> carry_array;

        inline FullAdderArray(
                BS<width> a, BS<width> b, BS<width> cin) {
            auto a_xor_b = a ^ b;
            sum_array = a_xor_b ^ cin;
            carry_array = (a & b) | (cin & a_xor_b);
        };
    };
}

#endif /* adder_hpp */
