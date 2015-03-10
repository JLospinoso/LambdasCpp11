#include <vector>
#include <string>
#include <functional>

class WordListHelper
{
public:
	WordListHelper();
	std::vector<int> counts(const std::vector<std::string> words);
	std::vector<int> vowels(const std::vector<std::string> words);
	std::vector<int> consonants(const std::vector<std::string> words);

	std::vector<int> counts_fn(const std::vector<std::string> words);
	std::vector<int> vowels_fn(const std::vector<std::string> words);
	std::vector<int> consonants_fn(const std::vector<std::string> words);
private:
	std::vector<int> map_word(const std::vector<std::string> words, std::function<int(std::string)> functor);
	std::vector<int> map_char(const std::vector<std::string> words, std::function<bool(char)> predicate);
	std::function<bool(char)> is_vowel;
};
