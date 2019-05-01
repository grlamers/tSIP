//---------------------------------------------------------------------------

#ifndef CallbackH
#define CallbackH
//---------------------------------------------------------------------------

#include <System.hpp>
#include <vector>

class Callback
{
public:
	enum Type
	{
		CALL_STATE = 0,
		CALL_REINVITE_RECEIVED,
		CALL_DTMF_STATE,
		REG_STATE,
		APP_STATE,
		DLG_INFO_STATE,
		MWI_STATE,
		PRESENCE_STATE,
		PAGING_TX_STATE,
		EVENT_TALK,
		AUDIO_CODEC_LIST,			///< audio codec list sent after static and dynamic modules are loaded
		SET_CALL_DATA,
		AUDIO_ERROR
	} type;

	enum ua_state_e
	{
		CALL_STATE_CLOSED = 0,
		CALL_STATE_INCOMING,
		CALL_STATE_OUTGOING,
		CALL_STATE_TRYING,
		CALL_STATE_RINGING,
		CALL_STATE_PROGRESS,
		CALL_STATE_ESTABLISHED,
		CALL_STATE_TRANSFER,			///< REFER request received
		CALL_STATE_TRANSFER_OOD			///< REFER outside of dialog received
	} state;

	enum reg_state_e
	{
		REG_STATE_UNREGISTER_OK = 0,
		REG_STATE_REGISTERING,
		REG_STATE_REGISTER_OK,
		REG_STATE_REGISTER_FAIL,
		REG_STATE_UNREGISTERING,
		REG_STATE_UNREGISTER_FAIL
	} reg_state;
	AnsiString prm;

	enum paging_tx_state_e
	{
		PAGING_TX_ENDED = 0,
		PAGING_TX_STARTED
	} paging_tx_state;

	enum app_state_e
	{
		APP_INITIALIZED = 0,
		APP_INIT_FAILED,
		APP_START_FAILED
	} app_state;

	AnsiString caller;
	AnsiString callerName;
	int scode;	// SIP code
	AnsiString alertInfo;
	AnsiString accessUrl;
	int accessUrlMode;
	int accountId;
	int callId;
	int contactId;
	int callAnswerAfter;
	AnsiString initialRxInvite;
	AnsiString paiPeerUri;
	AnsiString paiPeerName;

	int dlgInfoState;
	int dlgInfoDirection;
	AnsiString dlgInfoRemoteIdentity;
	AnsiString dlgInfoRemoteIdentityDisplay;

	int presenceState;
	AnsiString presenceNote;

	int mwiNewMsg;
	int mwiOldMsg;

	std::vector<AnsiString> audioCodecs;

	AnsiString dtmf;
	bool dtmfActive;	
};

#endif
