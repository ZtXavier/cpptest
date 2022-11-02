#include<iostream>
#include<queue>

int main() {
	std::priority_queue<int> a;
	std::priority_queue<int,std::vector<int>,std::greater<int>> c;
	std::priority_queue<std::string> b;

	for(int i = 0; i < 5; i++) {
		a.push(i);
		c.push(i);

	}
	while(!a.empty()) {
		std::cout << a.top() << ' ';
		a.pop();
	}
	std::cout << std::endl;



	while(!c.empty()) {
		std::cout << c.top() << ' ';
		c.pop();
	}
	std::cout << std::endl;

	b.push("abc");
	b.push("abcd");
	b.push("cdb");
	while(!b.empty()) {
		std::cout << b.top() << ' ';
		b.pop();
	}

	std::cout << std::endl;
	return 0;
}
