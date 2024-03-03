#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int y1, y2;

	//пример 3.4.
	//VARIANT 1
	_asm
	{
		mov ecx, 1	// k
		xor ebx, ebx	// clean sum OUT
		sumOut1 :
		push ecx
			mov esi, ecx	// n=k
			sumIn1 :
		mov eax, esi	// n -> eax
			imul eax, esi	// eax * n -> n^2
			add eax, ecx	// eax + k -> n^2 + k
			imul eax, eax	// eax * eax -> (n^2 + k)^2
			add ebx, eax	// eax -> sum OUT
			inc esi	// n++
			cmp esi, 5	// n<=5 ?
			jng sumIn1	// yes -> continue sum IN
			pop ecx
			inc ecx	// no -> k++ && quit sum IN && continue sum OUT
			cmp ecx, 5	// k<=5 ?
			jng sumOut1	// yes-> continue sum OUT
			mov y1, ebx	// no -> quit sum OUT && ebx -> y1
	}
	cout << "пример 3.4.: " << y1 << endl;


	//пример 3.5.
	//VARIANT 2
	_asm
	{
		mov ecx, 1 // k
		xor ebx, ebx // clean sum OUT
		sumOut2 :
		push ecx
			mov esi, ecx // n=k
			sumIn2 :
		mov eax, esi	// n -> eax
			imul eax, esi	// eax * n -> n^2
			mov edx, ecx	// k -> edx
			imul edx, edx	// edx * edx -> k^2
			add eax, edx	// eax + k -> n^2 + k^2
			imul eax, eax	// eax * eax -> (n^2 + k^2)^2
			add ebx, eax	// eax -> sum OUT
			inc esi	// n++
			cmp esi, 5	// n<=5 ?
			jng sumIn2	// yes -> continue sum IN
			pop ecx
			inc ecx	// no -> k++ && quit sum IN && continue sum OUT
			cmp ecx, 5	// k<=5 ?
			jng sumOut2	// yes-> continue sum OUT
			mov y2, ebx	// no -> quit sum OUT && ebx -> y2
	}
	cout << "пример 3.5.: " << y2 << endl;
}