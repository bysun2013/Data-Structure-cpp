/**
Solution:

This looks just like a straight forward string matching, isn't it? Couldn't we just match the pattern and the input string character by character? The question is, how to match a '*'?

A natural way is to use a greedy approach; that is, we attempt to match the previous character as many as we can. Does this work? Let us look at some examples.

s = "abbbc", p = "ab*c" Assume we have matched the first 'a' on both s and p. When we see"b*" in p, we skip all b's in s. Since the last 'c' matches on both side, they both match.

s = "ac", p = "ab*c" After the first 'a', we see that there is no b's to skip for "b*". We match the last 'c' on both side and conclude that they both match.

It seems that being greedy is good. But how about this case?

s = "abbc", p = "ab*bbc" When we see "b*" in p, we would have skip all b's in s. They both should match, but we have no more b's to match. Therefore, the greedy approach fails in the above case.

One might be tempted to think of a quick workaround. How about counting the number of consecutive b's in s? If it is smaller or equal to the number of consecutive b's after "b*" in p, we conclude they both match and continue from there. For the opposite, we conclude there is not a match.

This seem to solve the above problem, but how about this case: s = "abcbcd", p = "a.*c.*d"

Here, ".*" in p means repeat '.' 0 or more times. Since '.' can match any character, it is not clear how many times '.' should be repeated. Should the 'c' in p matches the first or second'c' in s? Unfortunately, there is no way to tell without using some kind of exhaustive search.

We need some kind of backtracking mechanism such that when a matching fails, we return to the last successful matching state and attempt to match more characters in s with '*'. This approach leads naturally to recursion.

The recursion mainly breaks down elegantly to the following two cases:

If the next character of p is NOT '*', then it must match the current character of s. Continue pattern matching with the next character of both s and p.
If the next character of p is '*', then we do a brute force exhaustive matching of 0, 1, or more repeats of current character of p... Until we could not match any more characters.
You would need to consider the base case carefully too. That would be left as an exercise to the reader. :)

*/
#include <iostream>

using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
			if(*p == 0)
				return *s == 0;

			if(*(p+1) != '*'){
				if(*s && (*s == *p || *p == '.'))
					return isMatch(s+1, p+1);
				else
					return false;
			}else{
				while(*s && (*s == *p || *p == '.')){
					if(isMatch(s, p+2))
						return true;
					s++;
				}
				return isMatch(s, p+2);
			}
    }
};

int main()
{
	Solution s;
	
	cout << std::boolalpha;

	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "aa") << endl;
	cout << s.isMatch("aaa", "a") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("aa", ".*") << endl;
	cout << s.isMatch("ab", ".*") << endl;
	cout << s.isMatch("aab", "c*a*b*") << endl;
	cout << s.isMatch("a", "a*..a*") << endl;

	return 0;
}