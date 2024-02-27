#include"bignum.h"

bignum::bignum() {
	size = 1;
	a = new int[size];
	for (int i = 0; i < size; i++) {
		a[i] = 0;
	}
}
bool bignum::operator==(const bignum& b)
{
	if (size != b.size)
		return false;

	else {
		for (int i = 0; i < size; i++) {
			if (a[i] != b.a[i])
				return false;
		}
		return true;
	}
}

bool bignum::operator!=(const bignum& b)
{
	return !(*this == b);
}

bignum bignum::operator+(const bignum& b2)
{
	int maxsize = b2.size > size ? b2.size : size;
	maxsize++;
	int* tempp = new int[maxsize];
	for (int i = 0; i < maxsize; i++) {
		tempp[i] = 0;
	}
	if (size > b2.size) {
		for (int i = 0; i < maxsize - 1; i++) {
			if (i < b2.size) {
				int temp = a[i] + b2.a[i] + tempp[i];
				tempp[i] = temp % 10;
				tempp[i + 1] += temp / 10;
			}
			else {
				int temp = a[i] + tempp[i];
				tempp[i] = temp % 10;
				tempp[i + 1] += temp / 10;
			}

		}
	}
	else {
		int temp = 0;
		for (int i = 0; i < maxsize - 1; i++) {
			if (i < size) {
				temp = a[i] + b2.a[i] + tempp[i];
				tempp[i] = temp % 10;
				tempp[i + 1] += temp / 10;
			}
			else {
				temp = a[i] + tempp[i];
				tempp[i] = temp % 10;
				tempp[i + 1] += temp / 10;
			}
		}
	}
	int index = maxsize - 1;
	while (tempp[index] == 0) index--;

	bignum res;
	res.size = index + 1;
	res.a = new int[res.size];
	for (int i = 0; i < res.size; i++) {
		res.a[i] = tempp[i];
	}
	return res;
}

bignum bignum::operator-(const bignum& b)
{
	bignum c;
	int max = size > b.size ? size : b.size;
	c.a = new int[max];
	for (int i = 0; i < max; i++) {
		c.a[i] = 0;
	}
	if (size > b.size) {
		for (int i = 0; i < b.size; i++) {
			if (a[i] > b.a[i]) {
				c.a[i] = a[i] - b.a[i];
			}
			else if (a[i] == b.a[i]) {
				c.a[i] = 0;
			}
			else if (a[i] < b.a[i]) {
				a[i + 1] = a[i + 1] - 1;
				a[i] = a[i] + 10;
				c.a[i] = a[i] - b.a[i];
			}
		}
		for (int i = b.size; i < size; i++) {
			c.a[i] = a[i];
		}
	}
	else if (size == b.size) {
		if (a[size - 1] > b.a[size - 1]) {
			for (int i = 0; i < b.size; i++) {
				if (a[i] > b.a[i]) {
					c.a[i] = a[i] - b.a[i];
				}
				else if (a[i] == b.a[i]) {
					c.a[i] = 0;
				}
				else if (a[i] < b.a[i]) {
					a[i + 1] = a[i + 1] - 1;
					a[i] = a[i] + 10;
					c.a[i] = a[i] - b.a[i];
				}
			}
		}
		else if (a[size - 1] == b.a[size - 1]) {
			for (int i = 0; i < b.size; i++) {
				if (a[i] > b.a[i]) {
					c.a[i] = a[i] - b.a[i];
				}
				else if (a[i] == b.a[i]) {
					c.a[i] = 0;
				}
				else if (a[i] < b.a[i]) {
					a[i + 1] = a[i + 1] - 1;
					a[i] = a[i] + 10;
					c.a[i] = a[i] - b.a[i];
				}
			}
		}
		else if (a[size - 1] < b.a[size - 1]) {
			cout << "-";
			for (int i = 0; i < b.size; i++) {
				if (a[i] < b.a[i]) {
					c.a[i] = b.a[i] - a[i];
				}
				else if (a[i] == b.a[i]) {
					c.a[i] = 0;
				}
				else if (a[i] > b.a[i]) {
					b.a[i + 1] = b.a[i + 1] - 1;
					b.a[i] = b.a[i] + 10;
					c.a[i] = b.a[i] - a[i];
				}
			}
		}
	}
	else if (size < b.size) {
		cout << "-";
		for (int i = 0; i < size; i++) {
			if (a[i] > b.a[i]) {
				b.a[i + 1] = b.a[i + 1] - 1;
				b.a[i] = b.a[i] + 10;
				c.a[i] = b.a[i] - a[i];

				c.a[i] = b.a[i] - a[i];
			}
			else if (a[i] == b.a[i]) {
				c.a[i] = 0;
			}
			else if (a[i] < b.a[i]) {
				c.a[i] = b.a[i] - a[i];

			}
		}
		for (int i = size; i < b.size; i++) {
			c.a[i] = b.a[i];
		}
	}
	for (int i = max - 1; i > 0; i--) {
		cout << c.a[i];
	}
	return c;
}

