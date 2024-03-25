#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int k, n, e, f = 0;
    cout << "Введите цену хлеба: ";
    cin >> n;
    cout << "Введите начальную сумму денег мальчика: ";
    cin >> k;


    if (k < 0 || n < 0) {
        cout << "Недопустимый ввод" << endl;
    }
    else {

        _asm {
            mov esi, 1
            mov eax, k
            mov ebx, n
            xor ecx, ecx
            mov edi, f

            cmp eax, ebx
            je ifEqual
            jnb ifBigger

            cmp eax, 0
            je zero

            push eax
            push ecx
            mov eax, esi
            mov ecx, 4
            xor edx, edx
            idiv ecx 
            pop ecx
            pop eax
            cmp edx, 0
            je baba

        cycle:

            add esi, 1
            imul eax, 2
            cmp eax, ebx
            jnb ifBigger

                push eax
                push ecx
                mov eax, esi
                mov ecx, 4
                xor edx, edx
                idiv ecx
                pop ecx
                pop eax
                cmp edx, 0
                je baba


            add esi, 1
            imul eax, 3
            cmp eax, ebx
            jnb ifBigger

                push eax
                push ecx
                mov eax, esi
                mov ecx, 4
                xor edx, edx
                idiv ecx
                pop ecx
                pop eax
                cmp edx, 0
                je baba


            push eax
            push ecx
            mov eax, esi
            mov ecx, 5
                xor edx, edx
            idiv ecx
                pop ecx
                pop eax
            cmp edx, 0
            je procent
            
            jmp baba


        ifEqual:
            mov ecx, 0
            jmp endE

        ifBigger:
            mov ecx, eax
            sub ecx, ebx
            jmp endE

        baba:
            sub eax, 30
            cmp eax, 0
            jng zero
            jmp cycle

                procent:
                imul ebx, 11
                push eax
                push ecx
                mov eax, ebx
                mov ecx, 10
                xor edx, edx
                idiv ecx
                mov ebx, eax
                pop ecx
                pop eax
                jmp cycle

        endE:
            mov e, ecx
            mov edi, 1
            mov f, edi
            jmp endO

        zero:
            cmp eax, ebx
            je ifEqual

                endO:
        }

        if(f == 1)
            cout << "Сдача: " << e << endl;
        else 
            cout << "Мальчик не может купить хлеб" << endl;
    }
}
