#include "MessageAnalyzer.h"
#include <fstream>

#ifndef NDEBUG
#include <iomanip>
#endif // NDEBUG

std::unordered_set<std::string> MessageAnalyzer::IGNORABLE_WORDS = {
    "i",       "me",         "my",      "myself", "we",     "our",     "ours",   "ourselves",  "you",   "your",
    "yours",   "yourselves", "he",      "him",    "his",    "himself", "she",    "her",        "hers",  "herself",
    "it",      "its",        "itself",  "they",   "them",   "their",   "theirs", "themselves", "what",  "which",
    "who",     "whom",       "this",    "that",   "these",  "those",   "am",     "is",         "are",   "was",
    "were",    "be",         "been",    "being",  "have",   "has",     "had",    "having",     "do",    "does",
    "did",     "doing",      "a",       "an",     "the",    "and",     "but",    "if",         "or",    "because",
    "as",      "until",      "while",   "of",     "at",     "by",      "for",    "with",       "about", "against",
    "between", "into",       "through", "during", "before", "after",   "above",  "below",      "to",    "from",
    "up",      "down",       "in",      "out",    "on",     "off",     "over",   "under",      "again", "further",
    "then",    "once",       "here",    "there",  "when",   "where",   "why",    "how",        "all",   "any",
    "both",    "each",       "few",     "more",   "most",   "other",   "some",   "such",       "no",    "nor",
    "not",     "only",       "own",     "same",   "so",     "than",    "too",    "very",       "can",   "will",
    "just",    "don",        "should",  "now"};

static constexpr double CLASS_PROBABILITY = 0.5;

void MessageAnalyzer::LearnFromStream(std::istream& istr, bool isSpam)
{
	ProcessStream(isSpam ? spamCounts_ : nonspamCounts_, istr);
}

bool MessageAnalyzer::AnalyzeStreamForSpam(std::istream& istr)
{
	WordsCounter counts;
	ProcessStream(counts, istr);
	nonspamCounts_.Append(counts);
	spamCounts_.Append(counts);
	WordsProbabilities isNonspam(counts, nonspamCounts_, allCounts_, CLASS_PROBABILITY);
	WordsProbabilities isSpam(counts, spamCounts_, allCounts_, CLASS_PROBABILITY);
	const double nonspamProbability = isNonspam.GetProbabilitiesProduct();
	const double spamProbability = isSpam.GetProbabilitiesProduct();
	return spamProbability > nonspamProbability;
}

void MessageAnalyzer::Normalize()
{
	allCounts_.AppendAndAdd(nonspamCounts_);
	allCounts_.AppendAndAdd(spamCounts_);
	nonspamCounts_.Append(allCounts_);
	spamCounts_.Append(allCounts_);
}

void MessageAnalyzer::Load(std::istream& istr)
{
	spamCounts_.Load(istr);
	nonspamCounts_.Load(istr);
}

void MessageAnalyzer::Save(std::ostream& ostr) const
{
	spamCounts_.Save(ostr);
	nonspamCounts_.Save(ostr);
}

void MessageAnalyzer::ProcessStream(WordsCounter& learnData, std::istream& istr)
{
	std::string word;
	while(!istr.fail())
	{
		word.clear();
		istr >> word;
		WordsCounter::FixWord(word);
		if(!word.empty() && word.size() > 1 && IGNORABLE_WORDS.find(word) == IGNORABLE_WORDS.end())
			learnData.AddWord(word);
	}
}

#ifndef NDEBUG
void MessageAnalyzer::DebugPrint(std::ostream& ostr) const
{
	ostr << "Non-Spam words:" << std::endl;
	ostr << "\tCount: " << nonspamCounts_.GetWordsSize() << std::endl;
	for(auto it = allCounts_.GetWordsBegin(); it != allCounts_.GetWordsEnd(); ++it)
	{
		ostr << '\t' << std::left << std::setw(20) << it->first;
		ostr << std::setw(10) << nonspamCounts_.GetWordCount(it->first);
		ostr << std::endl;
	}
	ostr << "Spam words:" << std::endl;
	ostr << "\tCount: " << spamCounts_.GetWordsSize() << std::endl;
	for(auto it = allCounts_.GetWordsBegin(); it != allCounts_.GetWordsEnd(); ++it)
	{
		ostr << '\t' << std::left << std::setw(20) << it->first;
		ostr << std::setw(10) << spamCounts_.GetWordCount(it->first);
		ostr << std::endl;
	}
}
#endif // NDEBUG
