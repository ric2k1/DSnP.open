/****************************************************************************
  FileName     [ cmdReader.cpp ]
  PackageName  [ cmd ]
  Synopsis     [ Define command line reader member functions ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#include "cmdParser.h"
#include "cmdCharDef.h"

#include <cassert>
#include <cstring>
#include <iostream>

//----------------------------------------------------------------------
//    External functions
//----------------------------------------------------------------------
void mybeep();
char mygetc(std::istream &);
ParseChar getChar(std::istream &);

//----------------------------------------------------------------------
//    Member Function for class Parser
//----------------------------------------------------------------------
void CmdParser::readCmd()
{
    if (_dofile.is_open()) {
        readCmdInt(_dofile);
        _dofile.close();
    }
    else
        readCmdInt(std::cin);
}

void CmdParser::readCmdInt(std::istream &istr)
{
    resetBufAndPrintPrompt();

    while (true) {
        ParseChar pch = getChar(istr);
        if (pch == INPUT_END_KEY)
            break;
        switch (pch) {
        case LINE_BEGIN_KEY:
        case HOME_KEY:
            moveBufPtr(_readBuf);
            break;
        case LINE_END_KEY:
        case END_KEY:
            moveBufPtr(_readBufEnd);
            break;
        case BACK_SPACE_KEY: /* TODO */
            break;
        case DELETE_KEY:
            deleteChar();
            break;
        case NEWLINE_KEY:
            addHistory();
            std::cout << static_cast<char>(NEWLINE_KEY);
            resetBufAndPrintPrompt();
            break;
        case ARROW_UP_KEY:
            moveToHistory(_historyIdx - 1);
            break;
        case ARROW_DOWN_KEY:
            moveToHistory(_historyIdx + 1);
            break;
        case ARROW_RIGHT_KEY: /* TODO */
            break;
        case ARROW_LEFT_KEY: /* TODO */
            break;
        case PG_UP_KEY:
            moveToHistory(_historyIdx - PG_OFFSET);
            break;
        case PG_DOWN_KEY:
            moveToHistory(_historyIdx + PG_OFFSET);
            break;
        case TAB_KEY: /* TODO */
            break;
        case INSERT_KEY:  // not yet supported; fall through to UNDEFINE
        case UNDEFINED_KEY:
            mybeep();
            break;
        default:  // printable character
            insertChar(static_cast<char>(pch));
            break;
        }
#ifdef TA_KB_SETTING
        taTestOnly();
#endif
    }
}

// This function moves _readBufPtr to the "ptr" pointer
// It is used by left/right arrowkeys, home/end, etc.
//
// Suggested steps:
// 1. Make sure ptr is within [_readBuf, _readBufEnd].
//    If not, make a beep sound and return false. (DON'T MOVE)
// 2. Move the cursor to the left or right, depending on ptr
// 3. Update _readBufPtr accordingly. The content of the _readBuf[] will
//    not be changed
//
// [Note] This function can also be called by other member functions below
//        to move the _readBufPtr to proper position.
bool CmdParser::moveBufPtr(char *const ptr)
{
    // TODO...
    return true;
}

// [Notes]
// 1. Delete the char at _readBufPtr
// 2. mybeep() and return false if at _readBufEnd
// 3. Move the remaining string left for one character
// 4. The cursor should stay at the same position
// 5. Remember to update _readBufEnd accordingly.
// 6. Don't leave the tailing "visible" character.
// 7. Call "moveBufPtr(...)" if needed.
//
// For example,
//
// cmd> This is the command
//              ^                (^ is the cursor position)
//
// After calling deleteChar()---
//
// cmd> This is he command
//              ^
//
bool CmdParser::deleteChar()
{
    // TODO...
    return true;
}

// 1. Insert character 'ch' for "repeat" times at _readBufPtr
// 2. Move the remaining string right for "repeat" characters
// 3. The cursor should move right for "repeats" positions afterwards
// 4. Default value for "repeat" is 1. You should assert that (repeat >= 1).
//
// For example,
//
// cmd> This is the command
//              ^                (^ is the cursor position)
//
// After calling insertChar('k', 3) ---
//
// cmd> This is kkkthe command
//                 ^
//
void CmdParser::insertChar(char character, int repeat)
{
    // TODO...
    assert(repeat >= 1);
}

// 1. Delete the line that is currently shown on the screen
// 2. Reset _readBufPtr and _readBufEnd to _readBuf
// 3. Make sure *_readBufEnd = 0
//
// For example,
//
// cmd> This is the command
//              ^                (^ is the cursor position)
//
// After calling deleteLine() ---
//
// cmd>
//      ^
//
void CmdParser::deleteLine()
{
    // TODO...
}

// This functions moves _historyIdx to index and display _history[index]
// on the screen.
//
// Need to consider:
// If moving up... (i.e. index < _historyIdx)
// 1. If already at top (i.e. _historyIdx == 0), beep and do nothing.
// 2. If at bottom, temporarily record _readBuf to history.
//    (Do not remove spaces, and set _tempCmdStored to "true")
// 3. If index < 0, let index = 0.
//
// If moving down... (i.e. index > _historyIdx)
// 1. If already at bottom, beep and do nothing
// 2. If index >= _history.size(), let index = _history.size() - 1.
//
// Assign _historyIdx to index at the end.
//
// [Note] index should not = _historyIdx
//
void CmdParser::moveToHistory(int index)
{
    // TODO...
}

// This function adds the string in _readBuf to the _history.
// The size of _history may or may not change. Depending on whether
// there is a temp history string.
//
// 1. Remove ' ' at the beginning and end of _readBuf
// 2. If not a null string, add string to _history.
//    Be sure you are adding to the right entry of _history.
// 3. If it is a null string, don't add anything to _history.
// 4. Make sure to clean up "temp recorded string" (added earlier by up/pgUp,
//    and reset _tempCmdStored to false
// 5. Reset _historyIdx to _history.size() // for future insertion
//
void CmdParser::addHistory()
{
    // TODO...
}

// This function retrieves the history string and displays it on the screen.
// The cursor should be positioned at the end of the string.
//
// For example,
//
// cmd> This is the command
//              ^                (^ is the cursor position)
//
// After calling retrieveHistory() ---
//
// cmd> This is the command
//                              ^
//
void CmdParser::retrieveHistory()
{
    // TODO...
}
