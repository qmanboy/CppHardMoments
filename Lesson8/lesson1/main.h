#pragma once
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

    [[nodiscard]] std::string GetPatronymic() const;
    friend bool operator<(const Person& p1, const Person& p2);
    friend bool operator==(const Person& p1, const Person& p2);
    friend std::ostream& operator<<(std::ostream& personStream, const Person& person);
};


struct PhoneNumber
{
    uint16_t m_countryCode{};
    uint16_t m_cityCode{};
    uint32_t m_number{};
    std::optional<uint16_t> m_extNumber;

    [[nodiscard]] std::string GetExtNumber() const;
    friend bool operator<(const PhoneNumber& p1, const PhoneNumber& p2);
    friend bool operator==(const PhoneNumber& p1, const PhoneNumber& p2);
    friend std::ostream& operator<<(std::ostream& phoneStream, const PhoneNumber& phoneNum);
};

class PhoneBook
{
private:
    std::vector<std::pair<Person, PhoneNumber>> m_phoneBook;
public:
    PhoneBook() = default;
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
    [[nodiscard]] const std::vector<std::pair<Person, PhoneNumber>>& GetPhoneBook() const;
    void SortByName();
    void SortByPhone();
    std::vector<std::pair<std::string, PhoneNumber>> GetPhoneNumber(const std::string& surname);
    void ChangePhoneNumber(const Person& person, const PhoneNumber& newNumber);
    friend std::ostream& operator<<(std::ostream& bookStream, const PhoneBook& phoneBk);
};




