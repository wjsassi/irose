-- functions

-- eDialogType
-- {
-- 	DLG_TYPE_MENU
-- 	DLG_TYPE_CHAR
-- 	DLG_TYPE_ITEM
-- 	DLG_TYPE_SKILL
-- 	DLG_TYPE_QUEST
-- 	DLG_TYPE_COMMUNITY
-- 	DLG_TYPE_CLAN
-- 	DLG_TYPE_HELP
-- 	DLG_TYPE_OPTION
-- }
-- eButton
-- {
--	MENU_BTN_CHAR
--	MENU_BTN_ITEM
--	MENU_BTN_SKILL
--	MENU_BTN_QUEST
--	MENU_BTN_COMMUNITY
--	MENU_BTN_CLAN
--	MENU_BTN_HELP
--	MENU_BTN_INFO
--	MENU_BTN_OPTION
--	MENU_BTN_EXIT
-- }
--
-- SC_OpenDialog ( eDialogType )
-- SC_SetButtonBlink( eDialogType, eButton )
-- SC_AddNpcIndicator ( npcno, auto_remove ) --npcno(중복 가능), auto_remove: 1(대화시도시 자동삭제:중복된모든), 0(스크립트 호출로 수동삭제)
-- SC_RemoveNpcIndicator ( npcno ) -- 중복시 중복 개수만큼 호출 필요
-- SC_AddCoordinatesIndicator ( index, zoneno, x, y ) -- index 중복불가
-- SC_RemoveCoordinatesIndicator ( index ) -- Add시 설정된 index



-- Tutorial 01
-- 처음 접속시
function Tutorial01( iOwnerIndex )	
	SC_ShowNotifyMessage( 1 );
end

-- Tutorial 02
-- 2 레벨로 승급
function Tutorial02( iOwnerIndex )	
	SC_ShowNotifyMessage( 2 );
	SC_OpenDialog ( DLG_TYPE_MENU )
	SC_SetButtonBlink( DLG_TYPE_MENU, MENU_BTN_CHAR )
end

-- Tutorial 03
-- 2레벨 경험치 150 이상이 되었을때
function Tutorial03( iOwnerIndex )	
	SC_ShowNotifyMessage( 3 );
end

-- Tutorial 04
-- 2레벨 경험치 220 이상이 되었을때
function Tutorial04( iOwnerIndex )	
	SC_ShowNotifyMessage( 4 );
	SC_OpenDialog ( DLG_TYPE_MENU )
	SC_SetButtonBlink( DLG_TYPE_MENU, MENU_BTN_ITEM )
end

-- Tutorial 05
-- 3레벨로 승급
function Tutorial05( iOwnerIndex )	
	SC_ShowNotifyMessage( 5 );
	SC_OpenDialog ( DLG_TYPE_MENU )
	SC_SetButtonBlink( DLG_TYPE_MENU, MENU_BTN_SKILL )
end

-- Tutorial 06
-- 3레벨 경험치 100 이상이 되었을때
function Tutorial06( iOwnerIndex )	
	SC_ShowNotifyMessage( 6 );
end

-- 5051 퀘스트를 받았을때 버튼 생성
function Tutorial07button()	
	SC_CreateEventButton( 7 )
end

-- Tutorial 07
-- 5051 퀘스트를 받았을때
function Tutorial07( iOwnerIndex )	
	SC_ShowNotifyMessage( 7 );
	SC_OpenDialog ( DLG_TYPE_MENU )
	SC_SetButtonBlink( DLG_TYPE_MENU, MENU_BTN_QUEST )
end

-- Tutorial 08
-- 4레벨로 승급
function Tutorial08( iOwnerIndex )	
	SC_ShowNotifyMessage( 8 );
end

-- T-warp 트리거 수행후 버튼 생성
function Tutorial09button()	
	SC_CreateEventButton( 9 )
end

-- Tutorial 09
-- T-warp 트리거 수행후 �
function Tutorial09( iOwnerIndex )	
	SC_ShowNotifyMessage( 9 );
end

-- Tutorial 10
-- 10레벨로 승급�
function Tutorial10( iOwnerIndex )	
	SC_ShowNotifyMessage( 10 );
end



-- Notify 01
function Notify01( iOwnerIndex )	
	SC_ShowNotifyMessage( 3 );
end








function InitTutorialEvent()
	
end


