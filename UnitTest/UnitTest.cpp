
#include "pch.h"
#include "CppUnitTest.h"
#include"../Ford_Fulkerson/Flows.h"
#include<fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForFordFulkerson
{
	TEST_CLASS(UnitTestForFordFulkerson)
	{
	public:

		TEST_METHOD(TestErrorFirstInputCharacter) {
			try {
				ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input2.txt");
				Flows Flows(input);
			}
			catch (exception& ex) {
				Assert::AreEqual(ex.what(), "Error entering the first character in the string. Check the correctness of the input in the file and correct these errors in the line under the number: 2");
			}
		}
		TEST_METHOD(TestCorrectInput)
		{
			ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input1.txt");
			Flows Flows(input);
			Assert::AreEqual(Flows.max_flow(), 5);
		}
		TEST_METHOD(TestErrorSecondInputCharacter) {
			try {
				ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input3.txt");
				Flows Flows(input);
			}
			catch (std::exception& ex) {
				Assert::AreEqual(ex.what(), "Error entering the second character in the string or missing a space after it. Check the correctness of the input in the file and correct these errors in the line under the number: 2");
			}
		}
		TEST_METHOD(TestErrorNumberInput) {
			try {
				ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input4.txt");
				Flows Flows(input);
			}
			catch (exception& ex) {
				Assert::AreEqual(ex.what(), "Error entering bandwidth in the string or the presence of a space after it.Please note that the bandwidth cannot be negative. Check that you entered the file correctly and correct these errors in the line number: 2");
			}
		}
		TEST_METHOD(TestEmptyInput) {
			try {
				ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input5.txt");
				Flows Flows(input);
			}
			catch (exception& ex) {
				Assert::AreEqual(ex.what(), "A data-entry error. Check the correctness of the input in the file and correct these errors in the line under the number: 2");
			}
		}
		TEST_METHOD(TestCorrectInput_6vert)
		{
			ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input6.txt");
			Flows Flows(input);
			Assert::AreEqual(Flows.max_flow(), 25);
		}
		TEST_METHOD(TestCorrectInput_2vert)
		{
			ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input7.txt");
			Flows Flows(input);
			Assert::AreEqual(Flows.max_flow(), 20);
		}
		TEST_METHOD(TestErrorVertexPathToItself) {
			try
			{
				ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input8.txt");
				Flows Flows(input);
			}
			catch (exception& ex) {
				Assert::AreEqual(ex.what(), "The path from the vertex to itself is impossible in the string under the number: 2");
			}
		}
		TEST_METHOD(TestCorrect_20vert)
		{
			ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input9.txt");
			Flows Flows(input);
			Assert::AreEqual(Flows.max_flow(), 19);
		}
		TEST_METHOD(TestErrorNoSource) {
			try
			{
				ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input10.txt");
				Flows Flows(input);
			}
			catch (exception& ex) {
				Assert::AreEqual(ex.what(), "Source is missing");
			}
		}
		TEST_METHOD(TestErrorNoSink) {
			try
			{
				ifstream input("C:\\Users\\User\\Desktop\\Ford_Fulkerson\\UnitTest\\Input11.txt");
				Flows Flows(input);
			}
			catch (exception& ex) {
				Assert::AreEqual(ex.what(), "Sink is missing");
			}
		}
		TEST_METHOD(TestMethod_MinFunctionMin) {
			int a = 1;
			int b = 2;
			int m = min(a, b);
			Assert::AreEqual(m, 1);
		}
		TEST_METHOD(TestMethod_Exception_MinFunctionEqual) {
			int a = 1;
			int b = 1;
			int m = min(a, b);
			Assert::AreEqual(m, 1);
		}
	};
}