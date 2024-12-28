
int findLengthOfLCIS(int* nums, int numsSize){
  int dp[numsSize + 1];
  int sign = 0;
  int maxlen = 1;
  dp[0] = 1;
  dp[1] = 1;
  for(int i = 1; i < numsSize; i++){
    if(nums[i - 1] < nums[i]){
      sign = 1;
    }
    if(!sign){
        dp[i] = 1;
    }
    else{
        dp[i] = dp[i - 1] + 1;
        sign = 0;
    }
    maxlen = dp[i] > maxlen ? dp[i] : maxlen;
  }
  return maxlen;
}
