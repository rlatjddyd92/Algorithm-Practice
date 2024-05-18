#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <cmath>

using namespace std;

#define ROAD '.'
#define WALL '#'
#define BOX 'B'
#define SPIKE '^'
#define MONSTER '&'
#define BOSS 'M'
#define PLAYER '@'

#define WEAPON 'W'
#define ARMOR 'A'
#define ACCESSORY 'O'

#define LEFT 'L'
#define RIGHT 'R'
#define UPWARD 'U'
#define DOWNWARD 'D'

#define SPIKEDAMEGE 5

#define LIMITACC 4
#define ACCHEAL 3

#define HPUP 5
#define ATTACKUP 2
#define DEFENCEUP 2

#define KEYMAX 200

template<typename T>
void SafeDelete(void* Dest)
{
	if (Dest != nullptr)
	{
		delete Dest;
		Dest = nullptr;
	}
}

enum class ACTYPE
{
	ACTYPE_HR = 0, // <- 승리 시 체력 ++3, 최대치까지만 회복 
	ACTYPE_RE = 1, // <- 주인공 사망 시 소멸하면서 주인공은 최대 체력으로 부활, 몬스터와 싸우는 중일 경우 몬스터도 체력 최대로 회복 
	ACTYPE_CO = 2, // <- 모든 전투, 첫 공격에서 데미지 2배 
	ACTYPE_EX = 3, // <- 경험치 1.2배, 소수점 아래는 버림 
	ACTYPE_DX = 4, // <- 가시에 입는 데미지 1로 고정, CO를 가지고 있을 경우 CO의 효과가 2배 -> 3배로 변경 
	ACTYPE_HU = 5, // <- 보스와 전투 시, 체력 최대치까지 회복, 보스의 첫 공격 데미지 0
	ACTYPE_CU = 6, // <- 능력 없음 
	ACTYPE_END
};

enum class ENGAGE
{
	ENGAGE_MONSETR = 0,
	ENGAGE_BOSS = 1,
	ENGAGE_SPIKE =2,
	ENGAGE_BOX = 3, 
	ENGAGE_END = 4,
};

class CPlayer
{
public:
	CPlayer():
		m_iLevel(1)
		, m_iHp(20)
		, m_iMaxHp(20)
		, m_iAttack(2)
		, m_iAdditional_Attack(0)
		, m_iDefence(2)
		, m_iAdditional_Defence(0)
		, m_iExp(0)
		, m_iNextExp(0)
		, m_iEquipAcc(0)
		, m_strResult("Press any key to continue.")
		, m_bDead(false)
	{
		m_iNextExp = m_iLevel * 5;
		m_vecAccessory.resize(int(ACTYPE::ACTYPE_END));
	}

