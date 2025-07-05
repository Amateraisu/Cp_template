__builtin_popcount(x): Counts the number of one’s(set bits) in an integer(long/long long).

__builtin_parity(x): Checks the Parity of a number.Returns true(1) if the number has odd parity(odd number of set bits) else it returns false(0) for even parity(even number of set bits).

__builtin_clz(x): Counts the leading number of zeros of the integer(long/long long).

__builtin_ffs(x) (Find First Set) which returns (the index of the least significant bits of x) + 1.

If x is of long type,we can use __builtin_clzl(x) If x is of long long type,we can use __builtin_clzll(x)
