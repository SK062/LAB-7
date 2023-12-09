#include <iostream>
#include <random>
#include <valarray>
#include <locale>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    int arraySize;

    cout << "Введiть розмiр масиву:" << endl;
    cin >> arraySize;

    if (arraySize <= 0)
    {
        cout << "Розмiр масиву повинен бути бiльше 0" << endl;
        return 1;
    }

    random_device rd;   // Джерело ентропії
    mt19937 gen(rd());  // Рандомайзер
    uniform_int_distribution<> distribution(1, 100);    //Кількість повторень

    vector<int> randomNumbers(arraySize);
    for (int i = 0; i < arraySize; ++i) {
        randomNumbers[i] = distribution(gen);
    }

    valarray<int> valArr(&randomNumbers[0], arraySize);
    cout << "Змiст valarray:\n";
    for (int i = 0; i < valArr.size(); ++i) {
        cout << valArr[i] << " ";
    }
    cout << endl;

    int sum = valArr.sum();
    cout << "Сума:\n" << sum << endl;

    int min = valArr.min();
    cout << "Мiнiмальне значення:\n" << min << endl;
    int max = valArr.max();
    cout << "Максимальне значення:\n" << max << endl;
    double average = static_cast<double>(sum) / valArr.size();
    cout << "Середнє арифметичне:\n" << average << endl;

    return 0;
}
