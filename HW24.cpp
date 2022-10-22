//���� ������ ������ � ������� ������������� �������
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr, const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

template <typename T> 
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

template <typename T>
void resize_arr(T*& arr, const int length1, int length2) {

	T* tmp = new T[length2];
	for (int i = 0; i < length1; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int m, n;

	std::cout << "������� 1.\n";
	std::cout << "������� ����� ������� A: \n";
	std::cin >> n;
	std::cout << "������� ����� ������� B: \n";
	std::cin >> m;
	int* A = new int[n];
	int* B = new int[m];
	std::cout << "����������� ������ A:\n";
	fill_arr(A, n, 1, 10);
	show_arr(A, n);
	std::cout << "����������� ������ B:\n";
	fill_arr(B, m, 1, 10);
	show_arr(B, m);
	int* C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < m + n; i++)
		C[i] = B[i - n];
	std::cout << "�������� ������ �:\n";
	show_arr(C, n + m);
	delete[] A;
	delete[] B;


	std::cout << "������� 2.\n";
	int size1, size2;
	std::cout << "������� ������� ����� �������: \n";
	std::cin >> size1;
	int* arr = new int[size1];
	fill_arr(arr, size1, 1, 10);
	std::cout << "����� ������������ �������: \n";
	show_arr(arr, size1);
	std::cout << "������� ����� ����� �������: \n";
	std::cin >> size2;
	std::cout << "������ � ���������� ������: ";
	resize_arr(arr, size1, size2);
	
	show_arr(arr, size2);

	


















	return 0;
}