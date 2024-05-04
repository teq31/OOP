#pragma once
class Word
{
public:
	std::string word;
	int fr;
	Word(std::string word, int fr) : word(word), fr(fr) {}
	bool operator< (const Word& other) const
	{
		if (fr == other.fr)
			return word > other.word;
		return fr < other.fr;
	}

};