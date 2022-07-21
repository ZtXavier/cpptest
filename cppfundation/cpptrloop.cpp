#include <iostream>
#include <memory>
 /* weak_ptr只有shared_ptr观测权没有使用权，不增加shared_ptr引用计数
如果要使用weak_ptr指向对象的功能，不能直接使用而应先用weak_ptr::lock()创建shared_ptr对象
weak_ptr用来防止shared_ptr的循环引用问题
 */

// weak_ptr使用惯例
/* if(auto ptr2 = wptr.lock()){
    //ptr2 is a new shared_ptr
    ptr2->work();
  } */

class Woman;
class Man{
private:
	std::weak_ptr<Woman> _wife;
	// std::shared_ptr<Woman> _wife;
public:
	void setWife(std::shared_ptr<Woman> woman){
		_wife = woman;
	}
 
	// void doSomthing(){
	// 	if(_wife.lock()){
	// 	}
	// }
 
	~Man(){
		std::cout << "kill man\n";
	}
};
 
class Woman{
private:
	// std::weak_ptr<Man> _husband;
	std::shared_ptr<Man> _husband;
public:
	void setHusband(std::shared_ptr<Man> man){
		_husband = man;
	}
	~Woman(){
		std::cout <<"kill woman\n";
	}
};
 
 
int main(int argc, char** argv){
	std::shared_ptr<Man> m(new Man());
	std::shared_ptr<Woman> w(new Woman());
	if(m && w) {
		m->setWife(w);
		w->setHusband(m);
	}
	return 0;
}