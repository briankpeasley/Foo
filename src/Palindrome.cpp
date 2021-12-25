#include <stdio.h>
#include <string>
#include <set>

bool IsPalindrome(std::string str)
{
    for(int32_t idx = 0, jdx = str.length() - 1; idx < jdx; idx++, jdx--)
    {
        if(str[idx] != str[jdx])
        {
            return false;
        }
    }

    return true;
}

void FindAllPalindromes(std::set<std::string>& output, std::string input)
{
    if(output.find(input) == output.end() && IsPalindrome(input))
    {
        output.insert(input);
    }

    if(input.length() == 1)
    {
        return;
    }

    FindAllPalindromes(output, input.substr(0, input.length() - 1));
    FindAllPalindromes(output, input.substr(1, input.length() - 1));
}

int main()
{
    std::set<std::string> palindromes;
    FindAllPalindromes(palindromes, "asfsa");

    for(std::set<std::string>::iterator iter = palindromes.begin(); iter != palindromes.end(); ++iter)
    {
        printf("%s\n", iter->c_str());
    }
}