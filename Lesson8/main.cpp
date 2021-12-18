#include <iostream>
#include <gtest/gtest.h>
#include "lesson1/main.h"

std::string Person::GetPatronymic() const
{
    if (m_patronymic.has_value())
        return m_patronymic.value();
    return "";
}

bool operator<(const Person& p1, const Person& p2)
{
    return std::tie(p1.m_surname, p1.m_name, p1.m_patronymic) < std::tie(p2.m_surname, p2.m_name, p2.m_patronymic);
}
bool operator==(const Person& p1, const Person& p2)
{
    return std::tie(p1.m_surname, p1.m_name, p1.m_patronymic) == std::tie(p2.m_surname, p2.m_name, p2.m_patronymic);
}
std::ostream& operator<<(std::ostream& personStream, const Person& person)
{
    personStream.setf(std::ios::left);
    return personStream << std::setw(12) << person.m_surname << ' ' << std::setw(10) << person.m_name << ' '
                        << std::setw(15) << person.GetPatronymic();
}

std::string PhoneNumber::GetExtNumber() const
{
    if (m_extNumber.has_value())
        return std::to_string(m_extNumber.value());
    return "";
}
bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return std::tie(p1.m_countryCode, p1.m_cityCode, p1.m_number, p1.m_extNumber)
           < std::tie(p2.m_countryCode, p2.m_cityCode, p2.m_number, p2.m_extNumber);
}
bool operator==(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return std::tie(p1.m_countryCode, p1.m_cityCode, p1.m_number, p1.m_extNumber)
           == std::tie(p2.m_countryCode, p2.m_cityCode, p2.m_number, p2.m_extNumber);
}
std::ostream& operator<<(std::ostream& phoneStream, const PhoneNumber& phoneNum)
{
    return phoneStream << '+' << phoneNum.m_countryCode << '(' << phoneNum.m_cityCode << ')'
                       << phoneNum.m_number << " " << phoneNum.GetExtNumber();
}

const std::vector<std::pair<Person, PhoneNumber>>& PhoneBook::GetPhoneBook() const
{
    return m_phoneBook;
}
void PhoneBook::SortByName()
{
    std::sort(m_phoneBook.begin(), m_phoneBook.end(),[](std::pair<Person, PhoneNumber>& entry1, std::pair<Person, PhoneNumber>& entry2 )
    {
        return entry1.first < entry2.first;
    });
}
void PhoneBook::SortByPhone()

{
    std::sort(m_phoneBook.begin(), m_phoneBook.end(),[](std::pair<Person, PhoneNumber>& entry1, std::pair<Person, PhoneNumber>& entry2 )
    {
        return entry1.second < entry2.second;
    });
}
std::vector<std::pair<std::string, PhoneNumber>> PhoneBook::GetPhoneNumber(const std::string &surname)
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
void PhoneBook::ChangePhoneNumber(const Person &person, const PhoneNumber &newNumber)
{
    for (auto& pair : m_phoneBook)
    {
        if (const_cast<Person &>(person) == pair.first)
        {
            pair.second = newNumber;
        }
    }
}
std::ostream& operator<<(std::ostream& bookStream, const PhoneBook& phoneBk)
{
    std::for_each(phoneBk.GetPhoneBook().begin(), phoneBk.GetPhoneBook().end(),[&](const std::pair<Person, PhoneNumber>& entry)
    {
        bookStream << entry.first << entry.second << "\n";
    });
    return bookStream;
}

TEST(Phonebook, SortByName)
{
    std::ifstream file("test_book.txt");
    PhoneBook test_book(file);
    test_book.SortByName();
    ASSERT_EQ(test_book.GetPhoneBook()[0].first.m_surname, "Aleksandrov");
    ASSERT_EQ(test_book.GetPhoneBook()[1].first.m_surname, "Dubinin");
    ASSERT_EQ(test_book.GetPhoneBook()[2].first.m_surname, "Morozov");
}

TEST(Phonebook, SortByPhone)
{
    std::ifstream file("test_book.txt");
    PhoneBook test_book(file);
    test_book.SortByPhone();
    ASSERT_EQ(test_book.GetPhoneBook()[0].second.m_countryCode, 7);
    ASSERT_EQ(test_book.GetPhoneBook()[1].second.m_countryCode, 37);
    ASSERT_EQ(test_book.GetPhoneBook()[2].second.m_countryCode, 493);
}

TEST(Phonebook, ChangePhoneNumber)
{
    std::ifstream file("test_book.txt");
    PhoneBook test_book(file);
    PhoneNumber test_number;
    test_number.m_countryCode = 8;
    test_number.m_cityCode = 812;
    test_number.m_number = 123456789;
    test_book.ChangePhoneNumber(test_book.GetPhoneBook()[0].first, test_number);
    ASSERT_EQ(test_book.GetPhoneBook()[0].second, test_number);
}

TEST(PhoneNumber, Operator_equally)
{
    PhoneNumber test_number;
    test_number.m_countryCode = 8;
    test_number.m_cityCode = 812;
    test_number.m_number = 123456789;
    PhoneNumber test_number2;
    test_number2.m_countryCode = 8;
    test_number2.m_cityCode = 812;
    test_number2.m_number = 123456789;
    PhoneNumber test_number3;
    test_number3.m_countryCode = 9;
    test_number3.m_cityCode = 812;
    test_number3.m_number = 123456789;
    ASSERT_TRUE(test_number == test_number2);
    ASSERT_FALSE(test_number == test_number3);
}


int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
