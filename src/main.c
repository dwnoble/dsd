// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
// Made for JamesM's tutorials 

#include "monitor.h"

// All our initialisation calls will go in here.
int main(struct multiboot *mboot_ptr)
{
	monitor_clear();
	monitor_write("Greetings, World!");
	
  return 0xDEADBABA;
}