bignum& bignum::operator=(const bignum& b)
{
	if (size != b.size) {
		delete[]a;
		size = b.size;
		a = new int[size];
	}
	for (int i = 0; i < size; i++) {
		a[i] = b.a[i];
	}
	return *this;
}

bool bignum::operator>(const bignum& b)
{
	if (size < b.size) {
		return false;
	}
	else if (b.size < size) {
		return true;
	}
	else if (size == b.size) {
		for (int i = b.size - 1; i >= 0; i--) {
			if (a[i] > b.a[i])
				return false;
			else if (a[i] < b.a[i])
				return true;
			else if (a[i] == b.a[i])
				continue;
		}
	}
}

bool bignum::operator<(const bignum& b)
{
	if (size < b.size) {
		return true;
	}
	else if (b.size < size) {
		return false;
	}
	else if (size == b.size) {
		for (int i = b.size - 1; i >= 0; i--) {
			if (a[i] > b.a[i])
				return true;
			else if (a[i] < b.a[i])
				return false;
			else if (a[i] == b.a[i])
				continue;
		}
		return false;
	}
}

bool bignum::operator<=(const bignum& b)
{
	return (!(*this > b) && *this == b);
}

bool bignum::operator>=(const bignum& b)
{
	return (!(*this < b) && *this == b);
}

bignum& bignum::operator+=(const bignum& b)
{
	int carry = 0, temp = 0;

	if (size < b.size) {
		cout << "not enough size" << endl;
		cout << "a=";
	}
	else if (size == b.size) {
		for (int i = 0; i < size; i++) {
			temp = a[i] + b.a[i];
			a[i] = temp % 10;
			carry = temp / 10;
			a[i + 1] = a[i + 1] + carry;
		}
	}
	else if (size > b.size) {
		for (int i = 0; i < b.size; i++) {
			temp = a[i] + b.a[i];
			a[i] = temp % 10;
			carry = temp / 10;
			a[i + 1] = a[i + 1] + carry;
		}
	}
	return *this;

}
bignum bignum::operator*(const bignum& b)
{
	int start = 0, carry = 0;
	int maxsize = size + b.size;
	int* temp = new int[maxsize];
	for (int i = 0; i < maxsize; i++) {
		temp[i] = 0;
	}
	for (int j = 0; j < b.size; j++) {
		for (int i = 0; i < size; i++) {
			carry = b.a[j] * a[i];
			temp[i + start] += carry % 10;
			temp[i + start + 1] += carry / 10;
			if (temp[i + start] > 9) {
				temp[i + start + 1] += temp[start + i] / 10;
				temp[i + start] += temp[start + i] % 10;
			}
		}
		start++;
	}
	bignum res;
	int index = maxsize - 1;
	while (temp[index] == 0) index--;
	res.size = index + 1;
	res.a = new int[res.size];
	for (int i = 0; i < res.size; i++) {
		res.a[i] = temp[i];
	}
	return res;
}

