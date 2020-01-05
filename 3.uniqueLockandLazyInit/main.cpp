#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
using namespace std;


// Say I only need to open the file once the shared_print fuction is called
class LogFile1 {

    std::mutex _mu;
    ofstream _f;
    public:
        LogFile1(){
            cout <<"Initialized"<<endl;

        } //Need a deconstructor

    // Remember shared_print is called by both main and t1 threads;

    void shared_print(string id, int value){


            if (!_f.is_open()){
                std::unique_lock <mutex> locker(_mu);
                _f.is_open();
            }
                //  This technique is not beneficial, because:
                //  main thread comes and pass inside the if scope (as _f is not open), and it locks the access
                //  meanwhile t1 may come, before _f is opened, and it will pass and wait because the source is locked
                //  once the main thread opens the _f, the source is unlocked to t1 and it also opens _f.
                // This shows that this method is not a thread safe method in the context of access.
        }
};

// A more thread safe option is to convey the unique_lock to the beginning of if like:
std::unique_lock <mutex> locker(_mu);
if (!_f.is_open()){
    _f.is_open();
}

// But this involves a lot of locking and unlocking, and this gives overhead of execution expense.



// Here comes the technique called the lazy initialization:
class LogFile2 {

    std::mutex _mu;
    std::once_flag _flag;
    ofstream _f;
public:
    LogFile2(){
        cout <<"Initialized"<<endl;

    } //Need a deconstructor

    // Remember shared_print is called by both main and t1 threads;

    void shared_print(string id, int value){
        std::call_once(_flag, [&](){_f.open("log.txt"); }); // This is lambda function implementation
    }
};