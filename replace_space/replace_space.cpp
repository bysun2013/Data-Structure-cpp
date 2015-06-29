#include <iostream>

using namespace std;

int replace(char *s){
	int i , j, count = 0;
	int s_len = strlen(s);
	
	if(!s)
		return 0;
	i = 0;
	while(i<s_len){
		if(s[i++] == ' ')
			count++;
	}
	//´ËÊ±i = s_len

	j = s_len + 2 * count;
	while(i >= 0){
		if(s[i] == ' '){
			s[j--] = '0';
			s[j--] = '2';
			s[j--] = '%';
		}else
			s[j--] = s[i];
		i--;
	}
}

int main()
{
	char s[100] = "We are happy. ";
	replace(s);

	cout << s <<endl;

	return 0;
}