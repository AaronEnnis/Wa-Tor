# Wator
Software Development Year 4 Project<br /> 
Concurrent Device Development Module<br /> 
Aaron Ennis & Lorcan Bermingham<br /> 
(C00190504) & (C00196903)

# Description

Re-create the famous Wa-Tor program in C++ and then optimised it with thread parallelism

# Setup

We decided to use the SFML graphics library over just OpenGL alone as it gives more options.

To install SFML on UBUNTU:

sudo apt-get install libsfml-dev

Download SFML, Open the downloaded directory in terminal, enter:

sudo cp -r include/SFML /usr/include

sudo cp -r /lib/* /usr/lib 

sudo cp -r share/SFML /usr/share

This will add the libraries to your HDD and allow you to compile the Wa-Tor program.


# Run

To compile the programe, open a terminal in the working directory and enter the command "make" and then "./main"

To remove all of the object files in the working directory, use the command "make CLEAN" in the terminal.

chmod 755 ./profile.sh first to run this file via command line

This file will clean, build and run the program and produce a valgrind profiling report on compleation.

The valgrind report can be viewed with kcachegrind GUI tool

To install profiling tools:

sudo apt-get update

sudo apt install valgrind

sudo apt install kcachegrind

see profile.sh for more info on the profiling.

# Create Doxygen

First you need to open the Doxyfile and edit OUTPUT_DIRECTORY to the working directory + "/docs" (i.e /home/aaron/Desktop/Wator/docs)

and then INPUT to the working directory (i.e /home/aaron/Desktop/Wator)

If you type 'make DOC' in a terminal in the working directory, the make file will compile the Doxygen code and it will display the Doxygen via Mozilla Firefox.

# Debugging

If you type 'make DEBUG' in to the terminal in the working directory you can enter debug mode.