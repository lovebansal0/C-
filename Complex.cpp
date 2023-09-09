//
//  Complex.cpp
//  MyC++
//
//  Created by Love Bansal on 06/09/23.
//

#include "Complex.hpp"
#include<iostream>
#include<ostream>
#include<istream>
using namespace std;
class complex
{
//.private:
//public:
    int a;
    int b;
public:
    complex()
    {
        
    }
    complex(int x,int y)
    {
        a=x;
        b=y;
    }
    complex operator+ (const complex &c)
    {
        complex o;
        o.a=c.a+a;
        o.b=c.b+b;
        return o;
    }
    friend complex operator -(const complex &, complex &d);
    //complex(complex &)=delete;
    //complex(complex &&)=delete;
    //complex operator=(complex &)=delete;
    friend ostream & operator<< (ostream &s,  complex c);
    friend istream &operator >> (istream &s,  complex &c);
};
istream &operator >> (istream &s,  complex &c)
{
    s>>c.a>>c.b;
    return s;
}
ostream & operator<< (ostream &s,  complex c)
{
    s<<c.a<<c.b;
    return s;
}
complex operator -(const complex &c, complex &d)
{
    complex o;
    o.a=c.a-d.a;
    o.b=c.b-d.b;
    return o;
}

int main1()
{
    complex c;
    complex d(2,3);
    complex e(d);
    complex f=d;
    
    c=d+e;
    cout<<c;
    cin>>c;
    cout <<c;
    
    c=c-f;
    cout<<c;
    //cout<<c.a<<c.b;
    return 0;
}
