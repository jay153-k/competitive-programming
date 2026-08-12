#pragma once

#include <cstdint>

template <int MOD>
class ModInt {
public:
    ModInt() : value_(0) {}

    template <typename T>
    ModInt(T value) {
        long long x = static_cast<long long>(value) % MOD;
        if (x < 0) {
            x += MOD;
        }
        value_ = static_cast<int>(x);
    }

    int value() const {
        return value_;
    }

    ModInt& operator+=(const ModInt& other) {
        value_ += other.value_;

        if (value_ >= MOD) {
            value_ -= MOD;
        }

        return *this;
    }

    ModInt& operator-=(const ModInt& other) {
        value_ -= other.value_;

        if (value_ < 0) {
            value_ += MOD;
        }

        return *this;
    }

    ModInt& operator*=(const ModInt& other) {
        value_ = static_cast<int>(
            static_cast<long long>(value_) * other.value_ % MOD
        );

        return *this;
    }

    ModInt& operator/=(const ModInt& other) {
        return *this *= other.inv();
    }

    friend ModInt operator+(ModInt lhs, const ModInt& rhs) {
        return lhs += rhs;
    }

    friend ModInt operator-(ModInt lhs, const ModInt& rhs) {
        return lhs -= rhs;
    }

    friend ModInt operator*(ModInt lhs, const ModInt& rhs) {
        return lhs *= rhs;
    }

    friend ModInt operator/(ModInt lhs, const ModInt& rhs) {
        return lhs /= rhs;
    }

    friend bool operator==(const ModInt& lhs, const ModInt& rhs) {
        return lhs.value_ == rhs.value_;
    }

    friend bool operator!=(const ModInt& lhs, const ModInt& rhs) {
        return !(lhs == rhs);
    }

    ModInt pow(long long exponent) const {
        ModInt base = *this;
        ModInt result = 1;

        while (exponent > 0) {
            if (exponent & 1LL) {
                result *= base;
            }

            base *= base;
            exponent >>= 1;
        }

        return result;
    }

    ModInt inv() const {
        return pow(MOD - 2);
    }

private:
    int value_;
};