#ifndef _MSD_STATE_CORE_H
#define _MSD_STATE_CORE_H


typedef struct
{
	int nStair1;
	int nStair2;
	int nStair3;
	int nStair4;
	int nStair5;
}BodyStateStruct;
//*****************************************************
typedef enum
{
	STAIR_1 = 1,
	STAIR_2 = 2,
	STAIR_3 = 3,
	STAIR_4 = 4,
	STAIR_5 = 5,
}StairEnum;

//*****************************************************
#define TOTAL_BODY_NUM		10
#define PROCESS_BODY		0
//*****************************************************
//------------------------
// Process Body Stair 1
#define PROCESS_BODY_STAIR1_BASE		0
#define PROCESS_Stand_By_State			PROCESS_BODY_STAIR1_BASE+0
#define PROCESS_Init_State				PROCESS_BODY_STAIR1_BASE+1
#define PROCESS_Move_State				PROCESS_BODY_STAIR1_BASE+2
#define PROCESS_Home_State				PROCESS_BODY_STAIR1_BASE+3

//------------------------
// Process Body Stair 2
#define PROCESS_BODY_STAIR2_BASE		0
#define PROCESS_BODY_INIT_STATE			PROCESS_BODY_STAIR2_BASE+0		// 切換Stair 1後第一個Case

//------------------------
// Common State for Stair 3
#define STAIR_3_NULL_STATE				0
#define STAIR_3_INIT_STATE				1

//------------------------
// Common State for Stair 4
#define STAIR_4_NULL_STATE				0
#define STAIR_4_INIT_STATE				1

//------------------------
// Common State for Stair 5
#define STAIR_5_NULL_STATE				0
#define STAIR_5_INIT_STATE				1
//*****************************************************
//*****************************************************
// Basic Functions
void ChangeBodyState(int nBody, int nStair, int nState);
int GetBodyState(int nBody, int nStair);

//*****************************************************
// Process Body
void ProcessBodyStateChange(StairEnum emStair, int nState);
int  GetProcessBodyState(StairEnum emStair);


#endif