	~CPlayer() { Release(); }

public:
	void InputBattleResult(int _iHp, int _iExp, string _strOpponentName, bool* _bIsReBorn)
	{
		m_iHp = _iHp;
		*_bIsReBorn = false;

		if (m_iHp <= 0)
		{
			if (m_vecAccessory[int(ACTYPE::ACTYPE_RE)])
			{
				m_vecAccessory[int(ACTYPE::ACTYPE_RE)] = false;
				--m_iEquipAcc;
				m_iHp = m_iMaxHp;
				*_bIsReBorn = true;
				return;
			}

			m_bDead = true;
			m_strResult = "YOU HAVE BEEN KILLED BY " + _strOpponentName + "..";
			m_iHp = 0;
		}
		else
		{
			if (m_vecAccessory[int(ACTYPE::ACTYPE_HR)])
			{
				m_iHp += ACCHEAL;
				if (m_iHp > m_iMaxHp)
					m_iHp = m_iMaxHp;
			}
			AddExpLevel(_iExp);
		}
	}
	void GetBattleInfo(int* _iPlayerHp, int* _iPlayerMaxHp, int* _iPlayerAttack, int* _iPlayerDefence, bool* _bPlayerCO, bool* _bPlayerDX, bool* _bPlayerHU)
	{
		*_iPlayerHp = m_iHp;
		*_iPlayerMaxHp = m_iMaxHp;
		*_iPlayerAttack = m_iAttack + m_iAdditional_Attack;
		*_iPlayerDefence = m_iDefence + m_iAdditional_Defence;
		*_bPlayerCO = m_vecAccessory[int(ACTYPE::ACTYPE_CO)];
		*_bPlayerDX = m_vecAccessory[int(ACTYPE::ACTYPE_DX)];
		*_bPlayerHU = m_vecAccessory[int(ACTYPE::ACTYPE_HU)];
	}
	void DamegeBySpike(bool* _bReborn)
	{
		if (!m_vecAccessory[int(ACTYPE::ACTYPE_DX)]) m_iHp -= SPIKEDAMEGE;
		else m_iHp -= SPIKEDAMEGE / SPIKEDAMEGE;

		if (m_iHp <= 0)
		{
			if (m_vecAccessory[int(ACTYPE::ACTYPE_RE)])
			{
				m_vecAccessory[int(ACTYPE::ACTYPE_RE)] = false;
				--m_iEquipAcc;
				m_iHp = m_iMaxHp;
				*_bReborn = true;
				return;
			}

			m_bDead = true;
			m_strResult = "YOU HAVE BEEN KILLED BY SPIKE TRAP..";
			m_iHp = 0;
		}
	}
	bool CheckPlayerDead()
	{
		return m_bDead;
	}
	bool EquipAccessory(ACTYPE _eAcType)
	{
		if (m_iEquipAcc >= LIMITACC)
			return false;

		if (!m_vecAccessory[int(_eAcType)])
		{
			++m_iEquipAcc;
			m_vecAccessory[int(_eAcType)] = true;
			return true;
		}

		return false;
	}
	void EquipWeapon(int _iAttack)
	{
		m_iAdditional_Attack = _iAttack;
	}
	void EquipArmor(int _iDefence)
	{
		m_iAdditional_Defence = _iDefence;
	}
	void SetWin()
	{
		m_strResult = "YOU WIN!";
	}
	void PlayerRender()
	{
		cout << "LV : " << m_iLevel << "\n";
		cout << "HP : " << m_iHp << "/" << m_iMaxHp << "\n";
		cout << "ATT : " << m_iAttack << "+" << m_iAdditional_Attack << "\n";
		cout << "DEF : " << m_iDefence << "+" << m_iAdditional_Defence << "\n";
		cout << "EXP : " << m_iExp << "/" << m_iNextExp << "\n";
		cout << m_strResult;
	}

private:
	void AddExpLevel(int _iGetExp)
	{
		if (m_vecAccessory[int(ACTYPE::ACTYPE_EX)])
		{
			_iGetExp *= 12;
			_iGetExp /= 10;
		}

		m_iExp += _iGetExp;

		if (m_iExp >= m_iNextExp)
		{
			m_iExp = 0;
			
			m_iMaxHp += HPUP;
			m_iAttack += ATTACKUP;
			m_iDefence += DEFENCEUP;
			m_iHp = m_iMaxHp;
			++m_iLevel;

			m_iNextExp = m_iLevel * 5;
		}
	}
	void Release()
	{
		m_vecAccessory.clear();
	}

	int m_iLevel;

	int m_iHp;
	int m_iMaxHp;

	int m_iAttack;
	int m_iAdditional_Attack;

	int m_iDefence;
	int m_iAdditional_Defence;

	int m_iExp;
	int m_iNextExp;

	int m_iEquipAcc;

	vector<bool> m_vecAccessory;

	string m_strResult;

	bool m_bDead;
};

class CMonster
{
public:
	CMonster(string _strName, int _iAttack, int _iDefence, int _iHp, int _iExp)
	{
		m_strName = _strName;
		m_iAttack = _iAttack;
		m_iDefence = _iDefence;
		m_iHp = _iHp;
		m_iExp = _iExp;
		m_bDead = false;
		m_bBoss = false;
	}

