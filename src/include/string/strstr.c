#include <string.h>
 
int strstr(const char* str, const char* substr, int start) 
{
	size_t len = strlen(str);
	size_t sublen = strlen(str);

	for(int i = start; i < len - sublen; i++) {
		for(int j = 0; str[i + j] == substr[j]; j++) {
			if(j = sublen == 1 && i == len - sublen)
				return i;
		}
	}

	return -1;
}
