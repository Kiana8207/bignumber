#include"bignum.h"

istream& operator>>(istream& in, bignum& b) {
	cout << "adad ra vared konid" << endl;
	string s;
	in >> s;
	b.size = s.size();
	b.a = new int[b.size];
	for (int i = 0; i < b.size; i++) {
		b.a[b.size - 1 - i] = s[i] - 48;
	}
	return in;
}
ostream& operator<<(ostream& out, const bignum& b) {
	for (int i = b.size - 1; i >= 0; i--) {
		out << b.a[i];
	}
	return out;
}

int main() {
	bignum a, b, c, e, f, g, x, y;
	cin >> a >> b;
	system("CLS");
	c = a;
	e = a;
	f = b;
	g = a;
	x = a;
	y = a;
	cout << "a:" << a << endl << "b:" << b << endl;
	cout << "---------------------" << endl;

	cout << "a+b=";
	bignum d = a + b;
	cout << d << endl;
	cout << "---------------------" << endl;

	cout << "a+=b=";
	cout << (c += b) << endl;
	cout << "---------------------" << endl;

	cout << "a-b=";
	cout << a - b << endl;
	cout << "---------------------" << endl;

	cout << "a-=b=";
	cout << (y -= b) << endl;
	cout << "---------------------" << endl;

	cout << "a*b=";
	cout << x * b << endl;
	cout << "---------------------" << endl;

	//cout << "a*=b=";
	//cout << (c *= b) << endl;
	//cout << "---------------------" << endl;

	cout << "a++=";
	cout << e++ << endl;
	cout << "---------------------" << endl;

	cout << "b++=";
	cout << b++ << endl;
	cout << "---------------------" << endl;

	cout << "a--=";
	cout << g-- << endl;
	cout << "---------------------" << endl;

	cout << "b--=";
	cout << f-- << endl;
	cout << "---------------------" << endl;

	if (b == a) {
		cout << "a==b" << endl;
		cout << "---------------------" << endl;
	}

	if (b != a) {
		cout << "a!=b" << endl;
		cout << "---------------------" << endl;
	}

	if (a < b) {
		cout << "a<b" << endl;
		cout << "---------------------" << endl;

	}

	if (a > b) {
		cout << "a>b" << endl;
		cout << "---------------------" << endl;
	}

	if (a <= b) {
		cout << "a<=b" << endl;
		cout << "---------------------" << endl;
	}

	if (a >= b) {
		cout << "a>=b" << endl;
		cout << "---------------------" << endl;

	}

	system("pause");
	return 0;
}