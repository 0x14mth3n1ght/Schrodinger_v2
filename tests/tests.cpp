/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestHermiteSuite_init = false;
#include "test_hermite.h"

static TestHermiteSuite suite_TestHermiteSuite;

static CxxTest::List Tests_TestHermiteSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestHermiteSuite( "test_hermite.h", 5, "TestHermiteSuite", suite_TestHermiteSuite, Tests_TestHermiteSuite );

static class TestDescription_suite_TestHermiteSuite_testHermite1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHermiteSuite_testHermite1() : CxxTest::RealTestDescription( Tests_TestHermiteSuite, suiteDescription_TestHermiteSuite, 25, "testHermite1" ) {}
 void runTest() { suite_TestHermiteSuite.testHermite1(); }
} testDescription_suite_TestHermiteSuite_testHermite1;

static class TestDescription_suite_TestHermiteSuite_testHermite2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHermiteSuite_testHermite2() : CxxTest::RealTestDescription( Tests_TestHermiteSuite, suiteDescription_TestHermiteSuite, 52, "testHermite2" ) {}
 void runTest() { suite_TestHermiteSuite.testHermite2(); }
} testDescription_suite_TestHermiteSuite_testHermite2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
