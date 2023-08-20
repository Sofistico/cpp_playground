
#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++){
        int num = nums[i];
        for(int z = i + 1; z < nums.size(); z++){
            int numz = nums[z];
            if(num + numz == target){
                return {i, z};
            }
        }
    }
    return {};
}


int main(){
    cout<<"Hello World"<<endl;
    vector<int> vec = vector<int>{3,2,4};
    auto sol = twoSum(vec, 6);
    for(auto i: sol){
        cout<<i<<endl;
    }

    return 0;
}