	~CMonster() {}

public:
	void GetBattleInfo(string* _strName, int* _iHp, int* _iAttack, int* _iDefence, int* _iExp)
	{
		*_strName = m_strName;
		*_iHp = m_iHp;
		*_iAttack = m_iAttack;
		*_iDefence = m_iDefence;
		*_iExp = m_iExp;
	}
	void SetDead()
	{
		m_bDead = true;
	}
	bool GetDead()
	{
		return m_bDead;
	}
	void SetBoss()
	{
		m_bBoss = true;
	}
	bool GetBoss()
	{
		return m_bBoss;
	}

private:
	string m_strName;

	int m_iAttack;
	int m_iDefence;

	int m_iHp;

	int m_iExp;

	bool m_bDead;

	bool m_bBoss;
};

class CBox
{
public:
	CBox(char _szEquipType, int _iStat, ACTYPE _eAccType)
	{
		m_szEquipType = _szEquipType;
		m_iStat = _iStat;
		m_eAccType = _eAccType;
		m_bDead = false;
	}

	~CBox() {}

public:
	void OpenBox(char* _szType, ACTYPE* _eType, int* _iStat)
	{
		if (m_bDead) return;
		*_szType = m_szEquipType;
		*_eType = m_eAccType;
		*_iStat = m_iStat;
	}
	bool GetDead()
	{
		return m_bDead;
	}
	void SetDead()
	{
		m_bDead = true;
	}

private:
	char m_szEquipType;
	bool m_bDead;
	int m_iStat;
	ACTYPE m_eAccType;
};

class CTileMgr   // <- 타일 정보를 보관하고 수정하는 역할, 필요에 따라 몬스터/박스 매니저 호출
{
public:
	CTileMgr():
		m_strCommand("")
		, m_iTurn(-1)
		, m_iPlayerRow(0)
		, m_iPlayerCol(0)
	{}
	~CTileMgr(){}

public:
	void InputTileInfo(int _iRow, int _iCol, int* _MonNum, int* _BoxNum, int* _BossRow, int* _BossCol)
	{
		int iMonNum = 0; 
		int iBoxNum = 0;

		vecTileMap.resize(_iRow + 1);

		for (int i = 1; i <= _iRow; ++i)
		{
			string strInput = "";

			cin >> strInput;

			vecTileMap[i].resize(_iCol + 1);

			for (int j = 1; j <= _iCol; ++j)
			{
				vecTileMap[i][j] = strInput[j - 1];
				if (strInput[j - 1] == MONSTER)
					++iMonNum;

				if (strInput[j - 1] == BOSS)
				{
					*_BossRow = i;
					*_BossCol = j;
					++iMonNum;
				}

				if (strInput[j - 1] == BOX)
					++iBoxNum;

				if (strInput[j - 1] == PLAYER)
				{
					m_iPlayerRow = i;
					m_iStartRow = m_iPlayerRow;
					m_iPlayerCol = j;
					m_iStartCol = m_iPlayerCol;
					vecTileMap[i][j] = ROAD;
				}
			}
		}

		*_MonNum = iMonNum;
		*_BoxNum = iBoxNum;
	}

	void InputCommand()
	{
		cin >> m_strCommand;
	}

