#include "sort.h"

sorttable::sorttable(int _size) {
	if (_size == 0) size = DEFAULT_TABLE_SIZE;
	else size = _size;
	n_empty = 0;
	table = new keypol[size];
	for (int i = 0; i < size; i++) {
		table[i].k = string();
		table[i].d = NULL;
	}
}

sorttable::~sorttable() {
	delete[] table;
}

void sorttable::insert(string _key, Tp _data) {
	if (n_empty == 0) {
		table[0].k = _key;
		table[0].d = _data;
	}
	for (int i = 0; i < n_empty; i++) {
		if ((table[i].k != "") && (table[i].k > table[i+1].k)) continue;
		else {
			for (int j = n_empty + 1; j > i; j--) {
				table[j].k = table[j - 1].k;
				table[j].d = table[j - 1].d;
			}
			table[i].k = _key;
			table[i].d = _data;
		}
	}
	n_empty++;
}

int sorttable::search(string _key) {
	int M = 0, S = 0, E = n_empty;   //  S - start, E - end, M - middle
	do {
		M = (S + E) / 2;
		if (_key < table[M].k) E = M - 1;
		else
			if (_key < table[M].k)
				S = M + 1;
			else
				return M;
		if (S > E)
			return NULL;
	} while (1);
}

void sorttable::del(string _key) {
	int M = 0, S = 0, E = n_empty;
	/*do {
		M = (S + E) / 2;
		if (_key < table[M].k) E = M - 1;
		else
			if (_key < table[M].k)
				S = M + 1;
			else {
				for (int i = M; i < n_empty; i++) {
					table[i].k = table[i + 1].k;
					table[i].d = table[i + 1].d;
				}
				n_empty--;
				return;
			}
			if (S > E)
				return;
	} while (1);*/
	M = search(_key);
	for (int i = M; i < n_empty; i++) {
		table[i].k = table[i + 1].k;
		table[i].d = table[i + 1].d;
	}
	n_empty--;
	return;
}

void sorttable::writetab() {
	int i;
	for (i = 0; i < n_empty; i++)
		cout << "table[" << i << "]: key = " << table[i].k << ", data = " << table[i].d << endl;
}