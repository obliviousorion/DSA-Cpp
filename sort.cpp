#include <iostream>
#include <vector>
using namespace std;

// Selection Sort implementation
void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i; j < n; j++) {
            if (arr[mini] > arr[j]) mini = j;
        }
        swap(arr[mini], arr[i]);
    }
}

// Bubble Sort Implementation
void bubbleSort(vector<int>& arr, int n) {
    for (int i = 0; i <= n-1; i++){
        bool swapped = false;
        for (int j = 0; j <= n-i-2; j++){
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Insertion Sort Implementation
void insertionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

// merge sort's merge function
void merge(vector<int>& arr, int first, int midpoint, int last){

    vector<int> dummy;
    

    // base condition if first = last
    if (first == last) return;

    // assuming first to mid is sorted 
    // and mid + 1 to last is sorted
    int left = first; // taking left array 
    int right = midpoint+1; // taking right array

    while(left <= midpoint && right <= last){
        if(arr[left] <= arr[right]){
            dummy.push_back(arr[left]);
            left++;
        } else {
            dummy.push_back(arr[right]);
            right++;
        }

    }
    // check and append if left has elements remaining
    while (left <= midpoint){
        dummy.push_back(arr[left]);
        left++;
    }
    // check and append if right has elements remaining
    while (right <= last){
        dummy.push_back(arr[right]);
        right++;
    }

    for (int i = first; i <= last; i++){
        arr[i] = dummy[i-first];
    }

}

// Merge Sort Implementation
void mergeSort(vector<int>& arr, int first, int last) {

    // base condition first = last
    if (first == last) return;
    // calculate midpoint of the array
    int midpoint = (first + last)/2;
    // recursive call on the two halves of the array
    mergeSort(arr, first, midpoint);
    mergeSort(arr, midpoint+1, last);
    // merging the two halves of the array 
    // after being sorted individually
    merge(arr, first, midpoint, last);
}

// Partition Helper function for quick sort
int partition(vector<int>& arr, int first, int last){
    // choosing pivot as mid element
    int pivot = arr[last];

    int i = first - 1;
    
    for(int j = first; j < last; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }

    swap(arr[i+1], arr[last]);

    return i + 1;
    
    
}

// Quick Sort Implementation
void quickSort(vector<int>& arr, int first, int last) {
    // Base condition: if the array has 1 or 0 elements, it's already sorted
    if (first >= last) return;

    // Partition the array and get the final resting index of the pivot
    int pivotIndex = partition(arr, first, last);

    // Recursively sort elements before and after partition
    quickSort(arr, first, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, last);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    cout << "Original Array:\t\t\t";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << "\n";

    // Selection Sort 
    cout << "Selection Sort:\t\t\t";
    vector<int> sort1 = arr;
    selectionSort(sort1, n);
    for(int i=0; i<n; i++) cout << sort1[i] << " ";
    cout << "\n";

    // Bubble Sort
    cout << "Bubble Sort:\t\t\t";
    vector<int> bsort = arr;
    bubbleSort(bsort, n);
    for (int i=0; i < n; i++) cout << bsort[i] << " ";
    cout << "\n";
    
    // Insertion Sort
    cout << "Insertion Sort:\t\t\t";
    vector<int> isort = arr;
    insertionSort(isort, n);
    for (int i=0; i < n; i++) cout << isort[i] << " ";
    cout << "\n";

    // Merge Sort
    cout << "Merge Sort:\t\t\t\t";
    vector<int> msort = arr;
    mergeSort(msort, 0, n-1);
    for (int i=0; i < n; i++) cout << msort[i] << " ";
    cout << "\n";

    cout << "Quick Sort:\t\t\t\t";
    vector<int> qsort = arr;
    quickSort(qsort, 0, n-1);
    for (int i=0; i < n; i++) cout << qsort[i] << " ";
    cout << "\n";
    
    return 0;
}
