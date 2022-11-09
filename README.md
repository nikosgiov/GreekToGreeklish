# GreekToGreeklish

# Instructions
Make sure to use : ISO-8859-7:1987 (Latin/Grek)<br />
To compile : make all<br />
To delete executable : make clean<br />
To execute : ./translate < yourfiletotranslate.txt<br />
        or : cat yourfiletotranslate.txt | translate

# Implementation

Translator is implemented as a finite state machine (FSM), with the different states being enumerations.
I used an array of pointers to functions, where each function is a state of our FSM and parses the current
character accordingly and obviously updates the current state if our FSM.