	ENGAGE MovePlayerByCommand()
	{
		++m_iTurn;

		if (m_iTurn >= m_strCommand.size())
			return ENGAGE::ENGAGE_END;

		int iRow = m_iPlayerRow;
		int iCol = m_iPlayerCol;

		switch (m_strCommand[m_iTurn])
		{
		case LEFT:
			--iCol;
			break;

		case RIGHT:
			++iCol;
			break;

		case UPWARD:
			--iRow;
			break;

		case DOWNWARD:
			++iRow;
			break;

		default:
			break;
		}

		if (CheckCanMove(iRow, iCol))
		{
			m_iPlayerRow = iRow;
			m_iPlayerCol = iCol;
		}

		if (vecTileMap[m_iPlayerRow][m_iPlayerCol] == MONSTER)
			return ENGAGE::ENGAGE_MONSETR;
		else if (vecTileMap[m_iPlayerRow][m_iPlayerCol] == BOSS)
			return ENGAGE::ENGAGE_BOSS;
		else if (vecTileMap[m_iPlayerRow][m_iPlayerCol] == BOX)
			return ENGAGE::ENGAGE_BOX;
		else if (vecTileMap[m_iPlayerRow][m_iPlayerCol] == SPIKE)
			return ENGAGE::ENGAGE_SPIKE;

		return ENGAGE::ENGAGE_END;
	}
	bool IsCommandEnd()
	{
		return m_iTurn >= m_strCommand.size() - 1;
	}
	void TIleRender()
	{
		if ((m_iPlayerRow) && (m_iPlayerCol))
			vecTileMap[m_iPlayerRow][m_iPlayerCol] = PLAYER;

		for (int i = 1; i < vecTileMap.size(); ++i)
		{
			for (int j = 1; j < vecTileMap[i].size(); ++j)
				cout << vecTileMap[i][j];

			cout << "\n";
		}
	}
	void TurnRender()
	{
		cout << "Passed Turns : " << m_iTurn + 1 << "\n";
	}
	void EraseTile(int _iRow, int _iCol)
	{
		vecTileMap[_iRow][_iCol] = ROAD;
	}
	void PlayerDead()
	{
		m_iPlayerRow = 0;
		m_iPlayerCol = 0;
	}
	void PlayerRE()
	{
		m_iPlayerRow = m_iStartRow;
		m_iPlayerCol = m_iStartCol;
	}
	void PlayerIndex(int* iRow, int* iCol)
	{
		*iRow = m_iPlayerRow;
		*iCol = m_iPlayerCol;
	}

private:
	
	bool CheckCanMove(int _iRow, int _iCol)
	{
		if ((_iRow <= 0) || (_iRow >= vecTileMap.size()))
			return false;

		if ((_iCol <= 0) || (_iCol >= vecTileMap[_iRow].size()))
			return false;

		if (vecTileMap[_iRow][_iCol] == WALL)
			return false;

		return true;
	}
	void Release()
	{
		for (auto& iter : vecTileMap)
		{
			iter.clear();
		}
		vecTileMap.clear();
	}

	int m_iStartRow;
	int m_iStartCol;

	int m_iPlayerRow;
	int m_iPlayerCol;

	string m_strCommand;
	vector<vector<char>> vecTileMap;
	int m_iTurn;
};

class CMonsterMgr  // <- 몬스터 정보를 보관하고 수정 
{
public:
	CMonsterMgr():
	m_bIsBossDead(false)
		, m_iMaxRow(0)
		, m_iBossKey(0)
	{
	}
	~CMonsterMgr() { Release(); }

public:
	void InputMonInfo(int _iMonNum, int _iMaxRow)
	{
		m_iMaxRow = _iMaxRow;

		for (int i = 0; i < _iMonNum; ++i)
		{
			int iRow = 0;
			int iCol = 0;
			string strName = "";
			int iAttack = 0;
			int iDefence = 0;
			int iHp = 0;
			int iExp = 0;

			cin >> iRow >> iCol >> strName >> iAttack >> iDefence >> iHp >> iExp;

			CMonster* pNew = new CMonster(strName, iAttack, iDefence, iHp, iExp);
			m_mapMonser.insert({ iRow * KEYMAX + iCol , pNew });
		}
	}
	bool SetBossIndex(int _iRow, int iCol)
	{
		if (m_mapMonser.find(_iRow * KEYMAX + iCol) != m_mapMonser.end())
		{
			m_mapMonser.find(_iRow * KEYMAX + iCol)->second->SetBoss();
			m_iBossKey = _iRow * KEYMAX + iCol;
			return true;
		}

		return false;
	}
	bool GetIsboss(int _iRow, int iCol)
	{
		if (m_mapMonser.find(_iRow * KEYMAX + iCol) != m_mapMonser.end())
			if (m_mapMonser.find(_iRow * KEYMAX + iCol)->second->GetBoss())
				return true;

		return false;
	}

