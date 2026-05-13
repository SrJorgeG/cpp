#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cmath>
#include <sstream>
#include <iomanip>

// --- Private constructors/destructor to prevent instantiation ---

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

// --- Helper: detect literal type ---

enum LiteralType
{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO_FLOAT,
    TYPE_PSEUDO_DOUBLE,
    TYPE_INVALID
};

static LiteralType detectType(const std::string& literal)
{
    // Char: 'c' format (single char with quotes)
    if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return TYPE_CHAR;

    // Single printable non-digit character (shell strips quotes from 'c')
    if (literal.size() == 1 && !isdigit(literal[0]))
        return TYPE_CHAR;

    // Pseudo float literals
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return TYPE_PSEUDO_FLOAT;

    // Pseudo double literals
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return TYPE_PSEUDO_DOUBLE;

    // Numeric detection
    int i = 0;
    bool hasDot = false;
    bool hasF = false;

    if (literal[i] == '-' || literal[i] == '+')
        i++;

    if (literal[i] == '\0')
        return TYPE_INVALID;

    if (!isdigit(literal[i]))
        return TYPE_INVALID;

    while (literal[i] && isdigit(literal[i]))
        i++;

    if (literal[i] == '.')
    {
        hasDot = true;
        i++;
        // Must have at least one digit after dot
        if (!literal[i] || !isdigit(literal[i]))
            return TYPE_INVALID;
        while (literal[i] && isdigit(literal[i]))
            i++;
    }

    if (literal[i] == 'f' && hasDot)
    {
        hasF = true;
        i++;
    }

    if (literal[i] != '\0')
        return TYPE_INVALID;

    if (hasF)
        return TYPE_FLOAT;
    if (hasDot)
        return TYPE_DOUBLE;
    return TYPE_INT;
}

// --- Helper: format float with proper precision ---

static std::string formatFloat(float f)
{
    if (std::isnan(f))
        return "nanf";
    if (std::isinf(f))
    {
        if (f < 0)
            return "-inff";
        return "+inff";
    }

    std::ostringstream oss;
    oss << std::setprecision(7) << f;
    std::string s = oss.str();
    // Ensure decimal point is present
    if (s.find('.') == std::string::npos && s.find('e') == std::string::npos)
        s += ".0";
    s += "f";
    return s;
}

// --- Helper: format double with proper precision ---

static std::string formatDouble(double d)
{
    if (std::isnan(d))
        return "nan";
    if (std::isinf(d))
    {
        if (d < 0)
            return "-inf";
        return "+inf";
    }

    std::ostringstream oss;
    oss << std::setprecision(15) << d;
    std::string s = oss.str();
    // Ensure decimal point is present
    if (s.find('.') == std::string::npos && s.find('e') == std::string::npos)
        s += ".0";
    return s;
}

// --- Main convert method ---

void ScalarConverter::convert(const std::string& literal)
{
    LiteralType type = detectType(literal);

    switch (type)
    {
        case TYPE_CHAR:
        {
            char c;
            if (literal.size() == 3)
                c = literal[1]; // 'c' format
            else
                c = literal[0]; // bare char (shell stripped quotes)

            if (!std::isprint(static_cast<int>(c)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << c << "'" << std::endl;

            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << formatFloat(static_cast<float>(c)) << std::endl;
            std::cout << "double: " << formatDouble(static_cast<double>(c)) << std::endl;
            break;
        }

        case TYPE_INT:
        {
            std::istringstream iss(literal);
            long val;
            iss >> val;

            if (iss.fail() || val < INT_MIN || val > INT_MAX)
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << formatFloat(static_cast<float>(val)) << std::endl;
                std::cout << "double: " << formatDouble(static_cast<double>(val)) << std::endl;
            }
            else
            {
                int n = static_cast<int>(val);

                if (n < 0 || n > 127)
                    std::cout << "char: impossible" << std::endl;
                else if (!std::isprint(n))
                    std::cout << "char: Non displayable" << std::endl;
                else
                    std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;

                std::cout << "int: " << n << std::endl;
                std::cout << "float: " << formatFloat(static_cast<float>(n)) << std::endl;
                std::cout << "double: " << formatDouble(static_cast<double>(n)) << std::endl;
            }
            break;
        }

        case TYPE_FLOAT:
        case TYPE_PSEUDO_FLOAT:
        {
            float f = std::strtof(literal.c_str(), NULL);

            // char
            if (std::isnan(f) || std::isinf(f) ||
                f < static_cast<float>(SCHAR_MIN) || f > static_cast<float>(SCHAR_MAX))
                std::cout << "char: impossible" << std::endl;
            else if (!std::isprint(static_cast<int>(f)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

            // int
            if (std::isnan(f) || std::isinf(f) ||
                f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(f) << std::endl;

            // float
            std::cout << "float: " << formatFloat(f) << std::endl;

            // double
            std::cout << "double: " << formatDouble(static_cast<double>(f)) << std::endl;
            break;
        }

        case TYPE_DOUBLE:
        case TYPE_PSEUDO_DOUBLE:
        {
            double d = std::strtod(literal.c_str(), NULL);

            // char
            if (std::isnan(d) || std::isinf(d) ||
                d < SCHAR_MIN || d > SCHAR_MAX)
                std::cout << "char: impossible" << std::endl;
            else if (!std::isprint(static_cast<int>(d)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

            // int
            if (std::isnan(d) || std::isinf(d) ||
                d < INT_MIN || d > INT_MAX)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(d) << std::endl;

            // float
            std::cout << "float: " << formatFloat(static_cast<float>(d)) << std::endl;

            // double
            std::cout << "double: " << formatDouble(d) << std::endl;
            break;
        }

        case TYPE_INVALID:
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}