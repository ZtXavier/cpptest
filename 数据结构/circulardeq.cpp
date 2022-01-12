#include<iostream>
#include<vector>


class Mycircular_deque
{
    private:
        std::vector<int> arr;
        int head,tail;
        int count;
    public:
        Mycircular_deque(int x) : head(0),tail(0),count(0),arr(x) {}

        bool in_Front(int value)
        {
            if(Full()) return false;
            --head;
            if(head == -1)
            {
                head = arr.size() - 1;
            }
            arr[head] = value;
            ++count;
            return true;
        }

        bool in_Last(int value)
        {
             if(Full()) return false;
            ++tail;
            if(tail == arr.size())
            {
                tail = arr.size() - 1;
            }
            arr[tail] = value;
            ++count;
            return true;
        }

        bool delete_front()
        {
            if(empty()) return false;
            head = (head + arr.size() + 1)%arr.size();
            --count;
            return true;
        }

        bool delete_last()
        {
            if(empty()) return false;
            tail = (tail + arr.size() - 1)%arr.size();
            --count;
            return true;
        }

        int get_front()
        {
             if(empty()) return -1;
             return arr[head];
        }

        int get_tail()
        {
            if(empty()) return -1;
            return arr[tail];
        }

        bool Full()
        {
            return count == arr.size();
        }

        bool empty()
        {
            return  count == 0;
        }
};



int main()
{
    Mycircular_deque dq(5);
    for(int i = 0;i < 5;i++)
    {
        dq.in_Front(i);
    }
    for(int i = 0;i < 5;i++)
    {
        std::cout << dq.get_tail() <<" ";
        
    }
    std::cout << std::endl;
    return 0;
}