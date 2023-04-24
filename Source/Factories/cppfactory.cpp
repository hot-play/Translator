#include "cppfactory.h"


UnitPtr CppFactory::createClass(const std::string &name) const {
    return std::make_shared<CppClassUnit>(name);
}

UnitPtr CppFactory::createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const {
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

UnitPtr CppFactory::createPrintOperator(const std::string &text) const {
    return std::make_shared<CppPrintOperatorUnit>(text);
}
