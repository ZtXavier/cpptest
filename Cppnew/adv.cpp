#include<iostream>
#include<iterator>
#include<vector>

// std::advance 需要iterator头文件
int main() {
	std::vector<int> v{3,1,4};
	auto v1 = v.begin();
	std::advance(v1,2);
	std::cout << *v1 << '\n';
	return 0;
}
