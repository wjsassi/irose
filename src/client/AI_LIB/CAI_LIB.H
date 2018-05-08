#ifndef	__CAI_OBJ_H
#define	__CAI_OBJ_H

///</
///</ �ΰ����� ��ü�� ���� Ŭ����...
///</
class STBDATA;
class CAI_OBJ 
{
private :
	ULONG			 m_ulAICheckTIME[ 2 ];

public  :
	CAI_OBJ ()		{	::ZeroMemory(m_ulAICheckTIME,sizeof(ULONG)*2);		}

	unsigned long	 Get_AICheckTIME(int iIDX)								{	return m_ulAICheckTIME[iIDX];		}
	void			 Set_AICheckTIME(int iIDX, unsigned long lCheckTIME)	{	m_ulAICheckTIME[iIDX] = lCheckTIME;	}

	virtual float	 Get_CurXPOS() = 0{ *(int*)0 = 10; }					///< ���� X�� ��ġ
	virtual float	 Get_CurYPOS() = 0{ *(int*)0 = 10; }					///< ���� Y�� ��ġ
#ifndef	__SERVER
	virtual float	 Get_CurZPOS() = 0{ *(int*)0 = 10; }					///< ���� Z�� ��ġ
#endif
	virtual float	 Get_BornXPOS() = 0{ *(int*)0 = 10; }					///< ó�� ���� X�� ��ġ
	virtual float	 Get_BornYPOS() = 0{ *(int*)0 = 10; }					///< ó�� ���� Y�� ��ġ

	virtual int		 Get_TAG() = 0{ *(int*)0 = 10; }						///< �ٸ� ��ü�� �ߺ����� �ʴ� ������ ���� ���Ѵ�.( �Ϲ������� ���� �ε��� )
//	virtual int		 Get_ObjTYPE() = 0{ *(int*)0 = 10; }					///< ��ü�� Ÿ���� ��´�.
//	virtual bool	 Is_SameTYPE(int iType) = 0{ *(int*)0 = 10; }			///< ��ü�� Ÿ���� iType�� ������?
//	virtual bool	 Is_AVATAR() = 0{ *(int*)0 = 10; }						///< ��ü�� Ÿ���� �ƹ�Ÿ �ΰ�?

	virtual int		 Get_PercentHP() = 0{ *(int*)0 = 10; }
	virtual int		 Get_HP() = 0{ *(int*)0 = 10; }						///< ��ü�� �������� ���Ѵ�.
	virtual int		 Get_CharNO() = 0{ *(int*)0 = 10; }					///< ��ü�� �ɸ��� ��ȣ�� ��´�.

	virtual int		 Get_LEVEL ()	=0;
	virtual int		 Get_ATK ()		=0;
	virtual int		 Get_DEF ()		=0;
	virtual int		 Get_RES ()		=0;
	virtual int		 Get_HIT ()		=0;	
	virtual int		 Get_CHARM ()	=0;
	virtual int		 Get_AVOID ()	=0;
	virtual int		 Get_SENSE ()	=0;
	virtual int		 Get_GiveEXP ()	=0;
	virtual int		 Get_CRITICAL()	=0;	

	virtual CAI_OBJ *Get_TARGET() = 0{ *(int*)0 = 10; }					///< ���� ����� ���Ѵ�.
	virtual CAI_OBJ *Get_OWNER()						{	return NULL;	}

//	virtual void	 Set_TARGET (CAI_OBJ *pAIObj) = 0{ *(int*)0 = 10; }	///< ���� ����� �����Ѵ�.
	virtual float	 Get_DISTANCE(CAI_OBJ *pAIObj) = 0{ *(int*)0 = 10; }	///< ������ �Ÿ��� ���Ѵ�.
	virtual float	 Get_MoveDISTANCE() = 0{ *(int*)0 = 10; }				///< ó�� ���� ��ġ�� ������ġ�� �Ÿ��� ���Ѵ�.

	virtual int		 Get_RANDOM(int iMod) = 0{ *(int*)0 = 10; }			///< ��ü�� ������ ���� ��ġ�� ���Ѵ�.

	virtual bool	 Change_CHAR(int /*iCharIDX*/)			{	return false;	}	///< iCharIDX�� ��ü�� ��ȯ ��Ų��.
	virtual bool	 Create_PET (int /*iCharIDX*/, float /*fPosX*/, float /*fPosY*/, int /*iRange*/)	{	return false;	}	///< iCharIDX�� ��ü�� ��ȯ ��Ų��.

	virtual void	 Say_MESSAGE (char* /*szMessage*/)		{	;	}		///< ��ȭ�� ����Ѵ�.
	virtual void	 Run_AWAY(int /*iDistance*/)			{	;	}
	virtual void	 Drop_ITEM(short /*nDropITEM*/)			{	;	}

	// command interface function
	virtual void Set_EMOTION(short /*nEmotionIDX*/)			{	;	}		///< ���� ǥ�� ������ �����Ѵ�.

	virtual bool SetCMD_STOP() = 0{ *(int*)0 = 10; }										///< ��ü�� ���� ������ �����Ѵ�.
	virtual bool SetCMD_MOVE2D (float fPosToX, float fPosToY, BYTE btRunMODE) = 0{ *(int*)0 = 10; }///< ��ü�� �̵� ������ �����Ѵ�.
#ifndef	__SERVER
	virtual bool SetCMD_MOVE (const D3DVECTOR& PosTo, BYTE btRunMODE) = 0{ *(int*)0 = 10; }///< ��ü�� �̵� ������ �����Ѵ�.
#endif
	virtual void SetCMD_RUNnATTACK(int iTargetObjTAG) = 0{ *(int*)0 = 10; }				///< ��ü�� ���� ������ �����Ѵ�.
	virtual void Special_ATTACK() = 0{ *(int*)0 = 10; }									///< ��ü�� Ư�� ���� ������ �����Ѵ�.

