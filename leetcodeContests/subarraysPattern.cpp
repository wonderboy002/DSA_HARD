#include <bits/stdc++.h>
using namespace std;
int countSubarrays(vector<int> nums, vector<int> pattern)
{
    // left and right are pointers of window
    // pk is the pattern counter
    int k=pattern.size()+1;
    int ans=0;
    int pk=0;
    for (int i=0;i<nums.size()-k+1;i++){
        for (int j=i;j<nums.size()-1;j++){
            if (pattern[pk]==1 && nums[j+1]>nums[j]){
                pk++;
            }
            else if (pattern[pk]==-1 && nums[j+1]<nums[j]){
                pk++;
            }
            else if (pattern[pk]==0 && nums[j+1]==nums[j]){
                pk++;
            }

            if (pk==pattern.size()){
                pk=0;
                ans++;
            }
        }
        return ans;
    }
}
int main()
{
    vector<int> nums ={1,2,3,4,5,6};
    vector<int> pattern = {1,1};

    int ans = countSubarrays(nums, pattern);
    cout << ans << endl;
    return 0;
}