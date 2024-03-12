/* infback9.h -- header for using inflateBack9 functions
 * Copyright (C) 2003 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h
 */

/*
 * This header file and associated patches provide a decoder for PKWare's
 * undocumented deflate64 compression method (method 9).  Use with infback9.c,
 * inftree9.h, inftree9.c, and inffix9.h.  These patches are not supported.
 * This should be compiled with zlib, since it uses zutil.h and zutil.o.
 * This code has not yet been tested on 16-bit architectures.  See the
 * comments in zlib.h for inflateBack() usage.  These functions are used
 * identically, except that there is no windowBits parameter, and a 64K
 * window must be provided.  Also if int's are 16 bits, then a zero for
 * the third parameter of the "out" function actually means 65536UL.
 * zlib.h must be included before this header file.
 */

#ifdef __cplusplus
extern "C" {
#endif

#define inflateBack9 gdal_inflateBack9
#define inflateBack9End gdal_inflateBack9End
#define inflateBack9Init_ gdal_inflateBack9Init_
#define inflateBack9Copy gdal_inflateBack9Copy

int inflateBack9 (z_stream FAR *strm,
                                    in_func in, void FAR *in_desc,
                                    out_func out, void FAR *out_desc);
int inflateBack9End (z_stream FAR *strm);
int inflateBack9Init_ (z_stream FAR *strm,
                                         unsigned char FAR *window,
                                         const char *version,
                                         int stream_size);
#define inflateBack9Init(strm, window) \
        inflateBack9Init_((strm), (window), \
        ZLIB_VERSION, sizeof(z_stream))

int inflateBack9Copy (z_streamp dest, z_streamp source);

#ifdef __cplusplus
}
#endif
