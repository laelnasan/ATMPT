/* 
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 NASAN 
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#ifndef ATMPT_H
#define ATMPT_H

#include<errno.h>
#include"nsnlog.h"

#define ATMPT(TYPE) \
	int _ERROR_HANDLER = 0;\
	TYPE atmpt_return
/*  OBS: if try is not used atmpt_return is not defined */

#define ERROR \
	handleerror:\
	switch(_ERROR_HANDLER) /* this is how we handle it*/

#define try atmpt_return = 

#define __proto_check(COND, F_MSG_FUNC, F_MSG, ...) do{\
	if(COND){\
		F_MSG_FUNC(F_MSG, ##__VA_ARGS__);\
		errno=0;\
		_ERROR_HANDLER = __LINE__;\
		goto handleerror;\
	}}while(0)

#define check(A, M, ...)\
	__proto_check(A, log_err, M, ##__VA_ARGS__)

#define check_mem(A) check((A), "Out of memory.")

#define check_dbg(A, M, ...) \
	__proto_check(A, log_dbg, M, ##__VA_ARGS__)	

#endif
