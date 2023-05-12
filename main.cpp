#include <QCoreApplication>
#include <iostream>
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
    // По строке смотрим фабрику какого языка нам нужно использовать
    if (language == "cpp") {
        return new CppFactory();
    } else if (language == "cs") {
        return new CsFactory();
    } else if (language == "java") {
        return new JavaFactory();
    } else {
        return new Factory();
    }
}

std::string generateProgram(std::string language) {
    try {
        Factory * factory = generateFactory(language);
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

        delete factory;
        return myClass->compile();
    }
    // В случае неподдерживаемого языка, будет вызов ошибки
    catch (const std::runtime_error& e) {
        std::cerr << e.what();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "C++ :" << std::endl;
    std::cout << generateProgram("qt") << std::endl;
//    std::cout << "-------------------------------" << std::endl;
//    std::cout << "C# :" << std::endl;
//    std::cout << generateProgram("cs") << std::endl;
//    std::cout << "-------------------------------" << std::endl;
//    std::cout << "Java :" << std::endl;
//    std::cout << generateProgram("java") << std::endl;
//    std::cout << std::endl;
    return a.exec();
}
