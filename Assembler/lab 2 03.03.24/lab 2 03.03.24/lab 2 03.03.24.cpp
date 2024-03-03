#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;


    if (n <= 0) {
        cout << "Недопустимый ввод" << endl;
        return 1;
    }

    int* arr = new int [n];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;


    if (n == 1) {
        cout << "Сдвигать нечего" << endl;
    }
    else {
        _asm {
            mov ecx, n
            dec ecx
            mov esi, arr
            mov ebx, [esi]
            cikl2 :
            mov eax, ebx
                mov ebx, [esi + 4]
                mov[esi + 4], eax
                add esi, 4
                loop cikl2

                mov esi, arr
                mov[esi], ebx
        }



        cout << "Массив после сдвига: ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
}