#pragma once

#include "WordsCounter.h"
#include "WordsProbabilities.h"
#include <iosfwd>
#include <string>
#include <unordered_map>
#include <unordered_set>

class MessageAnalyzer
{
  public:
	void LearnFromStream(std::istream& istr, bool isSpam);
	bool AnalyzeStreamForSpam(std::istream& istr);

	void Normalize();

	void Load(std::istream& istr);
	void Save(std::ostream& ostr) const;

#ifndef NDEBUG
	void DebugPrint(std::ostream& ostr) const;
#endif // NDEBUG

  private:
	WordsCounter nonspamCounts_;
	WordsCounter spamCounts_;
	WordsCounter allCounts_;

	static void ProcessStream(WordsCounter& learnData, std::istream& istr);

	static std::unordered_set<std::string> IGNORABLE_WORDS;
};
