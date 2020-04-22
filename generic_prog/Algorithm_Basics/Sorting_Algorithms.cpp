#include "Sorting_Algorithms.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/* Predicate functions */
bool isShorter(const string& s1, const string& s2);
bool GT6(const string& str);
string make_plural(unsigned count, const string& singular, const string& plural = "s");

void sort_elements_inside_container(void)
{
    vector<string> words;
#if 0
    string word;
    while (cin >> word)
    {
        words.push_back(word);
    }
#else
    words.push_back("the");
    words.push_back("quick");
    words.push_back("red");
    words.push_back("fox");
    words.push_back("jumps");
    words.push_back("over");
    words.push_back("the");
    words.push_back("slow");
    words.push_back("red");
    words.push_back("turtle");
#endif

    /* sort words alphabetically, so we can find the duplicates */
    sort(words.begin(), words.end());
    cout << "After sorting, the words vector become to : " << endl;
    int index = 0;
    for (vector<string>::const_iterator cit = words.begin(); cit != words.end(); ++cit)
    {
        cout << "words[" << index++ << "] = " << *cit << endl;
    }

    /* eliminate duplicate words:
     * unique records words, so that each word appears once in the front portion
     * of words and returns an iterator one past the unique range;
     * erase uses a vector operator to remove the nonunique elements.
     */
    vector<string>::iterator end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    /* sort words by size, but maintain alphabetic order for words of the same size */
    stable_sort(words.begin(), words.end(), isShorter);
    cout << "After sorted, the words vector changed to : " << endl;
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
    {
        cout << *it << "    ";
    }
    vector<string>::difference_type wc = count_if(words.begin(), words.end(), GT6);
    cout << endl << wc << " " << make_plural(wc, "word", "s") << " 6 characters or longer" << endl;
}

bool isShorter(const string& s1, const string& s2)
/* comparison function to be used to sort by word length */
{
    return (s1.size() < s2.size());
}

bool GT6(const string& str)
/* determine whether a length of a given word is 6 or more */
{
    return (str.size() >= 6);
}

string make_plural(unsigned count, const string& singular, const string& plural)
{
    if (count > 1)
        return (singular + plural);
    else
        return singular;
}