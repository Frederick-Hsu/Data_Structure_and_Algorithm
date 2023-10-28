/*!
 *  \file       utilize_map.cpp
 *  \brief
 *
 */


#include "utilize_map.hpp"

#include <iostream>

using Word = std::string;
using AdjacentWords = std::vector<std::string>;

#define APPROACH1   1
#define APPROACH2   2
#define APPROACH3   3
#define APPROACH    APPROACH3

void printHighChangeables(const std::map<Word, AdjacentWords>& adjacentWords,
                          int minWords)
{
    using namespace std;

    for (auto& entry : adjacentWords)
    {
        const AdjacentWords& words = entry.second;
        if (words.size() >= minWords)
        {
            cout << entry.first << "(" << words.size() << "): ";
            for (auto& word : words)
            {
                cout << " " << word;
            }
            cout << endl;
        }
    }
}

bool oneCharOff(const Word& word1, const Word& word2)
{
    if (word1.length() != word2.length())
        return false;

    int diffs = 0;
    for (size_t i = 0; i < word1.length(); ++i)
    {
        if (word1[i] != word2[i])
        {
            if (++diffs > 1)
                return false;
        }
    }
    return (diffs == 1);
}

#if (APPROACH == APPROACH1)
    std::map<Word, AdjacentWords> computeAdjacentWords(const std::vector<std::string>& words)
    {
        std::map<Word, AdjacentWords> adjWords;

        for (size_t i = 0; i < words.size(); ++i)
        {
            for (size_t j = i+1; j < words.size(); ++j)
            {
                if (oneCharOff(words[i], words[j]))
                {
                    adjWords[words[i]].push_back(words[j]);
                    adjWords[words[j]].push_back(words[i]);
                }
            }
        }
        return adjWords;
    }
#elif (APPROACH == APPROACH2)
    std::map<Word, AdjacentWords> computeAdjacentWords(const std::vector<std::string>& words)
    {
        std::map<Word, AdjacentWords> adjWords;
        std::map<int, std::vector<std::string>> wordsByLength;

        for (auto& word : words)    // 按长度将单词分组
        {
            wordsByLength[word.length()].push_back(word);
        }

        for (auto& entry : wordsByLength)   // 对每组分别进行处理
        {
            const std::vector<std::string>& groupWords = entry.second;
            for (size_t i = 0; i < groupWords.size(); ++i)
            {
                for (size_t j = i+1; j < groupWords.size(); ++j)
                {
                    if (oneCharOff(groupWords[i], groupWords[j]))
                    {
                        adjWords[groupWords[i]].push_back(groupWords[j]);
                        adjWords[groupWords[j]].push_back(groupWords[i]);
                    }
                }
            }
        }
        return adjWords;
    }
#elif (APPROACH == APPROACH3)
std::map<Word, AdjacentWords> computeAdjacentWords(const std::vector<std::string>& words)
{
    using namespace std;
    map<string, vector<string>> adjWords;
    map<int, vector<string>> wordsByLength;

    for (auto& word : words)
    {
        wordsByLength[word.length()].push_back(word);
    }

    for (auto& entry : wordsByLength)
    {
        const vector<string>& groupWords = entry.second;
        int groupNum = entry.first;

        for (int i = 0; i < groupNum; ++i)
        {
            map<string, vector<string>> repToWord;
            for (auto& word : groupWords)
            {
                string rep = word;
                rep.erase(i, 1);
                repToWord[rep].push_back(word);
            }

            for (auto& entry: repToWord)
            {
                const vector<string>& clique = entry.second;
                if (clique.size() >= 2)
                {
                    for (size_t p = 0; p < clique.size(); ++p)
                    {
                        for (size_t q = p+1; q < clique.size(); ++q)
                        {
                            adjWords[clique[p]].push_back(clique[q]);
                            adjWords[clique[q]].push_back(clique[p]);
                        }
                    }
                }
            }
        }
    }
    return adjWords;
}
#endif

