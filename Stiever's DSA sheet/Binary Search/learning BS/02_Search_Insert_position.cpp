/*

*/



/*
Because when high = low+1, then mid = low.
If the target > nums[mid], then low = mid + 1 = high. The target position can be low or high, since they are the same.
but if the target < nums[mid], then high = mid - 1 = low - 1. The target position must be low,
*/
