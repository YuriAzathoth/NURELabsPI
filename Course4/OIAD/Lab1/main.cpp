#include "MessageAnalyzer.h"
#include <clocale>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>

#define MESSAGE_ANALYZER_FILE "../data/message_analyzer.bin"

static inline void AnalyzeFile(MessageAnalyzer& analyzer, const char* filename, const std::string& theme)
{
	std::ifstream file(filename);
	if(!file.is_open())
		throw std::runtime_error(std::string("Could not load file: ") + filename);
	std::cout << std::left << std::setw(40) << filename;
	if(analyzer.AnalyzeStreamForSpam(file))
		std::cout << "Spam";
	else
		std::cout << "Not spam";
	std::cout << std::endl;
}

static inline void LearnFile(MessageAnalyzer& analyzer, const char* filename, bool isSpam)
{
	std::ifstream file(filename);
	if(!file.is_open())
		throw std::runtime_error(std::string("Could not load file: ") + filename);
	analyzer.LearnFromStream(file, isSpam);
}

int main()
{
	setlocale(LC_ALL, "");

	try
	{
		static const char* NONSPAM_FILES[] = {"../data/learn_nonspam_1.txt", "../data/learn_nonspam_2.txt",
		                                      "../data/learn_nonspam_3.txt", "../data/learn_nonspam_4.txt",
		                                      "../data/learn_nonspam_5.txt", "../data/learn_nonspam_6.txt"};
		static const char* SPAM_FILES[] = {"../data/learn_spam_1.txt", "../data/learn_spam_2.txt",
		                                   "../data/learn_spam_3.txt", "../data/learn_spam_4.txt",
		                                   "../data/learn_spam_5.txt", "../data/learn_spam_6.txt"};

		MessageAnalyzer analyzer;
		for(const char* filename : NONSPAM_FILES)
			LearnFile(analyzer, filename, false);
		for(const char* filename : SPAM_FILES)
			LearnFile(analyzer, filename, true);
		analyzer.Normalize();

		std::cout << std::left << std::setw(40) << "File name" << "Text type" << std::endl;
		AnalyzeFile(analyzer, "../data/test_nonspam_1.txt", "Cosmos");
		AnalyzeFile(analyzer, "../data/test_spam_1.txt", "Cosmos");
		AnalyzeFile(analyzer, "../data/test_nonspam_2.txt", "Transport");
		AnalyzeFile(analyzer, "../data/test_spam_2.txt", "Transport");
		AnalyzeFile(analyzer, "../data/test_nonspam_3.txt", "Show business");
		AnalyzeFile(analyzer, "../data/test_spam_3.txt", "Show business");
	}
	catch(std::exception& e)
	{
		std::cerr << "An exception has occured: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
