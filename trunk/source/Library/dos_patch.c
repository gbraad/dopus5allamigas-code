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

#include "dopuslib.h"

//#define DOSBase (data->dos_base)

/********************************** CreateDir **********************************/

// Patched CreateDir()
PATCHED_1(BPTR, ASM L_PatchedCreateDir, d1, char *, name)
{
	struct LibData *data;
	struct MyLibrary *libbase;
	struct FileInfoBlock *fib;
	BPTR lock;

	// Get library
	if (!(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Call original function
	lock=LIBCALL_1(BPTR, data->wb_data.old_function[WB_PATCH_CREATEDIR], DOSBase, IDOS, d1, name);

	// Failed?
	if (!lock) return 0;

	// Get directory information
	if ((fib=dospatch_fib(lock,libbase,1)))
	{
		// Send notification
		L_SendNotifyMsg(DN_DOS_ACTION,0,DNF_DOS_CREATEDIR,0,(char *)(fib+1),fib,libbase);

		// Free info block
		FreeVec(fib);
	}
	
	return lock;
}
PATCH_END


// Calls original CreateDir directly
BPTR LIBFUNC L_OriginalCreateDir(
	REG(d1, char *name),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If patch wasn't installed, call DOS directly
	if (!(data->flags&LIBDF_DOS_PATCH))
		return CreateDir(name);

	// Create directory
	return LIBCALL_1(BPTR, data->wb_data.old_function[WB_PATCH_CREATEDIR], DOSBase, IDOS, d1, name);
}

/********************************** DeleteFile **********************************/

// Patched DeleteFile()
PATCHED_1(long, ASM L_PatchedDeleteFile, d1, char *, name)
{
	struct LibData *data;
	struct MyLibrary *libbase;
	char *buf=0;
	BPTR lock;
	long res;
	APTR wsave=(APTR)-1;
	struct Process *task;
	
	// Get library
	if (!(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Find process
	if ((task=(struct Process *)FindTask(0)))
	{
		// Is it a process?
		if (task->pr_Task.tc_Node.ln_Type==NT_PROCESS)
		{
			// Save pointer and turn requesters off
			wsave=task->pr_WindowPtr;
			task->pr_WindowPtr=(APTR)-1;
		}
		else task=0;
	}

	// Try to lock file to delete
	if ((lock=Lock(name,ACCESS_READ)))
	{
		// Allocate buffer
		if ((buf=AllocVec(512,MEMF_CLEAR)))
		{
			// Get full path
			L_DevNameFromLockDopus(lock,buf,512,libbase);
		}

		// Unlock file
		UnLock(lock);
	}

	// Fix requesters
	if (task) task->pr_WindowPtr=wsave;

	// Call original function
	res=LIBCALL_1(long, data->wb_data.old_function[WB_PATCH_DELETEFILE], DOSBase, IDOS, d1, name);

	// Failed?
	if (!res) return 0;

	// Got name?
	if (buf && *buf)
	{
		// Send notification
		L_SendNotifyMsg(DN_DOS_ACTION,0,DNF_DOS_DELETEFILE,0,buf,0,libbase);
	}

	// Free buffer
	FreeVec(buf);
	return res;
}
PATCH_END


// Original DeleteFile
long LIBFUNC L_OriginalDeleteFile(
	REG(d1, char *name),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If patch wasn't installed, call DOS directly
	if (!(data->flags&LIBDF_DOS_PATCH))
		return DeleteFile(name);

	// Delete file
	return LIBCALL_1(long, data->wb_data.old_function[WB_PATCH_DELETEFILE], DOSBase, IDOS, d1, name);
}


/********************************** SetFileDate **********************************/

// Patched SetFileDate()
PATCHED_2(BOOL, ASM L_PatchedSetFileDate, d1, char *, name, d2, struct DateStamp *, date)
{
	struct LibData *data;
	struct MyLibrary *libbase;
	BOOL res;
	BPTR lock;
	APTR wsave=(APTR)-1;
	struct Process *task;

	// Get library
	if (!(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Call original function
	res=LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_SETFILEDATE], DOSBase, IDOS, d1, name, d2, date);

	// Failed?
	if (!res) return 0;

	// Find process
	if ((task=(struct Process *)FindTask(0)))
	{
		// Is it a process?
		if (task->pr_Task.tc_Node.ln_Type==NT_PROCESS)
		{
			// Save pointer and turn requesters off
			wsave=task->pr_WindowPtr;
			task->pr_WindowPtr=(APTR)-1;
		}
		else task=0;
	}

	// Try to lock file
	if ((lock=Lock(name,ACCESS_READ)))
	{
		struct FileInfoBlock *fib;

		// Get directory information
		if ((fib=dospatch_fib(lock,libbase,0)))
		{
			// Send notification
			L_SendNotifyMsg(DN_DOS_ACTION,0,DNF_DOS_SETFILEDATE,0,(char *)(fib+1),fib,libbase);

			// Free info block
			FreeVec(fib);
		}

		// Unlock file
		UnLock(lock);
	}

	// Fix requesters
	if (task) task->pr_WindowPtr=wsave;

	return res;
}
PATCH_END


// Calls original SetFileDate directly
BOOL LIBFUNC L_OriginalSetFileDate(
	REG(d1, char *name),
	REG(d2, struct DateStamp *date),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If patch wasn't installed, call DOS directly
	if (!(data->flags&LIBDF_DOS_PATCH))
		return (BOOL)SetFileDate(name,date);

	// Set date
	return LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_SETFILEDATE], DOSBase, IDOS, d1, name, d2, date);
}


/********************************** SetComment **********************************/

// Patched SetComment()
PATCHED_2(BOOL, ASM L_PatchedSetComment, d1, char *, name, d2, char *, comment)
{
	struct LibData *data;
	struct MyLibrary *libbase;
	BOOL res;
	BPTR lock;
	APTR wsave=(APTR)-1;
	struct Process *task;

	// Get library
	if (!(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Call original function
	res=LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_SETCOMMENT], DOSBase, IDOS, d1, name, d2, comment);

	// Failed?
	if (!res) return 0;

	// Find process
	if ((task=(struct Process *)FindTask(0)))
	{
		// Is it a process?
		if (task->pr_Task.tc_Node.ln_Type==NT_PROCESS)
		{
			// Save pointer and turn requesters off
			wsave=task->pr_WindowPtr;
			task->pr_WindowPtr=(APTR)-1;
		}
		else task=0;
	}

	// Lock file
	if ((lock=Lock(name,ACCESS_READ)))
	{
		struct FileInfoBlock *fib;

		// Get directory information
		if ((fib=dospatch_fib(lock,libbase,0)))
		{
			// Send notification
			L_SendNotifyMsg(DN_DOS_ACTION,0,DNF_DOS_SETCOMMENT,0,(char *)(fib+1),fib,libbase);

			// Free info block
			FreeVec(fib);
		}

		// Unlock file
		UnLock(lock);
	}

	// Fix requesters
	if (task) task->pr_WindowPtr=wsave;

	return res;
}
PATCH_END


// Calls original SetComment directly
BOOL LIBFUNC L_OriginalSetComment(
	REG(d1, char *name),
	REG(d2, char *comment),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If patch wasn't installed, call DOS directly
	if (!(data->flags&LIBDF_DOS_PATCH))
		return (BOOL)SetComment(name,comment);

	// Set comment
	return LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_SETCOMMENT], DOSBase, IDOS, d1, name, d2, comment);
}


