#ifndef BITPATTERN_HPP
#define BITPATTERN_HPP

#include <cstdint>
#include <stdexcept>

class BitPattern {
 private:
     
  std::uint64_t expected{};
  std::uint64_t mask{};

 public:
     
  template <std::size_t Size>
  explicit constexpr BitPattern(const char (&input)[Size]) {
      
    std::uint64_t cur_bit = 1;
    cur_bit <<= (Size - 2);
   
    for (const char val : input) {
        
      if (val == 0) {
        return;
      }

      if (val == '1') {
        expected |= cur_bit;
        mask |= cur_bit;
      } else if (val == '0') {
        mask |= cur_bit;
      }

      cur_bit >>= 1;
      
    }
    
  }

  template<typename ValueType>
  constexpr friend bool operator==(const ValueType value, const BitPattern &pattern) {
    return (value & pattern.mask) == pattern.expected;
  }
  
};

#endif
