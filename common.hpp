#ifndef common_hpp
#define common_hpp

#ifdef HLS
#   include <ap_int.h>
#   define BS ap_int
#else
#   include <bitset>
#   define BS std::bitset
#endif

#endif /* common_hpp */
