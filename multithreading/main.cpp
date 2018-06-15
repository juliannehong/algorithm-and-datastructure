#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Application
{
public:
    Application(){
        m_bDataLoaded = false;
    }
    void loadData(){ // for thread2
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Loading from data" << endl;
        lock_guard<mutex> lock(m_mutex);
        m_bDataLoaded = true;
    }
    void mainTask(){ // for thread1
        cout << "handshaking" << endl;
        m_mutex.lock();
        while (m_bDataLoaded != true){
            m_mutex.unlock();
            this_thread::sleep_for(chrono::milliseconds(100));
            m_mutex.lock();
        }
        m_mutex.unlock();
        cout << "do processing on loaded data" << endl;
    }
private:
    bool m_bDataLoaded;
    mutex m_mutex;
};

int main(){
    Application app;
    thread thread1(&Application::mainTask, &app);
    thread thread2(&Application::loadData, &app);
    thread2.join();
    thread1.join();
    return 0;
}