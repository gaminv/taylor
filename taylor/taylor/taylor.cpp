// taylor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// e^(-x) = 1 - x + (x^2)/2! - (x^3)/3! + (x^4)/4! + ...
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <stdexcept>
// prototype, declaration (объявление)
double taylor(double x,
    double absError,
    unsigned int numberMax);
int main()
{
    double absError = 1e-3;
    unsigned int numberMax = 1000;
    for (double x = -0.9; x <= 0.9; x += 0.1)
    {
        double s = pow(M_E, -x);
        double t = 0.0;
        try
        {
            t = taylor(x, absError, numberMax);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << s << " | " << t << '\n';
    }
    return 0;
}
// definition (определение)
double taylor(double x,
    double absError,
    unsigned int numberMax)
{
    double denominator = 1;
    double powerX = 1;
    double sum = 1 ;
    double element = 0.0;
    
    for (unsigned int i = 1; i < numberMax; i++)
    {
        powerX *= x;
     
        denominator *= i;
        
        element = powerX / denominator;

        (i % 2 != 0) ? sum -= element : sum += element;
    }



    if (std::fabs(element) > absError)
    {
        throw std::runtime_error("Accuracy absError not achieved by given numberMax");
    }
    return sum;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
