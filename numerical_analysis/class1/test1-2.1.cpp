
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

    double pi0 = 3.141592653589793;
    double ppi0 = con_d_8(pi0);
    std::cout << "absolute error of " << pi0 << "   = " << ppi0 - pi0 << std::endl;
    std::cout << "relative error = " << (ppi0 - pi0) / pi0 << std::endl;

    double pi1 = pi0 + 0.000123456789123;
    double ppi1 = con_d_8(pi1);
    std::cout << "absolute error of " << pi1 << "   = " << (ppi1 - pi1) << std::endl;
    std::cout << "relative error = " << (ppi1 - pi1) / pi1 << std::endl;

    double mp = pi1 - pi0;
    double mpp = con_d_8(ppi1 - ppi0);
    std::cout << "absolute error of " << mp << "   = " << (mpp - mp) << std::endl;
    std::cout << "relative error = " << (mpp - mp) / mp << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}