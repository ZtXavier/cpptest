#include<iostream>
using namespace std;

class circular_buffer {
    private:
        int point;
        int len;
        int capacity;
        int *data;
    public:
        void add(int v) {
            data[len++] = v;
            len = len % capacity;
        }
        int get() {
            int ret;
            if(len == 0) {
                return -1;
            } else {
                for(int i = 0; i < capacity; i++) {
                    cout << data[i] << " ";
                }
            }
            
            return data[(point++)%len]; 
        }
        circular_buffer(int size):point(0), capacity(size), len(0), data(new int[size]) {
        }
};  


int main() {
    circular_buffer c(7);
    for(int i = 0; i < 10; ++i) {
        c.add(i);
    }
    c.get();
    return 0;
}
