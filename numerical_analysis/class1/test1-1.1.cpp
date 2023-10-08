
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

    double f1 = 0.12346845;
    std::cout << f1 << " to 4 precision: " << con_d_4(f1) << std::endl;
    double f1_res = con_d_4(f1) - f1;
    std::cout << "absolute error = " << f1_res << std::endl;
    std::cout << "relative error = " << f1_res / f1 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    double f2 = 0.012346845;
    std::cout << f2 << " to 4 precision: " << con_d_4(f2) << std::endl;
    double f2_res = con_d_4(f2) - f2;
    std::cout << "absolute error = " << f2_res << std::endl;
    std::cout << "relative error = " << f2_res / f2 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    double f3 = 0.0012346845;
    std::cout << f3 << " to 4 precision: " << con_d_4(f3) << std::endl;
    double f3_res = con_d_4(f3) - f3;
    std::cout << "absolute error = " << f3_res << std::endl;
    std::cout << "relative error = " << f3_res / f3 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    double f4 = 0.0000012346845;
    std::cout << f4 << " to 4 precision: " << con_d_4(f4) << std::endl;
    double f4_res = con_d_4(f4) - f4;
    std::cout << "absolute error = " << f4_res << std::endl;
    std::cout << "relative error = " << f4_res / f4 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;


    return 0;
}