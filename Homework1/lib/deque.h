#pragma once
#include <iostream>
#include <vector>
#include <iterator>
using std::vector;
template<typename T>
using custom_iterator=typename std::vector<T>::const_iterator ;
namespace custom_std
{



    template<typename T>
    class custom_deque {
    public:
        custom_deque(std::initializer_list<T> list)
        {
            deque=list;
        }

        custom_deque()
        {

        }
        explicit custom_deque(size_t size)
        {
            deque.resize(size);
        }
        explicit custom_deque(size_t size,T value)
        {
            deque.resize(size);
            for(auto &el:deque) el=value;
        }
        void clear()
        {
            deque.clear();
        }
        T size() const
        {
            return deque.size();
        }

        [[nodiscard]] bool empty() const
        {
            return deque.empty();
        }
        void resize(T elem)
        {
            deque.resize(elem);
        }
        void resize(T elem,T value)
        {
            deque.resize(elem,value);
        }
        custom_iterator<T> begin() const noexcept
        {
            auto iter= deque.begin();
            return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);
        }
        const custom_iterator<T> cbegin() const noexcept
        {
            auto iter= deque.cbegin();
            return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);

        }
        custom_iterator<T> end() const noexcept
        {
            auto iter= deque.end();
            return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);
        }
        const custom_iterator<T> cend() const noexcept
        {
            auto iter= deque.cend();
            return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);
        }
        void assign(std::initializer_list<T> list)
        {
            deque.assign(list);
        }
        void assign(int n,T value)
        {
            deque.assign( n,value);
        }
        void swap(custom_deque<T>dq2)
        {
            deque.swap(dq2.deque);
        }
        void print()
        {
            for(const auto &i:deque)
                std::cout<<i<<" ";
        }
        void push_front(T temp)
        {
            deque.insert(deque.begin(), temp);

        }
        void push_back(T temp)
        {
            deque.push_back(temp);
        }
        void pop_front()
        {
            deque.erase(deque.begin());
        }
        void pop_back()
        {
            deque.pop_back();
        }
        void emplace_front(T temp)
        {
            deque.insert(deque.begin(), temp);
        }
        void emplace_back(T temp)
        {
            deque.push_back(temp);
        }
        void emplace(custom_iterator<T> pos,T temp)
        {
            deque.emplace(pos,temp);
        }

        custom_iterator<T> insert(custom_iterator<T> pos, int val)
        {
            return deque.insert(pos,val);
        }
        custom_iterator<T> insert(custom_iterator<T> pos,size_t  n, int val)
        {
            return deque.insert(pos,n,val);
        }
        custom_iterator<T> insert(custom_iterator<T> pos, std::_List_iterator<T> begin, std::_List_iterator<T>  end)
        {

            return deque.insert(pos,begin,end);

        }
        custom_iterator<T> insert(custom_iterator<T> pos, std::initializer_list<T> values)
        {

            return  deque.insert(pos,values);
            // return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);
        }
        custom_iterator<T> erase(custom_iterator<T> begin, custom_iterator<T> end)
        {
            auto iter= deque.erase(begin,end);
            return reinterpret_cast<__gnu_cxx::__normal_iterator<T *, vector<T>> &&>(iter);

        }
        custom_iterator<T> erase(custom_iterator<T> p)
        {
            return deque.erase(p);
        }
        T front()
        {
            if(!deque.empty())
            {
                T elem = deque[0];
                return elem;
            }
            return -1;
        }
        T back()
        {
            if(!deque.empty())
            {

                T elem=deque[deque.size() - 1];

                return elem;
            }

            return -1;
        }
        T at(int index)
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
        template <class V>
        friend std::ostream& operator<< (std::ostream &out, const custom_deque<V> &dq)
        {
            for (const auto &item : dq.deque)
                out << item<<" ";
            return out;
        }


        bool operator==(const custom_deque<T> &dq2)
        {
            if (deque.size() != dq2.size())
                return false;
            for(int i=0;i<deque.size();i++)

            {
                if(deque[i] != dq2.deque[i])
                    return false;
            }
            return true;


        }


        T operator[] (int index)
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
        const T operator[] (int index) const
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

    private:
        vector<T> deque;
    };
}