#include "WordsCounter.h"
#include <cctype>
#include <iostream>

void WordsCounter::AddWord(const std::string& word)
{
	auto it = counts_.find(word);
	if(it != counts_.end())
		++it->second;
	else
		counts_.emplace(word, 1);
}

void WordsCounter::AddWordZero(const std::string& word) { counts_.emplace(word, 0); }

void WordsCounter::Append(const WordsCounter& source)
{
	Map::iterator dstIt;
	for(Map::const_iterator srcIt = source.counts_.cbegin(); srcIt != source.counts_.cend(); ++srcIt)
		if(counts_.find(srcIt->first) == counts_.end())
			counts_.emplace(srcIt->first, 0);
}

void WordsCounter::AppendAndAdd(const WordsCounter& source)
{
	Map::iterator dstIt;
	for(Map::const_iterator srcIt = source.counts_.cbegin(); srcIt != source.counts_.cend(); ++srcIt)
	{
		dstIt = counts_.find(srcIt->first);
		if(dstIt != counts_.end())
			dstIt->second += srcIt->second;
		else
			counts_.emplace(srcIt->first, srcIt->second);
	}
}

void WordsCounter::Clean() { counts_.clear(); }

void WordsCounter::Load(std::istream& istr)
{
	char buffer[1024];
	unsigned wordsCount;
	unsigned wordSize;
	unsigned count;
	istr >> wordsCount;
	for(unsigned i = 0; i < wordsCount; ++i)
	{
		istr >> wordSize;
		istr.read(buffer, wordSize);
		istr >> count;
		counts_.emplace(buffer, count);
	}
}

void WordsCounter::Save(std::ostream& ostr) const
{
	ostr << static_cast<unsigned>(counts_.size());
	for(const auto& pair : counts_)
	{
		ostr << static_cast<unsigned>(pair.first.size());
		ostr.write(pair.first.data(), pair.first.size());
		ostr << pair.second;
	}
}

void WordsCounter::FixWord(std::string& word)
{
	for(auto it = word.begin(); it != word.end();)
		if(std::isalpha(*it))
		{
			*it = std::tolower(*it);
			++it;
		}
		else if(*it == '\'')
		{
			word.substr(0, std::distance(word.begin(), it));
			return;
		}
		else
			it = word.erase(it);
}
