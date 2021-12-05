#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <cstdio>

template<class Container>
void PrintContainer(Container& container)
{
    std::for_each(container.begin(), container.end(), [](const auto& _el){std::cout << _el << " ";});
    std::cout << std::endl;
}

template<class Iterator>
void PrintUnique(Iterator begin, Iterator end)
{
    std::set<typename std::iterator_traits<Iterator>::value_type> uniq;
    std::for_each(begin, end, [&uniq](const auto& _el){uniq.insert(_el);});
    PrintContainer(uniq);
}

void PrintMap(const std::multimap<int, std::string>& map)
{
    std::for_each(map.begin(), map.end(), [](const auto& _el){std::cout << _el.second << " Length = " << _el.first << ";" << std::endl;});
    std::cout << std::endl;
}

void SentencesIntoFile(std::ifstream& file)
{
    std::multimap<int, std::string> map;
    std::string ends = {".?!"};
    std::string str{};
    while (!file.eof())
    {
        char symbol;
        file.get(symbol);
        if (ends.find(symbol) == std::string::npos) //посимвольное считывание пока не найден признак конца предложения
        {
           str.push_back(symbol);
        }
        else
        {
            if (!str.empty()) //Чтобы в словарь не добавлялась пустая строка
            {
                str.push_back(symbol); //Добавление в строку последнего символа предложения('.','!','?')
                size_t counter = 0;
                while (!std::isalpha(str[counter]) || !std::isalnum(str[counter])) //Подсчет лишних сиволов в начале строки
                {
                    counter++;
                }
                str.erase(0, counter); //Удаление лишних символов
                for (size_t idx = str.find('\n'); idx != std::string::npos; idx = str.find('\n'))
                {
                    str.replace(idx, 1, " "); //Замена переносов строки на пробелы
                }
                map.insert({str.size(), str});
                str = "";
            }
        }
    }
    PrintMap(map);
}

int main()
{
    std::vector<int> vector{ 1,2,3,4,5,6,6,7 };
    PrintUnique(vector.begin(),vector.end());

    std::ifstream file;
    file.open("Text.txt");
    SentencesIntoFile(file);

    return 0;
}
