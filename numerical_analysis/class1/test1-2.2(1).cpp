
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

    double pi20 = 7654321.0;
    double pi21 = 0.2;

    double pi22 = con_d_7(pi20 + pi21 + pi21 + pi21 + pi21 + pi21);
    std::cout << "Sum of " << pi20 << " and five " << pi21 << " is " << pi22 << std::endl;

    double pi23 = con_d_7(pi21 + pi21 + pi21 + pi21 + pi21 + pi20);
    std::cout << "Sum of five " << pi21 << " and  " << pi20 << " is " << pi23 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}