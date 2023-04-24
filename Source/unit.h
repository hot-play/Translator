#ifndef UNIT_H
#define UNIT_H
#include <QCoreApplication>
#include <iostream>
#include <memory>

class Unit;

using UnitPtr = std::shared_ptr<Unit>;

class Unit {
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add(const UnitPtr&, Flags = 0);
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    virtual std::string generateShift(unsigned int level) const;
};

#endif // UNIT_H
