#include <iostream>
#include <cmath>

double time1, timedif;

double fibonacci(int n) {
    double Phi = pow(((1 + sqrt(5)) / 2), n);
    double phi = pow(((1 - sqrt(5)) / 2), n);
    double m = (Phi - phi) / sqrt(5);
    
    return m;
}

int main() {
    long num1{1};
    long num2{1};
    long temp{0};
    
    time1 = (double)clock();
    time1 = time1 / CLOCKS_PER_SEC;

    std::cout << "Enter iteration number: ";
    int iter{};
    std::cin >> iter;

    for (int i = 0; i < iter; i++)
    {
        temp = num2;
        num2 = num2 + num1;
        num1 = temp;
    }

    timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;

    // std::cout << "The result: " << num2 << "\n";
    std::cout << "The result from formula: " << fibonacci(iter + 2) << "\n";
    printf("The elapsed time is %lf seconds\n\n", timedif);

    return 0;
}
