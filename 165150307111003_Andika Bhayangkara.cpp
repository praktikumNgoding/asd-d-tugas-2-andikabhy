#include <iostream>
#include <string>

using namespace std;
//1 alokasi memori pada linked list
struct element {
	int bil;
	int pangkat;
	string x;
	element *next;
};

struct linkedTunggal {
	element *first;
};

element *alokasi_memori(int bil, string x, int pangkat); //allocation list in memori
void createBox(linkedTunggal *link); //create list
void addValue(linkedTunggal *link, element *elm); //insert list in memori
void displayList(linkedTunggal link); //View list in memori
void delloc(element *daftar); //delete list in memori
void dellForwd(linkedTunggal *list); //delete first list (index 0)
void addBck(linkedTunggal *list, element *elm); //insert list in last (index last)
void dellBck(linkedTunggal *list); //delete last insert
void insertIndex_ke_n(linkedTunggal *list, element *elm, int ke); //insert list after index n
void dellAftr(linkedTunggal *link, int index); //delete list after index n
void update(element *yang_akan_dirubah, int bil, string x, int pangkat);

//2 pembuatan gerbong dan pengisian nilai
void createBox(linkedTunggal *link) {
	link->first = NULL;
}

element *alokasi_memori(int bil, string x, int pangkat) {
	element *p = new element;

	p->bil = bil;
	p->pangkat = pangkat;
	p->x = x;

	p->next = NULL;

	return p;
}

void addValue(linkedTunggal *link, element *elm) {
	elm->next = link->first;
	link->first = elm;

	elm = NULL;
}

void displayList(linkedTunggal link) {
	if (link.first != 0) {
		element *p = link.first;
		while (p != 0) {
			cout << p->bil << p->x << p->pangkat << "  ~  ";
			p = p->next;
		}
	}
	else {
		cout << "Pengisian data" << endl;
	}
}

void delloc(element *daftar) {
	delete(daftar);
}

void dellForwd(linkedTunggal *list) {
	if (list->first != 0) {
		element *p = list->first;
		list->first = p->next;

		p = 0;

		delloc(p);
	}
	else {
		cout << "Sudah kosong" << endl;
	}
}

void addBck(linkedTunggal *list, element *elm) {
	if (list->first != 0) {
		element *p = list->first;
		while (p->next != 0) {
			p = p->next;
		}
		p->next = elm;
		elm = 0;
	}
	else {
		addValue(list, elm);
	}
}

void dellBck(linkedTunggal *list) {
	if (list->first != 0) {
		element *temp_1 = list->first;

		if (temp_1->next == 0) {
			delloc(temp_1);
		}
		else {
			element *temp_2 = temp_1;
			temp_1 = temp_2->next;
			while (temp_1->next != 0) {
				temp_2 = temp_1;
				temp_1 = temp_2->next;
			}
			temp_2->next = 0;
			delloc(temp_1);
		}
	}
	else {
		cout << "Kosong" << endl;
	}
}

void insertIndex_ke_n(linkedTunggal *list, element *elm, int index) {
	if (list->first != 0) {
		element *temp = list->first;

		int i = 0;
		while (temp != 0 && i < index)
		{
			temp = temp->next;
		}

		if (temp != 0) {
			elm->next = temp->next;
			temp->next = elm;
		}
		else {
			cout << "Data tidak sampai ke n-" << index << endl;
		}
	}
	else {
		addValue(list, elm);
	}
}
void dellAftr(linkedTunggal *link, int index) {
	if (link->first != 0) {
		element *temp = link->first;

		int i = 0;
		while (temp != 0 && i < index) {
			temp = temp->next;
		}

		if (temp != 0) {
			if (temp->next == NULL) {
				dellBck(link);
			}
			else {
				element *temp_2 = temp->next;
				temp->next = temp_2->next;
				temp_2->next = NULL;
				delloc(temp_2);
			}
		}
		else {
			cout << "Data tidak sampai ke n-" << index << endl;
		}
	}
	else {
		cout << "Setelah dell" << endl;
	}
}

void update(element *yang_akan_dirubah, int bil, string x, int pangkat) {
	yang_akan_dirubah->bil = bil;
	yang_akan_dirubah->x = x;
	yang_akan_dirubah->pangkat = pangkat;
}


int main()
{
	linkedTunggal link;
	createBox(&link);

	element *p1 = new element;

	p1 = alokasi_memori(12, "x^", 2);
	addValue(&link, p1);

	p1 = alokasi_memori(4, "x^", 3);
	addValue(&link, p1);

	p1 = alokasi_memori(2, "x^", 6);
	addValue(&link, p1);

	p1 = alokasi_memori(9, "x^", 8);
	insertIndex_ke_n(&link, p1, 0);

	p1 = alokasi_memori(6, "x^", 2);
	addBck(&link, p1);

	cout << "P1 = ";
	displayList(link);

	cout << "\n\nDepan, tengah, dan belakang di hapus maka jadi :" << endl;

	//proses penghapusan gerbong list
	dellForwd(&link);
	dellBck(&link);
	dellAftr(&link, 0);

	cout << "P1 = ";
	displayList(link);
	cout << "\n\n" << endl;
    return 0;
}

