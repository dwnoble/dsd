// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
// Based off of JamesM's tutorials 

#include "monitor.h"
#include "string.h"
#include "timer.h"

// All our initialisation calls will go in here.
int main(struct multiboot *mboot_ptr)
{
	/* Testing memcpy
	char *string = "Greetings, Worldly world!";
	char buff[100];
	memcpy(buff,string,26);
	monitor_clear();
	monitor_write(buff);
*/

	// Initialise all the ISRs and segmentation
	
	// Initialise the screen (by clearing it)
	//monitor_clear();
	// Write out a sample string
	
//	monitor_write("HELLO, world!\n");
	
	monitor_clear();
	init_descriptor_tables();
	//asm volatile("int $0x3");
	//asm volatile("int $0x4");
	// Enable interrupts
	asm volatile("sti");
	init_timer(50); // Initialise timer to 50Hz
	
	return 0xDEADBABA;
}
