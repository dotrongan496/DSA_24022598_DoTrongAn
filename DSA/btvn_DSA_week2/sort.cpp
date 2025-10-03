#include <iostream>

using namespace std;

void swapp(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//min O(n), max O(n^2)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool isSwapp = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapp(arr[j], arr[j + 1]);
                isSwapp = true;
            }
        }
        if (isSwapp == false) break;
    }
}
//O(n^2)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swapp(arr[i], arr[min]);
    }
}
//min o(n), tbinh O(n^2)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//O(log(N))
int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    int arr1[100], arr2[100], arr3[100];
    cout << "\n Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    bubbleSort(arr1, n);
    cout << "Mang sau khi sap xep (Bubble Sort): ";
    print(arr1, n);

    selectionSort(arr2, n);
    cout << "Mang sau khi sap xep (Selection Sort): ";
    print(arr2, n);

    insertionSort(arr3, n);
    cout << "Mang sau khi sap xep (Insertion Sort): ";
    print(arr3, n);
    
    int m;
    cin >> m;
    
    if (binarySearch(arr1, n, m) != -1){
    	cout << "tim thay phan tu o vi tri: " << binarySearch(arr1, n, m) << endl;;
	}
	else {
		cout << "Khong tim thay phan tu";
	}

    return 0;

}

