#include <pthread.h>
#include <iostream>
using namespace std;
void* worker_thread(void *arg){
    cout << "working thread" << endl;
    pthread_exit(NULL);
}

int main(){
    pthread_t my_thread;
    int ret;

    cout << "main() - creating worker_thread" << endl;
    ret = pthread_create(&my_thread, NULL, &worker_thread, NULL);
    if (ret != 0){
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    pthread_exit(NULL);
}
