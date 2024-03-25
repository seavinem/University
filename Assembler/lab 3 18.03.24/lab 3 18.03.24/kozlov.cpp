#include <iostream>
using namespace std;

extern "C" int __stdcall Procedure1(int* arr, int n);
extern "C" int __cdecl Procedure2(int* arr, int n);
extern "C" int __stdcall Procedure3(int* arr, int n);
extern "C" int __cdecl Procedure4(int* arr, int n);
extern "C" int __fastcall Procedure5(int* arr, int n);

int main() {
    setlocale(LC_ALL, "ru");

    int arr1[] = { 1 };
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int* arr2 = new int[n];
    int* arr3 = new int[n];
    int* arr4 = new int[n];
    int* arr5 = new int[n];

    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
        arr5[i] = arr1[i];
    }


    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i) {
        cout << arr1[i] << ' ';
    }
    cout << endl;


    Procedure1(arr1, n);
    Procedure2(arr2, n);
    Procedure3(arr3, n);
    Procedure4(arr4, n);
    Procedure5(arr5, n);

    cout << endl << "Массив после сдвига: " << endl << endl;

    cout << "Procedure1: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Procedure2: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Procedure3: ";
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    cout << "Procedure4: ";
    for (int i = 0; i < n; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;

    cout << "Procedure5: ";
    for (int i = 0; i < n; i++) {
        cout << arr5[i] << " ";
    }
    cout << endl;
}