	virtual CAI_OBJ* AI_FindFirstOBJ( int iDistance ) = 0{ *(int*)0 = 10; }
	virtual CAI_OBJ* AI_FindNextOBJ () = 0{ *(int*)0 = 10; }

	virtual int		Get_EconomyVAR(short /*nVarIDX*/)		{	return 0;	}
	virtual int		Get_WorldVAR  (short /*nVarIDX*/)		{	return 0;	}

	virtual int		Get_TeamNO () = 0{ *(int*)0 = 10; }

			///PVP �������� �̰ɷθ� �Ǵ��ؼ��� �ȵȴ�. 2005/07/14 - nAvy
			bool	Is_ALLIED( CAI_OBJ *pDestOBJ )
			{
			#ifdef	__SERVER
				if ( this->Get_OWNER() ) {
					if ( this->Get_OWNER() == pDestOBJ || this->Get_OWNER() == pDestOBJ->Get_OWNER() )
						return true;
				}
			#endif
				if ( -1 == pDestOBJ->Get_TeamNO() )		// ����ȣ -1 �̸� ������ ��
					return false;

				if ( this->Get_TeamNO() == pDestOBJ->Get_TeamNO() ||
					 (__int64)(this->Get_TeamNO()) * (__int64)(pDestOBJ->Get_TeamNO()) <= 100 )
					return true;

				return false;
			}
			bool	Is_SameTEAM( CAI_OBJ *pDestOBJ )
			{
			#ifdef	__SERVER
				if ( this->Get_OWNER() ) {
					if ( this->Get_OWNER() == pDestOBJ || this->Get_OWNER() == pDestOBJ->Get_OWNER() )
						return true;
				}
			#endif
				if ( -1 == pDestOBJ->Get_TeamNO() )		// ����ȣ -1 �̸� ������ ��
					return false;

				return ( this->Get_TeamNO() == pDestOBJ->Get_TeamNO() );
			}

	virtual BYTE	Is_DAY (void) = 0{ *(int*)0 = 10; }						// �㳷���� ����... ��:1, ��0
	virtual int		Get_ZoneTIME (void) = 0{ *(int*)0 = 10; }				// ���� �� �ð��� �����Ѵ�...
	virtual int		Get_WorldTIME(void) = 0{ *(int*)0 = 10; }				// ���� ���� �ð��� �����Ѵ�...
	virtual void	Set_TRIGGER (t_HASHKEY /*HashKEY*/)		{	;	}
#ifdef	__SERVER
	virtual DWORD	Get_MagicSTATUS() = 0{ *(int*)0 = 10; }
	virtual CAI_OBJ*Find_LocalNPC(int iNpcNO) = 0{ *(int*)0 = 10; }

	virtual void	Set_EconomyVAR(short nVarIDX, int iValue) = 0{ *(int*)0 = 10; }
	virtual void	Set_WorldVAR  (short nVarIDX, int iValue) = 0{ *(int*)0 = 10; }

	virtual void	Add_DAMAGE ( WORD wDamage ) = 0{ *(int*)0 = 10; }

	virtual bool	Send_gsv_CHAT ( char *szMsg ) = 0{ *(int*)0 = 10; }
	virtual bool	Send_gsv_SHOUT( char *szMsg ) = 0{ *(int*)0 = 10; }
	virtual void	Send_gsv_ANNOUNCE_CHAT( char *szMsg ) = 0{ *(int*)0 = 10; }

	virtual bool	SetCMD_Skill2SELF (short /*nSkillIDX*/, short /*nMotion*/)							{	return true;	}
	virtual bool	SetCMD_Skill2OBJ (int /*iTargetObjIDX*/, short /*nSkillIDX*/, short /*nMotion*/)	{	return true;	}
#endif
} ;


///<-------------------------------------------------------------------------------------------------
///
///	�ΰ����� ���� Ŭ����..
///

class CAI_PATTERN;
class CAI_FILE
{
private:
	CAI_PATTERN	 *m_pPattern;
	int			  m_iPatternCNT;
	unsigned long m_ulCheckStopAI;
	int			  m_iRateDamagedAI;

	void AI_Check (WORD wPattern, CAI_OBJ *pSourCHAR, CAI_OBJ *pDestCHAR=NULL, int iDamage=0);
public :
	CAI_FILE ();
	~CAI_FILE ();

	bool Load (char *szFileName, STBDATA *pSTB, int iLangCol);

	/// 0		ó�� ������
	void AI_WhenCREATED (CAI_OBJ *pSourCHAR);

	/// 1		���� �����϶�
	void AI_WhenSTOP (CAI_OBJ *pSourCHAR);

	/// 2		���� �̵���
	void AI_WhenAttackMOVE (CAI_OBJ *pSourCHAR, CAI_OBJ *pDestCHAR);

	/// 3		Ÿ�� ��������
	void AI_WhenDAMAGED (CAI_OBJ *pSourCHAR, CAI_OBJ *pDestCHAR, int iDamage);

	/// 4		������ �׿�����
	void AI_WhenKILL (CAI_OBJ *pSourCHAR, CAI_OBJ *pDestCHAR, int iDamage);

	/// 5		�ڽ��� ������
	void AI_WhenDEAD (CAI_OBJ *pSourCHAR, CAI_OBJ *pDestCHAR, int iDamage);
} ;


///<-------------------------------------------------------------------------------------------------
///
/// �ΰ����� ��ü���� �����ϴ� ȯ�� �Լ�...
///

extern int		AI_SysRANDOM( int iMod );

///<-------------------------------------------------------------------------------------------------
#endif