/*
 * File:	tokenizer.h
 * Author:	Luke Godfrey
 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
using namespace std;

class Tokenizer
{
	public:
		Tokenizer();
		void tokenize(string str);
		bool nextToken(string &str);
		void ignoreNext();
		string get(int i) const;
		int size() const;
	private:
		vector<string> tokens;
};

#endif