/********************************** SetProtection **********************************/

// Patched SetProtection()
PATCHED_2(BOOL, ASM L_PatchedSetProtection, d1, char *, name, d2, ULONG, mask)
{
	struct LibData *data;
	struct MyLibrary *libbase;
	BOOL res;
	BPTR lock;
	APTR wsave=(APTR)-1;
	struct Process *task;

	// Get library
	if (!(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Call original function
	res=LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_SETPROTECTION], DOSBase, IDOS, d1, name, d2, mask);

	// Failed?
	if (!res) return 0;

	// Find process
	if ((task=(struct Process *)FindTask(0)))
	{
		// Is it a process?
		if (task->pr_Task.tc_Node.ln_Type==NT_PROCESS)
		{
			// Save pointer and turn requesters off
			wsave=task->pr_WindowPtr;
			task->pr_WindowPtr=(APTR)-1;
		}
		else task=0;
	}

	// Lock file
	if ((lock=Lock(name,ACCESS_READ)))
	{
		struct FileInfoBlock *fib;

		// Get directory information
		if ((fib=dospatch_fib(lock,libbase,0)))
		{
			// Send notification
			L_SendNotifyMsg(DN_DOS_ACTION,0,DNF_DOS_SETPROTECTION,0,(char *)(fib+1),fib,libbase);

			// Free info block
			FreeVec(fib);
		}

		// Unlock file
		UnLock(lock);
	}

	// Fix requesters
	if (task) task->pr_WindowPtr=wsave;
	return res;
}
PATCH_END


