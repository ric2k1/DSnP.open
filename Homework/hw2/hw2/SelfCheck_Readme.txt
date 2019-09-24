To use the SelfCheck program
============================
1. Download the "SelfCheck" program from Ceina.

2. Download the "MustExist.txt" and "MustRemove.txt" files. Please note that

   for different homework, there are these two files with different contents,

   but with the same file names.

3. Put the your .tgz file, SelfCheck, MustExist.txt and MustRemove.txt in the

   same directory.

4. Type: ./SelfCheck bxxxxxxxx_hw1.tgz 

   For example, ./SelfCheck b77503057_hw1.tgz


What does the program checks
============================
1. The program will check your student ID which is part of your .tgz file.

   The student ID must follow the following rule:

   - The first character must be lower case
 
     and followed by eight digit numbers.

2. The program will check the existence of the files which is specified in

   MustExist.txt.

   If there are some lost files, the program will show error message and

   the lost files.

3. The program will check the absence of the files which is specified in

   MustRemove.txt.

   If there are some redundant files, the program will show error message

   and the redundant file names.

4. Otherwise, it will show "Succeed in self checking."


Note
====

1. The file "MustExist.txt" specifies the files you must include in
   submission. These are usually files where the TODOs reside.

2. The file "MustRemove.txt" specifies the files you must remove from
   submission. They are ususally files that you SHOULD NOT modify for
   your homework.

3. For those files that are neither in "MustExist.txt" nor in
   "MustRemove.txt", it is up to you whether to leave or remove them.
   However, please try to make your submission as slim as possible.

4. Remember to backup your homework before removing files in "MustRemove.txt". 

5. Don't worry we didn't get your complete files. For those in MustRemove.txt,
   we will copy them from reference code for compilation.
