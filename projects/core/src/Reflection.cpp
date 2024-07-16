//#include <iostream>
//#include <memory>
//#include <unordered_map>
//#include <vector>
//#include <string>
//#include <typeindex>
//#include <typeinfo>
//
//// Base annotation interface
//struct Annotation {};
//
//// Custom annotation derived from Annotation
//struct CustomAnnotation : public Annotation {
//    std::string val;
//    CustomAnnotation(const std::string& val) : val(val) {}
//};
//
//// Base class to hold annotations
//class Annotable {
//public:
//    // Static map to store annotations
//    static std::unordered_map<std::string, std::shared_ptr<Annotation>> annotations;
//
//    // Helper function to create annotations
//    static bool createAnnotation(const std::string& key, std::shared_ptr<Annotation> annotation) {
//        annotations[key] = annotation;
//        return true;
//    }
//};
//
//// Initialize the static map
//std::unordered_map<std::string, std::shared_ptr<Annotation>> Annotable::annotations;
//
//// Macro to annotate functions
//#define ANNOTATE(className, funcName, annotationType, annotationValue) \
//    namespace { \
//        static const bool funcName##_annotation_registered = Annotable::createAnnotation( \
//            std::string(typeid(className).name()) + "::" #funcName, \
//            std::make_shared<annotationType>(annotationValue) \
//        ); \
//    }
//
//// Example class that will use annotations
//class MyClass : public Annotable {
//public:
//    MyClass() {}
//
//    void myFunction() {
//        std::cout << "Executing myFunction" << std::endl;
//    }
//
//    // Annotate the function
//    ANNOTATE(MyClass, myFunction, CustomAnnotation, "This is a custom annotation")
//};
//
//int main() {
//    MyClass myClassInstance;
//    myClassInstance.myFunction();
//
//    // Accessing annotations for MyClass::myFunction
//    std::string key = std::string(typeid(MyClass).name()) + "::myFunction";
//    auto it = Annotable::annotations.find(key);
//    if (it != Annotable::annotations.end()) {
//        auto annotation = std::dynamic_pointer_cast<CustomAnnotation>(it->second);
//        if (annotation) {
//            std::cout << "Function Name: " << key << std::endl;
//            std::cout << "Annotation Value: " << annotation->val << std::endl;
//        }
//    }
//    else {
//        std::cout << "No annotations found for " << key << std::endl;
//    }
//
//    return 0;
//}
