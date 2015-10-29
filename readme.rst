Requirement
-----------
implement 3 code.

   1. Triangle 
   2. NextDate
   3. Commission

This homework requires

   1. develop in TDD 
   2. analysis
   
      A. boundary value
      B. equivalence class 
      C. edge values
      D. decision table based
   
   3. HW document & code
   
      A. draft in st2015.hackpad.com
      B. formal in google doc
      C. code in github.com (each stages)
   
         - test fail
         - writing new feature code
         - test pass
         - fix bug
         - regression

Google Test Framework 
----------------------
1. installation::

   [archlinux]
   pacman -S community/gtest

2. usage

   A. ``include "gtest/gtest.h"``
   B. linker option: ``-lgtest``

How to run this hw
------------------
1. install google test framework, see above.
2. build it

   A. if you want to do unittest::
   
       make

   B. if you want to test functionality::
      
       make example_use

3. run it::
   
   make run
