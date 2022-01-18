#include <iostream>
#include <string>
#include <limits>

#define FLAG_CHAR 0
#define FLAG_SPECIAL 1
#define FLAG_INT 2
#define FLAG_DECIMAL_ZERO 3
#define FLAG_DECIMAL_NONZERO 4

void put_int_to_char(int num)
{
    if (' ' <= num && num <= '~')
    {
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    }
    else if (0 <= num && num <= 127)
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }
}

void put_float_to_int_and_char(float num)
{
    if (num < std::numeric_limits<int>::min() || \
        std::numeric_limits<int>::max() < num)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        put_int_to_char(static_cast<int>(num));
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    }
}

void put_double_to_int_and_char(double num)
{
    if (num < std::numeric_limits<int>::min() || \
        std::numeric_limits<int>::max() < num)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        put_int_to_char(static_cast<int>(num));
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    }
}

int check_numeric_and_exit(const std::string& str, int& num)
{
    if (str.length() == 1 && (str[0] < '0' || '9' < str[0] ))
    {
        return FLAG_CHAR;
    }

    if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf" || \
        str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
    {
        return FLAG_SPECIAL;
    }

    num = 0;
    bool dot_flag = false;
    int decimal_zero_flag = true;
    bool zero_flag = false;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == '.')
        {
            if (dot_flag)
            {
                std::cout << str << " can't convert." << std::endl;
                return -1;
            }
            dot_flag = true;
        }
        else if ('0' <= str[i] && str[i] <= '9')
        {
            if (str[i] != '0')
            {
                zero_flag = true;
                if (dot_flag)
                {
                    decimal_zero_flag = false;
                }
            }
            if (zero_flag && !dot_flag)
            {
                ++num;
            }
        }
        else
        {
            if ((i == 0 && (str[i] == '-' || str[i] == '+')) || \
                (i == str.length() - 1 && str[i] == 'f' && dot_flag))
            {
                continue;
            }
            std::cout << str << " can't convert." << std::endl;
            return -1;
        }
    }
    return (!dot_flag) ? FLAG_INT : decimal_zero_flag ? FLAG_DECIMAL_ZERO : FLAG_DECIMAL_NONZERO;
}

void put_double(double value, int num, int flag)
{
    if (num == 6 || ((flag == FLAG_DECIMAL_ZERO || flag == FLAG_INT) && num < 6))
    {
        std::cout << "double: " << value << ".0" << std::endl;
    }
    else
    {
        std::cout << "double: " << value << std::endl;
    }
}

void put_float(float value, int num, int flag)
{
    if (num == 6 || ((flag == FLAG_DECIMAL_ZERO || flag == FLAG_INT) && num < 6))
    {
        std::cout << "float: " << value << ".0f" << std::endl;
    }
    else
    {
        std::cout << "float: " << value << "f" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Only one argument" << std::endl;
        return 0;
    }

    std::string str(argv[1]);
    int num;
    int flag = check_numeric_and_exit(str, num);

    if (flag < 0)
    {
        return 0;
    }

    if (flag == FLAG_CHAR)
    {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return 0;
    }

    int int_num = 0;
    bool int_flag = false;
    try
    {
        int_num = std::stoi(str);
        int_flag = true;
    }
    catch(const std::exception& e) {}

    double double_num = 0;
    bool double_flag = false;
    try
    {
        double_num = std::stod(str);
        double_flag = true;
    }
    catch(const std::exception& e) {}

    float float_num = 0;
    bool float_flag = false;
    try
    {
        float_num = std::stof(str);
        float_flag = true;
    }
    catch(const std::exception& e) {}

    if (!double_flag)
    {
        std::cout << str << " can't convert." << std::endl;
        return 0;
    }

    if (flag == FLAG_INT)
    {
        if (!int_flag)
        {
            std::cout << str << " can't convert." << std::endl;
            return 0;
        }
        put_int_to_char(int_num);
        std::cout << "int: " << int_num << std::endl;
        put_float(static_cast<float>(int_num), num, flag);
        put_double(static_cast<double>(int_num), num, flag);
        return 0;
    }

    if (str[str.length() - 1] == 'f')
    {
        if (!float_flag)
        {
            std::cout << str << " can't convert." << std::endl;
            return 0;
        }
        if (flag == FLAG_SPECIAL)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << float_num << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(float_num) << std::endl;
            return 0;
        }
        put_float_to_int_and_char(float_num);
        put_float(float_num, num, flag);
        put_double(static_cast<double>(float_num), num, flag);
        return 0;
    }

    if (flag == FLAG_SPECIAL)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(double_num) << "f" << std::endl;
        std::cout << "double: " << double_num << std::endl;
        return 0;
    }
    put_double_to_int_and_char(double_num);
    if (!float_flag)
    {
        std::cout << "float: impossible" << std::endl;
    }
    else
    {
        put_float(static_cast<float>(double_num), num, flag);
    }
    put_double(double_num, num, flag);
    return 0;
}
