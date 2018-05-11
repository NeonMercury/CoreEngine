#pragma once

#if defined(__ppc__) || defined(__ppc) || defined(__powerpc__) || defined(__powerpc)
#	define CE_BIG_ENDIAN 1
#else
#	define CE_LITTLE_ENDIAN 1
#endif

#if !defined(CE_LITTLE_ENDIAN) && !defined(CE_BIG_ENDIAN)
#error Could not detect endianness
#endif

#define CE_SWAP_BYTES_16(V) \
    ( (((V) >> 8) & 0x00FF) | (((V) << 8) & 0xFF00) )

#define CE_SWAP_BYTES_32(V) \
    ( (((V) >> 24) & 0x000000FF) | (((V) >>  8) & 0x0000FF00) | \
      (((V) <<  8) & 0x00FF0000) | (((V) << 24) & 0xFF000000) )

#define CE_SWAP_BYTES_64(V) \
    ( (((V) >> 56) & 0x00000000000000FF) | (((V) >> 40) & 0x000000000000FF00) | \
      (((V) >> 24) & 0x0000000000FF0000) | (((V) >>  8) & 0x00000000FF000000) | \
      (((V) <<  8) & 0x000000FF00000000) | (((V) << 24) & 0x0000FF0000000000) | \
      (((V) << 40) & 0x00FF000000000000) | (((V) << 56) & 0xFF00000000000000) )
