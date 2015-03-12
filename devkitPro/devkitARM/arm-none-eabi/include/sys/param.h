/* ARM configuration file; HZ is 100 rather than the default 60 */

#ifndef _SYS_PARAM_H
# define _SYS_PARAM_H

#ifndef HZ
# define HZ (60)
#endif
#ifndef NOFILE
# define NOFILE	(60)
#endif
#ifndef PATHSIZE
# define PATHSIZE (4096)
#endif

#define MAXPATHLEN	4096
#define BIG_ENDIAN      4321
#define LITTLE_ENDIAN   1234

#ifdef __ARMEB__
#define BYTE_ORDER BIG_ENDIAN
#else
#define BYTE_ORDER LITTLE_ENDIAN
#endif

#endif
