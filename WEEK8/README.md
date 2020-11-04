# WEEK8 Assignments
	This folder contains Week8 assignments.

## Assignment

The queue system for QelizXidmet - a not so successful competitor to AsanXidmet.
At QelizXidmet instead of making their customers' queuing experience as easy as possible they do the opposite.
A basic text based UI and the underlying queue system are designed in this program.

***1. The UI:***   
After every action the UI prints the current queue of the waiting persons.
The UI should be implemented inside a while loop that keeps looping and accepting user input until the program needs to finish.
The UI also lets the operator to type the key "quit" which will end the program. 

***2. The Queue:***  
The program should start with a queue of 5 people already in it.
When a person is selected as the lucky customer they are moved to the end of the queue which means they will be served the last.
The ui will let the operators of the QelizXidmet queue to keep entering people's names and move them to the back of the queue just to be able to mess with them.

***3. Features:***  
The UI lets the operator enter any name and that person is chosen as a lucky customer.  
Every time a person is selected as the lucky customer they are moved to the back of the queue.  
The ui also lets the operator to type "admit" which admits the first person in the queue into QelizXidmet therefore removing that person from the queue.   
Before quitting the program, any dynamic memory needs to be freed with free() and any pointer used to point there set to NULL. 
