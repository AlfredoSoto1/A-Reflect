#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <typeindex>
#include <typeinfo>

// Base annotation struct
struct Annotation {
    std::string value;
};

// Custom annotation derived from Annotation
struct CustomAnnotation : public Annotation {
    CustomAnnotation(const std::string& val) { value = val; }
};

// Base class to hold annotations
class Annotable {
public:
    // Static map to store annotations
    static std::unordered_map<std::type_index, std::vector<std::pair<std::string, std::shared_ptr<Annotation>>>> annotations;
};

// Initialize the static map
std::unordered_map<std::type_index, std::vector<std::pair<std::string, std::shared_ptr<Annotation>>>> Annotable::annotations;

// Macro to annotate functions
#define ANNOTATE(className, funcName, annotationType, annotationValue) \
    namespace { \
        static const bool funcName##_annotation_registered = []() { \
            auto annotation = std::make_shared<annotationType>(annotationValue); \
            Annotable::annotations[typeid(className)].emplace_back(#funcName, annotation); \
            return true; \
        }(); \
    }

// Example class that will use annotations
class MyClass : public Annotable {
public:
    MyClass() {}

    void myFunction() {
        // Function implementation
    }

    // Annotate the function
    ANNOTATE(MyClass, myFunction, CustomAnnotation, "This is a custom annotation")
};

int main() {
    MyClass myClassInstance;
    myClassInstance.myFunction();

    // Accessing annotations for MyClass
    auto it = Annotable::annotations.find(typeid(MyClass));
    if (it != Annotable::annotations.end()) {
        for (const auto& pair : it->second) {
            std::cout << "Function Name: " << pair.first << std::endl;
            std::cout << "Annotation Value: " << pair.second->value << std::endl;
        }
    }
    else {
        std::cout << "No annotations found for MyClass" << std::endl;
    }

    return 0;
}
