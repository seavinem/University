#include <iostream>
#include <time.h>
using namespace std;
int main() { 
	
	//статические массивы
	int a[] = { 4,6,8,10 };
	int x, y, pr;
	short y1;
	short a1[] = { 4,6,8,10 };
	
	//сумма элементов массива типа int
	_asm {
		mov ecx, 4
		xor eax, eax
		xor esi, esi //очистка индексного регистра
	cikl :
		add eax, dword ptr a[esi]
		add esi, 4 //увеличение индексного регистра на длину элемента
		loop cikl
		mov y, eax
	}
	cout << "sum=" << y << endl;
	
	//2-ой вариант: сумма элементов массива типа int
	_asm {
		mov ecx, 4
		xor eax, eax
		lea esi, a //занесение адреса массива a в регистр esi
	cikl2 :
		add eax, [esi]
		add esi, 4
		loop cikl2
		mov y, eax
	}
	cout << "sum=" << y << endl;
	
	//сумма элементов статического массива типа short
	_asm {
		mov ecx, 4
		xor eax, eax
		xor esi, esi
	cikl3 :
		add ax, word ptr a1[esi]
		add esi, 2
		loop cikl3
		mov y1, ax
	}
	cout << "sum=" << y1 << endl;
	
	//поиск элемента х в массиве
	cout << "x=";
	cin >> x;
	_asm {
		mov pr, 0
		mov ecx, 4
		xor esi, esi
	cikl1 :
		mov eax, dword ptr a[esi]
		cmp eax, x
		je end1
		add esi, 4
		loop cikl1
		jmp end2
	end1 :
		mov pr, 1
	end2 :
	}
	if (pr == 1) cout << "yes" << endl;
	else cout << "no" << endl;
	
	
	
	//динамические массивы
	
	int n;
	cout << "size off array = ";
	cin >> n;
	int* b = new int[n];
	srand(time(0));
	for (int i = 0; i < n; i++)
		b[i] = rand() % 100;
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	
	//сумма элементов динамического массива типа int
	_asm {
		mov ecx, n
		mov ebx, b //занесение адреса массива b
		xor eax, eax
	cikla :
		add eax, [ebx]
		add ebx, 4
		loop cikla
		mov y, eax
	}
	cout << "sum=" << y << endl;
	system("Pause");
	return 0;
}