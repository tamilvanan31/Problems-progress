Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. 
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
  
Approach:
Brute force solution in O(n^2). If you dont know the optimal solution, then your interview is screwed-up.
Optimal approach is by using merge sort algorithm

//Solution

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
        long long merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
        long long i = left, j = mid, k = left, cnt = 0;
        while(i <= (mid - 1) && j <= right) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++], cnt += (mid - i); 
            }
        }
        
        while(i <= mid - 1) temp[k++] = arr[i++];
        while(j <= right)  temp[k++] = arr[j++];
        
        for(int i = left; i <= right; ++i) arr[i] = temp[i];
        
        return cnt;
    }
    
    long long mergesort(long long arr[], long long temp[], long long left, long long right) {
        long long mid, cnt = 0;
        if(right > left) {
            mid = (left + right)/2;
            cnt += mergesort(arr, temp, left, mid);
            cnt += mergesort(arr, temp, mid + 1, right);
            cnt += merge(arr, temp, left, mid + 1, right);
        }
        return cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int temp[N];
        long long ans = mergesort(arr, temp, 0, N - 1);
        return ans;
    }
};
