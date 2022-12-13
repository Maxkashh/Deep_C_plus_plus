#include <iostream>
#include "../lib/deque.h"

using namespace custom_std;
int main()
{
custom_deque<int>dq{1,2,3,4,5};
std::cout<<dq.size()<<std::endl;
for (auto iter = dq.begin(); iter != dq.end(); iter++)
    std::cout << *iter << "\t";
std::cout<<std::endl;

dq.pop_front();
dq.push_back(0);
std::cout<<dq;
}