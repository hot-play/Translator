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
    virtual void add(const UnitPtr&, Flags = 0) {
        throw std::runtime_error( "Not supported" );
    }
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    virtual std::string generateShift(unsigned int level) const
    {
        static const auto DEFAULT_SHIFT = "    ";
        std::string result;
        for(unsigned int i = 0; i < level; ++i) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_H
