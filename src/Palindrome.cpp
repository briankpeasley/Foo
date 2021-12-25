#include <stdio.h>
#include <string>
#include <vector>
#include <map>

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

void FindAllPalindromes(std::map<std::string, int>& output, std::string input)
{
    if(output.find(input) == output.end() && IsPalindrome(input))
    {
        output[input] = 1;
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
    std::map<std::string, int> palindromes;
    FindAllPalindromes(palindromes, "asfsa");

    for(std::map<std::string,int>::iterator iter = palindromes.begin(); iter != palindromes.end(); ++iter)
    {
        printf("%s\n", iter->first.c_str());
    }
}