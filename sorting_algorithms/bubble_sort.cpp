#include <iostream>

void swap_data (int *a , int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort (int arr[] , int no_of_element) {
	for(int i = 0 ; i < no_of_element-1 ; i++)
		for(int j = 0 ; j < no_of_element-i-1 ; j++)
			if (arr[j] > arr[j+1])
				swap_data(&arr[j],&arr[j+1]);
}

void disp (int arr[] , int no_of_element) {
	std::cout << "The elements are: \n";
	for (int i = 0 ; i < no_of_element ; i++)
		std::cout << arr[i] << " ";
}

int main(int argc , char *argv[]) {
	if (std::stoi(argv[1]) != argc -2) {
		std::cout << "Invalid input...Please enter again...!!!" << std::endl;
		return EXIT_FAILURE;
	}
	int no_of_element = std::stoi(argv[1]);
	int arr[no_of_element];
	std::cout << "Number of elements: " << no_of_element << std::endl;
	for(int i = 0 ; i < no_of_element ; i++)
		arr[i] = std::stoi(argv[i+2]);
	disp(arr,no_of_element);
	bubble_sort(arr , no_of_element);
	disp(arr,no_of_element);
	return EXIT_SUCCESS;
}
