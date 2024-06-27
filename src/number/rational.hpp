#include "../../src/cp-template.hpp"

template < class integer > struct rational {
    integer sign, upper, lower;
    rational(const integer sign, const integer upper, const integer lower) : sign(sign), upper(upper), lower(lower) { reduce(); }
    rational(const integer upper, const integer lower) {
        if(upper == 0 and lower == 0) {
            cerr << "0/0 is not defined" << endl;
            exit(1);
        } else if(upper == 0) {
            this->sign = 1;
            this->upper = 0;
            this->lower = 1;
        } else if(lower == 0) {
            this->sign = 1;
            this->upper = 1;
            this->lower = 0;
        } else {
            const integer upper_sign = upper > 0 ? +1 : -1;
            const integer lower_sign = lower > 0 ? +1 : -1;
            this->sign = upper_sign * lower_sign;
            this->upper = upper_sign * upper;
            this->lower = lower_sign * lower;
            reduce();
        }
    }

    friend rational operator+(const rational& a) { return *this; }
    friend rational operator-(const rational& a) { return rational(-a.sign, a.upper, a.lower); }
    friend rational operator+(const rational& a, const rational& b) { return rational((a.sign * a.upper) * b.lower + a.lower * (b.sign * b.upper), a.lower * b.lower); }
    friend rational operator-(const rational& a, const rational& b) { return rational((a.sign * a.upper) * b.lower - a.lower * (b.sign * b.upper), a.lower * b.lower); }
    friend rational operator*(const rational& a, const rational& b) { return rational(a.sign * b.sign, a.upper * b.upper, a.lower * b.lower); }
    friend rational operator/(const rational& a, const rational& b) { return rational(a.sign * b.sign, a.upper * b.lower, a.lower * b.upper); }
    friend bool operator==(const rational& a, const rational& b) { return a.sign == b.sign and a.upper == b.upper and a.lower == b.lower; }
    friend bool operator!=(const rational& a, const rational& b) { return a.sign != b.sign or  a.upper != b.upper or  a.lower != b.lower; }
    friend bool operator<(const rational& a, const rational& b) {
        if(a.sign != b.sign)
            return a.sign == -1;
        else
            return (a.sign == -1) ^ (a.upper * b.lower < b.upper * a.lower);
    }
    rational& operator+=(const rational& r) { *this = *this + r; }
    rational& operator-=(const rational& r) { *this = *this - r; }
    rational& operator*=(const rational& r) { *this = *this * r; }
    rational& operator/=(const rational& r) { *this = *this / r; }

    friend std::ostream &operator<<(std::ostream& os, const rational& a) {
        os << (a.sign * a.upper) << "/" << a.lower;
        return os;
    }

  private:
    // for i128, boost::mp
    integer gcd(const integer a, const integer b) const {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    void reduce() {
        integer g = gcd(upper, lower);
        if(g != 0) {
            upper /= g;
            lower /= g;
        }
    }
};
