# Unique-Identifier-Batch-File-Renamer
C++ program that can rename files in batch based on a unique identifier.

A year ago, I decided to sync my files to my hard drive using window's File History.
I wiped my entire laptop with the belief that i could simply transfer the files back unto
the computer, and i did.. and it worked. Cool story right?
A couple weeks later i went to open a song that i had recorded on Audacity and it said that
i was missing about 789 ".au" files that was needed to open the project. Getting to the root
of the problem, i realized that not only were the ".au" files timestamped with the date and 
time of the file sync, but EVERYTHING, all files, were timestamped like so:

01fe3ff3.au  -->   01fe3ff3 (2015_09_12_6_00_UTC).au
allTxtDocs.txt --> allTxtDocs (2015_09_12_6_00_UTC).txt
anyKindOfCode.c --> anyKindOfCode (2015_09_12_6_00_UTC).c

This proved to be very problematic as there were an average of 800 ".au" files per song
and I had recorded over 50 songs with multiple artists over the span of a year, and not 
to mention C files that i couldn't reference from inside other programs anymore. At first,
I thought I was doomed. Then i got some hope and started chipping away, only removing the
timestamp and not changing the hex numbers on each of about 40,000 ".au" files.
Windows does provide a way to batch rename files, but it renames all the files with the 
same name. After months of chipping away slowly at these files, again i thought i was doomed
and gave up on the process. I went on to make more projects and tried to forget about the loss, 
until 2 days ago when i desperately needed access to a song I had previously recorded.
After 4 hours of slowly chipping again, i knew there had to be a better way. I put together
this C++ program and have tested it countless times with up to 5,000,000 files with no fail.
The program reads a file name up to a certain unique identifier (in my case, i noticed that
there was a space before the timestamps) and removes everything after, and the unique
identifier. The program is built with fail safes. If a renaming error occurs or if a file is 
about to be renamed with the wrong name, the program will print the error and stop.

01fe3ff3 (2015_09_12_6_00_UTC).au --> 01fe3ff3.au
allTxtDocs (2015_09_12_6_00_UTC).txt --> allTxtDocs.txt
anyKindOfCode (2015_09_12_6_00_UTC).c --> anyKindOfCode.c

My problem was solved! Opening one timestamped project was a process that took 6 hours, now it took 2 seconds.
