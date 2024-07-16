#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <functional>

// Base annotation interface
struct Annotation {};

// Custom annotation derived from Annotation
struct CustomAnnotation : public Annotation {
    std::string val;
    CustomAnnotation(const std::string& val) : val(val) {}
};

// Base class to hold annotations
class Annotable {
public:
    // Static map to store annotations
    static std::unordered_map<std::string, std::weak_ptr<Annotation>> annotations;

    template<class Class, typename Annotation>
    static std::function getFunction() {
        return nullptr;
    }
};

// Helper function to create annotations
bool createAnnotation(const std::string& key, Annotation* annotation) {
    Annotable::annotations[key] = std::shared_ptr<Annotation>(annotation);
    return true;
}

// Initialize the static map
std::unordered_map<std::string, std::weak_ptr<Annotation>> Annotable::annotations;

#define ANNOTATE(function, ...)         \
    function(__VA_ARGS__);              \
    static bool function##_annotation;  \

#define ANNOTATION(clazz_function, annotation)                                                                                        \
    bool clazz_function##_annotation = (Annotable::annotations[#clazz_function] = std::shared_ptr<Annotation>(new annotation), true); \


// Example class that will use annotations
class MyClass {
public:
    MyClass() {}

    void ANNOTATE(myFunction);
};

ANNOTATION(MyClass::myFunction, CustomAnnotation(""))
void MyClass::myFunction() {
    std::cout << "Executing myFunction" << std::endl;
}

int main() {
    MyClass myClassInstance;
    myClassInstance.myFunction();
    
    auto function = Annotable::getFunction<MyClass, CustomAnnotation>();

    for (auto&[name, annotation] : Annotable::annotations) {
        if (auto ann = annotation.lock())
            std::cout << name << " " << ann << std::endl;
    }

    return 0;
}
