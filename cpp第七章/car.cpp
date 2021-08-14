#include<cctype>
#include<iostream>
#include<string>

#define full_tank 85
class Car
{
public:
    std::string color;
    std::string engine;
    float gas_tank;
    unsigned int wheel;
    // Car(void);                    //构造函数
    float running(void);
    void setengine(std::string engine);
    void fill_tank(float gas);
    void change_clo(std::string color);
    void setwheel(int wheel);
    void warning(void);

};

void Car::fill_tank(float gas)
{
    gas_tank += gas;
}

void Car::change_clo(std::string color)
{
    this->color = color;
}

void Car::setwheel(int w)
{
    wheel = w;
}

void Car::setengine(std::string e)
{
    engine = e;
}

float Car:: running(void)
{
    std::cout << "汽车以120公里/时向西藏行驶..." << std::endl;
    gas_tank--;
    std::cout << "汽车油量剩余%" << 100*(gas_tank/full_tank) << std::endl;
    return gas_tank;
}

void Car::warning(void)
{
    std::cout << "注意！注意！ 油量剩余%" << 100*(gas_tank/full_tank) << std::endl;
}
int main(void)
{
        int i = 0;
        char ch;
        Car mycar;
        mycar.gas_tank = 40;
        mycar.setwheel(4);
        std::cout << "请选择你的车辆颜色:1.red 2.white" << std::endl;
        std::cin >> i;
        if(i == 1)
            mycar.change_clo("red");
        else
            mycar.change_clo("while");
        std::cout << "请选择你的车辆引擎:1.v8 2.r10" << std::endl;
        std::cin >> i;
        if(i == 1)
            mycar.change_clo("v8");
        else
            mycar.change_clo("r10");

        std::cout << "你的车辆以定制完成!!!准备上路!!!" << std::endl;

    while(1)
    {
        float ret =  mycar.running();
        if(ret <= 10.0)
        {
            if(ret == 0)
            {
                while(1)
                {
                    std::cout << "车已停止，请加油!!!" << std::endl;
                    std::cout << "是否停车加油 1.y 2.n" << std::endl;
                    std::cin >> ch;
                    if(ch == 'y')
                    {
                        std::cout << "请输入加的油量 (0 ~ 85)" << std::endl;
                        std::cin >> i;
                        if(i == 0)  continue;
                        mycar.fill_tank(i);
                        break;
                    }else    continue;

                }
            }
            mycar.warning();
            std::cout << "是否停车加油 1.y 2.n" << std::endl;
            std::cin >> ch;
            if(ch == 'y')
            {
                std::cout << "请输入加的油量 (0 ~ 85)" << std::endl;
                std::cin >> i;
                mycar.fill_tank(i);
            }else    continue;
        }
    }
    return 0;
}
