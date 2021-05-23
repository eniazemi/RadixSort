#include<bits/stdc++.h>
using namespace std;

int MaxInArray(int arr[], int n) // Function to get maximum value in array a[]. We need this to find the maximum digits
{
  int max_number = arr[0];
  for (int i=1; i < n; i++)
    if (arr[i] > max_number)
      max_number = arr[i];
  return max_number; // Function return the highest number (at the same time number with highest number of digits)
}

// Same as "classic" CountSort with a slight change to the function arguments
// because in RadixSort, CountSort is executed for each digit so it also depends on exp (passed by RadixSort function)
void CountSort(int arr[], int n, int exp)
{
  int result[n], i, count[10] = {0}; // count array

  // Counting occurence of unique digits (for decimal numbers unique numbers are 0, 1, 2....9)
  for (i =0; i < n; i++)
    count[(arr[i] / exp) % 10]++;

  // Changing the position of count so that it appears at actual position in result.
  for (i =1; i<10; i++)
    count[i] += count[i-1];

  // These 2 for loops sort the elements in array (depending from exp)
  for (i = n - 1; i >= 0; i--)
  {
    result[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }
  for (i =0; i <n; i++)
    arr[i] = result[i];
}

void RadixSort(int arr[], int n){
  int exp, max;                   // Exp store the position of digits that is sorting. RadixSort start sorting  from the least significant digits
  max = MaxInArray(arr, n);
  for (exp = 1; max/exp > 0; exp *= 10) // This loop pass as long as (max>exp) because if exp>max --> int(max/exp)=0 and we know that 0>0 is false
    CountSort(arr, n, exp);
}

// Time complexity : O(d*(n+b))
// Space complexity: n+2^d
int main()
{
  int n;
  cout<<" Number of elements to be sorted: ";
  cin>>n;
  int arr[n];

  cout << endl;
  cout << "Enter the elements: ";
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  RadixSort(arr, n);

  cout <<endl;
  cout<<"Sorted List: ";
  for (int i = 0; i < n; i++){
      if(i == n-1) cout<<arr[i]<<endl;
      else cout<<arr[i]<<", ";
  }
  return 0;
}
