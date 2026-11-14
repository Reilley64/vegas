#pragma once

struct JobOut;
struct JobSrc;

// 0x00df9880
unsigned int CopyAndAdvance(unsigned int, unsigned int, char *, int *);
// 0x00df9920
int FUN_00df9920(void *, void *, ::JobSrc *, ::JobOut *);
