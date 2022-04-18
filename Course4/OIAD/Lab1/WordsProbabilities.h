#pragma once

#include <string>
#include <unordered_map>

class WordsCounter;

class WordsProbabilities
{
  public:
	WordsProbabilities(const WordsCounter& analysingClass,
	                   const WordsCounter& comparableClass,
	                   const WordsCounter& allWords,
	                   double classProbability);

	double GetProbabilitiesProduct() const;

	double GetProbability(const std::string& word) const { return probabilities_.at(word); }

#ifndef NDEBUG
	void DebugPrint(std::ostream& ostr) const;
#endif // NDEBUG

  private:
	std::unordered_map<std::string, double> probabilities_;
};
