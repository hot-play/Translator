#ifndef UNIT_H
#define UNIT_H
#include <QCoreApplication>
#include <iostream>
#include <memory>

class Unit;

using UnitPtr = std::shared_ptr<Unit>;

class Unit {
public:
    // Модификаторы
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    // Метод добавления элемента
    virtual void add(const UnitPtr&, Flags = 0);
    // Компиляция объекта в текст
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    // Генерация "табов"
    virtual std::string generateShift(unsigned int level) const;
};

#endif // UNIT_H
