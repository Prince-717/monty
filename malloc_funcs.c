#include "monty.h"
/**
 * stk_calloc - concatenate tw strings specially
 * @nmemb: number of elements
 * @dimension: type of elements
 * Return: nothing
 */
void *stk_calloc(unsigned int nmemb, unsigned int dimension)
{
	void *pp = NULL;
	unsigned int i;

	if (nmemb == 0 || dimension == 0)
	{
		return (NULL);
	}
	pp = malloc(nmemb * dimension);
	if (pp == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmemb * dimension); i++)
	{
		*((char *)(pp) + i) = 0;
	}
	return (pp);
}
/**
 * reallocate - change the dimension and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *reallocate(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pp = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		pp = malloc(new_size);
		if (!pp)
			return (NULL);
		return (pp);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		pp = malloc(new_size);
		if (!pp)
			return (NULL);
		for (i = 0; i < old_size; i++)
			pp[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		pp = malloc(new_size);
		if (!pp)
			return (NULL);
		for (i = 0; i < new_size; i++)
			pp[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (pp);
}
