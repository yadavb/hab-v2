#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "errors.h"

#define TEST

#if defined(TEST)
    #define TEST_CLASS(name, body) \
        void name(void) \
        body

    #define TEST_METHOD(name, body) \
        void name(void) \
        body \
        name();

    #define RUN_TEST_CLASS(name) \
        name();

    #ifdef TEST_DEBUG
        #define HANG() \
            for (;;) \
            { \
            }
    #else
        #define HANG()
    #endif

    void ASSERT_IS_TRUE(bool value);

    void ASSERT_ARE_EQUAL(uint8_t expected, uint8_t actual);

    void executeTests(void);

    #define EXECUTE_TESTS() \
        executeTests();

#else
    #define TEST_CLASS(name, body)
    #define TEST_METHOD(name, body)
    #define RUN_TEST_CLASS(name)
    #define EXECUTE_TESTS()
#endif
