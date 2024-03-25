#include <iostream>
using namespace std;

extern "C" int __stdcall procedure1(int* arr, int n);
extern "C" int __cdecl procedure2(int* arr, int n);
extern "C" int __stdcall procedure3(int* arr, int n);
extern "C" int __cdecl procedure4(int* arr, int n);
extern "C" int __fastcall procedure5(int* arr, int n);

int main()
{
    int arr[] = { 3, -2, 5, -4, 1 };
    int n = sizeof(arr) / sizeof(int);

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int* arr1 = new int[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }

    procedure1(arr1, n);
    cout << "Результат вызова procedure1: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    int* arr2 = new int[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }

    procedure2(arr2, n);
    cout << "Результат вызова procedure2: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    int* arr3 = new int[n];
    for (int i = 0; i < n; i++) {
        arr3[i] = arr[i];
    }

    procedure3(arr3, n);
    cout << "Результат вызова procedure3: ";
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    int* arr4 = new int[n];
    for (int i = 0; i < n; i++) {
        arr4[i] = arr[i];
    }

    procedure4(arr4, n);
    cout << "Результат вызова procedure4: ";
    for (int i = 0; i < n; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;

    int* arr5 = new int[n];
    for (int i = 0; i < n; i++) {
        arr5[i] = arr[i];
    }

    procedure5(arr5, n);
    cout << "Результат вызова procedure5: ";
    for (int i = 0; i < n; i++) {
        cout << arr5[i] << " ";
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    return 0;
}
