// https://leetcode.com/problems/meeting-rooms-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval{
  int start;
  int end;
  Interval():start(0), end(0) {}
  Interval(int s, int e): start(s), end(e){}
};

bool canAttendMeetings(vector<Interval>& intervals) {
  sort(begin(intervals),end(intervals),[](Interval a, Interval b){
    return a.start < b.start;
  });
  for (int i = 1; i < intervals.size(); ++i){
    if (intervals[i-1].end < intervals[i].start)
      return false;
  }
  return true;
}

int minMeetingRooms(vector<Interval>& intervals){
  sort(begin(intervals),end(intervals),[](Interval a, Interval b){
    return a.start < b.start;
  });
  
}

int main(){
//[[0, 30],[5, 10],[15, 20]],

  vector<Interval> v {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
  cout << canAttendMeetings(v) << endl;
  
  return 0;
}

