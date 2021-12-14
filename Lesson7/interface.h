#ifndef LESSON7_INTERFACE_H
#define LESSON7_INTERFACE_H
#include <string>

class IRepository {
    virtual void Open() = 0;
    virtual void Save() = 0;
};

class IMethods {
    virtual double GetAverageScore(const proto::FullName& name) = 0;
    virtual std::string GetAllInfo(const proto::FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};

#endif
