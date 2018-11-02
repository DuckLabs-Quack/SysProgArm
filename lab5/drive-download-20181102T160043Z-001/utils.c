#include "utils.h"
#include "os_internal.h"

int checkPSRBits(uint32_t psr) {
	for (int i = 0; i < 8; i++) {
			if (psr & (1 << i)) {
				return 1;
			}
	}		
	return 0;
}

void reportState() {
	uint32_t psr;
	uint32_t control;
	int threadmode;
	int pointertype;
	int priv;
	
	psr = getPSR();
	control = getCONTROL();
	
	threadmode = checkPSRBits(psr);
	
	pointertype = control & (1 << 1) ? 1 : 0;
	priv	= control & (1 << 0) ? 1 : 0;
	
	int test = priv;
	
}

void _svc_report_state(_OS_SVC_StackFrame_t* const stack) {
	reportState();
	
	uint32_t value = stack->r0;
	value = value*2;
	stack->r0 = value;
	
}
