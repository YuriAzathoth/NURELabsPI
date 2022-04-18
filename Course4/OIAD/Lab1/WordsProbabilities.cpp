#include "WordsProbabilities.h"
#include "WordsCounter.h"

#ifndef NDEBUG
#include <iomanip>
#endif // NDEBUG

WordsProbabilities::WordsProbabilities(const WordsCounter& analysingClass,
                                       const WordsCounter& comparableClass,
                                       const WordsCounter& allWords,
                                       double classProbability)
{
	double probability;
	double rawProbability;
	double allCount;
	double analysingCount;
	double comparableCount;
	for(auto wordIt = analysingClass.GetWordsBegin(); wordIt != analysingClass.GetWordsEnd(); ++wordIt)
	{
		allCount = static_cast<double>(allWords.GetWordCount(wordIt->first));
		analysingCount = static_cast<double>(wordIt->second);
		comparableCount = static_cast<double>(comparableClass.GetWordCount(wordIt->first));
		if(allCount)
		{
			rawProbability = comparableCount / allCount;
			probability = (analysingCount * rawProbability + classProbability) / (analysingCount + 1.0f);
			probabilities_.emplace(wordIt->first, probability);
		}
	}
}

double WordsProbabilities::GetProbabilitiesProduct() const
{
	double ret = 1.0;
	for(const auto& pair : probabilities_)
		ret *= pair.second;
	return ret;
}

#ifndef NDEBUG
void WordsProbabilities::DebugPrint(std::ostream& ostr) const
{
	ostr << std::setw(20) << "Count:" << std::setw(20) << probabilities_.size() << std::endl;
	for(const auto& pair : probabilities_)
		ostr << std::setw(20) << pair.first << std::setw(20) << pair.second << std::endl;
}
#endif // NDEBUG
