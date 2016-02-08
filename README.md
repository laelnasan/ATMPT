# ATMPT
A simple set of macros that creates a friendly environment for error handling in C inspired by the Awesome Debug Macros of Zed A. Shaw. 

# What it does
**ATMPT** sets two variables, one for error identification and the other for function return storage. The first is a simple int type that increments it-self by 1 (starting from 0) every time a `check()` is made. A `check()` verifies a condition, if it comes to be true it may call `fprintf()` for `stderr` and always skip to `ERROR`. If it is false the error counter is increased by 1. For the log calls atmpt uses my other set of macros called nsnlog that is also found here.
The second variable is used for function return storage. It is just an attempt to reduce coding and may be removed together with `try` with no great penalties to the code. But it lets you do cool stuff like:

```C
int main(void){ 
  char* some_input;
  ...
  
  /***** start the environment and atributes a value to atmpt_return *****/
  ATMPT(object*) = function_that_returns_object(v,a,r,i,a,b,l,e,s);

  /***** check() verifies a condition, if true calls fprintf() and skip to ERROR() *****/
  check(atmpt_return == NULL, "Some shit happend: %s", object_error_description()); // error 0
  check(scanf("%s", some_input)==0, "No input"); // error 1
  check(some_function(atmpt_return, some_input) == -1, "Invalid input"); // error 2
  ...

  ERROR{
    case n:
      do_some_error_handling();
    case (n-1):
      something();
    ...
    
    default:
      object_free(atmpt_return);
  }
  return 0;
}
```
The `ERROR` block is just a switch with the error counter as argument. It makes possible to code some fallthrough error handling witch was the first purpose of the macros.

UPDATE: This approach is wrong by design. It only works if the check code happens to be reached in run-time. It makes it mandatory to initiate a new environment in every single new block, as in an if-clause for example. The new way uses the line number where the check was made as argument.
