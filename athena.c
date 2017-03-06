/*****************************************************
 *
 *                simple.c
 *
 *  A very simple X program that uses the Athena
 *  widgets
 *
 ****************************************************/

#include <X11/StringDefs.h>
#include  <X11/Intrinsic.h> 
#include  <X11/Xaw/Command.h> 

main(argc,argv)
int argc;
char **argv; {
     Widget toplevel;
     Widget command;
     void quit();

     toplevel = XtInitialize(argv[0],"simple",NULL, 0,
	 &argc, argv);

     command = XtCreateManagedWidget("press and die",
	 commandWidgetClass, toplevel, NULL, 0);

     XtAddCallback(command,XtNcallback,quit, NULL);

     XtRealizeWidget(toplevel);

     XtMainLoop();

}


void quit(w,client,call)
Widget w;
XtPointer client;
XtPointer call; {

     exit(0);

}
