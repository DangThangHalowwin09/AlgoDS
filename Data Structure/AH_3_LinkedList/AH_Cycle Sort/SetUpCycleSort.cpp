#include <iostream> 
using namespace std; 
  
void cycleSort(int arr[], int n) 
{ 
    int writes = 0; // đếm sô phần tử.
  
    // đảo lại vị trí trí các element về đúng vị trí
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) { 
        // khai báo phần tử bắt đầu.
        int item = arr[cycle_start]; 
  
        // đếm pos, số phần tử nhỏ hơn phần từ item 
        int pos = cycle_start; 
        
        for (int i = cycle_start + 1; i < n; i++) 
            if (arr[i] < item) 
                pos++; 
  
        // If item is already in correct position 
        if (pos == cycle_start) 
            continue; 
  
        // ignore all duplicate  elements 
        while (item == arr[pos]) 
            pos += 1; 
  
        // put the item to it's right position 
        if (pos != cycle_start) { 
            swap(item, arr[pos]); 
            writes++; 
        } 
  
        // Rotate rest of the cycle 
        while (pos != cycle_start) { 
            pos = cycle_start; 
  
            // Find position where we put the element 
            for (int i = cycle_start + 1; i < n; i++) 
                if (arr[i] < item) 
                    pos += 1; 
  
            // ignore all duplicate  elements 
            while (item == arr[pos]) 
                pos += 1; 
  
            // put the item to it's right position 
            if (item != arr[pos]) { 
                swap(item, arr[pos]); 
                writes++; 
            } 
        } 
    } 
  
    // Number of memory writes or swaps 
    // cout << writes << endl ; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cycleSort(arr, n); 
  
    cout << "After sort : " << endl; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
} 