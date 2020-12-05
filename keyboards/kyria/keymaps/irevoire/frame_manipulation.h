// uncompress data into the output vector, you need to be sure your output vector is large enough
void uncompress(const char *data, size_t len, char *output);

// save the result of base - other in other for each values
void undiff(const char *base, char *other, size_t len);

