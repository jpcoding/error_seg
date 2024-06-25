#include<vector>
#include<iostream>

std::vector<int> foo()
{
    std::vector<int> v(10000,0);
    for(int i = 0; i < 10000; i++)
    {
        v[i] = i;
    }
    std::cout << "address " << &v[0] << std::endl; 
    return v;
}

int main()
{
    auto v = foo();
    std::cout << v[0] << std::endl;
    std::cout << "address out " << &v[0] << std::endl; 

    return 0;
}