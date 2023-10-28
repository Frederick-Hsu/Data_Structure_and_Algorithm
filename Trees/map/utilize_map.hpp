/*!
 *  \file       utilize_map.hpp
 *  \brief
 *
 */


#pragma once

#include <map>
#include <string>
#include <vector>

/*!
 *  \brief      编写一个程序来找出通过单个字母的替换可以变成至少15个其他的单词的单词。
 *  \param      adjacentWords - 一个用来盛装相邻单词的map容器
 *  \param      minWords - 变体单词的数量至少15个。
 *  \example    wine 改变第一个字母可变成： dine, fine, line, mine, nine, pine, vine
 *                   改变第三个字母可变成： wide, wife, wipe, wire
 *                   改变第四个字母可变成： wind, wing, wink, wins
 */
void printHighChangeables(const std::map<std::string, std::vector<std::string>>& adjacentWords,
                          int minWords = 15);
/*!
 *  \brief      测试除一个字母替换外，两个单词是否相等。
 *  \param      word1 - 用户给出的一个单词
 *  \param      word2 - 待比较的另一个单词
 *  \return     若这两个单词只有在相当位置有一个字母相异外，其他字母均相同，则返回true, 否则返回false.
 */
bool oneCharOff(const std::string& word1, const std::string& word2);
/*!
 *  \brief      计算map对象，其中关键字为单词，而值则是相邻单词向量，每一个相邻单词跟关键字的单词只有一个字母相异。
 *  \param      words - 字典中所有单词的集合
 *  \return     返回每一个关键字单词的相邻单词向量的map容器
 */
std::map<std::string, std::vector<std::string>> computeAdjacentWords(const std::vector<std::string>& words);