iPrevEXP = 0;
iInitPrevEXP = 0;
iStartLevel1Event = 0;	-- 1렙 경험치0 일때 이벤트를 여러번 발생시키지 않기 위해.

-- CheckTutorialEvent
function CheckTutorialEvent()

	if iInitPrevEXP == 0 then
		iPrevEXP = SC_GetAvatarEXP();
		iInitPrevEXP = 1;
	end

	iAvatarExp 	= SC_GetAvatarEXP();
	iAvatarLEVEL 	= SC_GetAvatarLEVEL();
	
	-- 처음 접속시( 1레벨 경험치 0 )일경우
	if ( iStartLevel1Event == 0 ) and ( iAvatarLEVEL == 1 ) and ( iAvatarExp == 0 ) then	
		SC_CreateEventButton( 1 )
		iStartLevel1Event = 1
	end
	
	--2 레벨 경험치 150 이상 되었을때
	if ( iAvatarLEVEL == 2 ) and ( iAvatarExp >= 150 ) and ( iPrevEXP < 150 ) then
		SC_CreateEventButton( 3 )
	end
	
	--2 레벨 경험치 220 이상 되었을때
	if ( iAvatarLEVEL == 2 ) and ( iAvatarExp >= 220 ) and ( iPrevEXP < 220 ) then
		SC_CreateEventButton( 4 )
	end
	
	--3 레벨 경험치 220 이상 되었을때
	if ( iAvatarLEVEL == 3 ) and ( iAvatarExp >= 100 ) and ( iPrevEXP < 100 ) then
		SC_CreateEventButton( 6 )
	end
	
	
		
	-- 모든 처리후 iPrevEXP를 현재 경험치로 세팅해서 다음 프레임에서 경험치의 변화를 관찰한다.
	iPrevEXP = SC_GetAvatarEXP();
end




--SC_RunEvent : NPC 대화창
--SC_RunEventFieldWarp : Warp gate
--SC_RunEventObjectEvent


-- 메인에피소드 퀘스트 이벤트 오브젝트

-- 버섯 앞 이벤트
function mushroom( iObject, iState, bJustEnd )
	iIndex = SC_GetEventObjectIndex( iObject );
	SC_RunEventObjectEvent( iIndex, "3Ddata\\Event\\Object002.con", -1 );
end

-- 모래시계 이벤트
function sandglass( iObject, iState, bJustEnd )
	iIndex = SC_GetEventObjectIndex( iObject );
	SC_RunEventObjectEvent( iIndex, "3Ddata\\Event\\Object003.con", -1 );
end

-- 무서운 책 이벤트
function horriblebook( iObject, iState, bJustEnd )
	iIndex = SC_GetEventObjectIndex( iObject );
	SC_RunEventObjectEvent( iIndex, "3Ddata\\Event\\Object004.con", -1 );
end

-- 피라미드 이벤트01
function piramid01( iObject, iState, bJustEnd )
	iIndex = SC_GetEventObjectIndex( iObject );
	SC_RunEventObjectEvent( iIndex, "3Ddata\\Event\\Object005.con", -1 );	
end

-- 피라미드 이벤트02
function piramid02( iObject, iState, bJustEnd )
	iIndex = SC_GetEventObjectIndex( iObject );
	SC_RunEventObjectEvent( iIndex, "3Ddata\\Event\\Object006.con", -1 );
end

-- 올빼미의 눈
function owl( iObject, iState, bJustEnd )
	iIndex = SC_GetEventObjectIndex( iObject );
	SC_RunEventObjectEvent( iIndex, "3Ddata\\Event\\Object007.con", -1 );
end

-- 피라미드 이벤트03
function piramid03( iObject, iState, bJustEnd )
	iIndex = SC_GetEventObjectIndex( iObject );
	SC_RunEventObjectEvent( iIndex, "3Ddata\\Event\\Object005.con", -1 );
end

-- 고요한 협곡 마나
function mana( iObject, iState, bJustEnd )
	iIndex = SC_GetEventObjectIndex( iObject );
	SC_RunEventObjectEvent( iIndex, "3Ddata\\Event\\Object008.con", -1 );
end

-- 겐지스톤
function genzistone( iObject, iState, bJustEnd )
	iIndex = SC_GetEventObjectIndex( iObject );
	SC_RunEventObjectEvent( iIndex, "3Ddata\\Event\\Object009.con", -1 );
end

