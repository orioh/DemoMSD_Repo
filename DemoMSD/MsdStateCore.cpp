#include "StdAfx.h"

static BodyStateStruct stPrevBodyState[TOTAL_BODY_NUM];
static BodyStateStruct stMainBodyState[TOTAL_BODY_NUM];

void ChangeBodyState(int nBody, int nStair, int nState)
{
	if(nBody>=0 && nBody<TOTAL_BODY_NUM)
	{
		switch (nStair)
		{
		case 1:
			{
				stPrevBodyState[nBody].nStair1 = stMainBodyState[nBody].nStair1;
				stMainBodyState[nBody].nStair1 = nState;
			}
			break;
		case 2:
			{
				stPrevBodyState[nBody].nStair2 = stMainBodyState[nBody].nStair2;
				stMainBodyState[nBody].nStair2 = nState;
			}
			break;
		case 3:
			{
				stPrevBodyState[nBody].nStair3 = stMainBodyState[nBody].nStair3;
				stMainBodyState[nBody].nStair3 = nState;
			}
			break;
		case 4:
			{
				stPrevBodyState[nBody].nStair4= stMainBodyState[nBody].nStair4;
				stMainBodyState[nBody].nStair4 = nState;
			}
			break;
		case 5:
			{
				stPrevBodyState[nBody].nStair5 = stMainBodyState[nBody].nStair5;
				stMainBodyState[nBody].nStair5 = nState;
			}
			break;

		}
		
	}
}

int GetBodyState(int nBody, int nStair)
{
	int nGet;
	if(nBody>=0 && nBody<TOTAL_BODY_NUM)
	{
		switch (nStair)
		{
		case 1:
			{
				nGet = stMainBodyState[nBody].nStair1;
			}
			break;
		case 2:
			{
				nGet = stMainBodyState[nBody].nStair2;
			}
			break;
		case 3:
			{
				nGet = stMainBodyState[nBody].nStair3;
			}
			break;
		case 4:
			{
				nGet = stMainBodyState[nBody].nStair4;
			}
			break;
		case 5:
			{
				nGet = stMainBodyState[nBody].nStair5;
			}
			break;
		}
	}
	return nGet;
}

void ProcessBodyStateChange(StairEnum emStair, int nState)
{
	switch(emStair)
	{
	case STAIR_1:
		{
			ChangeBodyState(PROCESS_BODY, 1, nState);
			ChangeBodyState(PROCESS_BODY, 2, PROCESS_BODY_INIT_STATE);
			ChangeBodyState(PROCESS_BODY, 3, STAIR_3_INIT_STATE);
			ChangeBodyState(PROCESS_BODY, 4, STAIR_4_INIT_STATE);
			ChangeBodyState(PROCESS_BODY, 5, STAIR_5_INIT_STATE);
		}
		break;
	case STAIR_2:
		{
			ChangeBodyState(PROCESS_BODY, 2, nState);
			ChangeBodyState(PROCESS_BODY, 3, STAIR_3_INIT_STATE);
			ChangeBodyState(PROCESS_BODY, 4, STAIR_4_INIT_STATE);
			ChangeBodyState(PROCESS_BODY, 5, STAIR_5_INIT_STATE);
		}
		break;
	case STAIR_3:
		{
			ChangeBodyState(PROCESS_BODY, 3, nState);
			ChangeBodyState(PROCESS_BODY, 4, STAIR_4_INIT_STATE);
			ChangeBodyState(PROCESS_BODY, 5, STAIR_5_INIT_STATE);
		}
		break;
	case STAIR_4:
		{
			ChangeBodyState(PROCESS_BODY, 4, nState);
			ChangeBodyState(PROCESS_BODY, 5, STAIR_5_INIT_STATE);
		}
		break;
	case STAIR_5:
		{
			ChangeBodyState(PROCESS_BODY, 5, STAIR_5_INIT_STATE);
		}
		break;
	}
}

int  GetProcessBodyState(StairEnum emStair)
{
	return GetBodyState(PROCESS_BODY, emStair);
}