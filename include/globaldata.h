// This file exists because every file introduces this string into the (.rodata).
// There was no #ifdef guard in this file in the source, which is why it happens for every source file.
// Luckily, this tells us where file boundaries are exactly.
// This file gets included by each source file, just like in Chunsoft's original source, so we can have this string easily just like they did.

// Later, we can move this into "global.h" before the #ifdef guard. But we can only do this if "global.h" isn't included outside of .c files...
#include "gba/defines.h"
#include "gba/types.h"

#if (defined(__APPLE__) || defined(__CYGWIN__)) && !defined(_)
#define _(x) x
#endif

ALIGNED(4) static const u8 sPksDir0[] = _("pksdir0");
