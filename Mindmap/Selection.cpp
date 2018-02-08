#include "Selection.h"

Selection::Selection(Long capacity)
	:selections(capacity)
{
	this->capacity = capacity;
	this->length = 0;
}

Selection::Selection(const Selection & source)
	:selections(source.selections)
{
	this->capacity = source.capacity;
	this->length = source.length;
}

Selection::~Selection()
{
}

Long Selection::Add(Branch * branch)
{
	Long index;

	//선택된 브랜치의 마크를 보이게 한다.
	branch->GetMark()->Show();

	// branch를 배열에 추가한다.
	if (this->length < this->capacity) {
		index = this->selections.Store(this->length, branch);
	}
	else {
		index = this->selections.AppendFromRear(branch);
		this->capacity++;
	}

	this->length++;
	return index;
}

Long Selection::Remove(Branch * branch)
{
	Long index = -1;

	//찾는다.
	index = this->selections.LinearSearchUnique(&branch, CompareBranches);

	//찾으면 마크를 없애고 지운다.
	if (index != -1) {
		branch->GetMark()->Hide();

		this->selections.Delete(index);
		index = -1;
		this->length--;
	}
	return index;
}

void Selection::Clear()
{
	Branch* branch;
	Long i = 0;

	while (i < this->length) {
		//마크표시를 지운다.
		branch = this->selections.GetAt(i);
		branch->GetMark()->Hide();
		i++;
		//선택 해제한다.
		this->selections.Delete(i);
	}
	this->length = 0;
}

Branch * Selection::GetLastSelection()
{
	Branch *selection = NULL;
	if (this->length > 0) {
		selection = this->selections.GetAt(this->length - 1);
	}
	return selection;
}

Branch* Selection::GetAt(Long index)
{
	Branch *branch;
	branch = this->selections.GetAt(index);
	return branch;
}

bool Selection::IsSelected(Branch *branch)
{
	bool ret = false;
	Long index = -1;

	index = this->selections.LinearSearchUnique(&branch, CompareBranches);
	if (index != -1) {
		ret = true;
	}
	return ret;
}

Selection& Selection::operator=(const Selection & source)
{
	this->selections = source.selections;
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}

int CompareBranches(void *one, void *other) {
	int ret = -1;
	if (*((Branch**)one) == *((Branch**)other)) {
		ret = 0;
	}
	return ret;
}

/*
#include <iostream>
#include <string>
#include "Topic.h"
using namespace std;

int main(int argc, char argv[]) {
	bool ret;
	//선택 생성
	Selection selection;
	Selection selection2(3);

	//토픽 생성
	Topic mainTopic(1, 1, 1, 1, "mainTopic");
	Topic subTopic1(1, 1, 1, 1, "subTopic1");
	Topic subTopic2(1, 1, 1, 1, "subTopic2");

	//브랜치생성
	Branch mainBranch(111);
	Branch subBranch1;
	Branch subBranch2;

	//브랜치에 토픽추가
	mainBranch.Add(&mainTopic);
	subBranch1.Add(&subTopic1);
	subBranch2.Add(&subTopic2);

	//선택 생성 확인
	cout <<"selection capacity: " <<selection.GetCapacity() <<"  length :  "<< selection.GetLength()<< endl;
	cout << "selection2 capacity: " << selection2.GetCapacity() << "  length :  " << selection2.GetLength() << endl;

	//Add ,IsSelected  Test
	ret=selection.IsSelected(&mainBranch);
	if (ret == true) {
		cout << " 메인브랜치가 있습니다." << endl;
	}
	else {
		cout << "메인브랜치가 없습니다." << endl;
	}
	selection.Add(&mainBranch);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent()<< endl;

	ret = selection.IsSelected(&mainBranch);
	if (ret == true) {
		cout << "메인브랜치가 있습니다." << endl;
	}
	else {
		cout << "메인브랜치가 없습니다." << endl;
	}
	ret = selection.IsSelected(&subBranch1);
	if (ret == true) {
		cout << "섭브랜치1 있습니다." << endl;
	}
	else {
		cout << "섭브랜치1 없습니다." << endl;
	}
	selection.Add(&subBranch1);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;
	ret = selection.IsSelected(&subBranch1);
	if (ret == true) {
		cout << "섭브랜치1있습니다." << endl;
	}
	else {
		cout << "섭브랜치1없습니다." << endl;
	}
	selection.Add(&subBranch2);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;

	//복사생성자,Clear Test
	selection2 = selection;
	cout << endl<< "selection2 capacity: " << selection2.GetCapacity() << "  length :  " << selection2.GetLength()<<endl ;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent()  << endl;
	selection2.Clear();
	cout<< "selection2 capacity: " << selection2.GetCapacity() << "  length :  " << selection2.GetLength() << endl << endl;

	//Remove Test
	selection.Remove(&subBranch2);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;
	selection.Remove(&subBranch1);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;
	ret = selection.IsSelected(&mainBranch);
	if (ret == true) {
		cout << "메인브랜치가 있습니다." << endl;
	}
	else {
		cout << "메인브랜치가 없습니다." << endl;
	}
	selection.Remove(&mainBranch);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	ret = selection.IsSelected(&mainBranch);
	if (ret == true) {
		cout << "메인브랜치가 있습니다." << endl;
	}
	else {
		cout << "메인브랜치가 없습니다." << endl;
	}
	//cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;

	return 0;
}
*/