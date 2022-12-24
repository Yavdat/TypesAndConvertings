#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void PrintAverage() {
    vector<int> t = {8, 7, 3};

    int sum = 0;
    for (int x : t) {
        sum += x;
    }

    auto t_size = t.size(); // unsigned long

    // int avg = sum / t_size; // использование знакового и безнакового типов
    int avg = sum / static_cast<int>(t_size); // преобразовал в беззнаковый в знаковый

    cout << avg << endl; // 1431655761 при равенстве vector<int> t = {-8, -7, 3};
}

int main() {
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

    int y = -1;
    unsigned z = 1;

    cout << (y < z) << endl;

    cout << (-1 < 1u) << endl;

    vector<int> v = {4, 5};

    for (int i = 0; i < v.size(); ++i) { // int i будет вызывать некоторые проблемы при сравнении (signed/unsigned comparison)
        cout << i << " " << v[i] << endl;
    }

    for (size_t i = 0; i < v.size(); ++i) { // 1 способ решения: используем size_t
        cout << i << " " << v[i] << endl;
    }

    for (int i = 0; i < static_cast<int>(v.size()); ++i) { // 2 способ решения, явно преобразовываем v.size() к знаковому типу
        cout << i << " " << v[i] << endl;
    }

    return 0;
}