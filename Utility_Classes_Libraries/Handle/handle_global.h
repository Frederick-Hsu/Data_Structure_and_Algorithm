#ifndef HANDLE_GLOBAL_H
#define HANDLE_GLOBAL_H

    #include <QtCore/qglobal.h>

    #if defined(HANDLE_LIBRARY)
        #define HANDLESHARED_EXPORT Q_DECL_EXPORT
    #else
        #define HANDLESHARED_EXPORT Q_DECL_IMPORT
    #endif

#endif  /* HANDLE_GLOBAL_H */
