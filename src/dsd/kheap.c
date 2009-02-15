#include "kheap.h"

extern u32int end;
u32int placement_address = (u32int)&end;

u32int kmalloc_int(u32int sz, u32int align, u32int *phys)
{
  if (align == 1 && (placement_address & 0xFFFFF000)) // If the address is not already page-aligned
  {
    // Align it.
    placement_address &= 0xFFFFF000;
    placement_address += 0x1000;
  }
  if (phys)
  {
    *phys = placement_address;
  }
  u32int tmp = placement_address;
  placement_address += sz;
  return tmp;
}


// page aligned.
u32int kmalloc_a(u32int sz){
    return kmalloc_int(sz,1,0);
}


// returns a physical address.
u32int kmalloc_p(u32int sz, u32int *phys){
    return kmalloc_int(sz,0,phys);
}

// page aligned and returns a physical address.
u32int kmalloc_ap(u32int sz, u32int *phys){
    return kmalloc_int(sz,1,phys);
}


// vanilla (normal).
u32int kmalloc(u32int sz){
    return kmalloc_int(sz,0,0);
}


