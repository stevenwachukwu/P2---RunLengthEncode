Data Structures
Program 2: Run Length Compression

1 Goals of this Assignment
1. To implement the compression algorithm that matches the decompression
algorithm from Program 1.
2. To use file I/O in C++ (open, read a char, test for eof).
3. To use an acceptable coding style: no goto, no global variables, proper
indentation, and reasonable names.
4. To understand and use a type cast to create a 1-byte integer.
1.1 Review: Run Length Compression
This algorithm is effective on text or binary files that have the same byte repeated over and
over. Think of a file containing a table of numbers: it has lots of consecutive space
characters, and may have a repeated filler character, such as a ‘.’ .
In this scheme, any “run” of the same character (4 or more identical consecutive bytes)
is replaced by a triplet of bytes, consisting of
1. An escape character. We will use 0x7f, which is sometimes called “esc”. It is a non-
printing ASCII character.
2. The letter that has been repeated.
3. A 1-byte count = the number of repetitions.
To make this work, any esc character, or run of them, that occurs in the input must also
be replaced by a triplet: esc esc count .
Does it Compress? There is a general theoretical result that no algorithm can compress
all files while maintaining all the information in the file. Consider all sequences of N bits:
there are 2n different sequences, and you cannot represent all of them in fewer than N
bits. The best we can do is compress MOST files (at the cost of lengthening some) or
maintain all SIGNIFICANT information. Formats such as mp3 and jpg do throw away
information; they are called “lossy encodings”.
So it makes sense to ask what kind of files can/cannot be compressed using run-
length encoding. This representation does not throw away any bits – therefore it cannot
compress all files. What files CAN be compressed?
• If the input file contains no “esc” characters:
1. If one or more runs of length 4 or more exist: the output file will be shorter.
2. If the file contains no runs of length 4 or more: the output will be identical to
the input file
• If the input file contains runs of 1 or 2 “esc” characters, the output file will be longer
unless those short runs are balanced by longer runs.
1.2 The Compression Algorithm.
Your job is to implement the compression algorithm:
1. At all times, keep a “prior char” variable to compare to the “current char” read from the
input. Also maintain a short-integer “runCount”.
2. To begin, set the runCount to 1 and read the first input char into priorChar using a
method that does NOT skip whitespace.
3. Now enter a processing loop.
(a) Read a character into currentChar (do not skip whitespace). If it is the same as
priorChar:
• If the run counter has reached 255, write a triplet and reinitialize the
counter to 1.
• Else increment the run counter.
(b) If currentChar is different from priorChar:
• If the runCount is 1, 2, or 3, write out priorChar 1, 2, or 3 times.
• Else (the count is 4 or more) write out a triplet and reinitialize runCount to
1.
• In both cases, save currentChar in priorChar.
4. When end of file occurs, write out the last triplet or write the last char (priorChar) an
appropriate number of times.
5. Please note: if you handle the end of file wrong, the last character of your output
will be wrong.
If you have questions, email them to me. All programming in this course will be done in
C++. This assignment involves file I/O which must be done using the C++ I/O libraries.
Standards for style, organization, and OO usage will increase gradually throughout the
term. For this program, do it simply. You do not need any classes or structs. You can do
the whole thing in main().