// Calls original SetProtection directly
BOOL LIBFUNC L_OriginalSetProtection(
	REG(d1, char *name),
	REG(d2, ULONG mask),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If patch wasn't installed, call DOS directly
	if (!(data->flags&LIBDF_DOS_PATCH))
		return (BOOL)SetProtection(name,mask);

	// Set protection
	return LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_SETPROTECTION], DOSBase, IDOS, d1, name, d2, mask);
}


/********************************** Rename **********************************/

// Patched Rename()
PATCHED_2(BOOL, ASM L_PatchedRename, d1, char *, oldname, d2, char *, newname)
{
	struct FileInfoBlock *fib=0;
	struct LibData *data;
	struct MyLibrary *libbase;
	BOOL res;
	BPTR lock;
	char old_name[108];
	APTR wsave=(APTR)-1;
	struct Process *task;

	// Get library
	if (!(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Find process
	if ((task=(struct Process *)FindTask(0)))
	{
		// Is it a process?
		if (task->pr_Task.tc_Node.ln_Type==NT_PROCESS)
		{
			// Save pointer and turn requesters off
			wsave=task->pr_WindowPtr;
			task->pr_WindowPtr=(APTR)-1;
		}
		else task=0;
	}

	// Get lock on old file?
	if ((lock=Lock(oldname,ACCESS_READ)))
	{
		// Get file information
		if (!(fib=dospatch_fib(lock,libbase,0)))
		{
			// Failed to get info
			UnLock(lock);
			lock=0;
		}
	}

	// Fix requesters
	if (task) task->pr_WindowPtr=wsave;

	// Call original function
	res=LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_RENAME], DOSBase, IDOS, d1, oldname, d2, newname);

	// Failure?
	if (!res)
	{
		// Unlock and free fib
		if (fib) FreeVec(fib);
		if (lock) UnLock(lock);
		return res;
	}

	// Got no Fib?
	if (!fib) return res;

	// Store old name
	strcpy(old_name,fib->fib_FileName);

	// Turn requesters off
	if (task) task->pr_WindowPtr=(APTR)-1;

	// Get new information
	if (Examine(lock,fib))
	{
		// Copy new name to comment
		stccpy(fib->fib_Comment,fib->fib_FileName,79);

		// Restore old name
		strcpy(fib->fib_FileName,old_name);

		// Send notification
		L_SendNotifyMsg(DN_DOS_ACTION,0,DNF_DOS_RENAME,0,(char *)(fib+1),fib,libbase);
	}

	// Free info block and lock
	FreeVec(fib);
	UnLock(lock);
	
	// Fix requesters
	if (task) task->pr_WindowPtr=wsave;
	return res;
}
PATCH_END


// Calls original Rename directly
BOOL LIBFUNC L_OriginalRename(
	REG(d1, char *oldname),
	REG(d2, char *newname),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If patch wasn't installed, call DOS directly
	if (!(data->flags&LIBDF_DOS_PATCH))
		return (BOOL)Rename(oldname,newname);

	// Rename file
	return LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_RENAME], DOSBase, IDOS, d1, oldname, d2, newname);
}


