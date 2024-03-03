#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const int N = 5;
	int arr[N], max, min, ind_max = 0, ind_min = 0, c, n = N;

	//ввод элементов массива
	cout << "введите элементы массива: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	max = arr[0]; min = arr[0];
	
	//поиск первого максимального элемента и его индекса
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			ind_max = i;
		}
	}
	//поиск последнего минимального элемента и его индекса
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= min)
		{
			min = arr[i];
			ind_min = i;
		}
	}
	
	//вывод исходного массива
	cout << "\nисходный массив: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	//разбор случаев
	if (max == min)
		cout << "\nмаксимальный и минимальный элементы равны, менять нечего, полученный массив идентичен исходному" << endl;
	else
	{
		//смена элементов местами
		c = arr[ind_min];
		arr[ind_min] = arr[ind_max];
		arr[ind_max] = c;

		//вывод полученного массива
		cout << "\nполученный массив: ";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";


		//переделка
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == max)
			{
				for (int j = i; j < n - 1; j++)
				{
					c = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = c;
				}
				n--;
			}
		}
		cout << "\nполученный массив после уаления максимальных элементов: ";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
}