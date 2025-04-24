#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <numeric>
namespace mathlib {

    template<typename T>
    class Fraction {
    public:
        Fraction(T numerator, T denominator);
        Fraction();
        void Simplify();

        double ToDouble() const;
        float ToFloat() const;

        template<typename U>
        friend std::ostream& operator<<(std::ostream& stream, const Fraction<U>& fraction);
        
        template<typename U>
        friend std::istream& operator>>(std::istream& stream, Fraction<U>& fraction);

        bool operator==(const Fraction& fraction2) const;
        bool operator!=(const Fraction& fraction2) const;
        bool operator<(const Fraction& fraction2) const;
        bool operator>(const Fraction& fraction2) const;
        bool operator<=(const Fraction& fraction2) const;
        bool operator>=(const Fraction& fraction2) const;

        Fraction operator+(const Fraction& fraction) const;
        Fraction operator-(const Fraction& fraction) const;
        Fraction operator*(const Fraction& fraction) const;
        Fraction operator/(const Fraction& fraction) const;

    private:
        T m_numerator;
        T m_denominator;
        std::string m_errmsg = "Denominator cannot be zero.";
    };

    template<typename T>
    Fraction<T>::Fraction(T numerator, T denominator) {
        if (denominator == 0) {
            throw std::invalid_argument(m_errmsg);
        }
        m_numerator = numerator;
        m_denominator = denominator;
    }

    template<typename T>
    Fraction<T>::Fraction() {
        m_numerator = 1;
        m_denominator = 1;
    }

    template<typename T>
    void Fraction<T>::Simplify() {
        int gcd = std::gcd(m_numerator, m_denominator);
        m_numerator /= gcd;
        m_denominator /= gcd;

        if (m_denominator == 0) {
            throw std::invalid_argument(m_errmsg);
        }
    }

    template<typename T>
    double Fraction<T>::ToDouble() const {
        return static_cast<double>(m_numerator) / m_denominator;
    }

    template<typename T>
    float Fraction<T>::ToFloat() const {
        return static_cast<float>(m_numerator) / m_denominator;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const Fraction<T>& fraction) {
        stream << fraction.m_numerator << "/" << fraction.m_denominator;
        return stream;
    }

    template<typename T>
    std::istream& operator>>(std::istream& stream, Fraction<T>& fraction) {
        char separator;
        stream >> fraction.m_numerator >> separator >> fraction.m_denominator;
        if (fraction.m_denominator == 0) {
            throw std::invalid_argument(fraction.m_errmsg);
        }
        return stream;
    }

    template<typename T>
    bool Fraction<T>::operator==(const Fraction& fraction2) const {
        Fraction<T> temp1 = *this;
        Fraction<T> temp2 = fraction2;
        return (temp1.ToDouble() == temp2.ToDouble());
    }

    template<typename T>
    bool Fraction<T>::operator!=(const Fraction& fraction2) const {
        return !(*this == fraction2);
    }

    template<typename T>
    bool Fraction<T>::operator<=(const Fraction& fraction2) const {
        Fraction<T> temp1 = *this;
        Fraction<T> temp2 = fraction2;
        temp1.Simplify();
        temp2.Simplify();
        return temp1.ToDouble() <= temp2.ToDouble();
    }

    template<typename T>
    bool Fraction<T>::operator>=(const Fraction& fraction2) const {
        Fraction<T> temp1 = *this;
        Fraction<T> temp2 = fraction2;
        temp1.Simplify();
        temp2.Simplify();
        return temp1.ToDouble() >= temp2.ToDouble();
    }

    template<typename T>
    bool Fraction<T>::operator<(const Fraction& fraction2) const {
        Fraction<T> temp1 = *this;
        Fraction<T> temp2 = fraction2;
        temp1.Simplify();
        temp2.Simplify();
        return temp1.ToDouble() < temp2.ToDouble();
    }

    template<typename T>
    bool Fraction<T>::operator>(const Fraction& fraction2) const {
        return !(*this < fraction2);
    }

    template<typename T>
    Fraction<T> Fraction<T>::operator+(const Fraction& fraction) const {
        T numerator = (m_numerator * fraction.m_denominator) + (fraction.m_numerator * m_denominator);
        T denominator = m_denominator * fraction.m_denominator;
        return Fraction<T>(numerator, denominator);
    }

    template<typename T>
    Fraction<T> Fraction<T>::operator-(const Fraction& fraction) const {
        T numerator = (m_numerator * fraction.m_denominator) - (fraction.m_numerator * m_denominator);
        T denominator = m_denominator * fraction.m_denominator;
        return Fraction<T>(numerator, denominator);
    }

    template<typename T>
    Fraction<T> Fraction<T>::operator*(const Fraction& fraction) const {
        T numerator = m_numerator * fraction.m_numerator;
        T denominator = m_denominator * fraction.m_denominator;
        return Fraction<T>(numerator, denominator);
    }

    template<typename T>
    Fraction<T> Fraction<T>::operator/(const Fraction& fraction) const {
        if (fraction.m_numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        T numerator = m_numerator * fraction.m_denominator;
        T denominator = m_denominator * fraction.m_numerator;
        return Fraction<T>(numerator, denominator);
    }
}

#endif //FRACTION_H