int findLengthOfLCIS(int* nums, int numsSize) {
    int len = 1,maxlen = 1;
    for(int l = 0; l < numsSize - 1; l++){
      int r = l;
      while(r < numsSize - 1){
        if(nums[r] < nums[r + 1]){
         r++;
         len++;
        }
        else break;
      }
      maxlen = len > maxlen ? len : maxlen;
      len = 1;
    }
    return maxlen;
}
