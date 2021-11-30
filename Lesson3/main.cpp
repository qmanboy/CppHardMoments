#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

void PushBackToList(std::list<double>& _list)
{
    double sum{0};
    for (const auto& n : _list)
    {
        sum += n;
    }
    _list.push_back(sum/_list.size());
};

void PrintList(std::list<double>& _list)
{
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    for (const auto& n : _list)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
};

class Matrix
{
private:
    std::vector<std::vector<int>> m_matrix;
    size_t m_size;
    int m_det;

public:

    Matrix(size_t _size) : m_size(_size)
    {
        srand(time(NULL));
        m_det = 0;
        if (m_size < 2)
            m_size = 2;
        for (size_t idx = 0; idx < m_size; idx++)
        {
            std::vector<int> _vector;
            for (size_t jdx = 0; jdx < m_size; jdx++)
            {
                _vector.push_back(rand()%500);
            }
            m_matrix.push_back(_vector);
        }
    };

    void Print()
    {
        for (const auto& entry : m_matrix)
        {
            for (const auto& entry_in : entry)
            {
                std::cout << std::setw(4) << entry_in << " ";
            }
            std::cout << std::endl;
        }
    }

    double CalculateDeterminant(std::vector<std::vector<int>>& _matrix)
    {
        double det = 0;
        if (_matrix.size() > 2)
        {
            for (size_t index = 0; index < _matrix.size(); index++)
            {
                std::vector<std::vector<int>> resultMatrix;
                for (size_t idx = 0; idx < _matrix.size(); idx++)
                {
                    if (idx != 0)
                    {
                        std::vector<int> _vector;
                        for (size_t jdx = 0; jdx < _matrix.size(); jdx++)
                        {
                            if (jdx != index) _vector.push_back(_matrix[idx][jdx]);
                        }
                        resultMatrix.push_back(_vector);
                    }
                }
                det = det + ((_matrix[0][index] * std::pow(-1, index+2)) * CalculateDeterminant(resultMatrix));
            }
            return det;
        }
        else
        {
            return _matrix[0][0] * _matrix[1][1] - _matrix[1][0] * _matrix[0][1];
        }
    }


    std::vector<std::vector<int>>& GetMatrix()
    {
        return m_matrix;
    }


};

template <class T>
class myIterator
{
private:
    std::vector<T> &m_container;

public:
    explicit myIterator(std::vector<T> &_container) : m_container(_container)
    {
    }
    T* begin()
    {
        return &*m_container.begin();
    }

    T* end()
    {
        return begin() + (m_container.size());
    }

};

int main()
{
    std::cout << "=========list============" << std::endl;
    std::list<double> list = {4.4, 4.2, 5.1, 7.7, 3.5, 3.7};
    PrintList(list);
    PushBackToList(list);
    PrintList(list);

    std::cout << "=========determinant============" << std::endl;
    Matrix matrix(4);
    matrix.Print();
    double result = matrix.CalculateDeterminant(matrix.GetMatrix());
    std::cout.setf(std::ios::fixed);
    std::cout.precision(0);
    std::cout << "Det = " << result << std::endl;

    std::cout << "=========iterator============" << std::endl;
    std::vector<int> vector = {4, 2, 1, 7, 5, 7};
    myIterator mi(vector);
    for (const auto& n : mi)
    {
        std::cout << n << " ";
    };
    std::cout << std::endl;
    std::for_each(mi.begin(), mi.end(), [](int& num) {std::cout << num << " ";});

};