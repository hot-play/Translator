#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <Source/unit.h>
#include <Source/Factories/factory.h>
#include <Source/Factories/cppfactory.h>
#include <Source/Factories/csfactory.h>
#include <Source/Factories/javafactory.h>

#include <Source/ClassUnits/classunit.h>
#include <Source/MethodUnits/methodunit.h>

const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS =
{"public", "protected", "private", "private protected", "file", "internal", "protected iternal"};

Factory * generateFactory(std::string language) {
    if (language == "cpp") {
        return new CppFactory();
    } else if (language == "cs") {
        return new CsFactory();
    } else if (language == "java") {
        return new JavaFactory();
    } else {
        return nullptr;
    }
}

std::string generateProgram(std::string language) {
    auto factory = generateFactory(language);

    UnitPtr myClass = factory->createClass("MyClass");

    UnitPtr method = factory->createMethod("testFunc1", "void", 0);
    myClass->add(method, ClassUnit::PUBLIC);

    method = factory->createMethod("testFunc2", "void", MethodUnit::STATIC);
    myClass->add(method, ClassUnit::PRIVATE);

    method = factory->createMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST);
    myClass->add(method, ClassUnit::PUBLIC);

    method = factory->createMethod("testFunc4", "void", MethodUnit::STATIC);
    auto printOperator = factory->createPrintOperator(R"(Hello, world!\n)");
    method->add(printOperator, 0);
    myClass->add(method, ClassUnit::PROTECTED);
    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    std::cout << "CPP :" << std::endl;
    std::cout << generateProgram("cpp") << std::endl;
//    std::cout << "-------------------------------" << std::endl;
//    std::cout << "CS :" << std::endl;
//    std::cout << generateProgram("cs") << std::endl;
//    std::cout << "-------------------------------" << std::endl;
//    std::cout << "JAVA :" << std::endl;
//    std::cout << generateProgram("java") << std::endl;
//    std::cout << std::endl;
    return a.exec();
}
