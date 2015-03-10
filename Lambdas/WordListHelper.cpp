#include "WordListHelper.h"

WordListHelper::WordListHelper() {
	this->is_vowel = [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';  };
}

std::vector<int> WordListHelper::counts(const std::vector<std::string> words)
{
	std::vector<int> out{};
	for each (auto word in words)
	{
		out.push_back(word.length());
	}
	return out;
}

std::vector<int> WordListHelper::counts_fn(const std::vector<std::string> words)
{
	return this->map_word(words, [](std::string word) { return word.length(); });
}

std::vector<int> WordListHelper::vowels(const std::vector<std::string> words)
{
	std::vector<int> out{};
	for each (auto word in words)
	{
		int count{ 0 };
		for each (auto chr in word)
		{
			 count += chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u';
		}
		out.push_back(count);
	}
	return out;
}

std::vector<int> WordListHelper::vowels_fn(const std::vector<std::string> words)
{
	return this->map_char(words, this->is_vowel);
}

std::vector<int> WordListHelper::consonants(const std::vector<std::string> words)
{
	auto lengths = counts(words);
	auto vowelCounts = vowels(words);
	std::vector<int> out{};
	for (int index = 0; index < words.size(); index++) {
		out.push_back(lengths[index] - vowelCounts[index]);
	}
	return out;
}


std::vector<int> WordListHelper::consonants_fn(const std::vector<std::string> words)
{
	return this->map_char(words, [&](char c) { return !is_vowel(c); });
}

std::vector<int> WordListHelper::map_char(const std::vector<std::string> words, std::function<bool(char)> predicate) {
	auto char_count = [&](std::string word){
		int count{ 0 };
		for each (auto chr in word)
		{
			count += predicate(chr);
		}
		return count;
	};
	return this->map_word(words, char_count);
}

std::vector<int> WordListHelper::map_word(const std::vector<std::string> words, std::function<int(std::string)> functor) {
	std::vector<int> out{};
	for each (auto word in words)
	{
		out.push_back(functor(word));
	}
	return out;
}