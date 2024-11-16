#include <iostream>
#include <ctime>



using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int const size_sample = 45;
	int const size_table = size_sample * 1.5;
	int sample[size_sample];
	int table[size_table];
	int transition = 50;
	int steps = 0;

	for (int i = 0; i < size_table; i++)
		table[i] = 0;

	int i = 0;
	while (i < size_sample) {
		int r =  (rand() % 9 + 1) * 100000 + rand() * rand() % 100000;
		bool flag = true;

		for (int n = 0; n < i; n++) {
			if (sample[n] == r) {
				flag = false;
				break;
			}
		}

		if (flag) {
			sample[i] = r;
			i++;
		}
	}

	cout << "Последовательность сгенерированных ключей:\n";

	for (int i = 0; i < size_sample; i++) {
		int r = sample[i];

		if (i != 0 and i % 10 == 0)
			cout << endl;
		cout << r << "\t";

		int pos = ((r / 100000 + r / 10000 % 10) % 10 * 100 + (r / 1000 % 100 + r / 100 % 1000) % 10 * 10 
								    + (r / 10 % 10000 + r % 10) % 10) % size_table;

		if (table[pos] == 0) {
			table[pos] = r;
			steps++;
		}
		else {
			int n = 1;
			for (; n < transition; n++) {
				if (table[(pos + n * n) % size_table] == 0) {
					table[(pos + n * n) % size_table] = r;
					steps = steps + n + 1;
					break;
				}
			}

			if (n == transition) {
				while (table[(pos + n) % size_table] != 0)
					n++;

				table[(pos + n) % size_table] = r;
				steps = steps + n + 1;
			}
		}
	}

	cout << "\n\nХеш-таблица:\n";

	for (int i = 0; i < size_table; i++) {
		if (i != 0 and i % 5 == 0)
			cout << endl;
		cout << i << ")\t" << table[i] << "\t";
	}

	cout << "\n\nРассчитанные параметры:";
	cout << "\n- коэффициент заполнения таблицы = " << 1.0 * size_sample / size_table;
	cout << "\n- среднее число шагов            = " << 1.0 * steps / size_sample;



	cout << "\n\n\n\n";
	system("pause");
}
