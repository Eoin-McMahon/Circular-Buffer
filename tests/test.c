// Include definition of T1 test suite
#include "t1.h"

// This struct contains all test suites
TEST_SUITES {
    TEST_SUITE_ADD(T1), // add T1 test suite
    TEST_SUITES_CLOSURE
};

int main(int argc, char *argv[])
{

    // Run all test suites
    CU_RUN(argc, argv);

    return 0;
}
