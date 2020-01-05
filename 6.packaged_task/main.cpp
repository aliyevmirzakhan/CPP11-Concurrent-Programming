#include <iostream>
#include <deque>
#include <thread>
#include <future>
#include <functional>

using namespace std;

int factorial (int N){
    int res = 1;
    for (int i = N; i>1; i--)
        res*=i;

    cout <<"The factorial is: "<<res<<endl;
    return res;
}

std::deque<std::packaged_task<int()> > task_q; // A deque containing tasks
std::mutex mu; // Since both main and t1 threads uses task_q (to avoid data race condition);
std::condition_variable cond;


void thread_1(){
    std::packaged_task<int()> t;
    std::unique_lock <mutex> locker(mu);
    cond.wait(locker, [](){return !task_q.empty();});
    t = std::move(task_q.front());//Moving the address of packaged task to some other
    task_q.pop_front();
    t(); // T executes;
    locker.unlock();
}


int main() {

    std::thread t1(thread_1);
    std::future<int> fu;

    std::packaged_task <int()> t(std::bind(factorial, 6)); // Creating function object using std::bind
    // ... some process

    fu = t.get_future();
    // I am now instead of Invoking the task that invokes function object,
    // I am pushing it into the deque of packaged_task; I might then popped out from que and executed by some other
    std::unique_lock<mutex> locker(mu);
    task_q.push_back(std::move(t));
    locker.unlock();
    cond.notify_one();
    cout << fu.get()<<endl;

    t1.join();
    return 0;
}


// This program is now thread safe;

// 3 ways to return future:
// --promise::get_future();
// --packaged_task::get_future();
// --async() returns a future;



