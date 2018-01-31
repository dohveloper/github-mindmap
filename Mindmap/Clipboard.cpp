#include "Clipboard.h"

Clipboard::Clipboard(Long capacity)
	:clipboard(capacity)
{
	this->capacity = capacity;
	this->length = 0;
}

Clipboard::Clipboard(const Clipboard & source)
	:clipboard(source.clipboard)
{
	this->capacity = source.capacity;
	this->length = source.length;
}

Clipboard::~Clipboard()
{
}

void Clipboard::Copy(Selection *selection)
{
	Long index;
	Long i=0;
	Branch *currentItem;
	Branch *clone;
	
	while (i < selection->GetLength()) {
		currentItem = selection->GetAt(i);
		clone = currentItem->Clone();
		if (this->length < this->capacity) {
			index = this->clipboard.Store(this->length, clone);
		}
		else {
			index = this->clipboard.AppendFromRear(clone);
			this->capacity++;
		}
		this->length++;
		i++;
	}

}

void Clipboard::Paste(Selection *selection)
{
	Long i = 0;
	Branch *branch;
	branch = selection->GetLastSelection();

	while (i < this->length) {
		branch->Add(this->clipboard.GetAt(i));
		i++;
	}
}




Clipboard& Clipboard::operator=(const Clipboard & source)
{
	this->clipboard = source.clipboard;
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}



/*
#include <iostream>
#include <string>
#include "Topic.h"
using namespace std;

int main(int argc, char argv[]) {

bool ret;
//���� ����
Clipboard Clipboard;
Clipboard Clipboard2(3);

//���� ����
Topic mainTopic(1, 1, 1, 1, "mainTopic");
Topic subTopic1(1, 1, 1, 1, "subTopic1");
Topic subTopic2(1, 1, 1, 1, "subTopic2");

//�귣ġ����
Branch mainBranch(111);
Branch subBranch1;
Branch subBranch2;

//�귣ġ�� �����߰�
mainBranch.Add(&mainTopic);
subBranch1.Add(&subTopic1);
subBranch2.Add(&subTopic2);

//���� ���� Ȯ��
cout <<"Clipboard capacity: " <<Clipboard.GetCapacity() <<"  length :  "<< Clipboard.GetLength()<< endl;
cout << "Clipboard2 capacity: " << Clipboard2.GetCapacity() << "  length :  " << Clipboard2.GetLength() << endl;

//Add ,IsSelected  Test
ret=Clipboard.IsSelected(&mainBranch);
if (ret == true) {
cout << " ���κ귣ġ�� �ֽ��ϴ�." << endl;
}
else {
cout << "���κ귣ġ�� �����ϴ�." << endl;
}
Clipboard.Add(&mainBranch);
cout << "Clipboard capacity: " << Clipboard.GetCapacity() << "  length :  " << Clipboard.GetLength() << endl;
cout << "content : " << Clipboard.GetLastClipboard()->GetTopic()->GetContent()<< endl;

ret = Clipboard.IsSelected(&mainBranch);
if (ret == true) {
cout << "���κ귣ġ�� �ֽ��ϴ�." << endl;
}
else {
cout << "���κ귣ġ�� �����ϴ�." << endl;
}
ret = Clipboard.IsSelected(&subBranch1);
if (ret == true) {
cout << "���귣ġ1 �ֽ��ϴ�." << endl;
}
else {
cout << "���귣ġ1 �����ϴ�." << endl;
}
Clipboard.Add(&subBranch1);
cout << "Clipboard capacity: " << Clipboard.GetCapacity() << "  length :  " << Clipboard.GetLength() << endl;
cout << "content : " << Clipboard.GetLastClipboard()->GetTopic()->GetContent() << endl;
ret = Clipboard.IsSelected(&subBranch1);
if (ret == true) {
cout << "���귣ġ1�ֽ��ϴ�." << endl;
}
else {
cout << "���귣ġ1�����ϴ�." << endl;
}
Clipboard.Add(&subBranch2);
cout << "Clipboard capacity: " << Clipboard.GetCapacity() << "  length :  " << Clipboard.GetLength() << endl;
cout << "content : " << Clipboard.GetLastClipboard()->GetTopic()->GetContent() << endl;

//���������,Clear Test
Clipboard2 = Clipboard;
cout << endl<< "Clipboard2 capacity: " << Clipboard2.GetCapacity() << "  length :  " << Clipboard2.GetLength()<<endl ;
cout << "content : " << Clipboard.GetLastClipboard()->GetTopic()->GetContent()  << endl;
Clipboard2.Clear();
cout<< "Clipboard2 capacity: " << Clipboard2.GetCapacity() << "  length :  " << Clipboard2.GetLength() << endl << endl;


//Remove Test
Clipboard.Remove(&subBranch2);
cout << "Clipboard capacity: " << Clipboard.GetCapacity() << "  length :  " << Clipboard.GetLength() << endl;
cout << "content : " << Clipboard.GetLastClipboard()->GetTopic()->GetContent() << endl;
Clipboard.Remove(&subBranch1);
cout << "Clipboard capacity: " << Clipboard.GetCapacity() << "  length :  " << Clipboard.GetLength() << endl;
cout << "content : " << Clipboard.GetLastClipboard()->GetTopic()->GetContent() << endl;
ret = Clipboard.IsSelected(&mainBranch);
if (ret == true) {
cout << "���κ귣ġ�� �ֽ��ϴ�." << endl;
}
else {
cout << "���κ귣ġ�� �����ϴ�." << endl;
}
Clipboard.Remove(&mainBranch);
cout << "Clipboard capacity: " << Clipboard.GetCapacity() << "  length :  " << Clipboard.GetLength() << endl;
ret = Clipboard.IsSelected(&mainBranch);
if (ret == true) {
cout << "���κ귣ġ�� �ֽ��ϴ�." << endl;
}
else {
cout << "���κ귣ġ�� �����ϴ�." << endl;
}
//cout << "content : " << Clipboard.GetLastClipboard()->GetTopic()->GetContent() << endl;

return 0;
}
*/