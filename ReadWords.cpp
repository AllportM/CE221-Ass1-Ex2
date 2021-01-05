/**
 * ReadWords cpp source code for Assignment 1
 */
using namespace std;

#include "ReadWords.h"
#include <cctype>
#include <cstdlib>
#include <iostream>

/**
 * Takes input string, and trims any leading and trailing puncuation until a valid
 * character is found
 *
 * @param:
 *	string - word, input word to be trimmed
 *
 * @return:
 *	string - output word
 */
string removePunct(string word)
{
  // trims punctuation from beginning until non puncuation character found
  while (word.size() > 0 && ispunct(word[0]))
  {
    word.erase(0, 1);
  }
  //trims puncuation from end until non puncuation character found
  while (word.size() > 0 && ispunct(word[word.size()-1]))
  {
    word.erase(word.size() -1, 1);
  }
  return word;
}


ReadWords::ReadWords(const char *filename)
{
	// attepts to open file, or outputs error and throws error to be handled
	wordfile.open(filename);
    if (!wordfile)
    {   cout << "Failed to open " << filename << endl;
        throw(1);
    }
    //assigns first word, added eof statement here for error handling if blank file
    wordfile >> nextword;
    eoffound = false;
}

string ReadWords::getNextWord()
{
  // gets next word for processing, and inserts next word from file into member variable
  string word = nextword;
  wordfile >> nextword;

  // sets one word lookahead boolean
  if (wordfile.eof())
     eoffound = true;

  // remove punct
  word = removePunct(word);

  // detects if string contains characters && converts to lowercase
  if (word.size() > 1)
  {
    int i = 0;
    bool containsChar = false;
    while (i < word.size())
    {
      if (isupper(word[i]) || islower(word[i]))
      {
        containsChar = true;
        if (isupper(word[i])) word.at(i) = tolower(word.at(i));
      }
      i++;
    }
    // clears return string if not containsChar
    word = containsChar? word: "";
  }
  else word = "";

  return word;
}

bool ReadWords::isNextWord()
{
	return !eoffound;
}

void ReadWords::close()
{
	if (wordfile.is_open())
	{
  		wordfile.close();
	}
	else cout << "File already closed";
}
