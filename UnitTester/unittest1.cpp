#include "stdafx.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include  <fstream>
#include "readint.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(UnitTest1) //test suite for readint
	{
	public:
		
		TEST_METHOD(Case1) //invalid input
		{
			ifstream ss("C:\\Users\\Kelly Olivier\\Documents\\Visual Studio 2015\\Projects\\Homework 3.5\\UnitTester\\zeroinput.txt");
			if (ss.fail())
			{
				throw int(-1);
			}
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			cin.rdbuf(orig_cin);
			ss.close();
		}
		TEST_METHOD(Case2) //invalid argument
		{
			auto func = []() {
				read_int("My prompt: ", 5, 1);
			};
			Assert::ExpectException<invalid_argument>(func);
		}
		TEST_METHOD(Case3) //case 3
		{
			ifstream ss("C:\\Users\\Kelly Olivier\\Documents\\Visual Studio 2015\\Projects\\Homework 3.5\\UnitTester\\case3t.txt");
			if (ss.fail())
				throw int(-1);

			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			cin.rdbuf(orig_cin);
			ss.close();
		}
		TEST_METHOD(Case4) //Test case 4
		{
			auto func = []() {
				read_int("My prompt: ", 0, 0);
			};
			Assert::ExpectException<invalid_argument>(func);
		}
	};
}