#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>
using namespace std;

std::deque<int> q;
std::mutex mu;
std::condition_variable cond;


// I need to lock to provide single access to data q, Thus any time
// push or pop is invoked the resource should be locked.

void function1() {
    int count = 10;

    while (count > 0) {
        std::unique_lock<mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        cond.notify_one(); // Notifies that mutex is unlocked
        std::this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
}

//void function2() {
//    int data = 0;
//
//    while (data != 1){
//        std::unique_lock<mutex> locker(mu);
//
//        if (!q.empty()){
//            data = q.back();
//            q.pop_back();
//            locker.unlock();
//            cout << "t2 got the val from t1: "<< data << endl;
//        } else {
//            locker.unlock(); // The popping thread might work faster than pushing
//                             // thread, may require unnecessary looping (as the loop
//                             // starts immediately after unlock(). Further this fast looping
//                             // locks the mutex again preventing it to be locked in pusher function.
//            // A possible approach here is to introduce sleeper
//            std::this_thread::sleep_for(chrono::milliseconds(10));
//            // But this time estimating time remains as ubiquitous
//
//            // This is where a condition variable comes into play
//
//        }
//
//    }
//}


void function3(){
    int data = 0;

    while(data!=1){
        std::unique_lock<mutex> locker(mu); // Mutex is locked
        cond.wait(locker, [](){return !q.empty();}); // Wait forces t3 to sleep, while unlocking the Mutex, which is then
                              // locked by t1 and t1 pushes element to the que.
                              // After pushing cond.notify_one() wakes up t3 again, and data is popped back
                              // and in the 2nd loop the Mutex is locked again.

                              // ** the t3 can wake up spontaneously due to internal process (called spurious wake)
                              // in this case we use provoker prop of wait which is lambda function.
                              // when the t3 wakes up and sees q is empty it will sleep
        data = q.back();
        q.pop_back();
        locker.unlock();
        cout << "t3 got the val from t1: "<< data << endl;
    }
}



int main() {
    std::thread t1(function1);
//    std::thread t2(function2);
    std::thread t3(function3);

    t1.join();
    t3.join();

    return 0;
}
