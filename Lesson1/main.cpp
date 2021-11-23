#include <iostream>
#include <optional>
#include <tuple>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

struct Person
{
    std::string m_surname;
    std::string m_name;
    std::optional<std::string> m_patronymic;

    [[nodiscard]] std::string GetPatronymic() const
    {
        if (m_patronymic.has_value())
            return m_patronymic.value();
        return "";
    };

    bool operator<(const Person& p2)
    {
        return std::tie(m_surname, m_name, m_patronymic) < std::tie(p2.m_surname, p2.m_name, p2.m_patronymic);
    };
    bool operator==(const Person& p2)
    {
        return std::tie(this->m_surname, this->m_name, this->m_patronymic) == std::tie(p2.m_surname, p2.m_name, p2.m_patronymic);
    };
};

std::ostream& operator<<(std::ostream& personStream, const Person& person)
{
    personStream.setf(std::ios::left);
    return personStream << std::setw(12) << person.m_surname << ' ' << std::setw(10) << person.m_name << ' '
                        << std::setw(15) << person.GetPatronymic();
};

struct PhoneNumber
{
    uint16_t m_countryCode{};
    uint16_t m_cityCode{};
    uint32_t m_number{};
    std::optional<uint16_t> m_extNumber;

    [[nodiscard]] std::string GetExtNumber() const
    {
        if (m_extNumber.has_value())
            return std::to_string(m_extNumber.value());
        return "";
    };

    bool operator<(const PhoneNumber& p2)
    {
        return std::tie(this->m_countryCode, this->m_cityCode, this->m_number, this->m_extNumber)
               < std::tie(p2.m_countryCode, p2.m_cityCode, p2.m_number, p2.m_extNumber);
    };

    bool operator==(const PhoneNumber& p2)
    {
        return std::tie(this->m_countryCode, this->m_cityCode, this->m_number, this->m_extNumber)
               == std::tie(p2.m_countryCode, p2.m_cityCode, p2.m_number, p2.m_extNumber);
    };
};

std::ostream& operator<<(std::ostream& phoneStream, const PhoneNumber& phoneNum)
{
    return phoneStream << '+' << phoneNum.m_countryCode << '(' << phoneNum.m_cityCode << ')'
                       << phoneNum.m_number << " " << phoneNum.GetExtNumber();
};

class PhoneBook
{
private:
    std::vector<std::pair<Person, PhoneNumber>> m_phoneBook;
public:
    explicit PhoneBook(std::ifstream& file)
    {
        while (!file.eof())
        {
            std::string patronymic;
            std::string extNumber;
            std::pair<Person, PhoneNumber> m_entry;

            file >> m_entry.first.m_surname;
            file >> m_entry.first.m_name;
            file >> patronymic;
            m_entry.first.m_patronymic.emplace(patronymic);
            if (m_entry.first.m_patronymic.value() == "-")
            {
                m_entry.first.m_patronymic = std::nullopt;
            }
            file >> m_entry.second.m_countryCode;
            file >> m_entry.second.m_cityCode;
            file >> m_entry.second.m_number;
            file >> extNumber;
            if (extNumber == "-")
            {
                m_entry.second.m_extNumber = std::nullopt;
            }
            else
            {
                m_entry.second.m_extNumber.emplace(std::stoi(extNumber));
            }
            m_phoneBook.push_back(m_entry);
        }
    }

    [[nodiscard]] const std::vector<std::pair<Person, PhoneNumber>>& GetPhoneBook() const
    {
        return m_phoneBook;
    }

    void SortByName()
    {
        std::sort(m_phoneBook.begin(), m_phoneBook.end(),[](std::pair<Person, PhoneNumber>& entry1, std::pair<Person, PhoneNumber>& entry2 )
        {
            return entry1.first < entry2.first;
        });
    }

    void SortByPhone()
    {
        std::sort(m_phoneBook.begin(), m_phoneBook.end(),[](std::pair<Person, PhoneNumber>& entry1, std::pair<Person, PhoneNumber>& entry2 )
        {
            return entry1.second < entry2.second;
        });
    }

    std::vector<std::pair<std::string, PhoneNumber>> GetPhoneNumber(const std::string& surname)
    {
        std::vector<std::pair<std::string, PhoneNumber>> result;
        std::pair<std::string, PhoneNumber> resultPair;
        std::for_each(m_phoneBook.begin(), m_phoneBook.end(), [&](const std::pair<Person, PhoneNumber>& entry)
        {
            if (entry.first.m_surname == surname)
            {
                resultPair.first = entry.first.m_surname;
                resultPair.second = entry.second;
                result.push_back(resultPair);
            };
        });
        if (result.empty())
        {
            result = {{{"not found"},{0}}};
        }
        return result;
    }

    void ChangePhoneNumber(const Person& person, const PhoneNumber& newNumber)
    {
        for (auto& pair : m_phoneBook)
        {
            if (const_cast<Person &>(person) == pair.first)
            {
                pair.second = newNumber;
            }
        }
    }
};

std::ostream& operator<<(std::ostream& bookStream, const PhoneBook& phoneBk)
{
    std::for_each(phoneBk.GetPhoneBook().begin(), phoneBk.GetPhoneBook().end(),[&](const std::pair<Person, PhoneNumber>& entry)
    {
        bookStream << entry.first << entry.second << "\n";
    });
    return bookStream;
};

int main()
{
    std:: ifstream file("PhoneBook.txt");
    PhoneBook book(file);
    std::cout << book;

    std::cout << "------SortByName-------" << std::endl;
    book.SortByName();
    std::cout << book;

    std::cout << "------SortByPhone-------" << std::endl;
    book.SortByPhone();
    std::cout << book;

    std::cout << "-----GetPhoneNumber-----" << std::endl;
    auto print_phone_number = [&book](const std::string& surname)
    {
        std::cout << "Search phone number for: " << surname << std::endl;
        auto answer = book.GetPhoneNumber(surname);
        std::for_each(answer.begin(), answer.end(),[](const std::pair<std::string, PhoneNumber>& entry)
        {
            std::cout << entry.first << " " << entry.second << std::endl;
        });
    };
    print_phone_number("Solovev");
    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    std::cout << "----ChangePhoneNumber----" << std::endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },PhoneNumber{7, 123, 15344458, std::nullopt});
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, 9155448, 13 });
    std::cout << book;

    return 0;
}
