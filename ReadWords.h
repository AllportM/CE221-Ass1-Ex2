/**
 * ReadWords Interface for Assignment 1
 *
 * Created by msands, edited by mal - ma18533
 */

#ifndef READWORDS_H
#define READWORDS_H


using namespace std;

#include <string>
#include <fstream>

/**
 * ReadWords class associates filename argument to ifstream object, or raises error if invalid.
 * Class implements methods for attaining each word from the opened document utilizing one-word
 * lookahead isNextWord and provides ability to remove leading/trailing punctuation.
 *
 */
 class ReadWords
 {
   public:

	/**
	 * Readwords constructor, takes C-string filename as argument and associates to
	 * ifstream. If invalid filename given and integer error is thrown such that
	 * user can be prompted to re-enter by main function.
	 * Initializes member variables.
	 *
	 * @param:
	 *	*filename - const char array pointer
	 */
     ReadWords(const char *filename);

    /**
     * Closes the file.
     */
     void close();


    /**
	 * getNextWord attains next word from ifstream and uses one word lookahead boolean
	 * to determine if last word has been reached.
	 * Leading/Trailing puncuation is removed from each word via removePunct.
	 * Converts string to lowercase.
	 * If any word only consists on non characters, empty string is returned, or if the
	 * next word only contains 1 character/number/symbol.
	 *
	 * @return:
	 *		string, the next word
 	 */
     string getNextWord();

    /**
     * Returns true if there is a further word in the file, false if we have reached the
     * end of file.
     * @return:
     * 		bool - !eof
     */
     bool isNextWord();

   private:
     ifstream wordfile; // ifstream member variable
     string nextword; // string member used to contain the next word
     bool eoffound; // boolean member variable, used to see if end of file reached
 };

 #endif
