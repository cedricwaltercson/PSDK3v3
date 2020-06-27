/**
 * \kernelgroup{SceProcessmgr}
 * \usage{psp2kern/kernel/processmgr.h,SceProcessmgrForKernel_stub}
 */


#ifndef _PSP2_KERNEL_PROCESSMGR_H_
#define _PSP2_KERNEL_PROCESSMGR_H_

#include <psp2kern/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** UID of the current process */
#define SCE_KERNEL_PROCESS_ID_SELF 0

/** UID of the kernel process */
#define SCE_KERNEL_PROCESS_ID_KERNEL 0x10005

typedef struct SceKernelProcessInfo {
	SceSize size;           //!< size of this struct, make sure it's 0xE8
	SceUID pid;             //!< our process ID
	int unk1;
	int unk2;
	int unk3;
	SceUID ppid;            //!< parent process ID
	int unk[0xE8 / 4 - 6];  //!< the rest is unknown
} SceKernelProcessInfo;

void *ksceKernelGetProcessKernelBuf(SceUID pid);

int ksceKernelGetProcessInfo(SceUID pid, SceKernelProcessInfo *info);

int ksceKernelCreateProcessLocalStorage(const char *name, SceSize size);
void *ksceKernelGetProcessLocalStorageAddr(int key);
int ksceKernelGetProcessLocalStorageAddrForPid(SceUID pid, int key, void **out_addr, int create_if_doesnt_exist);

/**
 * @brief       Launch an application
 * @param[in]   titleid The TitleId of the app to open.
 * @param[in]   flags Some unknown flags.
 * @param[in]   path Path of the eboot.bin to launch.
 * @param[in]   unk Unknown.
 * @return      PID of the launched app on success, < 0 on error.
 */
SceUID ksceKernelLaunchApp(char* titleid, uint32_t flags, char *path, uint32_t unk);

/**
 * @brief       Resume a suspended process.
 * @param[in]   pid The process to resume.
 * @return      Zero on success, < 0 on error.
 */
int ksceKernelResumeProcess(SceUID pid);

/**
 * @brief       Suspend a running process.
 * @param[in]   pid The process to suspend.
 * @param[in]	status The new status for the process.
 * @return      Zero on success, < 0 on error.
 */
int ksceKernelSuspendProcess(SceUID pid, int status);

/**
 * @brief       Get the status of a given process.
 * @param[in]   pid The process ID to query.
 * @param[out]  status The bit field status of the process.
 * @return      Zero on success, < 0 on error.
 */
int ksceKernelGetProcessStatus(SceUID pid, int *status);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_KERNEL_PROCESSMGR_H_ */

