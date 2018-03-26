#ifndef LIBLUA_GLOBAL_H
#define LIBLUA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBLUA_LIBRARY)
#  define LIBLUASHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBLUASHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBLUA_GLOBAL_H
