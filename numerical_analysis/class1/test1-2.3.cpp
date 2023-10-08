
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

    double pi30 = 3.141592653589793;
    double ppi30 = con_d_8(pi30);
    std::cout << "absolute error of " << pi30 << "   = " << ppi30 - pi30 << std::endl;
    std::cout << "relative error = " << (ppi30 - pi30) / pi30 << std::endl;

    double pi31 = 0.000123456789123;
    double ppi31 = con_d_8(pi31);
    std::cout << "absolute error of " << pi31 << "   = " << (ppi31 - pi31) << std::endl;
    std::cout << "relative error = " << (ppi31 - pi31) / pi31 << std::endl;

    double mp30 = pi30 / pi31;
    double mpp30 = con_d_8(ppi30 / ppi31);
    std::cout << "absolute error of " << mp30 << "   = " << (mpp30 - mp30) << std::endl;
    std::cout << "relative error = " << (mpp30 - mp30) / mp30 << std::endl;

    return 0;
}