#include <iostream>
#include "../include/defer.hpp"

#define TEST(x) void test##x()


int test_local_variable() {
    int a = 9;
    defer::defer<int> defer1(a, 33);
    return a;
}


TEST(1) {
    std::cout << "--------------------TEST-1-START---------------------" << std::endl;
    std::cout << "defer can't change value of local variable if it will be returned before defer destructor called."
              << " In this case int test_local_variable() don't will return 33 with for c++ rules, it returns "
              << test_local_variable() << std::endl;
    std::cout << "--------------------TEST-1-END-----------------------" << std::endl;

};

TEST(2) {
    std::cout << "--------------------TEST-2-START---------------------" << std::endl;
    int a = 1;
    float b = 1.f;
    double c = 11.0;
    std::string d = "str";
    std::cout << "Before defer:" << std::endl;
    std::cout << "int a = 1;\n"
                 "float b = 1.f;\n"
                 "double c = 11.0;\n"
                 "std::string d = \"1\";" << std::endl;

    {
        defer::defer<int> ad(a, 2);
        defer::defer<float> bd(b, 2.f);
        defer::defer<double> cd(c, 22.0);
        defer::defer<std::string> dc(d, "STR");
    }

    std::cout << "After defer:" << std::endl;
    std::cout << "int a = " << a << std::endl
              << "float b = " << b << std::endl
              << "double c = " << c << std::endl
              << "std::string d = " << d << std::endl;

    std::cout << "--------------------TEST-2-END-----------------------" << std::endl;


};

void test_reference(std::string &a) {
    defer::defer<std::string> s(a, "test 2");
    a = "mmmm";
}

TEST(3) {
    std::cout << "--------------------TEST-3-START---------------------" << std::endl;
    std::string f = "str 2";
    test_reference(f);
    std::cout << f << std::endl;
    std::cout << "--------------------TEST-3-END-----------------------" << std::endl;
}


TEST(4) {
    std::cout << "--------------------TEST-4-START---------------------" << std::endl;
    defer::defer_call deferCall([]() {
        std::cout << std::endl << "This message is printed last among all console messages from TEST 4" << std::endl;
    });
    std::cout << "--------------------TEST-4-END-----------------------" << std::endl;
}

void test_call(int a, int b, int c, std::string &&notice) {
    std::cout << std::endl << "a+b+c = " << a + b + c << std::endl << notice << std::endl;

}

TEST(5) {
    std::cout << "--------------------TEST-5-START---------------------" << std::endl;
    defer::defer_call deferCall1(test_call, 23, 45, 22,
                                 "this message is printed last among all console messages from TEST 5");
    std::cout << "--------------------TEST-5-END-----------------------" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
