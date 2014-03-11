/*

Directory Opus 5
Original APL release version 5.82
Copyright 1993-2012 Jonathan Potter & GP Software

This program is free software; you can redistribute it and/or
modify it under the terms of the AROS Public License version 1.1.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
AROS Public License for more details.

The release of Directory Opus 5 under the GPL in NO WAY affects
the existing commercial status of Directory Opus for Windows.

For more information on Directory Opus for Windows please see:

                 http://www.gpsoft.com.au

*/
/*
 *
 * dopus.library header file
 *
 */

#ifndef DOPUS5_INTERFACE_DEF_H
#define DOPUS5_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.5.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef PROTO_DOS_H
#include <proto/dos.h>
#endif
#ifndef PROTO_INTUITION_H
#include <proto/intuition.h>
#endif
#ifndef PROTO_GRAPHICS_H
#include <proto/graphics.h>
#endif
#ifndef PROTO_LAYOUT_H
#include <proto/layout.h>
#endif
#ifndef PROTO_WB_H
#include <proto/wb.h>
#endif
#ifndef PROTO_WB_H
#include <proto/wb.h>
#endif
#ifndef PROTO_REXXSYSLIB_H
#include <proto/rexxsyslib.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct DOpusIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct DOpusIFace *Self);
	uint32 APICALL (*Release)(struct DOpusIFace *Self);
	void APICALL (*Expunge)(struct DOpusIFace *Self);
	struct Interface * APICALL (*Clone)(struct DOpusIFace *Self);
	void APICALL (*RemovedFunc0)(struct DOpusIFace *Self);
	UWORD APICALL (*RandomDopus)(struct DOpusIFace *Self, int limit);
	ULONG APICALL (*Atoh)(struct DOpusIFace *Self, char * str, short len);
	void APICALL (*BtoCStr)(struct DOpusIFace *Self, BSTR bstr, char * cstr, int len);
	ULONG APICALL (*DivideU)(struct DOpusIFace *Self, ULONG num, ULONG div, ULONG * rem, struct Library * utility);
	void APICALL (*Itoa)(struct DOpusIFace *Self, long num, char * str, char sep);
	void APICALL (*ItoaU)(struct DOpusIFace *Self, ULONG num, char * str, char sep);
	void APICALL (*Ito26)(struct DOpusIFace *Self, ULONG num, char * str);
	void APICALL (*BytesToString)(struct DOpusIFace *Self, ULONG bytes, char * string, short places, char sep);
	void APICALL (*DivideToString)(struct DOpusIFace *Self, char * string, ULONG num, ULONG div, short places, char sep);
	void APICALL (*SetBusyPointer)(struct DOpusIFace *Self, struct Window * window);
	void APICALL (*BuildKeyString)(struct DOpusIFace *Self, UWORD code, UWORD qual, UWORD mask, UWORD same, char * buffer);
	void APICALL (*ActivateStrGad)(struct DOpusIFace *Self, struct Gadget * gadget, struct Window * window);
	struct TimerHandle * APICALL (*AllocTimer)(struct DOpusIFace *Self, ULONG unit, struct MsgPort * port);
	void APICALL (*FreeTimer)(struct DOpusIFace *Self, TimerHandle * handle);
	void APICALL (*StartTimer)(struct DOpusIFace *Self, TimerHandle * handle, ULONG secs, ULONG micro);
	BOOL APICALL (*CheckTimer)(struct DOpusIFace *Self, TimerHandle * handle);
	void APICALL (*StopTimer)(struct DOpusIFace *Self, TimerHandle * handle);
	BPTR APICALL (*GetDosPathList)(struct DOpusIFace *Self, BPTR copy);
	void APICALL (*FreeDosPathList)(struct DOpusIFace *Self, BPTR list);
	short APICALL (*DoSimpleRequest)(struct DOpusIFace *Self, struct Window * window, struct DOpusSimpleRequest * simplereq);
	short APICALL (*SimpleRequest)(struct DOpusIFace *Self, struct Window * parent, char * title, char * buttons, char * message, char * buffer, APTR data, long bufsize, ULONG flags);
	short APICALL (*SelectionList)(struct DOpusIFace *Self, Att_List * list, struct Window * parent, struct Screen * screen, char * title, short ok, ULONG cancel, char * sel, char * flags, char * buffer, char ** switchtxt, ULONG * switchflags);
	BOOL APICALL (*WriteIcon)(struct DOpusIFace *Self, char * name, struct DiskObject * obj);
	void APICALL (*WriteFileIcon)(struct DOpusIFace *Self, char * source, char * dest);
	DragInfo * APICALL (*GetDragInfo)(struct DOpusIFace *Self, struct Window * window, struct RastPort * rast, long width, long height, long flags);
	void APICALL (*FreeDragInfo)(struct DOpusIFace *Self, DragInfo * draginfo);
	void APICALL (*GetDragImage)(struct DOpusIFace *Self, DragInfo * draginfo, ULONG x, ULONG y);
	void APICALL (*ShowDragImage)(struct DOpusIFace *Self, DragInfo * draginfo, ULONG x, ULONG y);
	void APICALL (*HideDragImage)(struct DOpusIFace *Self, DragInfo * draginfo);
	void APICALL (*StampDragImage)(struct DOpusIFace *Self, DragInfo * draginfo, ULONG x, ULONG y);
	void APICALL (*GetDragMask)(struct DOpusIFace *Self, DragInfo * drag);
	BOOL APICALL (*CheckDragDeadlock)(struct DOpusIFace *Self, DragInfo * drag);
	void APICALL (*AddDragImage)(struct DOpusIFace *Self, DragInfo * drag);
	void APICALL (*RemDragImage)(struct DOpusIFace *Self, DragInfo * drag);
	struct Window * APICALL (*OpenConfigWindow)(struct DOpusIFace *Self, NewConfigWindow * newwindow);
	void APICALL (*CloseConfigWindow)(struct DOpusIFace *Self, struct Window * window);
	struct IntuiMessage * APICALL (*GetWindowMsg)(struct DOpusIFace *Self, struct MsgPort * port);
	void APICALL (*ReplyWindowMsg)(struct DOpusIFace *Self, struct IntuiMessage * msg);
	void APICALL (*StripIntuiMessagesDopus)(struct DOpusIFace *Self, struct Window * window);
	void APICALL (*CloseWindowSafely)(struct DOpusIFace *Self, struct Window * window);
	int APICALL (*CalcObjectDims)(struct DOpusIFace *Self, void * parent, struct TextFont * font, struct IBox * pos, struct IBox * dest, GL_Object * last, ULONG flags, GL_Object * ob, GL_Object * d2arg);
	int APICALL (*CalcWindowDims)(struct DOpusIFace *Self, struct Screen * screen, ConfigWindow * pos, struct IBox * dest, struct TextFont * font, ULONG flags);
	ObjectList * APICALL (*AddObjectList)(struct DOpusIFace *Self, struct Window * window, ObjectDef * objects);
	void APICALL (*FreeObject)(struct DOpusIFace *Self, ObjectList * objlist, GL_Object * object);
	void APICALL (*FreeObjectList)(struct DOpusIFace *Self, ObjectList * objlist);
	void APICALL (*RefreshObjectList)(struct DOpusIFace *Self, struct Window * window, ObjectList * list);
	GL_Object * APICALL (*GetObject)(struct DOpusIFace *Self, ObjectList * list, int id);
	void APICALL (*StoreGadgetValue)(struct DOpusIFace *Self, ObjectList * list, struct IntuiMessage * msg);
	void APICALL (*SetGadgetValue)(struct DOpusIFace *Self, ObjectList * list, UWORD id, ULONG value);
	long APICALL (*GetGadgetValue)(struct DOpusIFace *Self, ObjectList * list, UWORD id);
	void APICALL (*SetObjectKind)(struct DOpusIFace *Self, ObjectList * list, ULONG id, UWORD kind);
	void APICALL (*SetGadgetChoices)(struct DOpusIFace *Self, ObjectList * list, ULONG id, APTR choices);
	BOOL APICALL (*CheckObjectArea)(struct DOpusIFace *Self, GL_Object * object, int x, int y);
	BOOL APICALL (*GetObjectRect)(struct DOpusIFace *Self, ObjectList * list, ULONG id, struct Rectangle * rect);
	void APICALL (*DisplayObject)(struct DOpusIFace *Self, struct Window * window, GL_Object * object, int fg, int bg, char * txt);
	void APICALL (*DisableObject)(struct DOpusIFace *Self, ObjectList * list, ULONG id, BOOL state);
	int APICALL (*BoundsCheckGadget)(struct DOpusIFace *Self, ObjectList * list, ULONG id, int min, int max);
	void APICALL (*AddWindowMenus)(struct DOpusIFace *Self, struct Window * window, MenuData * data);
	void APICALL (*FreeWindowMenus)(struct DOpusIFace *Self, struct Window * window);
	void APICALL (*SetWindowBusy)(struct DOpusIFace *Self, struct Window * window);
	void APICALL (*ClearWindowBusy)(struct DOpusIFace *Self, struct Window * window);
	STRPTR APICALL (*GetString)(struct DOpusIFace *Self, struct DOpusLocale * locale, LONG num);
	struct Gadget * APICALL (*FindKeyEquivalent)(struct DOpusIFace *Self, ObjectList * list, struct IntuiMessage * msg, int process);
	void APICALL (*ShowProgressBar)(struct DOpusIFace *Self, struct Window * window, GL_Object * object, ULONG total, ULONG count);
	void APICALL (*SetWindowID)(struct DOpusIFace *Self, struct Window * window, WindowID * id_ptr, ULONG id, struct MsgPort * port);
	ULONG APICALL (*GetWindowID)(struct DOpusIFace *Self, struct Window * window);
	struct MsgPort * APICALL (*GetWindowAppPort)(struct DOpusIFace *Self, struct Window * window);
	Att_List * APICALL (*Att_NewList)(struct DOpusIFace *Self, ULONG flags);
	Att_Node * APICALL (*Att_NewNode)(struct DOpusIFace *Self, Att_List * list, char * name, ULONG data, ULONG flags);
	void APICALL (*Att_RemNode)(struct DOpusIFace *Self, Att_Node * node);
	void APICALL (*Att_PosNode)(struct DOpusIFace *Self, Att_List * list, Att_Node * node, Att_Node * before);
	void APICALL (*Att_RemList)(struct DOpusIFace *Self, Att_List * list, long flags);
	Att_Node * APICALL (*Att_FindNode)(struct DOpusIFace *Self, Att_List * list, long number);
	long APICALL (*Att_NodeNumber)(struct DOpusIFace *Self, Att_List * list, char * name);
	Att_Node * APICALL (*Att_FindNodeData)(struct DOpusIFace *Self, Att_List * list, ULONG data);
	long APICALL (*Att_NodeDataNumber)(struct DOpusIFace *Self, Att_List * list, ULONG data);
	char * APICALL (*Att_NodeName)(struct DOpusIFace *Self, Att_List * list, long number);
	long APICALL (*Att_NodeCount)(struct DOpusIFace *Self, Att_List * list);
	void APICALL (*Att_ChangeNodeName)(struct DOpusIFace *Self, Att_Node * node, char * name);
	long APICALL (*Att_FindNodeNumber)(struct DOpusIFace *Self, Att_List * list, Att_Node * node);
	void APICALL (*AddSorted)(struct DOpusIFace *Self, struct List * list, struct Node * node);
	struct Menu * APICALL (*BuildMenuStrip)(struct DOpusIFace *Self, MenuData * data, struct DOpusLocale * locale);
	struct MenuItem * APICALL (*FindMenuItem)(struct DOpusIFace *Self, struct Menu * menu, UWORD id);
	UWORD APICALL (*DoPopUpMenu)(struct DOpusIFace *Self, struct Window * window, PopUpMenu * menu, PopUpItem ** item, UWORD code);
	PopUpItem * APICALL (*GetPopUpItem)(struct DOpusIFace *Self, PopUpMenu * menu, UWORD id);
	int APICALL (*IPC_Startup)(struct DOpusIFace *Self, IPCData * ipc, APTR data, struct MsgPort * reply);
	ULONG APICALL (*IPC_Command)(struct DOpusIFace *Self, IPCData * ipc, ULONG command, ULONG flags, APTR data, APTR data_free, struct MsgPort * reply);
	void APICALL (*IPC_Reply)(struct DOpusIFace *Self, IPCMessage * msg);
	void APICALL (*IPC_Free)(struct DOpusIFace *Self, IPCData * ipc);
	IPCData * APICALL (*IPC_FindProc)(struct DOpusIFace *Self, struct ListLock * list, char * name, BOOL act, ULONG data);
	void APICALL (*IPC_Quit)(struct DOpusIFace *Self, IPCData * ipc, ULONG flags, BOOL wait);
	void APICALL (*IPC_Hello)(struct DOpusIFace *Self, IPCData * ipc, IPCData * owner);
	void APICALL (*IPC_Goodbye)(struct DOpusIFace *Self, IPCData * ipc, IPCData * owner, ULONG flags);
	ULONG APICALL (*IPC_GetGoodbye)(struct DOpusIFace *Self, IPCMessage * msg);
	ULONG APICALL (*IPC_ListQuit)(struct DOpusIFace *Self, struct ListLock * list, IPCData * owner, ULONG flags, BOOL wait);
	void APICALL (*IPC_Flush)(struct DOpusIFace *Self, IPCData * port);
	void APICALL (*IPC_ListCommand)(struct DOpusIFace *Self, struct ListLock * list, ULONG command, ULONG flags, ULONG data, BOOL wait);
	IPCData * APICALL (*IPC_ProcStartup)(struct DOpusIFace *Self, ULONG * data, ULONG (*code)(IPCData *, APTR));
	int APICALL (*IPC_Launch)(struct DOpusIFace *Self, struct ListLock * list, IPCData ** ipc, char * name, ULONG entry, ULONG stack, ULONG data, struct Library * dos);
	APTR APICALL (*OpenImage)(struct DOpusIFace *Self, char * name, OpenImageInfo * info);
	void APICALL (*CloseImage)(struct DOpusIFace *Self, APTR image);
	APTR APICALL (*CopyImage)(struct DOpusIFace *Self, APTR image);
	void APICALL (*FlushImages)(struct DOpusIFace *Self);
	short APICALL (*RenderImage)(struct DOpusIFace *Self, struct RastPort * rp, APTR image, UWORD left, UWORD top, struct TagItem * tags);
	void APICALL (*GetImageAttrs)(struct DOpusIFace *Self, APTR image, struct TagItem * tags);
	void * APICALL (*NewMemHandle)(struct DOpusIFace *Self, ULONG puddle, ULONG thresh, ULONG type);
	void APICALL (*FreeMemHandle)(struct DOpusIFace *Self, void * handle);
	void APICALL (*ClearMemHandle)(struct DOpusIFace *Self, void * handle);
	void * APICALL (*AllocMemH)(struct DOpusIFace *Self, void * handle, ULONG size);
	void APICALL (*FreeMemH)(struct DOpusIFace *Self, void * memory);
	void APICALL (*DrawBox)(struct DOpusIFace *Self, struct RastPort * rp, struct Rectangle * rect, struct DrawInfo * info, BOOL recess);
	void APICALL (*DrawFieldBox)(struct DOpusIFace *Self, struct RastPort * rp, struct Rectangle * rect, struct DrawInfo * info);
	Cfg_Lister * APICALL (*NewLister)(struct DOpusIFace *Self, char * path);
	Cfg_ButtonBank * APICALL (*NewButtonBank)(struct DOpusIFace *Self, BOOL init, short type);
	Cfg_Button * APICALL (*NewButton)(struct DOpusIFace *Self, APTR memory);
	Cfg_Function * APICALL (*NewFunction)(struct DOpusIFace *Self, APTR memory, UWORD type);
	Cfg_Instruction * APICALL (*NewInstruction)(struct DOpusIFace *Self, APTR memory, short type, char * string);
	short APICALL (*ReadSettings)(struct DOpusIFace *Self, CFG_SETS * env, char * name);
	Cfg_Lister * APICALL (*ReadListerDef)(struct DOpusIFace *Self, APTR iff, ULONG id);
	Cfg_ButtonBank * APICALL (*OpenButtonBank)(struct DOpusIFace *Self, char * name);
	void APICALL (*DefaultSettings)(struct DOpusIFace *Self, CFG_SETS * settings);
	void APICALL (*DefaultEnvironment)(struct DOpusIFace *Self, CFG_ENVR * env);
	Cfg_ButtonBank * APICALL (*DefaultButtonBank)(struct DOpusIFace *Self);
	int APICALL (*SaveSettings)(struct DOpusIFace *Self, CFG_SETS * env, char * name);
	long APICALL (*SaveListerDef)(struct DOpusIFace *Self, APTR iff, Cfg_Lister * lister);
	int APICALL (*SaveButtonBank)(struct DOpusIFace *Self, Cfg_ButtonBank * bank, char * name);
	void APICALL (*CloseButtonBank)(struct DOpusIFace *Self, Cfg_ButtonBank * bank);
	void APICALL (*FreeListerDef)(struct DOpusIFace *Self, Cfg_Lister * lister);
	void APICALL (*FreeButtonList)(struct DOpusIFace *Self, struct List * list);
	void APICALL (*FreeButtonImages)(struct DOpusIFace *Self, struct List * list);
	void APICALL (*FreeButton)(struct DOpusIFace *Self, Cfg_Button * button);
	void APICALL (*FreeFunction)(struct DOpusIFace *Self, Cfg_Function * function);
	void APICALL (*FreeInstruction)(struct DOpusIFace *Self, Cfg_Instruction * ins);
	void APICALL (*FreeInstructionList)(struct DOpusIFace *Self, Cfg_Function * func);
	Cfg_ButtonBank * APICALL (*CopyButtonBank)(struct DOpusIFace *Self, Cfg_ButtonBank * bank);
	Cfg_Button * APICALL (*CopyButton)(struct DOpusIFace *Self, Cfg_Button * button, APTR memory, short type);
	Cfg_Function * APICALL (*CopyFunction)(struct DOpusIFace *Self, Cfg_Function * function, APTR memory, Cfg_Function * newfunc);
	Cfg_Filetype * APICALL (*NewFiletype)(struct DOpusIFace *Self, APTR memory);
	Cfg_FiletypeList * APICALL (*ReadFiletypes)(struct DOpusIFace *Self, char * name, APTR memory);
	int APICALL (*SaveFiletypeList)(struct DOpusIFace *Self, Cfg_FiletypeList * list, char * name);
	void APICALL (*FreeFiletypeList)(struct DOpusIFace *Self, Cfg_FiletypeList * list);
	void APICALL (*FreeFiletype)(struct DOpusIFace *Self, Cfg_Filetype * type);
	Cfg_Filetype * APICALL (*CopyFiletype)(struct DOpusIFace *Self, Cfg_Filetype * orig, APTR memory);
	Cfg_Function * APICALL (*FindFunctionType)(struct DOpusIFace *Self, struct List * list, UWORD type);
	short APICALL (*SaveButton)(struct DOpusIFace *Self, APTR iff, Cfg_Button * button);
	Cfg_Button * APICALL (*ReadButton)(struct DOpusIFace *Self, APTR iff, APTR memory);
	Cfg_Function * APICALL (*ReadFunction)(struct DOpusIFace *Self, APTR iff, APTR memory, struct List * funclist, Cfg_Function * function);
	struct IFFHandle * APICALL (*OpenIFFFile)(struct DOpusIFace *Self, char * name, int mode, ULONG id);
	void APICALL (*CloseIFFFile)(struct DOpusIFace *Self, struct IFFHandle * iff);
	struct Window * APICALL (*OpenStatusWindow)(struct DOpusIFace *Self, char * title, char * text, struct Screen * screen, LONG graph, ULONG flags);
	void APICALL (*SetStatusText)(struct DOpusIFace *Self, struct Window * window, char * text);
	void APICALL (*UpdateStatusGraph)(struct DOpusIFace *Self, struct Window * window, char * text, ULONG total, ULONG count);
	ILBMHandle * APICALL (*ReadILBM)(struct DOpusIFace *Self, char * name, ULONG flags);
	void APICALL (*FreeILBM)(struct DOpusIFace *Self, ILBMHandle * ilbm);
	void APICALL (*DecodeILBM)(struct DOpusIFace *Self, char * src, UWORD w, UWORD h, UWORD d, struct BitMap * dst, ULONG mask, char comp);
	void APICALL (*DecodeRLE)(struct DOpusIFace *Self, RLEinfo * rleinfo);
	void APICALL (*LoadPalette32)(struct DOpusIFace *Self, struct ViewPort * vp, ULONG * palette);
	void APICALL (*GetPalette32)(struct DOpusIFace *Self, struct ViewPort * vp, ULONG * palette, UWORD count, short first);
	APTR APICALL (*OpenBuf)(struct DOpusIFace *Self, char * name, long mode, long buffer_size);
	long APICALL (*CloseBuf)(struct DOpusIFace *Self, APTR file);
	long APICALL (*ReadBuf)(struct DOpusIFace *Self, APTR file, char * data, long size);
	long APICALL (*WriteBuf)(struct DOpusIFace *Self, APTR file, char * data, long size);
	long APICALL (*FlushBuf)(struct DOpusIFace *Self, APTR file);
	long APICALL (*SeekBuf)(struct DOpusIFace *Self, APTR file, long offset, long mode);
	long APICALL (*ExamineBuf)(struct DOpusIFace *Self, APTR file, struct FileInfoBlock * fib);
	DiskHandle * APICALL (*OpenDisk)(struct DOpusIFace *Self, char * disk, struct MsgPort * port);
	void APICALL (*CloseDisk)(struct DOpusIFace *Self, DiskHandle * handle);
	struct Gadget * APICALL (*AddScrollBars)(struct DOpusIFace *Self, struct Window * win, struct List * list, struct DrawInfo * drawinfo, short noidcmp);
	struct Gadget * APICALL (*FindBOOPSIGadget)(struct DOpusIFace *Self, struct List * list, UWORD id);
	void APICALL (*BOOPSIFree)(struct DOpusIFace *Self, struct List * list);
	BOOL APICALL (*SerialValid)(struct DOpusIFace *Self, serial_data * data);
	void APICALL (*WB_Install_Patch)(struct DOpusIFace *Self);
	BOOL APICALL (*WB_Remove_Patch)(struct DOpusIFace *Self);
	struct AppWindow * APICALL (*WB_AddAppWindow)(struct DOpusIFace *Self, ULONG id, ULONG data, struct Window * window, struct MsgPort * port, struct TagItem * tags);
	BOOL APICALL (*WB_RemoveAppWindow)(struct DOpusIFace *Self, struct AppWindow * window);
	struct AppWindow * APICALL (*WB_FindAppWindow)(struct DOpusIFace *Self, struct Window * window);
	struct MsgPort * APICALL (*WB_AppWindowData)(struct DOpusIFace *Self, struct AppWindow * window, ULONG * id, ULONG * userdata);
	BOOL APICALL (*WB_AppWindowLocal)(struct DOpusIFace *Self, struct AppWindow * window);
	APTR APICALL (*LockAppList)(struct DOpusIFace *Self);
	APTR APICALL (*NextAppEntry)(struct DOpusIFace *Self, APTR last, ULONG type);
	void APICALL (*UnlockAppList)(struct DOpusIFace *Self);
	APTR APICALL (*AddNotifyRequest)(struct DOpusIFace *Self, ULONG type, ULONG data, struct MsgPort * port);
	void APICALL (*RemoveNotifyRequest)(struct DOpusIFace *Self, APTR node);
	void APICALL (*SendNotifyMsg)(struct DOpusIFace *Self, ULONG type, ULONG data, ULONG flags, short wait, char * name, struct FileInfoBlock * fib);
	BOOL APICALL (*StrCombine)(struct DOpusIFace *Self, char * s1, char * s2, char * s3, int len);
	BOOL APICALL (*StrConcat)(struct DOpusIFace *Self, char * s1, char * s2, int len);
	BOOL APICALL (*WB_Launch)(struct DOpusIFace *Self, char * name, struct Screen * screen, short wait);
	void APICALL (*CopyLocalEnv)(struct DOpusIFace *Self, struct Library * a0);
	BOOL APICALL (*CLI_Launch)(struct DOpusIFace *Self, char * name, struct Screen * screen, BPTR cd, BPTR in, BPTR out, short wait, long stack);
	BOOL APICALL (*SerialCheck)(struct DOpusIFace *Self, char * num, ULONG * p);
	ULONG APICALL (*ChecksumFile)(struct DOpusIFace *Self, char * file, ULONG skip);
	void APICALL (*ReplyFreeMsg)(struct DOpusIFace *Self, APTR msg);
	BOOL APICALL (*TimerActive)(struct DOpusIFace *Self, TimerHandle * timer);
	Cfg_ButtonFunction * APICALL (*NewButtonFunction)(struct DOpusIFace *Self, APTR memory, UWORD type);
	APTR APICALL (*IFFOpen)(struct DOpusIFace *Self, char * name, UWORD mode, ULONG form);
	void APICALL (*IFFClose)(struct DOpusIFace *Self, APTR handle);
	long APICALL (*IFFPushChunk)(struct DOpusIFace *Self, APTR handle, ULONG id);
	long APICALL (*IFFWriteChunkBytes)(struct DOpusIFace *Self, APTR handle, APTR data, long size);
	long APICALL (*IFFPopChunk)(struct DOpusIFace *Self, APTR handle);
	long APICALL (*IFFWriteChunk)(struct DOpusIFace *Self, APTR handle, APTR data, ULONG chunk, ULONG size);
	struct Node * APICALL (*FindNameI)(struct DOpusIFace *Self, struct List * list, char * name);
	void APICALL (*AnimDecodeRIFFXor)(struct DOpusIFace *Self, unsigned char * delta, char * plane, UWORD rowbytes, UWORD sourcebytes);
	void APICALL (*AnimDecodeRIFFSet)(struct DOpusIFace *Self, unsigned char * delta, char * plane, UWORD rowbytes, UWORD sourcebytes);
	BOOL APICALL (*ConvertRawKey)(struct DOpusIFace *Self, UWORD code, UWORD qual, char * key);
	struct ClipHandle * APICALL (*OpenClipBoard)(struct DOpusIFace *Self, ULONG unit);
	void APICALL (*CloseClipBoard)(struct DOpusIFace *Self, struct ClipHandle * clip);
	BOOL APICALL (*WriteClipString)(struct DOpusIFace *Self, struct ClipHandle * clip, char * string, long len);
	long APICALL (*ReadClipString)(struct DOpusIFace *Self, struct ClipHandle * clip, char * string, long len);
	void APICALL (*LockAttList)(struct DOpusIFace *Self, Att_List * list, short exclusive);
	void APICALL (*UnlockAttList)(struct DOpusIFace *Self, Att_List * list);
	void APICALL (*RemovedFunc1)(struct DOpusIFace *Self);
	void APICALL (*RemovedFunc2)(struct DOpusIFace *Self);
	void APICALL (*RemovedFunc3)(struct DOpusIFace *Self);
	void APICALL (*RemovedFunc4)(struct DOpusIFace *Self);
	void APICALL (*RemovedFunc5)(struct DOpusIFace *Self);
	void APICALL (*RemovedFunc6)(struct DOpusIFace *Self);
	void APICALL (*RemovedFunc7)(struct DOpusIFace *Self);
	long APICALL (*GetSemaphore)(struct DOpusIFace *Self, struct SignalSemaphore * sem, long exc, char * data);
	void APICALL (*FreeSemaphore)(struct DOpusIFace *Self, struct SignalSemaphore * sem);
	void APICALL (*ShowSemaphore)(struct DOpusIFace *Self, struct SignalSemaphore * sem);
	BOOL APICALL (*SaveFunction)(struct DOpusIFace *Self, APTR iff, Cfg_Function * func);
	ULONG APICALL (*IFFNextChunk)(struct DOpusIFace *Self, APTR iff, ULONG form);
	long APICALL (*IFFChunkSize)(struct DOpusIFace *Self, APTR iff);
	long APICALL (*IFFReadChunkBytes)(struct DOpusIFace *Self, APTR iff, APTR buffer, long size);
	APTR APICALL (*IFFFileHandle)(struct DOpusIFace *Self, APTR iff);
	long APICALL (*IFFChunkRemain)(struct DOpusIFace *Self, APTR iff);
	ULONG APICALL (*IFFChunkID)(struct DOpusIFace *Self, APTR iff);
	ULONG APICALL (*IFFGetFORM)(struct DOpusIFace *Self, APTR iff);
	ULONG APICALL (*ScreenInfo)(struct DOpusIFace *Self, struct Screen * screen);
	struct Hook * APICALL (*GetEditHook)(struct DOpusIFace *Self, ULONG type, ULONG flags, struct TagItem * tags);
	void APICALL (*FreeEditHook)(struct DOpusIFace *Self, struct Hook * hook);
	void APICALL (*InitWindowDims)(struct DOpusIFace *Self, struct Window * window, WindowDimensions * dims);
	void APICALL (*StoreWindowDims)(struct DOpusIFace *Self, struct Window * window, WindowDimensions * dims);
	BOOL APICALL (*CheckWindowDims)(struct DOpusIFace *Self, struct Window * window, WindowDimensions * dims);
	void APICALL (*InitListLock)(struct DOpusIFace *Self, struct ListLock * ll, char * name);
	void APICALL (*IPC_QuitName)(struct DOpusIFace *Self, struct ListLock * list, char * name, ULONG flags);
	UWORD APICALL (*QualValid)(struct DOpusIFace *Self, UWORD qual);
	BPTR APICALL (*FHFromBuf)(struct DOpusIFace *Self, APTR file);
	ULONG APICALL (*WB_AppIconFlags)(struct DOpusIFace *Self, struct AppIcon * icon);
	BOOL APICALL (*GetWBArgPath)(struct DOpusIFace *Self, struct WBArg * arg, char * buf, long size);
	void APICALL (*RemovedFunc8)(struct DOpusIFace *Self);
	struct DosList * APICALL (*DeviceFromLock)(struct DOpusIFace *Self, BPTR lock, char * name);
	struct DosList * APICALL (*DeviceFromHandler)(struct DOpusIFace *Self, struct MsgPort * port, char * name);
	BOOL APICALL (*DevNameFromLockDopus)(struct DOpusIFace *Self, BPTR lock, char * buffer, long len);
	ULONG APICALL (*GetIconFlags)(struct DOpusIFace *Self, struct DiskObject * icon);
	void APICALL (*SetIconFlags)(struct DOpusIFace *Self, struct DiskObject * icon, ULONG flags);
	void APICALL (*GetIconPosition)(struct DOpusIFace *Self, struct DiskObject * icon, short * x, short * y);
	void APICALL (*SetIconPosition)(struct DOpusIFace *Self, struct DiskObject * icon, short x, short y);
	BOOL APICALL (*BuildTransDragMask)(struct DOpusIFace *Self, UWORD * mask, UWORD * image, short width, short height, short depth, long flags);
	ULONG * APICALL (*GetImagePalette)(struct DOpusIFace *Self, APTR image);
	void APICALL (*FreeImageRemap)(struct DOpusIFace *Self, ImageRemap * remap);
	void APICALL (*SwapListNodes)(struct DOpusIFace *Self, struct List * list, struct Node * s1, struct Node * s2);
	void APICALL (*RemovedFunc9)(struct DOpusIFace *Self);
	void APICALL (*Seed)(struct DOpusIFace *Self, int seed);
	void APICALL (*RemovedFunc10)(struct DOpusIFace *Self);
	void APICALL (*RemovedFunc11)(struct DOpusIFace *Self);
	void APICALL (*RemovedFunc12)(struct DOpusIFace *Self);
	struct DiskObject * APICALL (*CopyDiskObject)(struct DOpusIFace *Self, struct DiskObject * icon, ULONG flags);
	void APICALL (*FreeDiskObjectCopy)(struct DOpusIFace *Self, struct DiskObject * icon);
	void APICALL (*IFFFailure)(struct DOpusIFace *Self, APTR iff);
	struct DiskObject * APICALL (*GetCachedDefDiskObject)(struct DOpusIFace *Self, long type);
	void APICALL (*FreeCachedDiskObject)(struct DOpusIFace *Self, struct DiskObject * icon);
	struct DiskObject * APICALL (*GetCachedDiskObject)(struct DOpusIFace *Self, char * name, long flags);
	struct DiskObject * APICALL (*GetCachedDiskObjectNew)(struct DOpusIFace *Self, char * name, ULONG flags);
	ULONG APICALL (*IconCheckSum)(struct DOpusIFace *Self, struct DiskObject * icon, short which);
	APTR APICALL (*OpenProgressWindow)(struct DOpusIFace *Self, struct TagItem * tags);
	void APICALL (*CloseProgressWindow)(struct DOpusIFace *Self, APTR win);
	void APICALL (*HideProgressWindow)(struct DOpusIFace *Self, APTR win);
	void APICALL (*ShowProgressWindow)(struct DOpusIFace *Self, APTR win, struct Screen * scr, struct Window * a2arg);
	void APICALL (*SetProgressWindow)(struct DOpusIFace *Self, APTR win, struct TagItem * tags);
	void APICALL (*GetProgressWindow)(struct DOpusIFace *Self, APTR win, struct TagItem * tags);
	void APICALL (*SetNotifyRequest)(struct DOpusIFace *Self, APTR req, ULONG flags, ULONG mask);
	void APICALL (*ChangeAppIcon)(struct DOpusIFace *Self, APTR icon, struct Image * render, struct Image * select, char * title, ULONG flags);
	BOOL APICALL (*CheckProgressAbort)(struct DOpusIFace *Self, APTR win);
	char * APICALL (*GetSecureString)(struct DOpusIFace *Self, struct Gadget * gad);
	Cfg_Button * APICALL (*NewButtonWithFunc)(struct DOpusIFace *Self, APTR mem, char * label, short type);
	void APICALL (*FreeButtonFunction)(struct DOpusIFace *Self, Cfg_ButtonFunction * func);
	Cfg_ButtonFunction * APICALL (*CopyButtonFunction)(struct DOpusIFace *Self, Cfg_ButtonFunction * function, APTR memory, Cfg_ButtonFunction * newfunc);
	struct PubScreenNode * APICALL (*FindPubScreen)(struct DOpusIFace *Self, struct Screen * scr, BOOL lock);
	long APICALL (*SetAppIconMenuState)(struct DOpusIFace *Self, APTR icon, long item, long state);
	long APICALL (*SearchFile)(struct DOpusIFace *Self, APTR file, UBYTE * text, ULONG flags, UBYTE * buffer, ULONG size);
	char * APICALL (*ParseDateStrings)(struct DOpusIFace *Self, char * string, char * date, char * time, long * range);
	BOOL APICALL (*DateFromStrings)(struct DOpusIFace *Self, char * date, char * time, struct DateStamp * ds);
	APTR APICALL (*GetMatchHandle)(struct DOpusIFace *Self, char * name);
	void APICALL (*FreeMatchHandle)(struct DOpusIFace *Self, APTR handle);
	BOOL APICALL (*MatchFiletype)(struct DOpusIFace *Self, APTR handle, APTR type);
	void APICALL (*LayoutResize)(struct DOpusIFace *Self, struct Window * window);
	BOOL APICALL (*GetFileVersion)(struct DOpusIFace *Self, char * name, short * ver, short * rev, struct DateStamp * date, APTR prog);
	long APICALL (*AsyncRequest)(struct DOpusIFace *Self, IPCData * ipc, long type, struct Window * window, ULONG (*callback)(ULONG, APTR, APTR), APTR data, struct TagItem * tags);
	struct IntuiMessage * APICALL (*CheckRefreshMsg)(struct DOpusIFace *Self, struct Window * window, ULONG mask);
	BOOL APICALL (*RemapImage)(struct DOpusIFace *Self, APTR image, struct Screen * screen, ImageRemap * remap);
	void APICALL (*FreeRemapImage)(struct DOpusIFace *Self, APTR image, ImageRemap * remap);
	void APICALL (*FreeAppMessage)(struct DOpusIFace *Self, DOpusAppMessage * msg);
	void APICALL (*ReplyAppMessage)(struct DOpusIFace *Self, DOpusAppMessage * msg);
	ULONG APICALL (*SetLibraryFlags)(struct DOpusIFace *Self, ULONG flags, ULONG mask);
	void APICALL (*StartRefreshConfigWindow)(struct DOpusIFace *Self, struct Window * win, long state);
	void APICALL (*EndRefreshConfigWindow)(struct DOpusIFace *Self, struct Window * win);
	ULONG APICALL (*CompareListFormat)(struct DOpusIFace *Self, ListFormat * f1, ListFormat * f2);
	void APICALL (*UpdateGadgetValue)(struct DOpusIFace *Self, ObjectList * list, struct IntuiMessage * msg, UWORD id);
	void APICALL (*UpdateGadgetList)(struct DOpusIFace *Self, ObjectList * list);
	struct BitMap * APICALL (*NewBitMap)(struct DOpusIFace *Self, ULONG w, ULONG h, ULONG d, ULONG f, struct BitMap * b);
	void APICALL (*DisposeBitMap)(struct DOpusIFace *Self, struct BitMap * b);
	FuncArgs * APICALL (*ParseArgs)(struct DOpusIFace *Self, char * temp, char * args);
	void APICALL (*DisposeArgs)(struct DOpusIFace *Self, FuncArgs * args);
	void APICALL (*SetConfigWindowLimits)(struct DOpusIFace *Self, struct Window * window, ConfigWindow * min, ConfigWindow * max);
	void APICALL (*SetEnv)(struct DOpusIFace *Self, char * name, char * data, BOOL save);
	BOOL APICALL (*IsListLockEmpty)(struct DOpusIFace *Self, struct ListLock * list);
	DOpusAppMessage * APICALL (*AllocAppMessage)(struct DOpusIFace *Self, APTR mem, struct MsgPort * reply, short num);
	BOOL APICALL (*CheckAppMessage)(struct DOpusIFace *Self, DOpusAppMessage * msg);
	DOpusAppMessage * APICALL (*CopyAppMessage)(struct DOpusIFace *Self, DOpusAppMessage * msg, APTR mem);
	BOOL APICALL (*SetWBArg)(struct DOpusIFace *Self, DOpusAppMessage * msg, short num, BPTR lock, char * name, APTR mem);
	BPTR APICALL (*OriginalCreateDir)(struct DOpusIFace *Self, char * name);
	long APICALL (*OriginalDeleteFile)(struct DOpusIFace *Self, char * name);
	BOOL APICALL (*OriginalSetFileDate)(struct DOpusIFace *Self, char * name, struct DateStamp * date);
	BOOL APICALL (*OriginalSetComment)(struct DOpusIFace *Self, char * name, char * comment);
	BOOL APICALL (*OriginalSetProtection)(struct DOpusIFace *Self, char * name, ULONG mask);
	BOOL APICALL (*OriginalRename)(struct DOpusIFace *Self, char * oldname, char * newname);
	BPTR APICALL (*OriginalOpen)(struct DOpusIFace *Self, char * name, LONG access);
	BOOL APICALL (*OriginalClose)(struct DOpusIFace *Self, BPTR file);
	LONG APICALL (*OriginalWrite)(struct DOpusIFace *Self, BPTR file, void * data, LONG length);
	struct Gadget * APICALL (*CreateTitleGadget)(struct DOpusIFace *Self, struct Screen * scr, struct List * list, BOOL zoom, short offset, short type, UWORD id);
	struct Gadget * APICALL (*FindGadgetType)(struct DOpusIFace *Self, struct Gadget * gad, UWORD type);
	void APICALL (*FixTitleGadgets)(struct DOpusIFace *Self, struct Window * win);
	BOOL APICALL (*OriginalRelabel)(struct DOpusIFace *Self, char * dev, char * name);
	ILBMHandle * APICALL (*FakeILBM)(struct DOpusIFace *Self, UWORD * data, ULONG * pal, short w, short h, short d, ULONG flags);
	ULONG APICALL (*IPC_SafeCommand)(struct DOpusIFace *Self, IPCData * ipc, ULONG command, ULONG flags, APTR data, APTR data_free, struct MsgPort * reply, struct ListLock * list);
	void APICALL (*ClearFiletypeCache)(struct DOpusIFace *Self);
	struct Library * APICALL (*GetTimerBase)(struct DOpusIFace *Self);
	BOOL APICALL (*InitDragDBuf)(struct DOpusIFace *Self, DragInfo * drag);
	void APICALL (*FreeRexxMsgEx)(struct DOpusIFace *Self, struct RexxMsg * msg);
	struct RexxMsg * APICALL (*CreateRexxMsgEx)(struct DOpusIFace *Self, struct MsgPort * port, UBYTE * extension, UBYTE * host);
	long APICALL (*SetRexxVarEx)(struct DOpusIFace *Self, struct RexxMsg * msg, char * varname, char * value, long length);
	long APICALL (*GetRexxVarEx)(struct DOpusIFace *Self, struct RexxMsg * msg, char * varname, char ** bufpointer);
	struct RexxMsg * APICALL (*BuildRexxMsgEx)(struct DOpusIFace *Self, struct MsgPort * port, UBYTE * extension, UBYTE * host, struct TagItem * tags);
	void APICALL (*NotifyDiskChange)(struct DOpusIFace *Self);
	void APICALL (*GetDosListCopy)(struct DOpusIFace *Self, struct List * list, APTR memory);
	void APICALL (*FreeDosListCopy)(struct DOpusIFace *Self, struct List * list);
	BOOL APICALL (*DateFromStringsNew)(struct DOpusIFace *Self, char * date, char * time, struct DateStamp * ds, ULONG method);
	BOOL APICALL (*RemapIcon)(struct DOpusIFace *Self, struct DiskObject * icon, struct Screen * screen, short free);
	struct DiskObject * APICALL (*GetOriginalIcon)(struct DOpusIFace *Self, struct DiskObject * icon);
	long APICALL (*CalcPercent)(struct DOpusIFace *Self, ULONG amount, ULONG total, struct Library * utilbase);
	BOOL APICALL (*IsDiskDevice)(struct DOpusIFace *Self, struct MsgPort * port);
	void APICALL (*DrawDragList)(struct DOpusIFace *Self, struct RastPort * rp, struct ViewPort * vp, long flags);
	void APICALL (*RemoveDragImage)(struct DOpusIFace *Self, DragInfo * drag);
	void APICALL (*SetNewIconsFlags)(struct DOpusIFace *Self, ULONG flags, short prec);
	long APICALL (*ReadBufLine)(struct DOpusIFace *Self, APTR file, char * data, long size);
	ULONG APICALL (*GetLibraryFlags)(struct DOpusIFace *Self);
	short APICALL (*GetIconType)(struct DOpusIFace *Self, struct DiskObject * icon);
	void APICALL (*SetReqBackFill)(struct DOpusIFace *Self, struct Hook * hook, struct Screen ** scr);
	struct Hook * APICALL (*LockReqBackFill)(struct DOpusIFace *Self, struct Screen * scr);
	void APICALL (*UnlockReqBackFill)(struct DOpusIFace *Self);
	BOOL APICALL (*DragCustomOk)(struct DOpusIFace *Self, struct BitMap * bm);
	BOOL APICALL (*WB_LaunchNew)(struct DOpusIFace *Self, char * name, struct Screen * scr, short wait, long stack, char * tool);
	void APICALL (*UpdatePathList)(struct DOpusIFace *Self);
	void APICALL (*UpdateMyPaths)(struct DOpusIFace *Self);
	void APICALL (*GetPopUpImageSize)(struct DOpusIFace *Self, struct Window * window, PopUpMenu * menu, short * width, short * height);
	BOOL APICALL (*GetDeviceUnit)(struct DOpusIFace *Self, BPTR startup, char * device, short * unit);
	void APICALL (*StripWindowMessages)(struct DOpusIFace *Self, struct MsgPort * port, struct IntuiMessage * except);
	BOOL APICALL (*DeleteIcon)(struct DOpusIFace *Self, char * name);
	void APICALL (*MUFSLogin)(struct DOpusIFace *Self, struct Window * window, char * name, char * password);
	void APICALL (*UpdateEnvironment)(struct DOpusIFace *Self, CFG_ENVR * env);
	void APICALL (*ConvertStartMenu)(struct DOpusIFace *Self, Cfg_ButtonBank * bank);
	BPTR APICALL (*GetOpusPathList)(struct DOpusIFace *Self);
	long APICALL (*GetStatistics)(struct DOpusIFace *Self, long id);
	void APICALL (*SetPopUpDelay)(struct DOpusIFace *Self, short delay);
	BOOL APICALL (*WB_LaunchNotify)(struct DOpusIFace *Self, char * name, struct Screen * scr, short wait, long stack, char * tool, struct Process ** proc, IPCData * notify, ULONG flags);
	struct Window * APICALL (*WB_AppWindowWindow)(struct DOpusIFace *Self, struct AppWindow * appwindow);
	BOOL APICALL (*OpenEnvironment)(struct DOpusIFace *Self, char * name, struct OpenEnvironmentData * data);
	PopUpHandle * APICALL (*PopUpNewHandle)(struct DOpusIFace *Self, ULONG data, ULONG (*callback)(ULONG, APTR, APTR), struct DOpusLocale * locale);
	void APICALL (*PopUpFreeHandle)(struct DOpusIFace *Self, PopUpHandle * handle);
	PopUpItem * APICALL (*PopUpNewItem)(struct DOpusIFace *Self, PopUpHandle * handle, ULONG string, ULONG id, ULONG flags);
	void APICALL (*PopUpSeparator)(struct DOpusIFace *Self, PopUpHandle * handle);
	BOOL APICALL (*PopUpItemSub)(struct DOpusIFace *Self, PopUpHandle * handle, PopUpItem * item);
	void APICALL (*PopUpEndSub)(struct DOpusIFace *Self, PopUpHandle * handle);
	ULONG APICALL (*PopUpSetFlags)(struct DOpusIFace *Self, PopUpMenu * menu, UWORD id, ULONG value, ULONG mask);
	APTR APICALL (*AddAllocBitmapPatch)(struct DOpusIFace *Self, struct Task * task, struct Screen * screen);
	void APICALL (*RemAllocBitmapPatch)(struct DOpusIFace *Self, APTR handle);
	BOOL APICALL (*LoadPos)(struct DOpusIFace *Self, char * name, struct IBox * pos, short * font);
	BOOL APICALL (*SavePos)(struct DOpusIFace *Self, char * name, struct IBox * pos, short font);
	void APICALL (*DivideU64)(struct DOpusIFace *Self, UQUAD * num, ULONG div, UQUAD rem, UQUAD quo);
	void APICALL (*ItoaU64)(struct DOpusIFace *Self, UQUAD * num, char * str, int str_size, char sep);
	void APICALL (*DivideToString64)(struct DOpusIFace *Self, char * string, int str_size, UQUAD * bytes, ULONG div, int places, char sep);
	void APICALL (*BytesToString64)(struct DOpusIFace *Self, UQUAD * bytes, char * string, int str_size, int places, char sep);
	short APICALL (*RenderImageTags)(struct DOpusIFace *Self, struct RastPort * rp, APTR image, UWORD left, UWORD top, ...);
	struct Hook * APICALL (*GetEditHookTags)(struct DOpusIFace *Self, ULONG type, ULONG flags, ...);
	APTR APICALL (*OpenProgressWindowTags)(struct DOpusIFace *Self, ...);
	void APICALL (*SetProgressWindowTags)(struct DOpusIFace *Self, APTR win, ...);
	void APICALL (*GetProgressWindowTags)(struct DOpusIFace *Self, APTR win, ...);
	struct RexxMsg * APICALL (*BuildRexxMsgExTags)(struct DOpusIFace *Self, struct MsgPort * port, UBYTE * extension, UBYTE * host, ...);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* DOPUS5_INTERFACE_DEF_H */
