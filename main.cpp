#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    vector<int> t = {8, 7, 3};

    int sum = 0;
    for (int x : t) {
        sum += x;
    }

    auto t_size = t.size(); // unsigned long

    int avg = sum / t_size; // использование знакового и безнакового типов
    cout << avg << endl; // 1431655761 при равенстве vector<int> t = {-8, -7, 3};

    int x = 2'000'000'000;
    cout << x << " " << endl;
    x *= 2; // -294967296 не поместилось
    cout << x << " " << endl;

    // Типы с известным размером <cstdint>
    // int32_t - знаковый, всегда 32 бита
    // uint32_t - беззнаковый, всегда 32 бита

    cout << sizeof(int) << endl;
    cout << numeric_limits<int>::min() << " " <<
            numeric_limits<int>::max() << endl;

    cout << numeric_limits<int>::min() + 1 << " " <<
        numeric_limits<int>::max() -1 << endl; // получим максимум потом минимум

    

    return 0;
}