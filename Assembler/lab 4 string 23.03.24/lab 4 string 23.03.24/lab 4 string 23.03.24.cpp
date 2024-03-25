#include <iostream>
using namespace std;

int main() {
	const int N = 255;
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char stroka[N];
	cin >> stroka;

	_asm {
		lea esi, stroka
		lea edi, letters
	}
}