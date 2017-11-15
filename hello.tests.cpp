#include "hello.h"
#include <gmock/gmock.h>

using namespace CppTemplateApplication;

TEST(Hello, ObjectCreation) {
    Hello h;
}

TEST(Hello, toString) {
    Hello h;
    ASSERT_EQ("Hello World", h.toString());
}
