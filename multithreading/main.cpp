#include <iostream>
#include <thread>
#include <string>

using namespace std;
void thread_function(int x, string str)
{
    cout << str << " is " << x << endl;
}
 
int main() 
{
    int x = 10;
    string str = "hello";
    std::thread threadObj(thread_function, x, str);
    //cout << threadObj.get_id() << endl;
    threadObj.join();
    return 0;
}