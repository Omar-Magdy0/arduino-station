# arduino-station

*BIGANT is proud to introduce the ATSTATION* 
a mini General purpose control with a screen,button and a potentionmeter(more or less are optional) for basic user interface where you can have your own code and programs that run on the MCU just like an arduino . 

*THE code*
WELL here we have a base code where you can have your multiple programs run on the MCU easily because We have included what we call an applicationManager() that manages the functionalies you are going to add and
a Bootloader() that manages initializations and loading screen and whatever you want to run before the applicationManager();

*LET ME EXPLAIN*
lets say you want to have a PID temperature controller , an oscilloscope , a stepper motor controller (whatever you can think off)

you make a .cpp file that has the function that describes your program and is going to loop indefinetly and if needed a function that will run once at start for each functionality you want 
then head to the configuration.h file and uncomment the define statement and modify the appManagerlist as you want.
