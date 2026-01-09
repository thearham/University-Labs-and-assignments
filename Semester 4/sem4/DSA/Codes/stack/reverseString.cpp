//#include "stack.h"
//
//void reverseString(string S)
//{
//	Stack s1;
//	for (int i = 0; i < S.length(); i++)
//	{
//		string word = "";
//		while (S[i] != ' ' && i < S.length())
//		{
//			word += S[i];
//			i++;
//		}
//		s1.push(word);
//	}
//	while (!s1.isEmpty())
//	{
//		cout << s1.peak() << " ";
//		s1.pop();
//	}
//	cout << endl;
//}
//
//
//int main() {
//	string s = "Hey, How you doing?";
//	reverseString(s);
//	
//	return 0;
//}