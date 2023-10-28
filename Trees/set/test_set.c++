/*!
 *  \file       test_set.c++
 *  \brief
 *
 */


#include <gtest/gtest.h>
#include <set>

TEST(UTester4Set, CheckInsertItemIntoSet)
{
    std::set<int> s;
    for (int i = 0; i < 1'000'000; ++i)
    {
        s.insert(s.end(), i);
    }
    EXPECT_EQ(s.size(), 1'000'000);
}

#if 0
bool CaseInsensitiveCompare(std::string s1, std::string s2)
{
    if (s1.compare(s2))
        return true;
    else
        return false;
}

class MyString : public std::string
{
public:
    bool CaseInSensitiveCompare(const std::string& other)
    {
        if (this->compare(other))
            return true;
        else
            return false;
    }
};

TEST(UTester4Set, CheckSetSort)
{
    std::set<std::string, CaseInsensitiveCompare> s;
    s.insert("Hello");
    s.insert("HeLLo");

    std::cout << "The size is " << s.size() << std::endl;
}
#endif
