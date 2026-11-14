/**
 * Key Mapping and Macro Profiles for MacroPad
 *
 * @file keystroke.h
 */
#ifndef KEYSTROKE_H
#define KEYSTROKE_H

#include <BleKeyboard.h>

namespace keyStroke {
    bool connected();
    void copy();
    void paste();
    void screenShot();
    void altTab();

    /*  Productivity / Editor shortcuts  */
    void terminal();
    void comment();
    void undo(); 
    void explorer(); 
}
#endif
