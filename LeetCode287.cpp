int findDuplicate(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        if(nums[abs(nums[i])] > 0) {
            nums[abs(nums[i])] *= -1;
        } else return abs(nums[i]);
    }
    return 0;
}
