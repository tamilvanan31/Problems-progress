Given an array with n objects colored red, white or blue,  sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]
*/

//counting sort is the key here
void Solution::sortColors(vector<int> &A) {
    int n=A.size();
    vector<int> freq(3,0);
    for(int i=0;i<n;i++){freq[A[i]]++;}
    for(int i=0;i<n;i++){
        if(freq[0]>0){
            A[i]=0;
            freq[0]--;
        }
        else if(freq[1]>0){
            A[i]=1;
            freq[1]--;
        }
        else{
            A[i]=2;
        }
    }
}

//since inbuilt sort functions are not allowed here,so tried using my quicksort
//just to implement quicksort,anyways this gives TLE
int partition(vector<int> &A,int lo,int hi){
    
    int k=lo;
    for(int j=lo;j<hi;j++){
        if(A[j]<A[hi]){
            swap(A[j],A[k++]);
        }
    }
    swap(A[k],A[hi]);
    return k;
}
void kickSort(vector<int>& A,int lo,int hi){
    if(lo>=hi){return ;}
    int p=partition(A,lo,hi);
    kickSort(A,lo,p-1);
    kickSort(A,p+1,hi);
}
void Solution::sortColors(vector<int> &A) {
    kickSort(A,0,A.size()-1);
}

//Efficient solution is using Dutch national flag algo

void Solution::sortColors(vector<int> &nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            switch(nums[mid]) {
                case 0: 
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    ++mid;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
}
© 2021 GitHub, Inc.
Terms
Privacy
