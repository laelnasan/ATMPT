/*

The MIT License (MIT)

Copyright (c) 2016 NASAN 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/* NSNLOG.H 
 * nsnlog.h is a collection of definitions that helps manageing error log
 * Nasan - 2016.01.30
 */
#ifndef NSN_LOG_H
#define NSN_LOG_H

#include<stdio.h>
#include<errno.h>
#include<string.h>

#define log_print(HEAD, MSG, ...) fprintf(stderr, HEAD " %s:%d: " MSG "\n",__FILE__, __LINE__, ##__VA_ARGS__)

#ifdef NDEBUG
#define log_dbg(M, ...) while(0)
#else
#define log_dbg(M, ...) log_print("DEBUG", M, ##__VA_ARGS__)
#endif

#define log_info(M, ...) log_print("[INFO] (", ") " M, ##__VA_ARGS__)

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) log_print("[ERROR] (", "errno: %s ) " M, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) log_print("[WARN] (", "errno: %s ) " M, clean_errno(), ##__VA_ARGS__)

#endif
