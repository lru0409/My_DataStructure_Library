#include "SinglyLinkedList/SinglyLinkedList.hpp"
// #include "DoublyLinkedList/DoublyLinkedList.hpp"
// #include "DoublyCircularLinkedList/DoublyCircularLinkedList.hpp"
#include <iostream>
using namespace std;

typedef SinglyLinkedList<int> List;

static void leaks();
static void PrintList(const char *title, List& list);
static void CreationAndCopyTest();
static void PushAndPopTest();
static void IteratorTest();
static void InsertAndEraseTest();

int main()
{
	// atexit(leaks);

	CreationAndCopyTest();	// 리스트 생성 및 복사 테스트
	PushAndPopTest();		// 리스트 원소 푸시 및 팝 테스트
	IteratorTest();			// 리스트 순회하며 원소 변경하는 테스트
	InsertAndEraseTest();

	return 0;
}

static void CreationAndCopyTest()
{
	cout << "========== Creation And Copy Test ==========\n";

	List list1;
	PrintList("list1", list1);

	List list2(5, 10);
	PrintList("list2", list2);

	List list3(list2);
	PrintList("list3", list3);

	List list4(5, 5);
	list4 = list2;
	PrintList("list4", list4);

	cout << '\n';
}

static void PushAndPopTest()
{
	cout << "========== Push And Pop Test ==========\n";

	List list(3, 3);
	list.push_front(2);
	list.push_front(1);
	PrintList("list after push front", list);
	list.pop_back();
	list.pop_back();
	PrintList("list after pop back", list);

	list.clear();
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	PrintList("list after push back", list);
	list.pop_front();
	list.pop_front();
	list.pop_front();
	PrintList("list2 after pop front", list);

	cout << '\n';
}

static void IteratorTest()
{
	cout << "========== Iterator Test ==========\n";

	List list;
	for(int i = 1; i <= 10; i++)
		list.push_back(i);
	PrintList("before value change", list);

	List::Iterator iter;
	for(iter = list.begin(); iter != list.end(); iter++)
		(*iter) *= 10; // 모든 원소에 10을 곱함
	PrintList("after value change", list);

	cout << '\n';
}

static void InsertAndEraseTest()
{
	cout << "========== Insert And Erase Test ==========\n";
	List list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	PrintList("initial list", list);

	List::Iterator iter = list.begin();
	list.insert(iter, 0); // 리스트의 시작에 0 삽입
	PrintList("after insert 0 at the beginning", list);

	iter = list.begin();
	iter++;
	iter++;
	list.insert(iter, 1); // 리스트의 중간에 1 삽입
	PrintList("after insert 1 in middle", list);

	iter = list.begin();
	++iter;
	list.erase(iter); // 두 번째 원소(1) 삭제
	PrintList("after erase middle element", list);

	iter = list.begin();
	for(int i = 0; i < list.size() - 1; i++) iter++; // 마지막 원소로 이동
	list.erase(iter); // 마지막 원소(3) 삭제
	PrintList("after erase last element", list);

	cout << '\n';
}

static void PrintList(const char *title, List& list)
{
	cout << "----- " << title << " -----\n";
	cout << boolalpha << "Is Empty : " << list.empty() << '\n';
	cout << "count	 : " << list.size() << '\n';
	cout << "content	 : ";
	List::Iterator iter;
	for(iter = list.begin(); iter != list.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';
}

static void leaks()
{
	system("leaks a.out");
}