//Omar Elsayed
//Part 2
#include <iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;



int bubble_sort_count_swaps(int* arr, int n)  
{  
    int i, j, swaps;
    swaps = 0;
    for (i = 0; i < n-1; i++){
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  {
        if (arr[j] > arr[j+1]) { 
            swap(arr[j], arr[j+1]); 
            swaps++;
        }  
    }
    }
    return swaps;
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
    srand(time(0));


    cout << setw(8) << "n" << "    " << setw(4) << "    " << "Bubble Sort Comparisons" << "    " << setw(4) << "Bubble Sort Swaps" << endl <<setw(8);

    int *myArray1;
    myArray1 = new int[100];
    
    int *myArray2;
    myArray2 = new int[100];
    //Bubble Sort
    int count = 0;
    
    
    
    for (int i = 1; i <= 50; i++){
        for (int j = 0; j < i; j++){
            int random_num = (rand() % 50) + 1;
            myArray1[j] = random_num;
            myArray2[j] = random_num;
        }
        
        
        
        cout << i << setw(16);
        //Bubble Best
        count = bubble_sort_count_comparisons(myArray1, i);
        cout << count << setw(24);

        //Bubble Worst
        count = bubble_sort_count_swaps(myArray2, i);
        cout << count << setw(8);
        

        

        cout << endl;
        
        
    }
    


}
