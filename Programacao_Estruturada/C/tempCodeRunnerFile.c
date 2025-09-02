

void aloca_int(float **p, int tam)
{
  if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL)