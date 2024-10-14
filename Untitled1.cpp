#include <iostream>
using namespace std;
void swap(int *a, int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}
//Ma hoa cac mau bang cac so nguyen 0,1,2 de bieu dien lan luot mau do, trang va xanh
void sort_colors(int arr[],int n){
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high) {
        if (arr[mid] == 0) {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) { 
            mid++;
        } else { 
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = { 2, 0, 2, 0, 0, 1, 0, 0, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort_colors(arr, n);

    print_array(arr, n);

    return 0;
}
