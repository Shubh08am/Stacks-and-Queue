class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //circular array
        //concept of nge 
        //just create a imaginary vector and iterate over it using modulo property
        int n = nums.size(); 
        vector<int>nge(n);
        stack<int>s;
        //as we created img vector 
        //iterates from back
        for(int i=2*n-1;i>=0;i--){
           //remove smaller element from stack
           //instead of i -> i%n 
           while(!s.empty() and s.top()<=nums[i%n]) {
               s.pop();
           }
           //see for nge till i<n as after that img vector
           if(i<n) {
             if(!s.empty())  nge[i] = s.top();
             else if(s.empty()) nge[i] = -1;
           }
           //push in stack the greater value
           //i -> i%n
           s.push(nums[i%n]);
        }
        return nge;
    }
};