bignum bignum::operator++(int)//pishvandi
{
	int temp = 0, carry = 0;

	for (int i = 0; i < size; i++) {
		temp = a[i] + 1 + carry;
		a[i] = temp % 10;
		carry = temp / 10;
	}
	return *this;
}

bignum bignum::operator--(int) {//pishvandi
	for (int i = 0; i < size; i++) {
		if (a[i] < 1) {
			a[i + 1] = a[i + 1] - 1;
			a[i] = a[i] + 10;
			a[i] = a[i] - 1;
		}
		else if (a[i] == 1) {
			a[i] = 0;
		}
		else if (a[i] > 1) {
			a[i] = a[i] - 1;
		}
	}
	return *this;
}

bignum bignum::operator-=(const bignum& b)
{
	bignum c;
	int max = size > b.size ? size : b.size;
	c.a = new int[max];
	for (int i = 0; i < max; i++) {
		c.a[i] = 0;
	}
	if (size > b.size) {
		for (int i = 0; i < b.size; i++) {
			if (a[i] > b.a[i]) {
				c.a[i] = a[i] - b.a[i];
			}
			else if (a[i] == b.a[i]) {
				c.a[i] = 0;
			}
			else if (a[i] < b.a[i]) {
				a[i + 1] = a[i + 1] - 1;
				a[i] = a[i] + 10;
				c.a[i] = a[i] - b.a[i];
			}
		}
		for (int i = b.size; i < size; i++) {
			c.a[i] = a[i];
		}
	}
	else if (size == b.size) {
		if (a[size - 1] > b.a[size - 1]) {
			for (int i = 0; i < b.size; i++) {
				if (a[i] > b.a[i]) {
					c.a[i] = a[i] - b.a[i];
				}
				else if (a[i] == b.a[i]) {
					c.a[i] = 0;
				}
				else if (a[i] < b.a[i]) {
					a[i + 1] = a[i + 1] - 1;
					a[i] = a[i] + 10;
					c.a[i] = a[i] - b.a[i];
				}
			}
		}
		else if (a[size - 1] == b.a[size - 1]) {
			for (int i = 0; i < b.size; i++) {
				if (a[i] > b.a[i]) {
					c.a[i] = a[i] - b.a[i];
				}
				else if (a[i] == b.a[i]) {
					c.a[i] = 0;
				}
				else if (a[i] < b.a[i]) {
					a[i + 1] = a[i + 1] - 1;
					a[i] = a[i] + 10;
					c.a[i] = a[i] - b.a[i];
				}
			}
		}
		else if (a[size - 1] < b.a[size - 1]) {
			cout << "-";
			for (int i = 0; i < b.size; i++) {
				if (a[i] < b.a[i]) {
					c.a[i] = b.a[i] - a[i];
				}
				else if (a[i] == b.a[i]) {
					c.a[i] = 0;
				}
				else if (a[i] > b.a[i]) {
					b.a[i + 1] = b.a[i + 1] - 1;
					b.a[i] = b.a[i] + 10;
					c.a[i] = b.a[i] - a[i];
				}
			}
		}
	}
	else if (size < b.size) {
		cout << "-";
		for (int i = 0; i < size; i++) {
			if (a[i] > b.a[i]) {
				b.a[i + 1] = b.a[i + 1] - 1;
				b.a[i] = b.a[i] + 10;
				c.a[i] = b.a[i] - a[i];

				c.a[i] = b.a[i] - a[i];
			}
			else if (a[i] == b.a[i]) {
				c.a[i] = 0;
			}
			else if (a[i] < b.a[i]) {
				c.a[i] = b.a[i] - a[i];

			}
		}
		for (int i = size; i < b.size; i++) {
			c.a[i] = b.a[i];
		}
	}
	delete[]a;
	a = new int[max];
	for (int i = 0; i < max; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < max; i++) {
		a[i] = c.a[i];
	}
	return *this;
}