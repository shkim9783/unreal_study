#include <iostream>

/*

객체: 사물이나 사람같은 것들을 말한다.
프로그래밍에서 객체는 변수 하나하나를 객체로 볼 수 있다.

객체지향 프로그래밍: 특정 기능을 하는 객체들을 모아서 조립하여 하나의 완성된 프로그램을 만들어나가는 프로그래밍 방식이다.

클래스: 객체지향 프로그래밍을 지원하기 위한 문법이다.
	변수와 함수를 묶어서 사용할 수 있게 해주는 기능이다.

형태

class 클래스이름
{
	멤버변수나 멤버함수들.
};

클래스나 구조체는 멤버에 접근할 수 있는 수준을 정의할 수 있는 키워드를 지원해준다.
접근수준을 정의하는 키워드들은 특정 키워드를 사용하면 그 아래의 모든 멤버는 전부 영향을 받게 된다.
단, 다른 키워드를 만나게 된다면 그 위 까지만 영향을 주고 해당 키워드의 아래부터는 해당 키워드로 영향을 줄 수 있다.

클래스 내부: 클래스의 멤버함수 안을 의미한다.
클래스 외부: 클래스의 멤버함수가 아닌 멤버 변수를 의미한다.

- public: 클래스 내부, 외부에서 모두 접근이 가능한 키워드이다.

- private: 클래스 내부에서는 접근이 가능하지만 외부에서는 접근이 불가능한 키워드이다.

- protected: 나중에 상속할 때 다시 설명!

클래스는 아무것도 붙여주는 것이 없을 경우 기본으로 private으로 설정되 되고,
구조체는 아무것도 붙여주는 것이 없을 경우 기본으로 pubilc으로 설정되 된다.


클래스의 생성자와 소멸자
생성자: 클래스를 이용해서 객체를 생성하면 자동으로 호출이 되는 함수이다.
	만약 클래스에 생성자를 만들어두지 않느다면 컴파일러는 자동으로 기본 생성자를 만들어주게 된다.
	생성자 함수의 이름은 클래스 이름과 똑같아야 한다.
	반환타입은 아예 작성하면 안된다.

	예)
	CTest()
	{
	}

소멸자: 클래스를 이용해서 생성한 객체가 메모리에서 제거될 때 자동으로 호출이 되는 함수이다.
	만약 클래스에 소멸자를 만들어두지 않는다면 컴파일러는 자동으로 기본 소멸자를 만들어주게 된다.
	소멸자 함수의 이름은 클래스 이름과 똑같아야 한다.
	반환타입은 아예 작성하면 안된다.
	하지만 소멸자는 함수 이름 앞에 ~를 붙여야 한다.

	예)
	~CTest()
	{
	}

this: 자기자신의 포인터. 모든 클래스는 this를 가지고 있다.
this는 포인터변수 1개이다.
멤버함수를 호출할 때 호출한 객체의 주소가 this에 전달되고 호출된 함수가 종료될 때까지 this는 그 값을 그대로 유지하고 있다.
*/
class CTest // 클래스는 변수명 제일 앞에 C를 붙인다. 열거형은 E를 붙이기도 한다.
{
	// 멤버변수 네이밍
	int mNumber;
// 묶어서 접근수준을 선언한다.
private:
	int mNumber1;

public:
	int mNumber2 = 0;

public:
	void Output()
	{
		// 클래스 내부
		// mNumber1 = 1010;
		std::cout << "Ctest Class Ouput Function : " << this->mNumber2 <<
			std::endl;
	}

public:
	// Intializer를 사용하면 int a = 0; 과 같이 멤버변수를 선언과 동시에 초기화 하는 기능이다.
	// 현업에서 많이 사용하는 방식이다.
	CTest():
		mNumber(0),
		mNumber1(0)
	{
		std::cout << "CTest 생성자" << std::endl;
		// 여기에 초기화를 하면 변수를 선언한 후에 값을 대입해주는 개념이다.
		// int a; a = 0; 이것과 같은 개념이다.
		mNumber = 0;
	}

	CTest(int Num1) :
		mNumber(Num1),
		mNumber1(0),
		mNumber2(0)
	{
		std::cout << "CTest int 1개 생성자" << std::endl;
	}

	CTest(int Num1, int Num2) :
		mNumber(Num1),
		mNumber1(Num2),
		mNumber2(0)
	{
		std::cout << "CTest int 2개 생성자" << std::endl;
	}


	// 소멸자는 무조건 1개의 형태만 존재한다. 오버로딩이 불가능하다.
	~CTest()
	{
		std::cout << "CTest 소멸자" << std::endl;
	}

};


struct FTest
{
	int mNumber;
	int mNumber1;

};


// 외부에 선언되어 있는 함수 == 클래스 외부(멤버함수가 아니므로)
int main()
{
	/*CTest test1;
	CTest test2;
	CTest test3;*/

	CTest test1, test2(10), test3(10, 20);

	//test1.mNumbe = 100;

	//test1.mNumber2 = 100;
	test1.mNumber2 = 500;
	test2.mNumber2 = 600;
	test3.mNumber2 = 700;


	// test1.Output()을 하게되면 이때는 this가 test1객체의 메모리 주소가 된다.
	test1.Output();

	// test2.Output()을 하게되면 이때는 this가 test2객체의 메모리 주소가 된다.
	test2.Output();

	// test3.Output()을 하게되면 이때는 this가 test3객체의 메모리 주소가 된다.
	test3.Output();


	FTest test11;
	test11.mNumber = 200;


	return 0;
}