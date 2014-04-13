#ifndef _MODULE_DEPS_H
#define _MODULE_DEPS_H

#include <dopus/common.h>
#include <proto/dopus5.h>
#include <proto/module.h>

extern struct DOpusLocale *locale;
#ifdef __AROS__
typedef struct
{
	ULONG		ver;		// Module version
	char		*name;		// Module name
	char		*locale_name;	// Catalog name
	ULONG		flags;		// Module flags
	ULONG		function_count;	// Number of functions in module
	ModuleFunction	function[7];	// All the module functions
} ModuleInfo_7;
extern ModuleInfo_7 module_info;
#else
extern ModuleInfo module_info;
#endif



#define VALID_QUALIFIERS (IEQUALIFIER_LCOMMAND|IEQUALIFIER_RCOMMAND|\
                         IEQUALIFIER_CONTROL|IEQUALIFIER_LSHIFT|\
                         IEQUALIFIER_RSHIFT|IEQUALIFIER_LALT|IEQUALIFIER_RALT)


void init_locale_data(struct DOpusLocale *);


#define userlibname "ftp.module"
#define textsegmentname "$VER: ftp.module "LIB_STRING


#endif