	bool IsBossDead() { return m_bIsBossDead; }
	void RequestMonsterInfo(int _iRow, int _iCol, string* _strName, int* _iMonHp, int* _iMonAttack, int* _iMonDefence, int* _iExp)
	{
		int iKey = _iRow * KEYMAX + _iCol;
		if (m_mapMonser.find(iKey) == m_mapMonser.end())
			return;

		m_mapMonser.find(iKey)->second->GetBattleInfo(_strName, _iMonHp, _iMonAttack, _iMonDefence, _iExp);
	}
	void MonsterKill(int _iRow, int _iCol)
	{
		int iKey = _iRow * KEYMAX + _iCol;
		if (m_mapMonser.find(iKey) == m_mapMonser.end())
			return;

		m_mapMonser.find(iKey)->second->SetDead();
		if (iKey == m_iBossKey)
			m_bIsBossDead = true;
	}

private:
	void Release()
	{
		for (auto& pair : m_mapMonser)
		{
			SafeDelete<CMonster*>(pair.second);
		}
		m_mapMonser.clear();
	}

private:
	int m_iMaxRow;
	int m_iBossKey;
	map<int, CMonster*> m_mapMonser;
	bool m_bIsBossDead;
};

class CBoxMgr  // <- 박스 정보를 보관하고 수정, 필요에 따라 플레이어 객체에 정보 전달 
{
public:
	CBoxMgr() :
		m_iMaxRow (0)
	{}
	~CBoxMgr() { Release(); }

public:
	void InputBoxInfo(int _iBoxNum, int _iMaxRow)
	{
		m_iMaxRow = _iMaxRow;

		for (int i = 0; i < _iBoxNum; ++i)
		{
			int iRow = 0;
			int iCol = 0;
			char szType = {};
			int iStat = 0;
			string strType = "";
			ACTYPE eType = ACTYPE::ACTYPE_END;

			cin >> iRow >> iCol >> szType;

			if (szType == 'O')
				cin >> strType;
			else
				cin >> iStat;

			if (strType == "HR") { eType = ACTYPE::ACTYPE_HR; }
			else if (strType == "RE") { eType = ACTYPE::ACTYPE_RE; }
			else if (strType == "CO") { eType = ACTYPE::ACTYPE_CO; }
			else if (strType == "EX") { eType = ACTYPE::ACTYPE_EX; }
			else if (strType == "DX") { eType = ACTYPE::ACTYPE_DX; }
			else if (strType == "HU") { eType = ACTYPE::ACTYPE_HU; }
			else if (strType == "CU") { eType = ACTYPE::ACTYPE_CU; }

			CBox* pNew = new CBox(szType, iStat, eType);

			m_mapBox.insert({ iRow * KEYMAX + iCol , pNew });
		}
	}

	void GetBoxInfo(int _iRow, int _iCol, char* szType, ACTYPE* eType, int* _iStat)
	{
		int Key = _iRow * KEYMAX + _iCol;
		if (m_mapBox.find(Key) == m_mapBox.end())
			return;

		m_mapBox.find(Key)->second->OpenBox(szType, eType, _iStat);
	}

	void SetBoxDead(int _iRow, int _iCol)
	{
		int Key = _iRow * KEYMAX + _iCol;
		if (m_mapBox.find(Key) == m_mapBox.end())
			return;

		m_mapBox.find(Key)->second->SetDead();
	}

private:
	void Release()
	{
		for (auto& pair : m_mapBox)
		{
			SafeDelete<CBox*>(pair.second);
		}
		m_mapBox.clear();
	}

private:
	int m_iMaxRow;
	map<int, CBox*> m_mapBox;
};

class CGame_Instence // <- 타일/몬스터/박스 매니저 객체를 저장하고 불러오는 역할, 싱글톤 
{
private:
	static CGame_Instence* m_pInstence;
	CGame_Instence():
		m_pPlayer(nullptr)
		, m_pTileMgr(nullptr)
		, m_pMonsterMgr(nullptr)
		, m_pBoxMgr(nullptr)
	{
	}

