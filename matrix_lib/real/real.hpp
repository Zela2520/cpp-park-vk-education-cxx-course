#include <cstddef>
#include <iostream>

class Real {
    public:
    explicit Real() : m_number(0.0) {}
    explicit Real(double number) : m_number(number) {}
    
    operator double() { return m_number; }
    float toFloat() { return static_cast<float>(m_number); }
    int toInt() { return static_cast<int>(m_number); }

    private:
        double m_number;
};