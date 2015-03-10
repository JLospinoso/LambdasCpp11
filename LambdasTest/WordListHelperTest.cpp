#include "stdafx.h"
#include "CppUnitTest.h"
#include "WordListHelper.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LambdasTest
{		
	TEST_CLASS(WordListHelperTest)
	{
	public:
		TEST_METHOD(Counts)
		{
			WordListHelper helper{};
			std::vector < std::string > input { "o", "tw", "thr" };
			auto lengths = helper.counts(input);

			Assert::AreEqual(1, lengths.at(0));
			Assert::AreEqual(2, lengths.at(1));
			Assert::AreEqual(3, lengths.at(2));
		}

		TEST_METHOD(CountsFn)
		{
			WordListHelper helper{};
			std::vector < std::string > input{ "o", "tw", "thr" };
			auto lengths = helper.counts_fn(input);

			Assert::AreEqual(1, lengths.at(0));
			Assert::AreEqual(2, lengths.at(1));
			Assert::AreEqual(3, lengths.at(2));
		}

		TEST_METHOD(Vowels)
		{
			WordListHelper helper{};
			std::vector < std::string > input{ "aether", "io", "queueing" };
			auto lengths = helper.vowels(input);

			Assert::AreEqual(3, lengths.at(0));
			Assert::AreEqual(2, lengths.at(1));
			Assert::AreEqual(5, lengths.at(2));
		}


		TEST_METHOD(VowelsFn)
		{
			WordListHelper helper{};
			std::vector < std::string > input{ "aether", "io", "queueing" };
			auto lengths = helper.vowels_fn(input);

			Assert::AreEqual(3, lengths.at(0));
			Assert::AreEqual(2, lengths.at(1));
			Assert::AreEqual(5, lengths.at(2));
		}


		TEST_METHOD(Consonants)
		{
			WordListHelper helper{};
			std::vector < std::string > input{ "Hampsthwaite", "rythms", "strudel" };
			auto lengths = helper.consonants(input);

			Assert::AreEqual(8, lengths.at(0));
			Assert::AreEqual(6, lengths.at(1));
			Assert::AreEqual(5, lengths.at(2));
		}

		TEST_METHOD(ConsonantsFn)
		{
			WordListHelper helper{};
			std::vector < std::string > input{ "Hampsthwaite", "rythms", "strudel" };
			auto lengths = helper.consonants_fn(input);

			Assert::AreEqual(8, lengths.at(0));
			Assert::AreEqual(6, lengths.at(1));
			Assert::AreEqual(5, lengths.at(2));
		}
	};
}