	~CGame_Instence()
	{
		Safe_Delete<CPlayer*>(m_pPlayer);
		Safe_Delete<CTileMgr*>(m_pTileMgr);
		Safe_Delete<CMonsterMgr*>(m_pMonsterMgr);
		Safe_Delete<CBoxMgr*>(m_pBoxMgr);
	}

public:
	static CGame_Instence* Get_Instence()
	{
		if (!m_pInstence)
			m_pInstence = new CGame_Instence;

		return m_pInstence;
	}

	void Destroy_Instence()
	{
		if (m_pInstence != nullptr)
		{
			delete m_pInstence;
			m_pInstence = nullptr;
		}
	}

	void Initialize()
	{
		m_pPlayer = new CPlayer;
		m_pTileMgr = new CTileMgr;
		m_pMonsterMgr = new CMonsterMgr;
		m_pBoxMgr = new CBoxMgr;
	}

public: // <- 기본 정보 입력 
	void InputData()
	{
		int iRow = 0;
		int iCol = 0; 
		int iMonNum = 0;
		int iBoxNum = 0;
		int iBossRow = 0;
		int iBossCol = 0;

		cin >> iRow >> iCol;

		m_pTileMgr->InputTileInfo(iRow, iCol, &iMonNum, &iBoxNum, &iBossRow, &iBossCol);
		m_pTileMgr->InputCommand();
		m_pMonsterMgr->InputMonInfo(iMonNum, iRow);
		m_pBoxMgr->InputBoxInfo(iBoxNum, iRow);
		m_pMonsterMgr->SetBossIndex(iBossRow, iBossCol);
	}

public: // <- 주 기능 수행 
	bool OperateCommand()
	{
		ENGAGE eEngage = m_pTileMgr->MovePlayerByCommand();
		int iRow = 0;
		int iCol = 0;
		m_pTileMgr->PlayerIndex(&iRow, &iCol);
		bool bOpen = false;
		bool bReborn = false;

		if ((eEngage == ENGAGE::ENGAGE_MONSETR) || (eEngage == ENGAGE::ENGAGE_BOSS))
			Battle(iRow, iCol);
		else if (eEngage == ENGAGE::ENGAGE_SPIKE)
			m_pPlayer->DamegeBySpike(&bReborn);
		else if (eEngage == ENGAGE::ENGAGE_BOX)
			BoxOpen(iRow, iCol);

		if ((bReborn) && (eEngage == ENGAGE::ENGAGE_SPIKE))
			m_pTileMgr->PlayerRE();

		if ((m_pPlayer->CheckPlayerDead()) && (eEngage == ENGAGE::ENGAGE_SPIKE))
			m_pTileMgr->PlayerDead();

		int iResult = 0;
		iResult += m_pPlayer->CheckPlayerDead();
		iResult += m_pTileMgr->IsCommandEnd();
		iResult += m_pMonsterMgr->IsBossDead();

		return (iResult > 0);
	}

