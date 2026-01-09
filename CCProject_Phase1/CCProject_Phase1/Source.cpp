#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;


struct Token {
	string type;
	string value;
	Token* next;

	Token(string t, string v) : type(t), value(v), next(nullptr) {}
};

class LexicalAnalyzer {
private:
	Token* head;
	Token* tail;
	ofstream tokenFile;
	ofstream errorFile;
	int tokenCount = 0;
	int errorCount = 0;
	int keywordCount = 0;
	int identifierCount = 0;
	int numberCount = 0;
	int operatorCount = 0;


	void addToken(const string& type, const string& value) {
		Token* newToken = new Token(type, value);
		if (!head) {
			head = tail = newToken;
		}
		else {
			tail->next = newToken;
			tail = newToken;
		}
		tokenFile << "<" << type << ", " << value << ">" << endl;
	}

	void logError(const string& error) {
		errorFile << error << endl;
	}

	bool isKeyword(const string& word) {
		string keywords[] = { "loop", "agar", "magar", "asm", "else", "new", "this", "auto", "enum", "operator", "throw", "bool", "explicit", "private", "true", "break", "export", "protected", "try", "case", "extern", "public", "typedef", "catch", "false", "register", "typeid", "char", "float", "typename", "class", "for", "return", "union", "const", "friend", "short", "unsigned", "goto", "signed", "using", "continue", "if", "sizeof", "virtual", "default", "inline", "static", "void", "delete", "int", "volatile", "do", "long", "struct", "double", "mutable", "switch", "while", "namespace" };
		for (const string& kw : keywords) {
			if (word == kw) return true;
		}
		return false;
	}

	bool isIdentifier(const string& word) {
		if (word.empty() || (!isalpha(word[0]) && word[0] != '_')) return false;
		bool containsUnderscore = false;
		for (char ch : word) {
			if (!isalnum(ch) && ch != '_') return false;
			if (ch == '_') containsUnderscore = true;
		}
		return containsUnderscore;
	}

	bool isNumber(const string& word) {
		if (word.empty()) return false;
		
		int state = 0;
		for (char ch : word) {
			switch (state) {
			case 0:
				if (ch == '+' || ch == '-') state = 1;
				else if (isdigit(ch)) state = 2;
				else return false;
				break;
			case 1:
				if (isdigit(ch)) state = 2;
				else return false;
				break;
			case 2:
				if (isdigit(ch)) state = 2;
				else if (ch == '.') state = 3;
				else if (ch == 'E' || ch == 'e') state = 5;
				else return false;
				break;
			case 3:
				if (isdigit(ch)) state = 4;
				else return false;
				break;
			case 4:
				if (isdigit(ch)) state = 4;
				else if (ch == 'E' || ch == 'e') state = 5;
				else return false;
				break;
			case 5:
				if (ch == '+' || ch == '-') state = 6;
				else if (isdigit(ch)) state = 7;
				else return false;
				break;
			case 6:
				if (isdigit(ch)) state = 7;
				else return false;
				break;
			case 7:
				if (isdigit(ch)) state = 7;
				else return false;
				break;
			}
		}
		return state == 2 || state == 4 || state == 7;
	}

	bool isOperator(const string& word) {
		string operators[] = { "!=", "<>", "=:=", "==", "*", "+", "/", "-", ">>", "<<", "++", "=+", "&&", "||", "=>", "=<", "%", ":", "::", "--", "=", "<", ">" };
		for (const string& op : operators) {
			if (word == op) return true;
		}
		return false;
	}

	bool isPunctuation(char ch) {
		char punctuations[] = { '[', '{', '<', '>', '}', ']' };
		for (char p : punctuations) {
			if (ch == p) return true;
		}
		return false;
	}

	bool isOperatorChar(char ch) {
		return ch == '!' || ch == '<' || ch == '=' || ch == '>' || ch == '*' ||
		       ch == '+' || ch == '/' || ch == '-' || ch == '&' || ch == '|' ||
		       ch == '%' || ch == ':';
	}

public:
	LexicalAnalyzer() : head(nullptr), tail(nullptr) {}

	~LexicalAnalyzer() {
		while (head) {
			Token* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void analyze(const string& inputFile, const string& tokenOutput, const string& errorOutput) {
		ifstream file(inputFile);
		tokenFile.open(tokenOutput);
		errorFile.open(errorOutput);

		if (!file.is_open()) {
			cerr << "Error: Unable to open input file." << endl;
			return;
		}
		if (!tokenFile.is_open() || !errorFile.is_open()) {
			cerr << "Error: Unable to open output files." << endl;
			return;
		}

		string word;
		char ch;
		while (file >> noskipws >> ch) {
			if (isspace(ch)) {
				if (!word.empty()) {
					classifyWord(word);
					word.clear();
				}
			}
			else if (isPunctuation(ch)) {
				if (!word.empty()) {
					classifyWord(word);
					word.clear();
				}
				addToken("Punctuation", string(1, ch));
			}
			else if (ch == '"') {
				// Handle string literals
				if (!word.empty()) {
					classifyWord(word);
					word.clear();
				}
				string stringLiteral = "\"";
				while (file >> noskipws >> ch && ch != '"') {
					stringLiteral += ch;
				}
				stringLiteral += "\"";
				addToken("String", stringLiteral);
			}
			else if (isOperatorChar(ch)) {
				if (!word.empty()) {
					classifyWord(word);
					word.clear();
				}
				// Check for multi-character operators
				string op(1, ch);
				char nextCh;
				if (file.peek() != EOF) {
					nextCh = file.peek();
					string twoCharOp = op + nextCh;
					if (isOperator(twoCharOp)) {
						file >> noskipws >> nextCh;
						op = twoCharOp;
					}
				}
				if (isOperator(op)) {
					addToken("Operator", op);
					tokenCount++;
					operatorCount++;
				} else {
					addToken("Special", op);
				}
			}
			else if (ch == ';' || ch == ',' || ch == '(' || ch == ')') {
				if (!word.empty()) {
					classifyWord(word);
					word.clear();
				}
				addToken("Delimiter", string(1, ch));
			}
			else {
				word += ch;
			}
		}
		if (!word.empty()) classifyWord(word);

		file.close();
		tokenFile.close();
		errorFile.close();
	}

	void classifyWord(const string& word) {
		if (isKeyword(word)) {
			addToken("Keyword", word);
			tokenCount++;
			keywordCount++;
		}
		else if (isIdentifier(word)) {
			addToken("Identifier", word);
			tokenCount++;
			identifierCount++;
		}
		else if (isNumber(word)) {
			addToken("Number", word);
			tokenCount++;
			numberCount++;
		}
		else if (isOperator(word)) {
			addToken("Operator", word);
			tokenCount++;
			operatorCount++;
		}
		else {
			logError("Unknown token: " + word);
			errorCount++;
		}
	}
	void printCount() {
		cout << "Total Tokens: " << tokenCount << endl;
		cout << "Keywords: " << keywordCount << endl;
		cout << "Identifiers: " << identifierCount << endl;
		cout << "Numbers: " << numberCount << endl;
		cout << "Operators: " << operatorCount << endl;
		cout << "Errors: " << errorCount << endl;
	}
};

int main() {
	LexicalAnalyzer lexer;
	string inputFile = "Sourcecode.txt";
	string tokenOutput = "Token.txt";
	string errorOutput = "Error.txt";

	lexer.analyze(inputFile, tokenOutput, errorOutput);
	cout << "Lexical analysis completed. Check " << tokenOutput << " and " << errorOutput << " for results." << endl;
	lexer.printCount();

	return 0;
}
