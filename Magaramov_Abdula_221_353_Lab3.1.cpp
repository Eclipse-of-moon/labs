#include <iostream>

void sort_num(int* arr, int num)
{
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (arr[j + 1] < arr[j]) {

				int pred = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = pred;
			}
		}
	}
}

void sort_char(char* arr, int num) 
{
	char m[256] = { 0 };

	for (int i = 0; i < num; i++) {
		m[arr[i]]++;
	}

	for (int i = 0, b = 0; i < 256; i++) {
		for (int j = m[i]; j != 0; j--) {
			arr[b] = i;
			b++;
		}
	}

}

int main()
{
	int arr[] = { 1, 2, 4, 6, 0, 5, 7, 2, 5, 8 };
	char arr_ch[] = { 'a', 'j', 'a', 'g', 'h', 'v' };
	
	sort_num(arr, 10);
	sort_char(arr_ch, 6);
	
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << std::endl;

	}
	
	for (int i = 0; i < 6; i++) {
		std::cout << arr_ch[i] << std::endl;

	}

	return 0;
}
