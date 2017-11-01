// https://leetcode.com/problems/trapping-rain-water/description/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// using stack
//We keep a stack and iterate over the array. We add the index of the bar to the stack if bar is smaller than or equal to the bar at top of stack, which means that the current bar is bounded by the previous bar in the stack. If we found a bar longer than that at the top, we are sure that the bar at the top of the stack is bounded by the current bar and a previous bar in the stack, hence, we can pop it and add resulting trapped water to \text{ans}ans.

int trap(vector<int>& height){
  int result =  0;
  stack<int> st; //push to the stack until the next highest elem shows up

  for (int i = 0; i < height.size(); ++i){
    if (!st.empty() && st.top() < height[i]){ // time to pop the stack (add water horizontally!!)
      while (!st.empty()){
        int current_low = st.top();
        st.pop();
        if (!st.empty())
          break;
        int w = i - st.top() - 1;
        int h = min(height[i], height[st.top()]) - height[current_low];
        result += h*w;
      }
    }
    st.push(i);
  }
  return result;
}

int main(){
  vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
  cout << trap(v) << endl;
  return 0;
}
         