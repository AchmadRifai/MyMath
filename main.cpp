#include <iostream>
#include"Pecahan.h"

using namespace std;
using namespace math;

int main()
{
    Pecahan a(2),b(4),c;
    c=a+b;
    cout<<a.to_string()<<"+"<<b.to_string()<<"="<<c.to_string()<<endl;
    c=a-b;
    cout<<a.to_string()<<"-"<<b.to_string()<<"="<<c.to_string()<<endl;
    c=a*b;
    cout<<a.to_string()<<"*"<<b.to_string()<<"="<<c.to_string()<<endl;
    c=a/b;
    cout<<a.to_string()<<"/"<<b.to_string()<<"="<<c.to_string()<<endl;
    cout<<(a>b?"a lebih besar":"b lebih besar");
    return 0;
}
