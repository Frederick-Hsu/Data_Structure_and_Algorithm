#include "TextQuery.h"

#include <iostream>
#include <sstream>

using namespace std;

namespace CPlusPlus_Primer
{
    /* read input file : store each line as element in line_of_text */
    void TextQuery::store_file(std::ifstream& is)
    {
        std::string textline;
        while (getline(is, textline))
        {
            lines_of_text.push_back(textline);
        }
    }

    void TextQuery::read_file(std::ifstream &is)
    {
        store_file(is);
        build_map();
    }

    /* finds whitespace-separated words in the input vector, and
     * puts the word in word_map along with the line number.
     */
    void TextQuery::build_map()
    {
        /* process each line from the input vector */
        for (line_no line_num = 0; line_num != lines_of_text.size(); ++line_num)
        {
            /* we'll use line to read the text, a word at one time. */
            std::istringstream line(lines_of_text[line_num]);
            std::string word;
            while (line >> word)
            {
                /* add this line number to the set;
                 * subscript wil add word to the map if it is not already there
                 */
                word_map[word].insert(line_num);
            }
        }
    }

    std::set<TextQuery::line_no> TextQuery::run_query(const string& query_word) const
    {
        /* Note : must use find and not subscript the map directly to
         * avoid adding words to word_map.
         */
        map<string, set<line_no>>::const_iterator loc = word_map.find(query_word);
        if (loc == word_map.end())
        {
            return set<line_no>();		/* not found, return empty set */
        }
        else
        {
            return loc->second;			/* fetch and return set of line numbers for this word. */
        }
    }

    TextQuery::line_no TextQuery::size() const
    {
        return lines_of_text.size();
    }

    string TextQuery::text_line(TextQuery::line_no line) const
    {
        if (line < lines_of_text.size())
        {
            return lines_of_text[line];
        }
        throw std::out_of_range("line number out of range.");
    }

    void print_results(const std::set<TextQuery::line_no>& locs,
                       const std::string& sought,
                       const TextQuery& file)
    {
        /* if the word was found, then print count and all occurrences */
        typedef std::set<TextQuery::line_no> line_nums;

        line_nums::size_type size = locs.size();
        std::cout << "\n" << sought << " occurs "
            << size << " "
            << make_plural(size, "time", "s")
            << std::endl;
        /* print each line in which the word appeared */
        for (line_nums::const_iterator it = locs.begin(); it != locs.end(); ++it)
        {
            std::cout << "\t(line "
                /* don't confound user with text lines starting at 0 */
                << (*it) + 1 << ") "
                << file.text_line(*it)
                << std::endl;
        }

    }

    std::string make_plural(std::size_t ctr, const std::string& word, const std::string& ending)
    {
        return ((ctr == 1) ? word : word + ending);
    }

    std::ifstream& open_file(std::ifstream& in, const std::string& file)
    {
        in.close();		/* close in case that it was already opened */
        in.clear();		/* clear any existing errors */
        in.open(file.c_str());		/* open the file we were given */
        return in;
    }
}
