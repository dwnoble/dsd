// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
// Based off of JamesM's tutorials 

#include "monitor.h"
#include "string.h"
#include "timer.h"
#include "paging.h"
#include "kheap.h"

// All our initialisation calls will go in here.
int main(struct multiboot *mboot_ptr)
{
	monitor_clear();

	// Initialise all the ISRs and segmentation
	//init_descriptor_tables();
	//asm volatile("int $0x3");
	//asm volatile("int $0x4");
	// Enable interrupts
	//asm volatile("sti");
	//init_timer(50); // Initialize timer to 50Hz
	

 	// Initialise all the ISRs and segmentation
	init_descriptor_tables();
	// Initialise the screen (by clearing it)
	monitor_clear();

	initialize_paging();
	monitor_write("Hello, paging world!\n");

	u32int *ptr = (u32int*)0xA0000000;
	u32int do_page_fault = *ptr;

	return 0;

//	return 0xDEADBABA;
}