/********************************** Relabel **********************************/

// Patched Relabel()
PATCHED_2(BOOL, ASM L_PatchedRelabel, d1, char *, volumename, d2, char *, name)
{
	struct LibData *data;
	struct MyLibrary *libbase;
	struct FileInfoBlock fib;
	BOOL res;

	// Get library
	if (!(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Call original function
	res=LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_RELABEL], DOSBase, IDOS, d1, volumename, d2, name);

	// Failure?
	if (!res) return res;

	// Fake fib with new name
	strcpy(fib.fib_FileName,name);

	// Send notification
	L_SendNotifyMsg(DN_DOS_ACTION,0,DNF_DOS_RELABEL,0,volumename,&fib,libbase);
	return res;
}
PATCH_END


// Calls original Relabel directly
BOOL LIBFUNC L_OriginalRelabel(
	REG(d1, char *volumename),
	REG(d2, char *name),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Relabel disk
	return LIBCALL_2(BOOL, data->wb_data.old_function[WB_PATCH_RELABEL], DOSBase, IDOS, d1, volumename, d2, name);
}


/********************************** Open **********************************/

// Patched Open()
PATCHED_2(BPTR, ASM L_PatchedOpen, d1, char *, name, d2, LONG, accessMode)
{
	struct LibData *data;
	struct MyLibrary *libbase;
	struct FileInfoBlock *fib;
	BPTR file,lock;
	BOOL create=0;
	APTR wsave=(APTR)-1;
	struct Process *task;
	struct FileHandleWrapper *handle;

	// Get library
	if (!(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Find process
	if ((task=(struct Process *)FindTask(0)))
	{
		// Is it a process?
		if (task->pr_Task.tc_Node.ln_Type==NT_PROCESS)
		{
			// Save pointer and turn requesters off
			wsave=task->pr_WindowPtr;
			task->pr_WindowPtr=(APTR)-1;
		}
		else task=0;
	}

	// Check mode
	switch (accessMode)
	{
		// Create?
		case MODE_NEWFILE:
			create=1;
			break;

		// Read/write
		case MODE_READWRITE:

			// If file is going to be created, we use it
			if (!(lock=Lock(name,ACCESS_READ))) create=1;
			else UnLock(lock);
			break;
	}

	// Fix requesters
	if (task) task->pr_WindowPtr=wsave;

	// Call original function
	file=LIBCALL_2(BPTR, data->wb_data.old_function[WB_PATCH_OPEN], DOSBase, IDOS, d1, name, d2, accessMode);

	// Failure?
	if (!file) return file;

	// If file is Interactive, assume it's not a filesystem
	if (IsInteractive(file)) return file;

	// Allocate FileInfoBlock and buffer
	if (!(fib=AllocVec(sizeof(struct FileInfoBlock)+512,MEMF_CLEAR)))
		return file;

	// Disable requesters
	if (task) task->pr_WindowPtr=(APTR)-1;

	// Get lock on parent directory
	if ((lock=ParentOfFH(file)))
	{
		// Allocate wrapper handle
		if ((handle=AllocVec(sizeof(struct FileHandleWrapper),0)))
		{
			// Fill out handle
			handle->fhw_FileHandle=file;
			handle->fhw_Flags=0;
			handle->fhw_Parent=lock;

			// Lock file list
			ObtainSemaphore(&data->file_list.lock);

			// Add to head of list
			AddHead(&data->file_list.list,(struct Node *)handle);

			// Unlock file list
			ReleaseSemaphore(&data->file_list.lock);
		}

		// If this was a create operation, we need to send a message now
		if (create)
		{
			// Get buffer pointer
			char *path=(char *)(fib+1);

			// Get full path of parent, and terminate it
			L_DevNameFromLockDopus(lock,path,512,libbase);
			AddPart(path,"",512);

			// Got path?
			if (*path)
			{
				// Examine the new file
				if (ExamineFH(file,fib))
				{
					// Send notification
					L_SendNotifyMsg(DN_DOS_ACTION,0,DNF_DOS_CREATE,0,path,fib,libbase);
				}
			}
		}

		// Unlock parent, unless handle has grabbed it
		if (!handle) UnLock(lock);
	}

	// Free fib
	FreeVec(fib);

	// Fix requesters
	if (task) task->pr_WindowPtr=wsave;
	return file;
}
PATCH_END


// Calls original Open directly
BPTR LIBFUNC L_OriginalOpen(
	REG(d1, char *name),
	REG(d2, LONG accessMode),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If patch wasn't installed, call DOS directly
	if (!(data->flags&LIBDF_DOS_PATCH))
		return Open(name,accessMode);

	// Open file
	return LIBCALL_2(BPTR, data->wb_data.old_function[WB_PATCH_OPEN], DOSBase, IDOS, d1, name, d2, accessMode);
}


/********************************** Close **********************************/

// Patched Close()
PATCHED_1(BOOL, ASM L_PatchedClose, d1, BPTR, file)
{
	struct LibData *data;
	struct MyLibrary *libbase;

	// Get library
	if (!file || !(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If this is the 'last' file, clear pointer
	if (data->last_file==file)
		data->last_file=0;

	// Is file not interactive (ie a filesystem)?
	if (!IsInteractive(file))
	{
		struct FileHandleWrapper *handle;

		// See if we have a wrapper
		if ((handle=find_filehandle(file,data)))
		{
			// Remove it from the list
			Remove((struct Node *)handle);

			// Unlock the list
			ReleaseSemaphore(&data->file_list.lock);

			// Did the file get written to?
			if (handle->fhw_Flags&FHWF_WRITTEN)
			{
				struct FileInfoBlock *fib;
				APTR wsave=(APTR)-1;
				struct Process *task;

				// Find process
				if ((task=(struct Process *)FindTask(0)))
				{
					// Is it a process?
					if (task->pr_Task.tc_Node.ln_Type==NT_PROCESS)
					{
						// Save pointer and turn requesters off
						wsave=task->pr_WindowPtr;
						task->pr_WindowPtr=(APTR)-1;
					}
					else task=0;
				}

				// Allocate FileInfoBlock and buffer
				if ((fib=AllocVec(sizeof(struct FileInfoBlock)+512,MEMF_CLEAR)))
				{
					char *path=(char *)(fib+1);

					// Get full path of parent and terminate it
					L_DevNameFromLockDopus(handle->fhw_Parent,path,512,libbase);
					AddPart(path,"",512);

					// Got path?
					if (*path)
					{
						// Examine the file
						if (ExamineFH(file,fib))
						{
							// Send notification
							L_SendNotifyMsg(DN_DOS_ACTION,0,DNF_DOS_CLOSE,0,path,fib,libbase);
						}
					}

					// Free fib
					FreeVec(fib);
				}

				// Fix requesters
				if (task) task->pr_WindowPtr=wsave;
			}

			// Unlock parent lock
			UnLock(handle->fhw_Parent);

			// Free wrapper handle
			FreeVec(handle);
		}
	}

	// Close file
	return LIBCALL_1(BOOL, data->wb_data.old_function[WB_PATCH_CLOSE], DOSBase, IDOS, d1, file);
}
PATCH_END


// Calls original Close directly
BOOL LIBFUNC L_OriginalClose(
	REG(d1, BPTR file),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If patch wasn't installed, call DOS directly
	if (!(data->flags&LIBDF_DOS_PATCH))
		return (BOOL)Close(file);

	// Close file
	return LIBCALL_1(BOOL, data->wb_data.old_function[WB_PATCH_CLOSE], DOSBase, IDOS, d1, file);
}


/********************************** Write **********************************/

// Patched Write()
PATCHED_3(LONG, ASM L_PatchedWrite, d1, BPTR, file, d2, void *, wdata, d3, LONG, length)
{
	struct LibData *data;
	struct MyLibrary *libbase;
	struct FileHandleWrapper *handle;

	// Get library
	if (!file || !(libbase=GET_DOPUSLIB)) return 0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Different to the last file we saw?
	if (data->last_file!=file)
	{
		// See if we have a wrapper
		if ((handle=find_filehandle(file,data)))
		{
			// Set 'written' flag
			handle->fhw_Flags|=FHWF_WRITTEN;

			// Unlock the list
			ReleaseSemaphore(&data->file_list.lock);
		}

		// Remember this file
		data->last_file=file;
	}

	// Write data
	return LIBCALL_3(LONG, data->wb_data.old_function[WB_PATCH_WRITE], DOSBase, IDOS, d1, file, d2, wdata, d3, length);
}
PATCH_END


// Calls original Write directly
LONG LIBFUNC L_OriginalWrite(
	REG(d1, BPTR file),
	REG(d2, void *wdata),
	REG(d3, LONG length),
	REG(a6, struct MyLibrary *libbase))
{
	struct LibData *data;

	#ifdef __amigaos4__
	libbase = dopuslibbase_global;
	#endif
	
	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// If patch wasn't installed, call DOS directly
	if (!(data->flags&LIBDF_DOS_PATCH))
		return Write(file,wdata,length);

	// Write data
	return LIBCALL_3(LONG, data->wb_data.old_function[WB_PATCH_WRITE], DOSBase, IDOS, d1, file, d2, wdata, d3, length);
}


/******************************************************************************/

// Get information on a filelock
struct FileInfoBlock *dospatch_fib(BPTR lock,struct MyLibrary *libbase,BOOL req)
{
	struct FileInfoBlock *fib=0;
	struct LibData *data;
	BPTR parent;
	BOOL ok=0;
	APTR wsave=(APTR)-1;
	struct Process *task=0;

	// Get data pointer
	data=(struct LibData *)libbase->ml_UserData;

	// Find process
	if (req && (task=(struct Process *)FindTask(0)))
	{
		// Is it a process?
		if (task->pr_Task.tc_Node.ln_Type==NT_PROCESS)
		{
			// Save pointer and turn requesters off
			wsave=task->pr_WindowPtr;
			task->pr_WindowPtr=(APTR)-1;
		}
		else task=0;
	}

	// Get parent directory
	if ((parent=ParentDir(lock)))
	{
		// Get FileInfoBlock and a buffer
		if ((fib=AllocVec(sizeof(struct FileInfoBlock)+512,MEMF_CLEAR)))
		{
			char *buf;

			// Get buffer pointer
			buf=(char *)(fib+1);

			// Get full path of parent, and terminate it
			L_DevNameFromLockDopus(parent,buf,512,libbase);
			AddPart(buf,"",512);

			// Got path?
			if (*buf)
			{
				// Examine the lock
				if (Examine(lock,fib)) ok=1;
			}
		}

		// Not ok?
		if (!ok)
		{
			FreeVec(fib);
			fib=0;
		}

		// Unlock parent
		UnLock(parent);
	}

	// Fix requesters
	if (task) task->pr_WindowPtr=wsave;
	return fib;
}

// Find FileHandle in tracking list
struct FileHandleWrapper *find_filehandle(BPTR file,struct LibData *data)
{
	struct FileHandleWrapper *handle;

	// Lock list
	ObtainSemaphore(&data->file_list.lock);

	// Go through list
	for (handle=(struct FileHandleWrapper *)data->file_list.list.lh_Head;
		handle->fhw_Node.mln_Succ;
		handle=(struct FileHandleWrapper *)handle->fhw_Node.mln_Succ)
	{
		// Match handle
		if (handle->fhw_FileHandle==file)
		{
			// Not the top one?
			if (handle!=(struct FileHandleWrapper *)data->file_list.list.lh_Head)
			{
				// Shift it to the top as the most recently accessed
				Remove((struct Node *)handle);
				AddHead(&data->file_list.list,(struct Node *)handle);
			}

			// Return the handle (leave the list locked)
			return handle;
		}
	}

	// Not found
	ReleaseSemaphore(&data->file_list.lock);
	return 0;
}
