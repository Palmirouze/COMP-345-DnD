//! @file
//! @brief CPPUNIT test cases
//! Two other test cases are implemented here.

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include "Dice.h"
using namespace CppUnit;

//! Test Class for the Dice class
//! Two additionnal test cases were added.
class DiceTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(DiceTest);
	CPPUNIT_TEST(testDiceRollInputValidity); //!test the lower bound of the returned value
	CPPUNIT_TEST(testDiceRollingBounds); //!test the upper bound of the returned value
	CPPUNIT_TEST(testDiceModifier); //!test the modifier
	CPPUNIT_TEST(testMultipleDiceRolls); //!test multiple dice rolls
	CPPUNIT_TEST_SUITE_END();
protected:
	void testDiceRollInputValidity();
	void testDiceRollingBounds();
	void testDiceModifier();
	void testMultipleDiceRolls();
};

//! cppunit test cases registration
CPPUNIT_TEST_SUITE_REGISTRATION(DiceTest);

//! test method for role function of the Dice class
//! Test Case: the the validity of input string
void DiceTest::testDiceRollInputValidity()
{
	int result = 0;

	// test that if the string is valid, the result is calculated
	result = Dice::roll("4d20");
	CPPUNIT_ASSERT(result > 0);
	result = Dice::roll("3d10+1");
	CPPUNIT_ASSERT(result > 0);

	//test that is the string is invalid, roll() returns -1
	result = Dice::roll("4d");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("d20");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("420");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("4d20+");
	CPPUNIT_ASSERT(result == -1);
}

//! test method for role function of the Dice class
//! Test Case: the upperbound of all values returned from roll function
void DiceTest::testDiceRollingBounds()
{
	int result = 0;

	for (int j = 1; j <= 1000; j++) {
		result = Dice::roll("1d4");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 4);
	}
	for (int j = 1; j <= 1000; j++) {
		result = Dice::roll("1d6");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 6);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d8");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 8);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d10");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 10);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d12");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 12);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d20");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 20);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d100");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 100);
	}

}

//! test method for role function of the Dice class
//! Test Case: tests various modifiers and ensures the result is greater than them
void DiceTest::testDiceModifier()
{
	int result = 0;

	result = Dice::roll("1d4+100");
	CPPUNIT_ASSERT(result > 100);
	CPPUNIT_ASSERT(result <= 104);

	result = Dice::roll("1d10+10");
	CPPUNIT_ASSERT(result > 10);
	CPPUNIT_ASSERT(result <= 110);

	result = Dice::roll("2d4+2");
	CPPUNIT_ASSERT(result >= 4);
	CPPUNIT_ASSERT(result <= 10);

	result = Dice::roll("1d8+1000");
	CPPUNIT_ASSERT(result > 1000);
	CPPUNIT_ASSERT(result <= 1008);


}

//! test method for role function of the Dice class
//! Test Case: check for bounds of values for multiple dice rolls
void DiceTest::testMultipleDiceRolls()
{
	int result = 0;

	result = Dice::roll("2d4");
	CPPUNIT_ASSERT(result >= 2);
	CPPUNIT_ASSERT(result <= 8);

	result = Dice::roll("3d8");
	CPPUNIT_ASSERT(result >= 3);
	CPPUNIT_ASSERT(result <= 24);

	result = Dice::roll("10d100");
	CPPUNIT_ASSERT(result >= 10);
	CPPUNIT_ASSERT(result <= 1000);

	result = Dice::roll("100d4");
	CPPUNIT_ASSERT(result >= 100);
	CPPUNIT_ASSERT(result <= 400);
}
