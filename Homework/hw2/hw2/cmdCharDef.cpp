/****************************************************************************
  FileName     [ cmdCharDef.cpp ]
  PackageName  [ cmd ]
  Synopsis     [ Process keyboard inputs ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#include "cmdCharDef.h"

#include <termios.h>

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <iostream>

namespace
{
//----------------------------------------------------------------------
//    Global static functions
//----------------------------------------------------------------------
static struct termios storedSettings;

static void resetKeypress()
{
    tcsetattr(0, TCSANOW, &storedSettings);
}

static void setKeypress()
{
    struct termios newSettings;
    tcgetattr(0, &storedSettings);
    newSettings = storedSettings;
    newSettings.c_lflag &= (~ICANON);
    newSettings.c_lflag &= (~ECHO);
    newSettings.c_cc[VTIME] = 0;
    tcgetattr(0, &storedSettings);
    newSettings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &newSettings);
}
}  // anonymous namespace

//----------------------------------------------------------------------
//    Global functions
//----------------------------------------------------------------------
char mygetc(std::istream &istr)
{
    char character;
    setKeypress();
    istr.unsetf(std::ios_base::skipws);
    istr >> character;
    istr.setf(std::ios_base::skipws);
    resetKeypress();
#ifdef TEST_ASC
    std::cout << static_cast<int>(character);
#endif  // TEST_ASC
    return character;
}

void mybeep()
{
    std::cout << static_cast<char>(BEEP_CHAR);
}

inline ParseChar returnCh(int);

#ifndef TA_KB_SETTING
// YOU NEED TO CUSTOMIZE THIS PART...
// YOU NEED TO CUSTOMIZE THIS PART...
//
// Modify "cmdCharDef.h" to work with the following code
//
// Make sure you DO NOT define TA_KB_SETTING in your Makefile
//
ParseChar getChar(std::istream &istr)
{
    const char character = mygetc(istr);

    if (istr.eof())
        return returnCh(INPUT_END_KEY);
    switch (character) {
    // Simple keys: one code for one key press
    // -- The following should be platform-independent
    case LINE_BEGIN_KEY:  // Ctrl-a
    case LINE_END_KEY:    // Ctrl-e
    case INPUT_END_KEY:   // Ctrl-d
    case TAB_KEY:         // tab('\t') or Ctrl-i
    case NEWLINE_KEY:     // enter('\n') or ctrl-m
        return returnCh(character);

    // TODO... Check and change if necessary!!!!!!
    // -- The following simple/combo keys are platform-dependent
    //    You should test to check the returned codes of these key presses
    // -- You should either modify the "enum ParseChar" definitions in
    //    "cmdCharDef.h", or revise the control flow of the "case ESC" below
    //
    // -- You need to handle:
    //    { BACK_SPACE_KEY, ARROW_UP/DOWN/RIGHT/LEFT,
    //      HOME/END/PG_UP/PG_DOWN/INSERT/DELETE }
    //
    // Combo keys: multiple codes for one key press
    // -- Usually starts with ESC key, so we check the "case ESC"
    // case ESC_KEY:

    // For the remaining printable and undefined keys
    default:
        if (std::isprint(static_cast<unsigned char>(character)))
            return returnCh(character);
        else
            return returnCh(UNDEFINED_KEY);
    }

    return returnCh(UNDEFINED_KEY);
}
#else   // TA_KB_SETTING is defined
// DO NOT CHANGE THIS PART...
// DO NOT CHANGE THIS PART...
//
// This part will be used by TA to test your program.
//
// TA will use "make -DTA_KB_SETTING" to test your program
//
ParseChar getChar(std::istream &istr)
{
    const char character = mygetc(istr);

    if (istr.eof())
        return returnCh(INPUT_END_KEY);
    switch (character) {
    // Simple keys: one code for one key press
    // -- The following should be platform-independent
    case LINE_BEGIN_KEY:  // Ctrl-a
    case LINE_END_KEY:    // Ctrl-e
    case INPUT_END_KEY:   // Ctrl-d
    case TAB_KEY:         // tab('\t') or Ctrl-i
    case NEWLINE_KEY:     // enter('\n') or ctrl-m
        return returnCh(character);

    // -- The following simple/combo keys are platform-dependent
    //    You should test to check the returned codes of these key presses
    // -- You should either modify the "enum ParseChar" definitions in
    //    "cmdCharDef.h", or revise the control flow of the "case ESC" below
    case BACK_SPACE_KEY:
        return returnCh(character);

    // Combo keys: multiple codes for one key press
    // -- Usually starts with ESC key, so we check the "case ESC"
    case ESC_KEY: {
        const char combo = mygetc(istr);
        // Note: ARROW_KEY_INT == MOD_KEY_INT, so we only check MOD_KEY_INT
        if (combo == static_cast<char>(MOD_KEY_INT)) {
            const char key = mygetc(istr);
            if ((key >= static_cast<char>(MOD_KEY_BEGIN)) &&
                (key <= static_cast<char>(MOD_KEY_END))) {
                if (mygetc(istr) == MOD_KEY_DUMMY)
                    return returnCh(static_cast<int>(key) + MOD_KEY_FLAG);
                else
                    return returnCh(UNDEFINED_KEY);
            }
            else if ((key >= static_cast<char>(ARROW_KEY_BEGIN)) &&
                     (key <= static_cast<char>(ARROW_KEY_END)))
                return returnCh(static_cast<int>(key) + ARROW_KEY_FLAG);
            else
                return returnCh(UNDEFINED_KEY);
        }
        else {
            mybeep();
            return getChar(istr);
        }
    }
    // For the remaining printable and undefined keys
    default:
        if (std::isprint(static_cast<unsigned char>(character)))
            return returnCh(character);
        else
            return returnCh(UNDEFINED_KEY);
    }

    return returnCh(UNDEFINED_KEY);
}
#endif  // TA_KB_SETTING

inline ParseChar returnCh(int character)
{
#ifndef MAKE_REF
    return ParseChar(character);
#else
    switch (ParseChar(character)) {
    case LINE_BEGIN_KEY:
        return ParseChar(TA_LINE_BEGIN_KEY);
    case LINE_END_KEY:
        return ParseChar(TA_LINE_END_KEY);
    case INPUT_END_KEY:
        return ParseChar(TA_INPUT_END_KEY);
    case TAB_KEY:
        return ParseChar(TA_TAB_KEY);
    case NEWLINE_KEY:
        return ParseChar(TA_NEWLINE_KEY);
    case ESC_KEY:
        return ParseChar(TA_ESC_KEY);
    case BACK_SPACE_KEY:
        return ParseChar(TA_BACK_SPACE_KEY);
    case ARROW_KEY_FLAG:
        return ParseChar(TA_ARROW_KEY_FLAG);
    case ARROW_KEY_INT:
        return ParseChar(TA_ARROW_KEY_INT);
    case ARROW_UP_KEY:
        return ParseChar(TA_ARROW_UP_KEY);
    case ARROW_DOWN_KEY:
        return ParseChar(TA_ARROW_DOWN_KEY);
    case ARROW_RIGHT_KEY:
        return ParseChar(TA_ARROW_RIGHT_KEY);
    case ARROW_LEFT_KEY:
        return ParseChar(TA_ARROW_LEFT_KEY);
        //      case ARROW_KEY_BEGIN: return ParseChar(TA_ARROW_KEY_BEGIN);
        //      case ARROW_KEY_END  : return ParseChar(TA_ARROW_KEY_END);
    case MOD_KEY_FLAG:
        return ParseChar(TA_MOD_KEY_FLAG);
        // comment out because MOD_KEY_INT == ARROW_KEY_INT
        // Uncomment it out if yours are different
        //      case MOD_KEY_INT    : return ParseChar(TA_MOD_KEY_INT);
    case HOME_KEY:
        return ParseChar(TA_HOME_KEY);
    case INSERT_KEY:
        return ParseChar(TA_INSERT_KEY);
    case DELETE_KEY:
        return ParseChar(TA_DELETE_KEY);
    case END_KEY:
        return ParseChar(TA_END_KEY);
    case PG_UP_KEY:
        return ParseChar(TA_PG_UP_KEY);
    case PG_DOWN_KEY:
        return ParseChar(TA_PG_DOWN_KEY);
    case MOD_KEY_BEGIN:
        return ParseChar(TA_MOD_KEY_BEGIN);
    case MOD_KEY_END:
        return ParseChar(TA_MOD_KEY_END);
    case MOD_KEY_DUMMY:
        return ParseChar(TA_MOD_KEY_DUMMY);
    case UNDEFINED_KEY:
        return ParseChar(TA_UNDEFINED_KEY);
    case BEEP_CHAR:
        return ParseChar(TA_BEEP_CHAR);
    case BACK_SPACE_CHAR:
        return ParseChar(TA_BACK_SPACE_CHAR);
    case PARSE_CHAR_END:
        return ParseChar(TA_PARSE_CHAR_END);
    default:
        return ParseChar(TA_UNDEFINED_KEY);
    }
#endif
}
