
#ifndef _LIB_PROTOS_H
#define _LIB_PROTOS_H

#include <dopus/common.h>
#include <proto/dopus5.h>
#include <proto/module.h>

/* init.c */
ULONG freeBase(struct LibraryHeader* lib);
ULONG initBase(struct LibraryHeader* lib);



// protos:

LIBPROTO(L_Module_Entry, int, 	REG(a0, char *args),
								REG(a1, struct Screen *screen),
								REG(a2, IPCData *ipc),
								REG(a3, IPCData *main_ipc),
								REG(d0, ULONG mod_id),
								REG(d1, EXT_FUNC(func_callback)));
	
LIBPROTO(L_Module_Identify, ModuleInfo *, REG(d0, int num));


#endif /* _LIB_PROTOS_H */
