#ifndef CONSOLEQUIZ_SYSCLEAR_HPP
#define CONSOLEQUIZ_SYSCLEAR_HPP

#if defined( _WIN32 ) || defined( _WIN64 )
    #include <windows.h>
    #define SYS_CLEAR_COMMAND "cls"
#else
    #include <cstdio>
    #include <cstdlib>
    #define SYS_CLEAR_COMMAND "clear"
#endif

void clear();

#endif //CONSOLEQUIZ_SYSCLEAR_HPP
