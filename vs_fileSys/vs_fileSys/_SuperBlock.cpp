#include "_SuperBlock.h"

void s_init(_superBlock *s)
{
	s->s_fsize = Disk::diskCapacity / 512;
	s->s_isize = 128;
	s->s_ninode = s->s_isize * (512 / 64);
	s->s_nfree = s->s_fsize - s->s_isize - 1;
}
