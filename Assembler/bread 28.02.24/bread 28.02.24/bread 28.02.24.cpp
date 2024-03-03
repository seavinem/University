#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int k, n, e;
    cout << "Введите цену хлеба: ";
    cin >> n;
    cout << "Введите начальную сумму денег мальчика: ";
    cin >> k;

    if (k < 0 || n < 0) {
        cout << "Недопустимый ввод" << endl;
    }
    else {

        _asm {
            mov eax, k
            mov ebx, n
            xor ecx, ecx

            cmp eax, ebx
            je ifEqual

        cycle:
            cmp eax, ebx
            jnb ifBigger
            imul eax, 2
            cmp eax, ebx
            jnb ifBigger
            imul eax, 3
            cmp eax, ebx
            jnb ifBigger
            jmp cycle


        ifEqual:
            mov ecx, 0
            jmp endE

        ifBigger:
            mov ecx, eax
            sub ecx, ebx
            jmp endE

        endE:
            mov e, ecx
            mov k, eax
            mov n, ebx
        }

        cout << endl << "Конечная сумма денег мальчика перед покупкой хлеба: " << k << endl
            << "Цена хлеба: " << n << endl
            << "Сдача: " << e << endl;
    }
}
