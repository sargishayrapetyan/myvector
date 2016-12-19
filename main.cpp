#include <iostream>
#include "Vector.h"

int main()
{
	Vector<int> v(7, 10);
	for (int i = 0; i < v.get_size(); ++i)
		std::cout << v[i] <<std::endl;
	Vector<int>::iterator it = v.end();
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << "   " << *it << std::endl;
	it = (v.end() - 1);
	std::cout << *it;
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	std::cout << "size = " << v.get_size() << std::endl;
	std::cout << "v[10] = " << v[9] << std::endl;
 	v.pop_back();
	for(int i = 0; i < v.get_size(); ++i)
	std::cout << "v[" << i << "] =" << v[i] << std::endl;
	std::cout << "*it = " << *it << std::endl;
	it = v.end() - 1;
	std::cout << "it = " << *it << std::endl;
	Vector<int>::iterator iter = v.erase(it);
	std::cout << "iter = " << *iter << std::endl;
	Vector<int> v1;
	v1.push_back(5);
	v1.push_back(6);
	std::cout << "v1[0] = " << v1[0] << std::endl;
	std::cout << "v1[1] = " << v1[1] << std::endl;
	std::cout << "v1.get_size() = " << v1.get_size() << std:: endl;
	auto it1 = v1.begin();
	Vector<int> v2 = { 1, 2, 3, 4 };
	std::cout << "v2[0] = " << v2[0] << std::endl;
	std::cout << "v2.get_size() = " << v2.get_size() << std::endl;



	//Vector<int>::iterator vi
	
}