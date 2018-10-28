#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "serial.h"

void secret(void) {
	printf("Access granted\r\n");
}

int main(void) {
	serial_init();

	char const *pwd_store = "password";
	char attempt[10] = "\x55\x55\x55\x55\x55\x55\x55\x55\x55\x55";
	
	// Try to overwrite the link register here so that secret() is run
	// even if the password is incorrect
	// 0x08000340
	strcpy(attempt, "AAAAAAAAAA\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x40\x03");
	if (0 == strcmp(attempt, pwd_store)) {
		secret();
	}
}
