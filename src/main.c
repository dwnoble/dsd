// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
// Based off of JamesM's tutorials 

#include "monitor.h"
#include "string.h"

// All our initialisation calls will go in here.
int main(struct multiboot *mboot_ptr)
{
	char *string = "Greetings, Worldly world!";
	char buff[100];
	
	memcpy(buff,string,26);
	
	monitor_clear();
//	monitor_write("Greetings, World!");
	monitor_write(buff);
	
  return 0xDEADBABA;
}
