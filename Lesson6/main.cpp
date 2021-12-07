#include <iostream>
#include <iomanip>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>

std::mutex mute, mute2;

template <class T>
void pcout(const T& _input) 
{
    mute.lock();
    std::cout << "started thread " << std::this_thread::get_id() << std::endl;
    std::cout << _input << std::endl;
    std::cout << "stopped thread " << std::this_thread::get_id() << std::endl;
    mute.unlock();
};

template<class T>
void Print(T _input)
{
    pcout(_input);
};

bool isprime(uint32_t _number)
{
    for(uint32_t i = 2; i <= sqrt(_number); i++)
        if(_number % i == 0)
            return false;
    return true;
}

uint64_t PrimeCheck(uint64_t _num)
{
    uint64_t idx = 1;
    uint64_t primecount = 1;
    uint64_t outnumber = 0;
    size_t progress = 0;
    size_t  old_progress = 0;
    while(idx)
    {
        if (isprime(idx))
        {
            outnumber = idx;
            progress = (uint64_t)(((double)primecount/(double)_num)*100);
            if (progress != old_progress) 
            {
                std::cout << '\r' << "Calculate: " << std::string(progress, '|') << ' ' << progress << "%" << std::flush; //вывод прогресса вычислений
                old_progress = progress;
            }
            if (primecount++ == _num)
                break;
        }
        idx++;
    }
    return outnumber;
}

void PrintVector(const std::string _msg, std::vector<uint16_t>& _vector) 
{
    std::cout << _msg << " > ";
    std::for_each(_vector.begin(), _vector.end(), [](auto _el){std::cout << _el << " ";});
    std::cout << std::endl;
}

void Owner(std::vector<uint16_t>& _things) 
{
    while(!_things.empty()) 
    {
        {
        std::lock_guard lg(mute);
        _things.push_back(rand()%100);
        PrintVector("Owner put", _things);
        }       
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Owner's end!" << std::endl;
}

void Thief(std::vector<uint16_t>& _things) 
{
    while(!_things.empty()) 
    {
        {
        std::lock_guard lg(mute);
        std::cout << "Thief's target > " << *(std::max_element(_things.begin(),_things.end())) << std::endl;
        _things.erase(std::max_element(_things.begin(),_things.end()));
        PrintVector("Thief took", _things);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "Thief's end!" << std::endl;
}

int main()
{
    std::thread th1([](auto _input){Print (_input);}, 1);
    std::thread th2([](auto _input){Print (_input);}, "two");
    std::thread th3([](auto _input){Print (_input);}, 3.5f);
    th1.join();
    th2.join();
    th3.join();

    uint64_t result;
    std::thread th([&]() {result = PrimeCheck(1000000);});
    th.join();
    std::cout << std::endl << "Result: "<< result << std::endl;

    std::vector<uint16_t> things{14,22,78,33,89,13,25,56,90,85,42,11};
    std::thread owner(Owner, std::ref(things));
    std::thread thief(Thief, std::ref(things));
    owner.join();
    thief.join();
    
    system("pause");
    return 0;
};