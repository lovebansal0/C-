
#include<thread>
#include<iostream>
using namespace std;
#include<thread>
#include<mutex>

class Singleton
{
private:
    static Singleton *obj;
    Singleton()
    {
        str="Hello";
    }
    
public:
    string str;
    static Singleton *getObj()
    {
        if(obj==nullptr)
        {
            
            obj=new Singleton;
            cout<<"hello"<<this_thread::get_id();
        }
        return obj;
        
    }
};
Singleton* Singleton ::obj=nullptr;

class SingletonSafe
{
private:
    static SingletonSafe *obj;
    static mutex _m;
    SingletonSafe()
    {
        str="Hello";
    }
    
public:
    string str;
    static SingletonSafe *getObj()
    {
        _m.lock();
        if(obj==nullptr)
        {
            
            obj=new SingletonSafe;
            cout<<"hello"<<this_thread::get_id();
        }
        _m.unlock();
        return obj;
        
    }
};
SingletonSafe* SingletonSafe ::obj=nullptr;
mutex SingletonSafe::_m;

int main1()
{
    Singleton *sin=Singleton::getObj();
    //Singleton *s=sin;
    Singleton *s=Singleton::getObj();
//std:this_thread::sleep_for(50);
    cout<<sin->str;
    return 0;
}
