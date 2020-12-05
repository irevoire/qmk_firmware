#include <stddef.h>

void uncompress(const char *data, size_t len, char *output) {
	size_t current_pos_in_output = 0;

	for (size_t i = 0; i < len; i++) {
		char byte = data[i];
		int mode = byte >> 7;
		int n = byte & 0b01111111;

		if (mode) {
			for (size_t tmp = 0; tmp < n; tmp++) {
				output[current_pos_in_output++] = data[++i];
			}
		}
		else {
			char next = data[++i];

			for (size_t tmp = 0; tmp < n; tmp++) {
				output[current_pos_in_output++] = next;
			}
		}
	}
}

void undiff(const char *base, char *other, size_t len) {
	for (size_t i = 0; i < len; i++) {
		other[i] = base[i] - other[i];
	}
}

