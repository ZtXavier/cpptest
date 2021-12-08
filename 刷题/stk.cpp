#include<iostream>


class My_Stack
{
public:
    My_Stack(int size);
    void M_Sinit();
    bool M_Sempty();
    int M_Ssize();
    void M_Sshow();
    int M_Spop();
    int M_Stop();
    void M_Spush(int num);
private:
    int *array;
    int size;
    int capital;
    int top;
    int for_each;
};

My_Stack::My_Stack(int size){
    this->top = -1;
    this->array = new int[size];
    this->capital = size;
    this->size = 0;
}


void My_Stack::M_Sinit(){

}

bool My_Stack::M_Sempty(){
    if(size == 0){
        return true;
    }else{
        return false;
    }
}

int My_Stack::M_Ssize(){
    return size;
}

void My_Stack::M_Sshow(){
    for(int i = 0;i < size;i++){
        if(i == size - 1)
        std::cout << array[i] ;
        std::cout << array[i] << " ";
    }
}

void My_Stack::M_Spush(int num){
    array[++top] = num;
    size++;
}

int My_Stack::M_Stop(){
    return array[top];
}

int My_Stack::M_Spop(){
    return array[top--];
}


void test01(){
    int flag = 0;
    int num;
    int maxlen = 10,stp;
    My_Stack sk(maxlen);
    while(std::cin >> stp){
        switch(stp){
            case 3:
                if(flag == 0){
                    std::cout << "stack is not exist" << std::endl;
                    break;
                }
                else if(sk.M_Sempty()){
                    std::cout << "The stack is Empty1" << std::endl;
                    break;
                }
                else{
                    std::cout << sk.M_Spop() << std::endl;
                }
            case 1:
                flag = 1;
                while(std::cin >> num) sk.M_Spush(num);

            case 2:
                if(sk.M_Sempty()){
                    std::cout << "The stack is Empty2" << std::endl;
                    break;
                }else if(sk.M_Ssize() == 10){
                    std::cout << "The stack is full" << std::endl;
                    break;
                }
                else{
                    if(std::cin >> num)
                    sk.M_Spush(num);
                    else std::cout << "data error";
                }
            case 4:
                if(flag == 0){
                    std::cout << "stack is not exist" << std::endl;
                    break;
                }
               sk.M_Sshow();
            case 5:
                if(flag == 0){
                    std::cout << "stack is not exist" << std::endl;
                    break;
                }
                else{
                    std::cout << sk.M_Ssize() << std::endl;
                }
                break;
        }
    }
}


int main(){
    test01();
    return 0;
}