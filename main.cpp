#include <iostream>
#include <string>
#include <list>
using namespace std;

struct FeedItem
{
	int itemId;
	string title;
	string pics[51];  
	string author;
	string category;
};

typedef list<FeedItem> ReorderList;

ReorderList reorderFeedItems(ReorderList inputItems) { //50->10
	ReorderList ans;
	ReorderList::iterator i;
	ReorderList::iterator j;
	//2.3 ����ʱ, ��ͬcategory��FeedItem���������ʾ2��
	for (i = inputItems.begin(), j = ++inputItems.begin(); j != inputItems.end(); i++, j++) {
		if (i->category != j->category) {
			continue;
		}
		else if (i->category == j->category) {
			j++;
			if (i->category != j->category) {
				continue;
			}
			else if (i->category == j->category) { //�������3���������ŵ���һ��category��ͬ��Ԫ�غ���
				i = j;
				FeedItem tmp = *i;
				while (i->category == j->category && j != inputItems.end()) {
					j++;
				}
				inputItems.erase(i);
				inputItems.insert(++j, tmp);
			}
		}
	}
	//2.2 ����ʱ, ��ͬauthor��FeedItem��������
	for (i = inputItems.begin(), j = ++inputItems.begin(); j != inputItems.end(); i++, j++) {
		if (i->author != j->author) {
			continue;
		}
		else if (i->author == j->author) {  //�����ڣ���Ԫ�����ŵ���һ��author��ͬ��Ԫ�غ���
			i = j;
			FeedItem tmp = *i;
			while (i->author == j->author && j != inputItems.end()) {
				j++;
			}
			inputItems.erase(i);
			inputItems.insert(++j, tmp);
		}
	}
	//����ִ��2.3������Ҫ����ִ��2.2������Ҫ������ڷ�����ͻʱ����������2.2

	//�����ȡǰ10�����
	int k = 0;
	i = inputItems.begin();
	while (k < 10) {
		ans.push_back(*i);
		i++;
		k++;
	}
	return ans;
}

int main() {
	//������������
	return 0;
}