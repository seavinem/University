#include <iostream>
using namespace std;

int main() {
    char* input = new char[255];
    char* uppercaseWords = new char[255];

    cout << "Enter a string (max 255 characters): ";
    cin.getline(input, 256);


    _asm {
        mov esi, input
        mov edi, uppercaseWords
        mov ecx, 0 
        mov ebx, 0

    word_loop:
        mov al, [esi]

        cmp al, 0
        je end_loop
        cmp al, ' '
        je word_end

        inc ebx
        
        cmp al, 'A'
        jl not_uppercase
        cmp al, 'Z'
        jg not_uppercase

        inc ecx
        inc esi
        
        jmp word_loop

    not_uppercase:
        inc esi
        jmp word_loop

    word_end:
        cmp ebx, 0
        je space
        cmp ebx, ecx
        je add_word
        mov ecx, 0
        mov ebx, 0
        inc esi
        jmp word_loop

    add_word:
        sub esi, ecx

    move_cycle :
        cmp ebx, 0
        je add_word_end
        movsb
        dec ebx
        jmp move_cycle

    add_word_end:
        mov [edi], ' '
        inc edi
        mov ecx, 0
        mov ebx, 0
        jmp word_loop

    space:
        inc esi
        jmp word_loop


    end_loop :
        cmp ebx, 0
        je end_
        cmp ebx, ecx
        je add_word

    end_:
        mov[edi], 0
    }

    if(strlen(uppercaseWords) != 0)
        cout << "Uppercase words: " << uppercaseWords << endl;
    else
        cout << "No uppercase words" << endl;
}