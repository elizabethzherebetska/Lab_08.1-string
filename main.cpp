#include <iostream>
#include <string>

using namespace std;
int Count(const string s)
{
	int k = 0;
	size_t pos = 0;
	while ((pos = s.find(',', pos)) != -1)
	{
		pos++;
		if (pos<s.length() && s[pos] == '-') //щоб не виходили за межі стрічки
			k++;
	}
	return k;
}
string Change(const string& s)
{
	string res = s;
	size_t pos = 0;
	while ((pos = res.find(',', pos)) != -1)
		if (res[pos + 1] == '-')
			res.replace(pos, 2, "*");
		else
			pos++;
	return res;
}
int main()
{
	string str;
	cout << "Enter string:" << endl;
		getline(cin, str);
	cout << "String contained " << Count(str) << " groups of ',-'" << endl;
	string dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}