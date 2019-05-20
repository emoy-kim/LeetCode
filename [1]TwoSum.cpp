#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
   for(size_t i = 0; i < nums.size() - 1; ++i){
      for(size_t j = i + 1; j < nums.size(); ++j){
          if(nums[i] + nums[j] == target){
              vector<int> answer{ static_cast<int>(i), static_cast<int>(j) };
              return answer;
          }
      }
   }
}