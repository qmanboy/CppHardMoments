#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include "timer.h"


template <class T>
class CreateVector
{
private:
    std::vector<T*> _vector;
public:
    CreateVector<T>()
    {
        for (size_t idx = 0; idx < 25; idx++)
        {
            int* temp = new int(rand()%500);
            _vector.push_back(temp);
        }
    }
    ~CreateVector()
    {
        std::for_each(_vector.begin(),_vector.end(),[](const int* element)
        {
            delete element;
        });
    }

    void Print()
    {
        std::for_each(_vector.begin(),_vector.end(),[](T* element)
        {
            std::cout << *element << " ";
        });
        std::cout << std::endl;
    }

    std::vector<T*>& Get()
    {
        return _vector;
    }
};

template <class T>
void Swap(T* number1, T* number2)
{
    T buf = *number1;
    *number1 = *number2;
    *number2 = buf;

}

template <class T>
void SortPointers(std::vector<T*>& _vector)
{

    std::sort(_vector.begin(),_vector.end(),[](T* element1, T* element2)
    {
        return *element1 < *element2;
    });
}

std::vector<char>& TxtToVector(std::ifstream& file)
{
    static std::vector<char> txt_vector;
    while (!file.eof())
    {
        char ch;
        file >> ch;
        txt_vector.push_back(ch);
    }
    return txt_vector;
}

std::string letters ={"AaEeIiOoUuYy"};

auto VowelCountIf(std::vector<char>& _vector)
{
    Timer timer("Count_if_find");
    auto count = std::count_if(_vector.begin(), _vector.end(), [&](char _char)
    {
        return (letters.find(_char) != std::string::npos);
    });
    timer.print();
    return count;
}

auto VowelCountFor(std::vector<char>& _vector)
{
    Timer timer("Count_for");
    auto count = std::count_if(_vector.begin(), _vector.end(), [&](char _char)
    {
        for (char letter : letters)
        {
            if (_char == letter)
                return true;
        }
        return false;
    });
    timer.print();
    return count;
}

auto VowelForFind(std::vector<char>& _vector)
{
    Timer timer("For_find");
    size_t count{0};
    for (auto _char : _vector)
    {
        if (letters.find(_char) != std::string::npos)
        {
            count++;
        }
    }
    timer.print();
    return count;
}

auto VowelForFor(std::vector<char>& _vector)
{
    Timer timer("For_for");
    size_t count{0};
    for (auto _char : _vector)
    {
        for (char letter : letters)
        {
            if (_char == letter)
                count++;
        }
    }
    timer.print();
    return count;
}

int main() {
    std::cout << "<---------Swap--------->" << std::endl;
    int a = 43;
    int b = 82;
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "&a = " << &a << " &b = " << &b << std::endl;
    Swap(&a,&b);
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "&a = " << &a << " &b = " << &b << std::endl;

    std::cout << "<---------SortPointers--------->" << std::endl;
    CreateVector<int> int_vector;
    int_vector.Print();
    SortPointers(int_vector.Get());
    int_vector.Print();

    std::cout << "<---------VowelCount--------->" << std::endl;
    std:: ifstream file("War and peace.txt");
    auto text = TxtToVector(file);
    std::cout << VowelCountIf(text) << std::endl;
    std::cout << VowelCountFor(text)<< std::endl;
    std::cout << VowelForFind(text)<< std::endl;
    std::cout << VowelForFor(text)<< std::endl;

    return 0;
}

