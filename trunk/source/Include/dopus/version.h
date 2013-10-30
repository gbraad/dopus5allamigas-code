#ifndef DOPUS_VERSION_H
#define DOPUS_VERSION_H

// transforms a define into a string
#define STRI(x)  STRI2(x)
#define STRI2(x) #x

// converts AROS archetecture into integer for conditional tests
#undef i386
#define i386 386
#undef arm
#define arm 603

//set the compile date from the makefile date definition
#define DOPUSDATE STRI(COMPDATE)

// set the program version/revision
#define PROG_VERSION    5
#define PROG_REVISION   90

// set the library & modules version/revision
#define LIB_VERSION    69
#define LIB_REVISION   0

// set the commands version/revision (viewfont, dopusrt5, loadwb)
#define CMD_VERSION    63
#define CMD_REVISION   0

// set platform identification
#ifdef DEBUG
	#if defined(__amigaos3__)
		#define PLATFORM [OS3dev]
	#elif defined(__amigaos4__)
		#define PLATFORM [OS4dev]
	#elif defined(__MORPHOS__)
		#define PLATFORM [MOSdev]
	#elif defined(__AROS__)
		#if ARCH == 386
			#undef i386
			#define PLATFORM [AROSdev-i386]
		#elif ARCH == 603
			#undef arm
			#define PLATFORM [AROSdev-arm]
		#else
			#warning Unknown architecture!
			#define PLATFORM [AROSdev]
		#endif
	#else
		#error Unsupported operating system!
	#endif
#else
	#if defined(__amigaos3__)
		#define PLATFORM [OS3]
	#elif defined(__amigaos4__)
		#define PLATFORM [OS4]
	#elif defined(__MORPHOS__)
		#define PLATFORM [MOS]
	#elif defined(__AROS__)
		#if ARCH == 386
			#undef i386
			#define PLATFORM [AROS-i386]
		#elif ARCH == 603
			#undef arm
			#define PLATFORM [AROS-arm]
		#else
			#warning Unknown architecture!
			#define PLATFORM [AROS]
		#endif
	#else
		#error Unsupported operating system!
	#endif
#endif

// set the version/revision strings
#define PROG_STRING STRI(PROG_VERSION)"."STRI(PROG_REVISION)" "STRI(PLATFORM)" ("DOPUSDATE")"
#define LIB_STRING STRI(LIB_VERSION)"."STRI(LIB_REVISION)" "STRI(PLATFORM)" ("DOPUSDATE")"
#define CMD_STRING STRI(CMD_VERSION)"."STRI(CMD_REVISION)" "STRI(PLATFORM)" ("DOPUSDATE")"

#define COPYRIGHT  " Copyright (c) 2012-2013 dopus5 Open Source Team "

#endif /* DOPUS_VERSION_H */
