/*
** strvmerge.c for 42sh
**
** Made by Seblu
** Login   <seblu@epita.fr>
**
** Started on  Sun Jul 30 04:03:35 2006 Seblu
** Last update Thu Aug  3 05:29:38 2006 Seblu
*/

#include <string.h>
#include "mem.h"

char			*strvmerge(const char *const *vtable)
{
  size_t		string_sz = 0;
  const char *const	*elem;
  char			*new;

  for (elem = vtable; *elem; ++elem)
    string_sz += strlen(*elem);
  secmalloc(new, ++string_sz * sizeof (char));
  string_sz = 0;
  for (elem = vtable; *elem; ++elem)
    {
      strcpy(new + string_sz, *elem);
      string_sz += strlen(*elem);
    }
  return new;
}
