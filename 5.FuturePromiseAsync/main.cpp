#include <iostream>
#include <thread>
#include <mutex>
#include <future>

using namespace std;


//std::mutex mu;
//std::condition_variable cond;
//
//
//void factorial(int N, int& x){
//    int res = 1;
//
//    for (int i = N; i>1; i--)
//        res*=i;
//
//    std::unique_lock<mutex> locker(mu);
//    x = res;
//    cout <<"Result is: "<< x <<endl;
//    locker.unlock();
//    cond.notify_one();
//
//}
//
//int main(){
//    /* What is I want to return value that has been calculated in child thread to
//       main Thread?
//     */
//    // Since x is shared between main and t1 threads mutex is needed to avoid data race
//    // I also need to make sure that child thread assign val to x before parent thread fetches using std::ref(),
//    // thus condition variable also needed;
//
//    int x;
//
//
//
//    std::thread t1(factorial, 4, std::ref(x));
//
//    std::unique_lock<mutex> locker(mu);
//    cond.wait(locker);
//    cout << "value from child thread: "<< x << endl;
//    locker.unlock();
//    t1.join();
//    return 0;
//}
//
//// This function will output correct result, but as can be seen it contains many locks and unlock
//// which is pretty messy.

// =================================================================================================

// Luckily C++ has a much elegant way to address this issue;
int factorial(std::future<int>& f){
    int res = 1;
    //(...) do some job in child thread paralelly

    int N = f.get(); // When thread reaches here it waits parent to send int as per promise
    for (int i = N; i>1; i--)
        res*=i;

    cout <<"Result is: "<< x <<endl;
    return res;
}

int main(){
    /* What is I want to return value that has been calculated in child thread to
       main Thread?
     */
    // Since x is shared between main and t1 threads mutex is needed to avoid data race
    // I also need to make sure that child thread assign val to x before parent thread fetches using std::ref(),
    // thus condition variable also needed;

    int x;
    std::promise <int> p; // Promise to be sent to other thread at some time in the future
    std::future<int> f = p.get_future(); // A future integer that is promised
    std::future<int> fu = std::async(std::launch::async,factorial, std::ref(f));


    p.set_value(4); // Sending the promised integer;
    x = fu.get(); // fu will wait until child thread executes the factorial func and return result

    // Saying child thread may not be appropriate depending on state of async:
            // it may devote a seperate thread or not in default state, but the state can be customized
            //                             --> std::async(std::launch:async, func_name, input_val); - creates thread
            //                             --> std::async(std::launch::deferred, func_name, input_val); - single thread

    // *** fu.get(); can only be called once
    return 0;
}