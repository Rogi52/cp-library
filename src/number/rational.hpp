template < class integer > struct rational {
    integer sign, upper, lower;
    rational(const integer sign, const integer upper, const integer lower) : sign(sign), upper(upper), lower(lower) { reduce(); }
    rational(const integer upper, const integer lower) {
        const integer upper_sign = upper / abs(upper);
        const integer lower_sign = lower / abs(lower);
        this->sign  = upper_sign * lower_sign;
        this->upper = upper_sign * upper;
        this->lower = lower_sign * lower;
        reduce();
    }
    friend rational operator-(const rational& a) { return rational(-a.sign, a.upper, a.lower); }
    friend rational operator+(const rational& a, const rational& b) {
        if(a.sign == b.sign)
            return rational(a.sign, a.upper * b.lower + a.lower * b.upper, a.lower * b.lower);
        else
            return rational((a.sign * a.upper) * b.lower + a.lower * (b.sign * b.upper), a.lower * b.lower);
    }
    friend rational operator*(const rational& a, const rational& b) { return rational(a.sign * b.sign, a.upper * b.upper, a.lower * b.lower); }
    friend rational operator/(const rational& a, const rational& b) { return rational(a.sign * b.sign, a.upper * b.lower, a.lower * b.upper); }
    friend bool operator==(const rational& a, const rational& b) { return a.sign == b.sign and a.upper == b.upper and a.lower == b.lower; }
    friend bool operator<(const rational& a, const rational& b) {
        if(a.sign != b.sign)
            return a.sign == -1;
        else
            return (a.sign == -1) ^ (a.upper * b.lower < b.upper * a.lower);
    }
    friend std::ostream &operator<<(std::ostream& os, const rational& a) {
        os << (a.sign * a.upper) << "/" << a.lower;
        return os;
    }

  private:
    integer abs(const integer x) const { return +x >= -x ? +x : -x; }
    integer gcd(const integer a, const integer b) const { if(b == 0) return a; return gcd(b, a % b); }
    void reduce() { integer g = gcd(upper, lower); upper /= g, lower /= g; }
};
