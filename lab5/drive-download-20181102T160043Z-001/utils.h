#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>
#include "os.h"

uint32_t getPSR(void);
uint32_t getCONTROL(void);

void reportState(void);

uint32_t __svc(SVC_REPORT_STATE) report_state(uint32_t);

#endif /* UTILS_H */
