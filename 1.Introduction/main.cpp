#include <iostream>
#include <thread>
#include <string>
using namespace std;


class Functor {
public:
    void operator()(const string& msg){

        cout << "t1 says: "<< msg <<endl;
    }
};

int main (){

//    Functor fct;
    string s = "I am the child thread";
    std::thread t1((Functor()), std::move(s)); //t1 starts running
//    t1.join(); // main thread waits for t1 to finish

//    t1.detach(); //t1 will run freely, and main does not wait for t1
//                 //to finish -- daemon thread

    std::thread t2 = std::move(t1);

    try {
        cout <<"main says: My name is main thread\n"<<endl;
        t2.join();
    }


    catch (...) {
        t2.join();
        throw;
    }

    cout<<std::thread::hardware_concurrency()<<endl;
    return 0;
}