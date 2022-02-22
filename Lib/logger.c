/****************************************************************************
* Title                 :   Logger
* Filename              :   logger.c
* Author                :   Itachi
* Origin Date           :   Nov 22, 2021
* Version               :   1.0.0
* Compiler              :   TI
* Target                :   TM4C123
* Notes                 :   None
*****************************************************************************/

/*************** INTERFACE CHANGE LIST **************************************
*
*    Date       Software Version    Initials        Description
*  Nov 22, 2021    XXXXXXXXXXX      Itachi      Interface Created.
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "logger.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

/* -----------Log_Ctor---------------
 * Constructor for Log object
 * Input:
 * 			- me: 		Pointer to object
 * 			- is_on:	If == 0, will not log message
 * 			- default_log_level: only subsystem with higher level will be log out
 * Output: No
 */
void Log_Ctor(LogObj_t* const me, bool on_off, eLogLevel_t default_log_level)
{
	static struct Log_vtable_t const Log_vtable =
	{
		.Log_SendMsg =  &Log_Sendmsg,
	};
	me->p_vtb = &Log_vtable;
	me->b_log_on	= on_off;
	me->e_cur_log_level	= default_log_level;
	int idx;
	for(idx=0; idx < LOGSYSTEM_MAX; idx++)
		me->e_log_list[idx] = LOGLEVEL_DEBUG;
}

/* -----------Log_Msg---------------
 * Constructor for Log object
 * Input:
 * 			- me: 	Pointer to object
 * 			- sys:	sub-system this log belong to
 * 			- msg:  pointer to message
 * Output: true if successfully log the message out
 * Note: Conditions MUST be satisfy to be log out
 * 1. me->b_log_on = true
 * 2. Only subsystem with log level > than current level will be log out
 */
bool Log_Msg(LogObj_t* const me, eLogSubSystem_t sys, char *msg, uint32_t msg_len)
{
	if(me->b_log_on == true)
	{
		if( (me->e_log_list[sys]) >= (me->e_cur_log_level) )
		{
			return (*me->p_vtb->Log_SendMsg)(me, msg, msg_len);
		}
	}
	else{}
	return true;
}


bool Log_Sendmsg(LogObj_t* const p_logger, char *msg, uint32_t msg_len)
{
	/* purely-virtual function should never be called */
	ASSERT(0);
	return 0U;
};


void Log_SetOutputLevel(LogObj_t * const me, eLogSubSystem_t sys, eLogLevel_t level)
{
	me->e_log_list[sys] = level;
}

void Log_GlobalOn(LogObj_t* const me)
{
	me->b_log_on = true;
}

void Log_GlobalOff(LogObj_t*const  me)
{
	me->b_log_on= false;
}
