#include "javafactory.h"


UnitPtr JavaFactory::createClass(const std::string &name) const {
    return std::make_shared<JavaClassUnit>(name);
}

UnitPtr JavaFactory::createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

UnitPtr JavaFactory::createPrintOperator(const std::string &text) const {
    return std::make_shared<JavaPrintOperatorUnit>(text);
}
