/*
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.

This is one of those problems.

Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

Food for thought :

Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

// there are two possible approach...
//1. create a boolean array and get the missing number.
//2. math related solution

//1st approach
class Solution{
public:
    int *findTwoElement(int *arr, int N) {
        int repeating,missing;
        bool present[N+1] = {false};  //Checks which numbers are present
        for(int i=0;i<N;++i)
        {
            if(present[arr[i]]==true)
                repeating = arr[i];
            present[arr[i]] = true;
        }
        
        for(int i=1;i<=N;++i)
        {
            if(present[i]==false)
            {
                missing = i;
                break;
            }
        }
        int *p = new int[2];
        *(p + 1) = missing, *(p + 0) = repeating;
        return p;
    }
};


//2nd approach
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size();
    long long int sn = (n*(n + 1))/2, sn2 = (n*(n + 1)*(2*n + 1))/6;

    for(int i = 0; i < A.size(); ++i) sn -= (long long int)A[i], sn2 -= ((long long int)A[i]*(long long int)A[i]); 

    long long int x = (sn + sn2/sn)/2;
    long long int y = x - sn;

    return {y, x};
}

/*
    consider this example:
    [1,2,2,4] of form [w,x,y,z]
    sn = 10
    sn^2 = 30 for n = 4
    
    for input array
    ipsn = 9
    ipsn^2 = 25
    
    so, the approach goes like...
    let y,x be the repeating and missing number
    w + x + y + z = 10     for n^2: w^2 + x^2 + y^2 + z^2 = 30
    w + y + y + z = 9 (-)           w^2 + y^2 + y^2 + z^2 = 25(-)
    ------------------              --------------------------
    x - y = 1                            x^2 - y^2 = 5
    ------------------              --------------------------
    
     x^2 - y^2 = 5 -> (x + y) (x - y) = 5 -> 1(x + y) = 5 
     x + y = 5
     x - y = 1(+)
     ---------
     2x = 6 -> x = 3
     ---------
     x = 3 -> y = 2...
    
*/
