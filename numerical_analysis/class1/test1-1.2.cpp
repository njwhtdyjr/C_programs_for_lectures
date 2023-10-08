
#include <iostream>
#include <sstream> //字符串流函数的调用准备
#include <iomanip> //格式化操作的调用准备

#include "convert.hpp"

int main(int argc, char *argv[])
{
    std::cout.precision(12);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    double f5 = 4.015 * 100;
    std::cout << "Product of " << 4.015 << " and " << 100 << " is " << con_d_3(f5) << std::endl;
    std::cout << f5 << " to 3 precision: " << con_d_3(f5) << std::endl;

    double ff5 = con_d_3(4.015 * 100);
    std::cout << ff5 << std::endl;

    double fff5 = con_d_3(401.5);
    std::cout << fff5 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    float f6 = 7654321.0f;
    float f7 = 0.4f;

    float f8 = con_f_7(f6 + f7);
    std::cout << "Sum of " << f6 << " and " << f7 << " is " << f8 << std::endl;

    std::cout << f6 + f7 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}