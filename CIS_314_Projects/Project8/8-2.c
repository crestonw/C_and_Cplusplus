// Author: Creston Wilson
// CIS 314

#include <stdio.h>
#include <stdlib.h>

struct Block
{
	unsigned char valid[4];
	unsigned int tag;
	unsigned char value;
};

unsigned int getOffset(unsigned int address)
{
	return address & 0x0000000F;
}

unsigned int getSet(unsigned int address)
{
	return address & 0x7FFFFFF0;
}

unsigned int getTag(unsigned int address)
{
	return address & 0x80000000;
}

void main()
{
	struct Block *cache = (struct Block*) malloc(16*sizeof(struct Block));
	char buffer[256];
	char c;
	unsigned int addSet;
	unsigned int addTag;
	unsigned char val;

	do {
		printf("Enter 'r' for read, 'w' for write, 'p' to print, and 'q' to quit: ");
		fgets(buffer, 256, stdin);
		c = buffer[0];

		if (c == 'w')
		{
			printf("Enter 32-bit unsigned hex address: ");
			fgets(buffer, 256, stdin);
			addSet = getSet((unsigned int) buffer[0]);
			addTag = getTag((unsigned int) buffer[0]);

			printf("Enter 32-bit unsigned hex value: ");
			fgets(buffer, 256, stdin);
			val = (unsigned char) buffer[0];

			if(sizeof(cache) >= addSet)
			{
				printf("evicting block - set: %i - tag: %i - valid: %c - value: %x\n", addSet, addTag, cache[addSet].valid, val);
				struct Block cache[addSet];
				cache[addSet].valid = 1;
				cache[addSet].tag = addTag;
				cache[addSet].value = val;

				printf("wrote set - set: %i - tag: %i - valid: %c - value: %x\n", addSet, addTag, 1, val);
			}

			else
			{
				struct Block cache[addSet];
				cache[addSet].valid = 1;
				cache[addSet].tag = addTag;
				cache[addSet].value = val;
				
				printf("wrote set - set: %i - tag: %i - valid: %c - value: %x\n", addSet, addTag, 1, val);
			}


		} else if (c == 'r')
		{
			printf("Enter 32-bit unsigned hex address: ");
			fgets(buffer, 256, stdin);
			addSet = getSet((unsigned int) buffer[0]);
			addTag = getTag((unsigned int) buffer[0]);

			printf("looking for set: %i - tag: %i\n", addSet, addTag);

			if(sizeof(cache) > addSet)
			{
				if(cache[addSet].tag == addTag)
				{
					printf("found set: %i - tag: %i - offset: %i - valid: %c - value: %x\n", addSet, cache[addSet].tag, cache[addSet].valid, cache[addSet].value);
					printf("hit!\n");
				}
				else if(cache[addSet.tag != addTag])
				{
					printf("found set: %i - tag: %i - offset: %i - valid: %c - value: %x\n", addSet, cache[addSet].tag, cache[addSet].valid, cache[addSet].value);
					printf("tags don't match - miss!\n");
				}
			}

			else
			{
				printf("no valid set found - miss!\n");
			}

		} else if (c == 'p')
		{
			for (size_t i = 0; i < sizeof(cache); i++)
			{
				if (cache[i].valid)
				{
					printf("set: %i - tag: %i - valid: %c - value: %x\n", i, cache[i].tag, cache[i].valid, cache[i].value);
				}
			}
		}

	}
	while(c != 'q');
	printf("done\n");

}
