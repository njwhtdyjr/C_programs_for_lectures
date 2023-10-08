
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

	double e001 = 2.718281828459045;
	double a100 = 1.0 / 100.0;
	double ae100 = 1.0 / e001 / 100.0;
	double astep100 = 0.5 * (a100 + ae100);
	std::cout << "a100 = " << a100 << ",  astep100 = " << astep100 << ", ae100 = " << ae100 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	double Istar_o[10];
	double Istar_stable[10];
	double Istar_stable_con[20];

	Istar_o[0] = con_d_4(1.0 - 1.0 / e001);

	for (int i = 1; i < 10; i++)
	{
		Istar_o[i] = con_d_4(1 - i * Istar_o[i - 1]);
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Istar_o[" << i << "] = " << Istar_o[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	Istar_stable[9] = con_d_4(0.5 * (1.0 / 10.0 + 1.0 / e001 / 10.0));

	for (int i = 8; i >= 0; i--)
	{
		Istar_stable[i] = con_d_4(1.0 / (i + 1) * (1.0 - Istar_stable[i + 1]));
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Istar_stable[" << i << "] = " << Istar_stable[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	Istar_stable_con[19] = (0.5 * (1.0 / 20.0 + 1.0 / e001 / 20.0));

	for (int i = 18; i >= 0; i--)
	{
		Istar_stable_con[i] = (1.0 / (i + 1) * (1.0 - Istar_stable_con[i + 1]));
	}

	for (int i = 0; i < 20; i++)
	{
		std::cout << "Istar_stable_con[" << i << "] = " << Istar_stable_con[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	double Istar_o_res[10];
	double Istar_o_res_rela[10];
	double Istar_stable_res[10];
	double Istar_stable_res_rela[10];

	for (int i = 0; i < 10; i++)
	{
		Istar_o_res[i] = Istar_o[i] - Istar_stable_con[i];
		Istar_o_res_rela[i] = Istar_o_res[i] / Istar_stable_con[i];

		Istar_stable_res[i] = Istar_stable[i] - Istar_stable_con[i];
		Istar_stable_res_rela[i] = Istar_stable_res[i] / Istar_stable_con[i];
	}
	std::cout << "Istar_o_res" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << ", " << Istar_o_res[i] << ", " << Istar_o_res_rela[i] << std::endl;
	}

	std::cout << "Istar_stable_res" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << ", " << Istar_stable_res[i] << ", " << Istar_stable_res_rela[i] << std::endl;
	}

	return 0;
}