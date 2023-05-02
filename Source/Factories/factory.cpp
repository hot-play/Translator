#include "factory.h"

UnitPtr Factory::createClass(const std::string &name) const {
    throw std::runtime_error("Language not supported");
}

UnitPtr Factory::createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const {
    throw std::runtime_error("Language not supported");
}

UnitPtr Factory::createPrintOperator(const std::string &text) const {
    throw std::runtime_error("Language not supported");
}
