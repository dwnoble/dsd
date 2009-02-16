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
    /*
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
	*/

    // Initialise all the ISRs and segmentation
    init_descriptor_tables();
    // Initialise the screen (by clearing it)
    monitor_clear();
    u32int a = kmalloc(8);
    initialize_paging();
    u32int b = kmalloc(8);
    u32int c = kmalloc(8);
    monitor_write("a: ");
    monitor_write_hex(a);
    monitor_write(", b: ");
    monitor_write_hex(b);
    monitor_write("\nc: ");
    monitor_write_hex(c);

    kfree(c);
    kfree(b);
    u32int d = kmalloc(12);
    monitor_write(", d: ");
    monitor_write_hex(d);

    return 0;
}
