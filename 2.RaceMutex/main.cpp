#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <mutex>

using namespace std;

class LogFile {

    std::mutex _mu;
    std::mutex _mu2;
    ofstream _f;

    public:
        LogFile(){
            _f.open("log.txt");
        }
//        ~LogFile(){
//            _f.close();
//        }

        void shared_print(string id, int value){
            std::lock(_mu, _mu2);
            std::lock_guard<mutex> locker(_mu, std::adopt_lock);
            std::lock_guard<mutex> locker2(_mu2, std::adopt_lock);
            cout << "From "<<id<<": "<<value<< endl;
        }

        void shared_print2(string id, int value){
            std::lock(_mu, _mu2);
            std::lock_guard<mutex> locker(_mu2, std::adopt_lock);
            std::lock_guard<mutex> locker2(_mu, std::adopt_lock);
            cout << "From "<<id<<": "<<value<< endl;
        }
};



void function1(LogFile& log){
    for (int i=0; i>-100; i--)
        log.shared_print(string("t1"), i);
}

int main() {

    LogFile log;
    std::thread t1(function1, std::ref(log));

    for (int i=0; i<100; i++)
        log.shared_print2(string("main"), i);


    t1.join();

    return 0;
}
