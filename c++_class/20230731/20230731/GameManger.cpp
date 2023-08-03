#include "GameManger.h"
#include "BattleManager.h"


CGameManager* CGameManager::mInst = nullptr;

// 게임 매니저 생성자
CGameManager::CGameManager()
{
}

// 게임 매니저 소멸자
// 메모리가 제거가 될 때 자동으로 호출된다.
CGameManager::~CGameManager()
{
}

EMainMenu CGameManager::Menu()
{
	system("cls");
	std::cout << "1. 전투" << std::endl;
	std::cout << "2. 상점" << std::endl;
	std::cout << "3. 가방" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "메뉴를 선택하세요: ";

	int Input;

	std::cin >> Input;

	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Input;
}

bool CGameManager::Init()
{
	// 전투 관리자 클래스 생성과 초기화
	if (!CBattleManager::GetInst()->Init())
		return false;

	return true;
}

void CGameManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EMainMenu::Battle:
			CBattleManager::GetInst()->Run();
			break;
		case EMainMenu::Store:
			break;
		case EMainMenu::Inventory:
			break;
		case EMainMenu::Exit:
			return;
		}
	}
}
