#include <iostream>
#include <fstream>
#include "lesson7.pb.h"
#include "interface.h"

class StudentsGroup: public proto::StudentsGroup, virtual public IMethods, virtual public IRepository
{
    public:
    void Open() override
    {
        std::ifstream in("./lesson7.bin", std::ios_base::binary);
        if (this->ParseFromIstream(&in))
        {
            std::cout << "Deserialization is successful" << std::endl;
        }
    }

    void Save() override
    {
        std::ofstream out("./lesson7.bin", std::ios_base::binary);
        if (this->SerializePartialToOstream(&out))
        {
            std::cout << "Serialization is successful" << std::endl;
        }
    }

    double GetAverageScore(const proto::FullName& name) override
    {
        for (const auto& student : this->m_group())
        {
            if (std::tie(student.m_fullname().m_name(), student.m_fullname().m_surname(),
                         student.m_fullname().m_patronymic())
                == std::tie(name.m_name(), name.m_surname(), name.m_patronymic()))
            {
                return student.m_averagescore();
            }
        }
        return 0;
    }

    std::string GetAllInfo() override
    {
        std::string all_info;
        for (const auto& student : this->m_group())
        {
            all_info += student.m_fullname().m_name() + " " + student.m_fullname().m_surname() + " "
            + student.m_fullname().m_patronymic() + " ";
            for (const auto& score : student.m_scores())
            {
                all_info += std::to_string(score) + " ";
            }
            all_info += std::to_string(student.m_averagescore()) + '\n';
        }
        return all_info;
    }
    std::string GetAllInfo(const proto::FullName& name) override
    {
        std::string all_info;
        for (const auto& student : this->m_group())
        {
            if (std::tie(student.m_fullname().m_name(), student.m_fullname().m_surname(),
                         student.m_fullname().m_patronymic())
                == std::tie(name.m_name(), name.m_surname(), name.m_patronymic()))
            {
                all_info += student.m_fullname().m_name() + " " + student.m_fullname().m_surname() + " "
                            + student.m_fullname().m_patronymic() + " ";
                for (const auto &score: student.m_scores())
                {
                    all_info += std::to_string(score) + " ";
                }
                all_info += std::to_string(student.m_averagescore()) + '\n';
            }
        }
        if (!all_info.empty())
            return all_info;
        else
            return "Not found";
    }
};

void FillStudents(proto::Student* student, const std::string& name, const std::string& surname, const std::string& patronymic )
{
    double sum = 0;

    proto::FullName* fullname = student->mutable_m_fullname();
    fullname->set_m_name(name);
    fullname->set_m_surname(surname);
    fullname->set_m_patronymic(patronymic);
    student->set_allocated_m_fullname(fullname);

    for (size_t idx = 0; idx < 10; idx++)
    {
        student->add_m_scores(static_cast<int>(1 + (idx+rand()) % 5));
        sum += student->m_scores(idx);
    }
    student->set_m_averagescore(sum/student->m_scores_size());
}

int main()
{
    StudentsGroup students;

    proto::Student *student = students.add_m_group();
    FillStudents(student, "Ivan", "Ivanov", "Ivanovich");

    proto::Student *student2 = students.add_m_group();
    FillStudents(student2, "Petr", "Petrov", "Petrovich");

    proto::Student *student3 = students.add_m_group();
    FillStudents(student3, "Aleksey", "Alekseev", "Alekseevich");

    std::cout << "=========students out===========" << std::endl;
    std::cout << students.GetAllInfo();
    std::cout << students.GetAllInfo(student2->m_fullname());
    students.Save();
    std::cout << std::endl;

    std::cout << "==========students_from_bin out===========" << std::endl;
    StudentsGroup students_from_bin;
    students_from_bin.Open();
    std::cout << students_from_bin.GetAllInfo();
    std::cout << students_from_bin.GetAllInfo(student->m_fullname());

    return 0;
}
