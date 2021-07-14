#include<iostream>
#include<vector>
#include<tuple>

template<typename T>
std::tuple<int, int, T> findMaxCrossingSubArray(const std::vector<T> &vec, int low, int mid, int high) {
  if(low == high){
    return {low, high, vec[low]};
  }
  
  int maxLeft = mid;
  T leftSum = vec[mid];
  T sum = 0;
  
  for(int i = mid; i >= low; i--){
    sum += vec[i];
    if (sum > leftSum){
      leftSum = sum;
      maxLeft = i;
    }
  }

  int maxRight = mid + 1;
  T rightSum = vec[maxRight];
  sum = 0;
  for(int i = maxRight; i <= high; i++){
    sum += vec[i];
    if (sum > rightSum){
      rightSum = sum;
      maxRight = i;
    }
  }

  return {maxLeft, maxRight, leftSum + rightSum};
}


template<typename T>
std::tuple<int, int, T> subArrayMaxDivideAndConquer(const std::vector<T> &vec, int low, int high) {
  if (low == high){
    return {low, high, vec[low]};
  }
  int mid = (low + high) / 2;
  auto [crossLow, crossHigh, crossSum] = findMaxCrossingSubArray(vec, low, mid, high);
  auto [rightLow, rightHigh, rightSum] = subArrayMaxDivideAndConquer(vec, mid + 1, high);
  auto [leftLow, leftHigh, leftSum] = subArrayMaxDivideAndConquer(vec, low, mid);

  if (leftSum > crossSum && leftSum > rightSum){
    return {leftLow, leftHigh, leftSum};
  } else if (rightSum > crossSum && rightSum > leftSum){
    return {rightLow, rightHigh, rightSum}; 
  } else{
    return {crossLow, crossHigh, crossSum};
  }
}

template<typename T>
std::tuple<int, int, T> subArrayMaxWindowing(const std::vector<T> &vec, int low, int high){
  int currentLeft = low;
  int left = low;
  int right = low;
  T sum = 0;
  T maxSum = 0;

  for(int i = low; i <= high; i++){
    if (sum < 0){
      currentLeft = i;
      sum = vec[i];
    } else {
      sum += vec[i];
    }
    
    if(sum > maxSum){
      maxSum = sum;
      right = i;
      left = currentLeft;
    }
  }

  return {left, right, maxSum};
}