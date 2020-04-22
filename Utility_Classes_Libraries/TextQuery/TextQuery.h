#ifndef TEXTQUERY_H
#define TEXTQUERY_H

	#include <vector>
	#include <string>
	#include <set>
	#include <map>
    #include <fstream>

namespace CPlusPlus_Primer
{
	class TextQuery
	{
	public:
        explicit TextQuery(void) {}      /* default constructor, no need to initialize any member */
		/* typedefs to make declarations easier */
		typedef std::vector<std::string>::size_type line_no;
		/* interface:
		 *		read_file	- builds internal data structures for the given file
		 *		run_query	- finds the given word and returns set of lines on which it appears
		 *		text_line	- returns a requested line from the input file
		 */
		void read_file(std::ifstream& is);
		std::set<line_no> run_query(const std::string&) const;
		std::string text_line(line_no) const;
        line_no size() const;
	private:
		/* utility functions used by read_file */
		void store_file(std::ifstream&);	/* store input file */
		void build_map();	/* associated each word with a set of line numbers */

		std::vector<std::string> lines_of_text;		/* remember the whole input file */
		std::map<std::string, std::set<line_no>> word_map;
	};

	void print_results(const std::set<TextQuery::line_no>& locs,
					   const std::string& sought,
					   const TextQuery& file);
	std::string make_plural(std::size_t ctr, const std::string& word, const std::string& ending);
	std::ifstream& open_file(std::ifstream& in, const std::string& file);
}

#endif	/* TEXTQUERY_H */
