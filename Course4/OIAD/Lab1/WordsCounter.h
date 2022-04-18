#pragma once

#include <memory>
#include <string>
#include <unordered_map>

class WordsCounter
{
  public:
	using Map = std::unordered_map<std::string, unsigned>;

	void AddWord(const std::string& word);
	void AddWordZero(const std::string& word);
	void Append(const WordsCounter& source);
	void AppendAndAdd(const WordsCounter& source);
	void Clean();

	void Load(std::istream& istr);
	void Save(std::ostream& ostr) const;

	unsigned GetWordCount(const std::string& word) const
	{
		const auto it = counts_.find(word);
		return it != counts_.end() ? it->second : 0;
	}

	Map::const_iterator GetWordsBegin() const { return counts_.cbegin(); }
	Map::const_iterator GetWordsEnd() const { return counts_.cend(); }
	unsigned GetWordsSize() const noexcept { return static_cast<unsigned>(counts_.size()); }

	static void FixWord(std::string& word);

  private:
	Map counts_;
};
