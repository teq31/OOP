#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include "Word.h"

std::map<std::string, int> WordCount(std::string filename)
{
    std::ifstream file(filename);
    std::map<std::string, int> count;
    if (!file)
    {
        std::cout << "Error opening file!" << std::endl;
        return count;
    }

    std::string line;
    char sep[] = " ,?!.";
    while (std::getline(file, line))
    {
        while (line.size())
        {
            int pos = line.find_first_of(sep);

            std::string word = line.substr(0, pos);
            for (int i = 0; i < word.size(); i++)
                word[i] = tolower(word[i]);

            count[word]++;

            line = line.substr(pos + 1);
        }
    }
    return count;
}

void print(std::priority_queue<Word> queue)
{
	while (!queue.empty())
	{
		Word top = queue.top();
		std::cout << top.word << " => " << top.fr << std::endl;
		queue.pop();
	}
}
int main()
{
	std::string filename = "text.txt";
	std::map <std::string, int> count = WordCount(filename);
    std::priority_queue<Word> queue;
    for (auto &pair : count)
    {
        Word word(pair.first, pair.second);
        queue.push(word);
    }

	print(queue);
	return 0;
}
