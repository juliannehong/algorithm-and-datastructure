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
  int room(0);
  int current_interval = { 0, 0 };
  for (int i = 0; i < intervals.size() - 1; ++i) {
      if (intervals[i].end <= intervals[i + 1].start)
          continue;
      else {
          if (intervals[i + 1].start < current_interval[1])
              room++;

          current_interval[0] = intervals[i + 1].start;
      }
  }
  return room;
}

int main(){
//[[0, 30],[5, 10],[15, 20]],

  vector<Interval> v {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
  cout << canAttendMeetings(v) << endl;
  cout << minMeetingRooms(v) << endl;
  
  return 0;
}

