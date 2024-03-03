#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int N, mult;
    
    cout << "Задача: Найти произведение нечетных цифр целого числа N" << endl
        << "Введите целое целое число N: ";
   
    cin >> N;

    _asm {
        mov eax, N
        mov ecx, 1
        mov ebx, 10

    cycle :
        xor edx, edx
        div ebx
        test dl, 1
        jz skip
        imul ecx, edx
    skip :
        cmp eax, 0
        jne cycle
        
        mov mult, ecx
    }

    if (mult == 1 && to_string(N).find('1') == -1) {
        cout << "В числе N нет нечетных цифр" << endl;
    }
    else {
        cout << "Произведение нечетных цифр целого числа N: " << mult << endl;
    }
}
