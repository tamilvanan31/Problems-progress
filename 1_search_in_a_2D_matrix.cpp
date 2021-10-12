1. Write an efficient algorithm that searches for a value in an matrix. This matrix has the following properties:m x n
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
 
Solution:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        
        int n = matrix.size(), m = matrix[0].size(), low = 0, high = (m*n) - 1;
        while(low <= high) {
            int middle = (low + (high - low) / 2);
            if(matrix[middle/m][middle%m] == target) return true;
            else if(matrix[middle/m][middle%m] < target) low = middle + 1;
            else high = middle - 1;
        }
        return false;
    }
};

2. Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
  
Solution: 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int n = matrix.size(), m = matrix[0].size(), i = 0, j = m - 1;
        
        while(i < n && j >= 0) {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) --j;
            else ++i;
        }
        return false;
    }
};

© 2021 GitHub, Inc.
Terms
Privacy
