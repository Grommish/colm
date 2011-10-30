/*
 *  Copyright 2007-2011 Adrian Thurston <thurston@complang.org>
 */

/*  This file is part of Colm.
 *
 *  Colm is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  Colm is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with Colm; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

#ifndef __COLM_PROGRAM_H
#define __COLM_PROGRAM_H

#include <colm/pdarun.h>

typedef struct ColmRuntimeData
{
	LangElInfo *lelInfo;
	long numLangEls;

	ProdInfo *prodInfo;
	long numProds;

	RegionInfo *regionInfo;
	long numRegions;

	Code *rootCode;
	long rootCodeLen;

	FrameInfo *frameInfo;
	long numFrames;

	FunctionInfo *functionInfo;
	long numFunctions;

	PatReplInfo *patReplInfo;
	long numPatterns;

	PatReplNode *patReplNodes;
	long numPatternNodes;

	GenericInfo *genericInfo;
	long numGenerics;

	long argvGenericId;

	const char **litdata;
	long *litlen;
	Head **literals;
	long numLiterals;

	CaptureAttr *captureAttr;
	long numCapturedAttr;

	FsmTables *fsmTables;
	PdaTables *pdaTables;
	int *startStates;
	int *eofLelIds;
	int *parserLelIds;
	long numParsers;

	long globalSize;

	long firstNonTermId;

	long integerId;
	long stringId;
	long anyId;
	long eofId;
	long noTokenId;
} RuntimeData;


typedef struct ColmProgram
{
	int argc;
	const char **argv;

	unsigned char ctxDepParsing;
	RuntimeData *rtd;
	Tree *global;
	long nextIlGen;
	int induceExit;
	int exitStatus;

	PoolAlloc kidPool;
	PoolAlloc treePool;
	PoolAlloc parseTreePool;
	PoolAlloc listElPool;
	PoolAlloc mapElPool;
	PoolAlloc headPool;
	PoolAlloc locationPool;
	PoolAlloc ilPool;

	Tree *trueVal;
	Tree *falseVal;

	Kid *heap;

	Tree **se;

	Stream *stdinVal;
	Stream *stdoutVal;
	Stream *stderrVal;

	RunBuf *allocRunBuf;

	Tree **vm_stack;
	Tree **vm_root; 

	/* Returned from the main line. */
	Tree *returnVal;
} Program;

#endif
