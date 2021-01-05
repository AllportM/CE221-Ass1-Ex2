/**
 * Bar controller for assignment 1
 * Written by MAL / Ma18533 / 1802882
 */

#ifndef WORDCONT_
#define WORDCONT_

using namespace std;

#include <string>
#include <fstream>
#include <unordered_map>
#include "ReadWords.h"


/*
 * BarController class stores two ReadWrite objects as class member variables
 * and uses these to both populate an unordered map with words and count the frequency of
 * the occurences of those words in the second object.
 * Output is displayed to both screen, and an associated ofstream object file in a manner
 * requested showing 20 stars for the maximum counted word and a ratio there inbetween.
 */
class BarController
{
  public:
 /*
  * Main constructor, initializes referenced ReadWord objects annd output ofstream file.
  *
  * @param:
  *		&bigFile - ReadWords object reference for words to be checked against
  *		&checkWords - ReadWords object reference, words to be checked for
  *		outF - string, filename for output file
  */
  BarController(ReadWords &bigFile, ReadWords &checkWords, string outF);

 /*
  * populateMap loops through all nextWord strings in given ReadWord object initializing them
  * in unordered map member variable @ 0.
  *
  * @return
  * 	bool, false if no words to populate in file
  */
  bool populateMap();

 /*
  * findWords loops through all nextWord strings in given ReadWord member to count the frequency
  * of occurences from words populated to ordered map, increasing their value in the map.
  *
  * @return
  * 	bool, false if there was no occurences of words found in file
  */
  bool findWords();

 /*
  * Overloads the string operator to give desired bar chart output
  */
  operator string() const;

 /*
  * Outputs this objects string form to screen and output file, also closes any associated word
  * files in ReadWord objects
  */
  void doBar();
  void closeMemFile();

  private:
	ReadWords *bigWords; // pointer to pre-made word file to be analyzed, ReadWords object
	ReadWords *checkWords; // pointer to pre-made word file with words to be checked for
	ofstream outF; // output file steream
	unordered_map<string, int> checkMap; // map used to count frequency
};

#endif