	bool Battle(int _iRow, int _iCol)
	{
		int iPlayerHp = 0;
		int iPlayerMaxHp = 0;
		int iPlayerAttack = 0;
		int iPlayerDefence = 0;
		bool bPlayerCO = false;
		bool bPlayerDX = false;
		bool bPlayerHU = false;

		string strName = "";
		int iMonsterHp = 0;
		int iMonsterAttack = 0;
		int iMonsterDefence = 0;
		int iMonsterEXP = 0;
		bool bIsBoss = false;

		m_pPlayer->GetBattleInfo(&iPlayerHp, &iPlayerMaxHp, &iPlayerAttack, &iPlayerDefence, &bPlayerCO, &bPlayerDX, &bPlayerHU);
		m_pMonsterMgr->RequestMonsterInfo(_iRow, _iCol, &strName , &iMonsterHp, &iMonsterAttack, &iMonsterDefence, &iMonsterEXP);
		bIsBoss = m_pMonsterMgr->GetIsboss(_iRow, _iCol);

		while (1)
		{
			if ((bPlayerHU) && (bIsBoss))
				iPlayerHp = iPlayerMaxHp;

			if ((bPlayerCO) && (!bPlayerDX))
				iMonsterHp -= max(1, iPlayerAttack*2 - iMonsterDefence);
			else if ((bPlayerCO) && (bPlayerDX))
				iMonsterHp -= max(1, iPlayerAttack*3 - iMonsterDefence);
			else 
				iMonsterHp -= max(1, iPlayerAttack - iMonsterDefence);

			bPlayerCO = false;
			bPlayerDX = false;
				
			if (iMonsterHp <= 0) break;

			if ((bPlayerHU) && (bIsBoss))
			{
				bPlayerHU = false;
				continue;
			}
				
			iPlayerHp -= max(1, iMonsterAttack - iPlayerDefence);

			if (iPlayerHp <= 0) break;
		}

		bool bReborn = false;

		m_pPlayer->InputBattleResult(iPlayerHp, iMonsterEXP, strName, &bReborn);

		if ((!bReborn) && (iMonsterHp <= 0))
		{
			m_pMonsterMgr->MonsterKill(_iRow, _iCol);
			m_pTileMgr->EraseTile(_iRow, _iCol);
			if (m_pMonsterMgr->IsBossDead()) m_pPlayer->SetWin();
			return true;
		}

		if (bReborn)
		{
			m_pTileMgr->PlayerRE();
			return true;
		}
			
		if (iPlayerHp <= 0)
		{
			m_pTileMgr->PlayerDead();
			return false;
		}
	}

	bool BoxOpen(int _iRow, int _iCol)
	{
		char szType = {};
		ACTYPE eType = ACTYPE::ACTYPE_END;
		int iStat = 0;

		m_pBoxMgr->GetBoxInfo(_iRow, _iCol, &szType, &eType, &iStat);

		bool bOpen = true;

		if (szType == WEAPON)
			m_pPlayer->EquipWeapon(iStat);
		else if (szType == ARMOR)
			m_pPlayer->EquipArmor(iStat);
		else if (szType == ACCESSORY)
			bOpen = m_pPlayer->EquipAccessory(eType);

		m_pBoxMgr->SetBoxDead(_iRow, _iCol);
		m_pTileMgr->EraseTile(_iRow, _iCol);
			

		return bOpen;
	}

	void ShowResult()
	{
		m_pTileMgr->TIleRender();
		m_pTileMgr->TurnRender();
		m_pPlayer->PlayerRender();
	}



private:
	template <typename T>
	void Safe_Delete(T dest)
	{
		if (dest != nullptr)
		{
			delete dest;
			dest = nullptr;
		}
	}

private:
	CPlayer* m_pPlayer;
	CTileMgr* m_pTileMgr;
	CMonsterMgr* m_pMonsterMgr;
	CBoxMgr* m_pBoxMgr;
};

CGame_Instence* CGame_Instence::m_pInstence = nullptr;

class CMain_Game // <- 모든 게임 관련 기능을 작동시키는 객체, 턴을 세고 게임의 종료를 결정
{
public:
	CMain_Game()
	{

	}

	~CMain_Game()
	{
		Release();
	}

	void Update()
	{
		Play_Turn();
		Show_Result();
	}

	void Initialize()
	{
		CGame_Instence::Get_Instence()->Initialize();
		CGame_Instence::Get_Instence()->InputData();
	}

private:
	void Release() 
	{
		CGame_Instence::Get_Instence()->Destroy_Instence();
	}
	
	void Play_Turn()
	{
		while(1)
		{
			if (CGame_Instence::Get_Instence()->OperateCommand())
				break;
		}
	}

	void Show_Result()
	{
		CGame_Instence::Get_Instence()->ShowResult();
	}

private:

};

int main()
{
	CMain_Game cMainGame;

	cMainGame.Initialize();

	cMainGame.Update();

	cMainGame.~CMain_Game();

	return 0;
}