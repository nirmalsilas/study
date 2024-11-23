#include<iostream>
#include<vector>
#include<algorithm>
#include <thread>
#include <chrono>
using namespace std;

//binary search
/*Binary search is an efficient algorithm for finding an item from a sorted list of items. 
It works by repeatedly dividing in half the portion of the list that could contain the item, 
until you've narrowed down the possible locations to just one.

Steps of Binary Search:
Initial Setup: Start with the entire list.
Middle Element: Find the middle element of the list.
Comparison:
If the middle element is equal to the target value, the search is complete.
If the target value is less than the middle element, repeat the search on the left half of the list.
If the target value is greater than the middle element, repeat the search on the right half of the list.
Repeat: Continue the process until the target value is found or the subarray size becomes zero.
*/


/* pseudo code

--------------------------------------------
   (left)-,-,-,-,-(mid),-,-,-,-(right)
--------------------------------------------
 function binarySearch(arr, target):
    left = 0
    right = length(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid
        else if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1  // Target not found
*/

//time complexity is O(logn)
#if 0
int binary_search(const std::vector<int>& arr , const int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while(left<=right)
    {
        int mid  = (left +(right -left))/2;
        
        if (arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid+1;
        else
            right = mid-1;              
    }
    return -1;
    
}

int main()
{
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int target = 5;
    std::cout<<"index of target is "<<binary_search(arr,target)<<std::endl;
    
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 0;

}
#endif

/*
35. Search Insert Position
Given a sorted array of distinct integers and a target value,
return the index if the target is found. If not, return the index where it would be if it were inserted in order.

*/

#if 0
int binary_search(const std::vector<int>& arr , const int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while(left<=right)
    {
        int mid  = (left + right)/2;   //left + (right -left))/2; can be used to avoid overflow 
                                        //incase value are INT_MAX, INT_MAX-1
        
        if (arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid+1;
        else
            right = mid-1;              
    }
    return left;
    
}

int main()
{
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int target = 5;
    std::cout<<"index of target is "<<binary_search(arr,target)<<std::endl;
    
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 0;

}
#endif
//seach a 2D matrix
//question 74
/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

#if 0
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    if (rows == 0) return false;
    int cols = matrix[0].size();
    
    int left = 0, right = rows * cols - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_value = matrix[mid / cols][mid % cols]; //mid/cols gives row and mid%cols gives column
        
        if (mid_value == target) {
            return true;
        } else if (mid_value < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
#endif

//162. Find Peak Element
//A peak element is an element that is strictly greater than its neighbors.
//Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
#if 0
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;  

    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] > nums[mid+1])
            right =mid;//peak is on the left
        else
            left =mid+1; //peak is on the right
    }// when left == right, we have found the peak
    return left;
        
    }
    #endif
//33. Search in Rotated Sorted Array
//There is an integer array nums sorted in non-decreasing order . rotated with an unknown pivot
//chek and return the index of target in the array 
#if 0
bool search (vector<int>& nums, int target)
{
    int left = 0, right = nums.size()-1;
    while(left<=right)
    {
        int mid = left + (right - left)/2;
         if (nums[mid] == target) {
            return mid;
        }

        if(nums[left]<nums[mid]) //left half is sorted
        {
            if(nums[left]<=target && target<=nums[mid])
                right = mid;
            else
                left = mid+1;
        }
        else 
        {
            //right half is sorted or left half is not sorted
            if(nums[mid]<=target && target<=nums[right])
                left = mid;
            else
                right = mid-1;
        }


    }
    return -1

}
#endif


//34. Find First and Last Position of Element in Sorted Array
//Given an array of integers nums sorted in non-decreasing order, 
//find the starting and ending position of a given target value.

#if 0

 vector<int> searchRange(vector<int>& nums, int target) {
        int right = nums.size()-1;
        int left = 0;

        int first = -1;

        while(left<=right)
        {
            int mid = left +(right-left)/2;
            if(nums[mid] == target)
            {
                first =mid;
                right =mid -1; // search on the left side(moving right to left side to find the first occurance)
            }
            if(nums[mid]>target)
                right =mid -1;
            else
                left =mid+1;            

        }

        left = 0;
        right = nums.size()-1;
        int last = -1;
        while(left<=right)
        {
            int mid = left +(right-left)/2;
            if(nums[mid] == target)
            {
                last =mid;
                left =mid +1; // search on the right side(moving left to right side to find the last occurance)
            }
            if(nums[mid]>target)
                right =mid -1;
            else
                left =mid+1;            

        }
        return {first,last};
        
    }
#endif


//153. Find Minimum in Rotated Sorted Array
//Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
//Given the sorted rotated array nums of unique elements, return the minimum element of this array.

bool search (vector<int>& nums)
{
    int left = 0, right = nums.size()-1;
    while(left<=right)
    {
        int mid = left + (right - left)/2;
        
        if(nums[mid] > nums[right]) 
            left = mid+1; //minimum is on the right
        else
            right = mid; //minimum is on the left
        
            

    }
    return nums[left]; //return the minimum element

}