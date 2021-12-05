#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

template <class T, class Container>
void insert_sorted(Container& _container, const T _element)
{
    if (std::is_sorted(_container.begin(), _container.end()))
    {
        _container.insert(std::lower_bound(_container.begin(), _container.end(), _element), _element);
    }
    else
    {
        std::cout << "Container is not sorted!" << std::endl;
    }
};

template <class Container>
void PrintContainer(Container& _container)
{
    std::for_each(_container.begin(), _container.end(), [](auto _el){std::cout << _el << " ";});
    std::cout << std::endl;
};

double DigiError(std::vector<double>& v1, std::vector<int>& v2)
{
    //std::accumulate();
    double sum = 0;
    size_t idx = 0;
    for (const auto& _el : v1)
    {
        sum += std::pow((_el - v2[idx++]), 2);
    }
    return std::sqrt(sum/v1.size()); //если речь о среднем квадратичном отклонении
}

int main()
{
    std::vector<int> vector{4,2,5,63,12,22,33,56,12};
    std::vector<double> list{4.1,2.5,5.4,63.8,12.1,12.7,33.0,56.4,12.9};
    std::string string{"hello world!"};
    PrintContainer(vector);
    PrintContainer(list);
    PrintContainer(string);

    std::sort(vector.begin(), vector.end());
    std::sort(list.begin(), list.end());
    std::sort(string.begin(), string.end());
    PrintContainer(vector);
    PrintContainer(list);
    PrintContainer(string);

    insert_sorted(vector, 25);
    insert_sorted(list, 12.3);
    insert_sorted(string, 'B');
    PrintContainer(vector);
    PrintContainer(list);
    PrintContainer(string);

    std::vector<double> d_vector(8, 0);
    std::generate(d_vector.begin(), d_vector.end(),[](){return (100.0 + (double)(rand() % 100))/(double)3.3;});
    std::vector<int> i_vector;
    std::for_each(d_vector.begin(), d_vector.end(), [&](double _el){i_vector.push_back((int)_el);});

    PrintContainer(d_vector);
    PrintContainer(i_vector);

    std::cout << "Result = " << DigiError(d_vector, i_vector) << std::endl;
};