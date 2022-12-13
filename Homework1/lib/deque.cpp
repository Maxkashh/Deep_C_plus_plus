#include <iostream>
#include "deque.h"
using namespace custom_std;

template <typename T>
custom_deque<T>::custom_deque(size_t size)
{
    deque.resize(size);
}

template <typename T>
void custom_deque<T>::push_front(T temp)
{
    deque.insert(deque.begin(), temp);

}
template <typename T>
void custom_deque<T>::push_back(T temp)
{
deque.push_back(temp);
}
template <typename T>
void custom_deque<T>::pop_front()
{
    deque.erase(deque.begin());
}
template <typename T>
void custom_deque<T>::pop_back()
{
    deque.pop_back();
}

template<typename T>
void custom_deque<T>::print()
{
for(const auto &i:deque)
    std::cout<<i<<" ";
}


template<typename T>
T custom_deque<T>::operator[](const int index) {
    T res=0;
    try
    {
        res= deque.at(index);

    }
    catch (std::out_of_range &e)
    {
        std::cout << "out_of_range" << std::endl;
    }
    return res;
}

template<typename T>
const T custom_deque<T>::operator[](const int index) const
{
    T res=0;
    try
    {
        res= deque.at(index);
    }
    catch (std::out_of_range &e)
    {
        std::cout << "out_of_range" << std::endl;
    }
    return res;
}

template<typename T>
custom_deque<T>::custom_deque(std::initializer_list<T> list)
{
deque=list;
}

template<typename T>
T custom_deque<T>::front()
{
    if(!deque.empty())
    {
        T elem = deque[0];
        return elem;
    }
    return -1;
}

template<typename T>
T custom_deque<T>::back()
{
    if(!deque.empty())
    {
        T elem=deque[deque.size()-1];
        return elem;
    }

    return -1;
}

template<typename T>
T custom_deque<T>::size() const
{
    return deque.size();
}

template<typename T>
void custom_deque<T>::clear()
{
deque.clear();
}

template<typename T>
T custom_deque<T>::at(const int index)
{
    try
    {
        return deque.at(index);
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Incorrect index" << std::endl;
    }

}

template<typename T>
void custom_deque<T>::resize(T elem, T value)
{
deque.resize(elem,value);
}

template<typename T>
void custom_deque<T>::resize(T elem)
{
deque.resize(elem);
}

template<typename T>
bool custom_deque<T>::empty() const
{
    return deque.empty();
}

template<typename T>
void custom_deque<T>::emplace_front(T temp)
{
    deque.insert(deque.begin(), temp);
}

template<typename T>
void custom_deque<T>::emplace_back(T temp)
{
    deque.push_back(temp);
}

template<typename T>
custom_iterator<T> custom_deque<T>::begin() const noexcept
{
    auto iter= deque.begin();
    return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);
}

template<typename T>
custom_iterator<T> custom_deque<T>::end() const noexcept
{
    auto iter= deque.end();
    return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);
}

template<typename T>
void custom_deque<T>::assign(std::initializer_list<T> list)
{
deque.assign(list);
}

template<typename T>
void custom_deque<T>::assign(int n, T value)
{
    deque.assign( n,value);
}


template<typename T>
void custom_deque<T>::swap( custom_deque<T> dq2)
{
deque.swap(dq2.deque);
}

template<typename T>
custom_iterator<T> custom_deque<T>::insert(custom_iterator<T> pos, int val)
{
    return deque.insert(pos,val);
}

template<typename T>
custom_iterator<T> custom_deque<T>::insert(custom_iterator<T> pos, size_t n, int val)
{
    return deque.insert(pos,n,val);
}

template<typename T>
custom_iterator<T> custom_deque<T>::insert(custom_iterator<T> pos, std::_List_iterator<T> begin, std::_List_iterator<T> end)
{

    return deque.insert(pos,begin,end);

}

template<typename T>
custom_iterator<T> custom_deque<T>::insert(custom_iterator<T> pos, std::initializer_list<T> values)
{

    return  deque.insert(pos,values);
   // return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);
}

template<typename T>
custom_iterator<T> custom_deque<T>::erase(custom_iterator<T> p)
{
    return deque.erase(p);
}

template<typename T>
custom_iterator<T> custom_deque<T>::erase(custom_iterator<T> begin, custom_iterator<T> end)
{
    auto iter= deque.erase(begin,end);
    return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);

}

template<typename T>
const custom_iterator<T> custom_deque<T>::cbegin() const noexcept
{
    auto iter= deque.cbegin();
    return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);

}

template<typename T>
const custom_iterator<T> custom_deque<T>::cend() const noexcept
{
    auto iter= deque.cend();
    return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);
}

template<typename T>
custom_deque<T>::custom_deque()
{

}

template<typename T>
custom_deque<T>::custom_deque(size_t size, T value)
{
deque.resize(size);
for(auto &el:deque) el=value;
}




template<typename T>
void custom_deque<T>::emplace(custom_iterator<T> pos, T temp)
{
deque.emplace(pos,temp);
}


