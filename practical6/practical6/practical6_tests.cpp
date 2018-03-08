/*
* Library Test Cases Using the Catch 2 Test Library
* https://github.com/catchorg/Catch2/
*
* practical6_tests.cpp
*
* Updated on: 7th March 2018
* Author: Your name
*/

// important to add this definition and then include the library
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Library Header files 
#include "Array.h"
#include "ArrayList.h"
#include "OrderedList.h"


// Question 2
// PreCondition: n > 0 && n <= size() and array elements are unique
template<class T>
T getNthLargest(int n, const ArrayList<T> & list)
{
	// replace with your algorithm 
	return 0;
}


// You can add some additional tests to the partially completed test sections below.

/**
 *  ArrayList Processing Test Axioms
 */
TEST_CASE("ArrayList Processing Axioms", "[ArrayListFunc]")
{
	ArrayList<int> l;

	SECTION("Test getNthLargest")
	{	
		// create a suitable test - replace true with the test expression
		REQUIRE(true);
	}

	SECTION("Test Reverse")
	{
		// create a suitable test - replace true with the test expression
		REQUIRE(true);
	}

	SECTION("Test Take")
	{
		// create a suitable test - replace true with the test expression
		REQUIRE(true);
	}

	SECTION("Test Drop")
	{
		// create a suitable test - replace true with the test expression
		REQUIRE(true);
	}

	SECTION("Test mid")
	{
		// create a suitable test - replace true with the test expression
		REQUIRE(true);
	}
}

//  ------------------- DO NOT MODIFY BELOW THIS LINE ---------------------

/**
 *  ArrayList Class Test Axioms
 */
TEST_CASE("ArrayList Axioms", "[ArrayList]")
{
	ArrayList<int> l;

	SECTION("SizeTest")
	{
		REQUIRE(l.size() == 0);
	}

	SECTION("Test Copy Constructor")
	{
		ArrayList<int> a;
		a.add(1);
		a.add(3);
		a.add(2);

		ArrayList<int> c(a);

		REQUIRE(a == c);
	}

	SECTION("Test Assignment Operator")
	{
		ArrayList<int> a;
		a.add(1);
		a.add(3);
		a.add(2);

		ArrayList<int> c;
		c = a;

		REQUIRE(a == c);
	}

	SECTION("Empty Test")
	{
		REQUIRE(l.isEmpty() == true);
	}

	SECTION("AddThenSizeIsOne")
	{
		l.add(0, 1);
		REQUIRE(l.size() == 1);
	}

	SECTION("AddThenNotEmpty")
	{
		l.add(0, 1);
		REQUIRE(l.isEmpty() == false);
	}

	SECTION("Add Then Get")
	{
		l.add(1);
		l.add(2);
		REQUIRE(l.get(1) == 2);
	}

	SECTION("Add Remove Then Size")
	{
		l.add(0, 1);
		l.remove(0);

		REQUIRE(l.size() == 0);
	}

	SECTION("Test Equal")
	{
		ArrayList<int> r;
		r.add(0, 1);
		l.add(0, 1);

		REQUIRE(l == r);
	}

	SECTION("Test Not Equal")
	{
		ArrayList<int> r;
		r.add(0, 1);
		l.add(0, 2);

		REQUIRE(l != r);
	}

	SECTION("Test Clear then equal")
	{
		l.add(1);
		l.clear();
		REQUIRE(l == ArrayList<int>());
	}

	SECTION("Test Invalid Remove")
	{
		REQUIRE_THROWS(l.remove(0));
	}

	SECTION("Test Set Out of Range")
	{
		REQUIRE_THROWS(l.set(0, 1));
	}

}


