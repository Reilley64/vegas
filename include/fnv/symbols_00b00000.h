#pragma once

class BSWin32TaskletManager;

// 0x00b00a00
::BSWin32TaskletManager &GetTaskletManager();
// 0x00b00c90
void CallVfn1OnAllEntries(void *);
// 0x00b00d50
char FUN_00b00d50(void *);
// 0x00b00da0
char QueueTasklet(void *);
