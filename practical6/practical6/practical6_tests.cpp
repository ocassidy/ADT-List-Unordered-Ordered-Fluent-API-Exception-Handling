/*
* Library Test Cases Using the Catch 2 Test Library
* https://github.com/catchorg/Catch2/
*
* practical6_tests.cpp
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
	// create an ordered list from the un-ordered arraylist
	OrderedList<T> temp(list);

	return temp.get(temp.size() - n);
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
		// setup
		l.add(1); 
		l.add(2); 
		l.add(4); 
		l.add(8);

		// largest element in l should be 8
		REQUIRE(getNthLargest(1, l) == 8);
		REQUIRE(getNthLargest(2, l) == 4);
		REQUIRE(getNthLargest(3, l) == 2);
		REQUIRE(getNthLargest(4, l) == 1);
	}

	SECTION("Test Reverse")
	{
		// setup
		l.add(3); l.add(2); l.add(9); l.add(7);

		// reverse of the reverse of l should be equal to l
		REQUIRE(l.reverse().reverse() == l);
	}

	SECTION("Test Take")
	{
		// setup
		l.add(1);
		l.add(2);
		l.add(4);
		l.add(8);

		// create a result list that should be equal to the result of taking 2 from l
		ArrayList<int> r; 
		r.add(1); 
		r.add(2);

		// taking first 2 elements of l produces a list equal to r
		REQUIRE(l.take(2) == r);
	}

	SECTION("Test Drop")
	{
		// setup
		l.add(1);
		l.add(2);
		l.add(4);
		l.add(8);

		// create a result list that should be equal to the result of dropping 2 from l
		ArrayList<int> r; 
		r.add(4);
		r.add(8);

		// dropping first 2 elements of l produces a list equal to r
		REQUIRE(l.drop(2) == r);
	}

	SECTION("Test mid")
	{
		// setup
		l.add(1);
		l.add(2);
		l.add(4);
		l.add(8);

		ArrayList<int> m = l.mid(0, 2);

		// check new list is correct size and first and last elements
		REQUIRE(m.size() == 2);
		REQUIRE(m.get(1) == 2);
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


