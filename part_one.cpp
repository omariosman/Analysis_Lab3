//Omar Elsayed

#include <iostream>
#include<iomanip>
#include<ctime>
using namespace std;


int insertion_sort_count_comparisons(int* arr, int n)  
{  
    int comp = 0;
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
      do {
          comp++;
          if (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }
      } while(j >= 0 && arr[j] > key);
   
        arr[j + 1] = key;  
    }  
    return comp;
} 












int bubble_sort_count_comparisons(int* arr, int n)  
{  
    int i, j, comp;
    comp = 0;
    for (i = 0; i < n-1; i++){
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++, comp++)  {
        if (arr[j] > arr[j+1])  
            swap(arr[j], arr[j+1]); 
        }  
        
    }
    return comp;
}
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

void reverseArray(int *myArr, int n){
    int *tempArr;
    tempArr = new int[n];
    int k = n - 1;
    for (int i = 0; i < n; i++){
        tempArr[i] = myArr[k];
        k--;
    }
    
    for (int i = 0; i < n; i++){
        myArr[i] = tempArr[i];
    }
}


int main()
{
    //srand(time(0));


    cout << setw(8) << "n" << "    " << setw(4) << "    " << "Bubble Sort - Best" << "    " << setw(4) << "Bubble Sort - Worst" << "    " << "Insertion Sort - Best" << "    " << "Insertion Sort - Worst" <<  endl <<setw(8);

    int *myArray;
    myArray = new int[100];
    
    //Bubble Sort
    int count = 0;
    for (int i = 1; i <= 10; i++){
        for (int j = 0; j < i; j++){
            myArray[j] = j;
        }
        cout << i << setw(16);
        //Bubble Best
        count = bubble_sort_count_comparisons(myArray, i);
        cout << count << setw(24);
        reverseArray(myArray, i);
        
        //Bubble Worst
        count = bubble_sort_count_comparisons(myArray, i);
        cout << count << setw(24);
        reverseArray(myArray, i);
        reverseArray(myArray, i);
        //Insertion Best
        count = insertion_sort_count_comparisons(myArray, i);
        cout << count << setw(24);
        reverseArray(myArray, i);
        
        //Insertion Worst
        count = insertion_sort_count_comparisons(myArray, i);
        cout << count << setw(8);
        
        cout << endl;
        
    }
    


}
